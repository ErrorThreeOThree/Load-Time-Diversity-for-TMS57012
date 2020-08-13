/** @file
*   @brief Load time diversification source file
*   @date 19-06-07
*   @version 0.1
*
*   This file contains:
*   - Functions for load-time diversification
*   - Functions to verify the diversified version
*/
#include "string_custom.h"
#include "stdint.h"
#include "diversity.h"
#include "rand.h"

/**
 * @brief number of branch offset bits
 * The number of bits used for branch offset. Equal to the branch range.
 */
#define INSTR_JUMP_OFFS_MASK_BITS_AMOUNT 24

/**
 * @brief branch destination offset bits
 * Masks the destination offset bits of all branch instructions
 */
#define INSTR_BRANCH_OFFS_MASK 0x00FFFFFF

/**
 * @brief branch instruction encoding bits
 * Masks the instruction encoding bits of branch instructions
 */
#define INSTR_JUMP_INSTR_MASK (~INSTR_BRANCH_OFFS_MASK)

/***** global variables *****/

/***** function declaration *****/

uint32_t calculate_instr_jump_offset(const struct div_data *data, const struct bt_entry *bt, uint32_t mis_id);

void update_mis_code_exec_offs(struct div_data *data);

int verify_instruction(const struct div_data *data, uint32_t instr_exec_offs, uint32_t cur_mis_id);

int verify_jump(const struct div_data *data, uint32_t jmp_instr_exec_offs,
		uint32_t jmp_instr_load_offset, uint32_t cur_mis_id);

uint32_t code_get_mis_id(uint32_t instr_offs, const uint32_t *mis_code_offs, const uint32_t *mis_code_size);

uint32_t reduce(uint32_t x, uint32_t N);

/***** Function definitions *****/

/**
*   @brief fast reduction of x to range 0...N
*   @author https://lemire.me/blog/2016/06/27/a-fast-alternative-to-the-modulo-reduction/
*   @param[in] x value to be reduced
*   @param[in] N reduction limit
*
*   Reduces the number @p x in to a value from 0 to @p N. Source:
*/
uint32_t reduce(uint32_t x, uint32_t N) {
  return ((uint64_t) x * (uint64_t) N) >> 32 ;
}

/**
 *  @brief Initialize div_data
 *  @author Julian Hartmer
 *  @param[in] data
 *  @param[in] code_load
 *  @param[in] code_exec
 *  @param[in] data_load
 *
 * Initializes @p data with the values values mis_code_load_offs, mis_code_size and bt stored at @p data_load,
 * Copies @p code_load and @p code_exec. Initializes id_to_pos, pos_to_id and mis_code_exec_offs with zeros.
 */
void div_load_data(struct div_data *data, const uint32_t *code_load, uint32_t *code_exec, const uint32_t *data_load) {
	int i;

	data->code_load = code_load;
	data->code_exec = code_exec;
	memcpy_custom(data, data_load, sizeof(uint32_t) * (2*MIS_AMOUNT + 2*BT_SIZE));

	for (i = 0; i < MIS_AMOUNT; i++) {
		data->pos_to_id[i] = i;
		data->id_to_pos[i] = i;
	}
}

/**
*   @brief Generates a new order of MIS, updates @p data 's id_to_pos and pos_to_id
*   @author Julian Hartmer
*   @param[in] data initialized pointer to struct div_data
*
*   Generates a new MIS order. Uses PRNG. Stores the order in @p data 's id_to_pos and pos_to_id.
*/
void div_generate_MIS_order(struct div_data *data) {
	uint32_t i, j, tmp;
	/* generate random sequence from id_to_position
       Fisher-Yate shuffle */
	for (i = MIS_AMOUNT-1; i > 0; i--) {
		j = reduce(rand_custom(), i+1);
		//swap id_to_position[i] and id_to_position[j]
		tmp = data->id_to_pos[i];
		data->id_to_pos[i] = data->id_to_pos[j];
		data->id_to_pos[j] = tmp;

		/* swap position_to_id's entries with the swapped values
		   from id_to_position */
		tmp = data->pos_to_id[data->id_to_pos[i]];
		data->pos_to_id[data->id_to_pos[i]] =
			data->pos_to_id[data->id_to_pos[j]];
		data->pos_to_id[data->id_to_pos[j]] = tmp;
	}
}

/**
*   @brief Loads the program with MIS order specified in @p data 's id_to_pos and pos_to_id. Updates @p data 's mis_code_exec_offs
*   @author Julian Hartmer
*   @param[in] data initialized pointer to struct div_data with order specified in id_to_pos and pos_to_id
*
*   Loads the program from address @p data 's code_load to code_exec with MIS order @p data 's id_to_pos and pos_to_id. Updates @p data 's mis_code_exec_offs. Fixes all branches using the @p data 's branch table bt.
*/
void div_load_user_program(struct div_data *data) {
	uint32_t cur_mis, cur_instr_offs, cur_bt_entry, cur_instr, jump_offset;

	cur_bt_entry = 0;

	update_mis_code_exec_offs(data);

	/* iterate over all MIS: from order in Flash */
	for (cur_mis = 0; cur_mis < MIS_AMOUNT; cur_mis++) {
	    /* cur_instr_offs: iterates over all instructions in MIS */
		for (cur_instr_offs = data->mis_code_load_offs[cur_mis]; cur_instr_offs < data->mis_code_load_offs[cur_mis] + data->mis_code_size[cur_mis]; cur_instr_offs++)
		{
		    /* load instruction from flash */
			cur_instr = data->code_load[cur_instr_offs];
			/* check if instruction has a branch-table entry: update intstruktion accordingly */
			if (cur_bt_entry < BT_SIZE && data->bt[cur_bt_entry].instr_offset == cur_instr_offs) {
				jump_offset = calculate_instr_jump_offset(data, &data->bt[cur_bt_entry], cur_mis);
				cur_instr = (cur_instr & INSTR_JUMP_INSTR_MASK) |
						((cur_instr + jump_offset) & INSTR_BRANCH_OFFS_MASK);
				cur_bt_entry++;
			}
			/* load instruction to RAM */
			data->code_exec[cur_instr_offs - data->mis_code_load_offs[cur_mis]  + data->mis_code_exec_offs[cur_mis]] = cur_instr;
		}
	}
}

/**
*   @brief Calculates the execution-load offset of the jump in bt
*   @author Julian Hartmer
*   @param[in] data pointer to div_data
*   @param[in] bt Branch table entry for current branch
*   @param[in] mis_id current instruction's MIS ID
*   @return execution-load offset
*
*   Loads the program from address @p data 's code_load to code_exec with MIS order id_to_pos and pos_to_id in @p data's members. Updates @p data 's mis_code_exec_offs.
*/
uint32_t calculate_instr_jump_offset(const struct div_data *data, const struct bt_entry *bt, uint32_t mis_id)
{
	int32_t cur_mis_diff, target_mis_diff;

	cur_mis_diff = data->mis_code_exec_offs[mis_id] - data->mis_code_load_offs[mis_id];
	target_mis_diff = data->mis_code_exec_offs[bt->jump_dst_mis] - data->mis_code_load_offs[bt->jump_dst_mis];

	return target_mis_diff - cur_mis_diff;
}

/**
*   @brief Updates the code execution offsets in @p data
*   @author Julian Hartmer
*   @param[in] data pointer to div_data
*   @return execution-load-offset
*
*   Updates the code execution offsets in @p data
*/
void update_mis_code_exec_offs(struct div_data *data) {
	uint32_t i, cur_offs;

	cur_offs = 0;
	for (i = 0; i < MIS_AMOUNT; i++) {
		data->mis_code_exec_offs[data->pos_to_id[i]] = cur_offs;
		cur_offs += data->mis_code_size[data->pos_to_id[i]];
	}
}

/**
*   @brief Verifies the loaded program
*   @author Julian Hartmer
*   @param[in] data pointer to div_data
*   @return -1 on success or offset of the function which caused verfication error
*
*   Verifies each line loaded to @p data ->code_exec by comparing the destination MIS and offset inside MIS with the original MIS and offset.
*   Should only be used for debug purposes as it is optimized poorly.
*/
int div_verify_exec_code(const struct div_data *data) {
	uint32_t mis_pos, instr_offs, next_mis_offset, i;
	uint32_t code_size = 0;
	for (i = 0; i < MIS_AMOUNT; i++)
		code_size += data->mis_code_size[i];

	mis_pos = 0;
	next_mis_offset = data->mis_code_exec_offs[data->pos_to_id[mis_pos+1]];
	for (instr_offs = 0; instr_offs < code_size; instr_offs++) {

		/* check if next mis reached */
		if (mis_pos != MIS_AMOUNT-1 && instr_offs >= next_mis_offset) {
			mis_pos++;
			if (mis_pos != MIS_AMOUNT-1)
				next_mis_offset = data->mis_code_exec_offs[data->pos_to_id[mis_pos+1]];
		}
		 if (!verify_instruction(data, instr_offs, data->pos_to_id[mis_pos])) {
			 return instr_offs;
		 }
	}
	return -1;
}

/**
*   @brief Verifies instruction @p instr_exec_offs
*   @author Julian Hartmer
*   @param[in] data pointer to div_data
*   @param[in] instr_exec_offs offset of the instruction which we verify
*   @param[in] cur_mis_id MIS id of @p cur_instr_exec_offs
*   @return 0 on error, -1 on success
*
*   Verifies the instruction at exec offset @p instr_exec_offs
*/
int verify_instruction(const struct div_data *data, uint32_t instr_exec_offs, uint32_t cur_mis_id) {
	uint32_t bt_offs, instr_load_offs;
	int is_jump;
	is_jump = 0;
	instr_load_offs = instr_exec_offs + data->mis_code_load_offs[cur_mis_id] -
			data->mis_code_exec_offs[cur_mis_id];

	/* search branch table: is instruction a jump? */
	for (bt_offs = 0; bt_offs < BT_SIZE; bt_offs++) {
		if (data->bt[bt_offs].instr_offset == instr_load_offs) {
			is_jump = 1;
			break;
		}
	}

	if (is_jump) {
		/* check if upper 2 bytes stayed the same */
		if ( (data->code_exec[instr_exec_offs] & INSTR_JUMP_INSTR_MASK) !=
				(data->code_load[instr_load_offs] & INSTR_JUMP_INSTR_MASK)) {

			return 0;
		} else if(!verify_jump(data, instr_exec_offs, instr_load_offs, cur_mis_id)) {

			return 0;
		}

	} else {
		if (data->code_load[instr_load_offs] != data->code_exec[instr_exec_offs])
		{
			return 0;
		}
	}
	return 1;
}

/**
*   @brief Verifies a branch instruction
*   @author Julian Hartmer
*   @param[in] data pointer to div_data
*   @param[in] jmp_instr_exec_offs position of branch instruction in exec which is verified
*   @param[in] jmp_instr_load_offs position of branch instruction in load which is verified
*   @param[in] cur_mis_id the instruction's MID id in exec
*   @return -1 on success or offset of the function which caused verfication error
*
*   Verifies the branch instruction at @p jmp_instr_exec_offs by comparing the desination MIS and offset of the desination instruction to the correspongin load instruction.
*/
int verify_jump(const struct div_data *data, uint32_t jmp_instr_exec_offs,
		uint32_t jmp_instr_load_offs, uint32_t cur_mis_id) {
	uint32_t mis_load, mis_exec, offs_mis_instr_load, offs_mis_instr_exec,
			instr_exec_offs, instr_load_offs;
	int32_t code_exec_jmp_width, code_load_jmp_width;

    code_exec_jmp_width = ((int32_t)data->code_exec[jmp_instr_exec_offs] & INSTR_BRANCH_OFFS_MASK);

    code_load_jmp_width = ((int32_t)data->code_load[jmp_instr_load_offs] & INSTR_BRANCH_OFFS_MASK);

    /* sign extend if negative */
    if (code_exec_jmp_width & (1u << (INSTR_JUMP_OFFS_MASK_BITS_AMOUNT-1))) {
        code_exec_jmp_width |= INSTR_JUMP_INSTR_MASK;
    }

    if (code_load_jmp_width & (1u << (INSTR_JUMP_OFFS_MASK_BITS_AMOUNT-1))) {
        code_load_jmp_width |= INSTR_JUMP_INSTR_MASK;
    }

    /* add 2, because pc is already 2 instructions ahead of branch */
    code_exec_jmp_width += 2;
    code_load_jmp_width += 2;

	instr_exec_offs = (int32_t)jmp_instr_exec_offs + code_exec_jmp_width;
	instr_load_offs = (int32_t)jmp_instr_load_offs + code_load_jmp_width;

	mis_exec = code_get_mis_id(instr_exec_offs, &data->mis_code_exec_offs[0], &data->mis_code_size[0]);
	mis_load = code_get_mis_id(instr_load_offs, &data->mis_code_load_offs[0], &data->mis_code_size[0]);

	if (MIS_AMOUNT == mis_exec || MIS_AMOUNT == mis_load) {
		return 0;
	}
	offs_mis_instr_load = instr_load_offs - data->mis_code_load_offs[mis_load];

	offs_mis_instr_exec = instr_exec_offs - data->mis_code_exec_offs[mis_exec];

	if ((mis_load == mis_exec) && (offs_mis_instr_load == offs_mis_instr_exec))
	{
		return 1;
	} else {
		return 0;
	}
}

/**
*   @brief Calculates and return the MIS of the instruction.
*   @author Julian Hartmer
*   @param[in] instr_offs offset of the instruction
*   @param[in] mis_code_offs pointer to array of MIS offset. Either data->mis_code_load_offs if the instruction is in load or data->mis_code_exec_offs if the instruction is in exec
*   @param[in] mis_code_size Array storing the size of each MIS. Should be data->mis_code_size
*   @return Instruction's MIS or MIS_AMOUNT on error
*
*   Calculates and return the instructions MIS at @p offset instr_offs. Can be done for exec or load by setting @p mis_code_offs to data->mis_code_exec_offs or data->mis_code_load_offs accordingly.
*/
uint32_t code_get_mis_id(uint32_t instr_offs, const uint32_t *mis_code_offs, const uint32_t *mis_code_size)
{
	/* iterate through all MIS. Check, if instruction at offset instr_offs
	   is in current MIS. Return the MIS or MIS_AMOUNT when MIS not found. */
	uint32_t mis = 0;
	while (! (mis_code_offs[mis] <= instr_offs && instr_offs < (mis_code_offs[mis] + mis_code_size[mis]) ))
	{
		mis++;
		if (MIS_AMOUNT == mis) break;
	}
	return mis;
}

/**
 * @brief sets all members of @p data to zero.
 * @param[in] data pointer to struct div_data
 *
 * Sets all members of @p data to zero
 */
void div_data_set_zeros(struct div_data * data) {
    memset_custom(data, 0, sizeof (struct div_data));
}
