#include "diversification.h"
#include "stdio.h"

#define INSTR_JUMP_OFFS_MASK 0xFFFF
#define INSTR_JUMP_INSTR_MASK (~INSTR_JUMP_OFFS_MASK)

// Global Variables
uint32_t code_load_g[CODE_SIZE] = {0};
uint32_t code_exec_g[CODE_SIZE] = {0};

uint64_t seed_g;

// local function declarations

// calculate the jump offset, which is added to the jump
uint32_t calculate_instr_jump_offset(struct div_data *data, struct bt_entry *bt, uint32_t mis_id);

// updates mis_code_exec_offs
void update_mis_code_exec_offs(struct div_data *data);

// Verifies the instruction at instr_offs. Returns 1 on success.
int verify_instruction(struct div_data *data, uint32_t instr_exec_offs, uint32_t cur_mis_id);

// Verifies the jump at instr_exec_offs. Returns 1 on success.
int verify_jump(struct div_data *data, uint32_t jmp_instr_exec_offs,
		uint32_t jmp_instr_load_offset, uint32_t cur_mis_id);

uint32_t code_get_mis_id(uint32_t instr_offs, uint32_t *mis_code_offs, uint32_t *mis_code_size);
//////////////////////////
// USER FUNCTIONS BEGIN //
//////////////////////////


// Change these functions for new simulation cases
void init_code(uint32_t *code) {
	uint32_t i, j, pos;
	// for jumps: first 2 bytes are jump instr, last 2 are destination
	uint16_t *code_split = (uint16_t *) code;

	for (i = 0; i < MIS_AMOUNT; i++) {
		for (j = 0; j < MIS_AMOUNT; j++) {
			pos = i * MIS_AMOUNT + j;
			// set first 2 bytes to the instruction's address
			code_split[2*pos+1] = pos;

			// jump offset
			code_split[2*pos] = (j*MIS_AMOUNT) - pos + (RAND_FUNC () % MIS_AMOUNT);
		}
	}
}

void init_mis_code_load_offs(uint32_t *offs) {
	uint32_t i;

	for (i = 0; i < MIS_AMOUNT; i++) {
		offs[i] = i * MIS_AMOUNT;
	}
}

void init_mis_code_size(uint32_t *code_size) {
	uint32_t i;

	for (i = 0; i < MIS_AMOUNT; i++) {
		code_size[i] = MIS_AMOUNT;
	}
}

void init_bt(struct bt_entry *bt) {
	uint32_t i, j, pos;
	pos = 0;
	for (i = 0; i < MIS_AMOUNT; i++) {
		for (j = 0; j < MIS_AMOUNT; j++) {
			if (i != j) {
				bt[pos].instr_offset = i*MIS_AMOUNT + j;
				bt[pos].jump_dst_mis = j;
				pos++;
			}
		}
	}
}

void init_id_to_pos(uint32_t *id_to_pos) {
	uint32_t i;

	for (i = 0; i < MIS_AMOUNT; i++) {
		id_to_pos[i] = i;
	}
}

////////////////////////
// USER FUNCTIONS END //
////////////////////////

void simulation_init(struct div_data *data, uint64_t seed) {
	seed_g = seed;
	rand_set_seed(seed);
	init_div_data(data);
	init_code(data->code_load_addr);
}

void init_div_data(struct div_data *data) {
	int i;

	data->code_load_addr = code_load_g;
	data->code_exec_addr = code_exec_g;

	init_mis_code_load_offs(&data->mis_code_load_offs[0]);
	init_mis_code_size(&data->mis_code_size[0]);

	init_id_to_pos(&data->id_to_pos[0]);

	init_bt(&data->bt[0]);

	for (i = 0; i < MIS_AMOUNT; i++) {
		data->pos_to_id[i] = data->id_to_pos[i];
		data->mis_code_exec_offs[i] = 0;
	}
}

void div_shffl_order(struct div_data *data) {
	uint32_t i, j, tmp;
	// generate random sequence from id_to_position
	// Fisher-Yate shuffle
	for (i = MIS_AMOUNT-1; i > 0; i--) {
		j = RAND_FUNC ()%(i+1);
		//swap id_to_position[i] and id_to_position[j]
		tmp = data->id_to_pos[i];
		data->id_to_pos[i] = data->id_to_pos[j];
		data->id_to_pos[j] = tmp;

		// swap position_to_id's entries with the swapped values
		// from id_to_position
		tmp = data->pos_to_id[data->id_to_pos[i]];
		data->pos_to_id[data->id_to_pos[i]] =
			data->pos_to_id[data->id_to_pos[j]];
		data->pos_to_id[data->id_to_pos[j]] = tmp;
	}
}

void print_load_code(const struct div_data *data) {
	if (!DEBUG) return;
	uint32_t i,j;
	i = 0;

	debug_print("================== load_code =================\n");
	while (i < CODE_SIZE) {
		debug_print("%05d: ", i);
		for (j = i+5; i < j && i < CODE_SIZE; i++) {
			debug_print("0x%08X ", data->code_load_addr[i]);
		}
		debug_print("\n");
	}
	debug_print("==============================================\n");
}

void print_exec_code(const struct div_data *data) {
	debug_print("================== exec_code =================\n");
	uint32_t i,j;
	i = 0;

	while (i < CODE_SIZE) {
		debug_print("%05d: ", i);
		for (j = i+5; i < j && i < CODE_SIZE; i++) {
			debug_print("0x%08X ", data->code_exec_addr[i]);
		}
		debug_print("\n");
	}
	debug_print("==============================================\n");
}

void div_load_exec_code(struct div_data *data) {
	uint32_t cur_mis, cur_instr_offs, cur_bt_entry, cur_instr, jump_offset;

	cur_bt_entry = 0;

	update_mis_code_exec_offs(data);

	for (cur_mis = 0; cur_mis < MIS_AMOUNT; cur_mis++) {
		for (cur_instr_offs = data->mis_code_load_offs[cur_mis]; cur_instr_offs < data->mis_code_load_offs[cur_mis] + data->mis_code_size[cur_mis]; cur_instr_offs++)
		{
			cur_instr = data->code_load_addr[cur_instr_offs];
			if (cur_bt_entry < BT_SIZE && data->bt[cur_bt_entry].instr_offset == cur_instr_offs) {
				jump_offset = calculate_instr_jump_offset(data, &data->bt[cur_bt_entry], cur_mis);
				cur_instr = (cur_instr & INSTR_JUMP_INSTR_MASK) |
						((cur_instr + jump_offset) & INSTR_JUMP_OFFS_MASK);
				cur_bt_entry++;
			}
			data->code_exec_addr[cur_instr_offs - data->mis_code_load_offs[cur_mis]  + data->mis_code_exec_offs[cur_mis]] = cur_instr;
		}
	}
}

uint32_t calculate_instr_jump_offset(struct div_data *data, struct bt_entry *bt, uint32_t mis_id)
{
	int16_t cur_mis_diff, target_mis_diff;

	cur_mis_diff = data->mis_code_exec_offs[mis_id] - data->mis_code_load_offs[mis_id];
	target_mis_diff = data->mis_code_exec_offs[bt->jump_dst_mis] - data->mis_code_load_offs[bt->jump_dst_mis];

	return target_mis_diff - cur_mis_diff;
}

void update_mis_code_exec_offs(struct div_data *data) {
	uint32_t i, cur_offs;

	cur_offs = 0;
	for (i = 0; i < MIS_AMOUNT; i++) {
		data->mis_code_exec_offs[data->pos_to_id[i]] = cur_offs;
		cur_offs += data->mis_code_size[data->pos_to_id[i]];
	}
}

void print_div_data(const struct div_data *data) {
	if (!DEBUG) return;
	uint32_t i, j;
	debug_print("================== div_data ==================\n");
	debug_print("code_load_addr: 0x%016lX\n", (uint64_t) data->code_load_addr);
	debug_print("code_exec_addr: 0x%016lX\n", (uint64_t) data->code_exec_addr);
	debug_print("                   ");
	for (i = 0; i < MIS_AMOUNT; i++)
		debug_print(" %3u  ", i);
	debug_print("\nmis_code_load_offs:");
	for (i = 0; i < MIS_AMOUNT; i++)
		debug_print("%05u ", data->mis_code_load_offs[i]);
	debug_print("\nmis_code_exec_offs:");
	for (i = 0; i < MIS_AMOUNT; i++)
		debug_print("%05u ", data->mis_code_exec_offs[i]);
	debug_print("\nmis_code_size:     ");
	for (i = 0; i < MIS_AMOUNT; i++)
		debug_print("%05u ", data->mis_code_size[i]);
	i = 0;
	debug_print("\nid_to_pos:         ");
	for (i = 0; i < MIS_AMOUNT; i++)
		debug_print("%05u ", data->id_to_pos[i]);
	debug_print("\npos_to_id:         ");
	for (i = 0; i < MIS_AMOUNT; i++)
		debug_print("%05u ", data->pos_to_id[i]);
	debug_print("\nbranch_table:");
	i = 0;
	while (i < BT_SIZE) {
		debug_print("\n    ");
		for (j = i + 4; i < j && i < BT_SIZE; i++)
			debug_print(" (%05u %05u)", data->bt[i].instr_offset, data->bt[i].jump_dst_mis);
	}
	debug_print("\n");
	debug_print("=============================================\n");
}

int div_verify_exec_code(struct div_data *data) {
	uint32_t mis_pos, instr_offs, next_mis_offset;

	mis_pos = 0;
	next_mis_offset = data->mis_code_exec_offs[data->pos_to_id[mis_pos+1]];
	for (instr_offs = 0; instr_offs < CODE_SIZE; instr_offs++) {

		// check if next mis reached
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

int verify_instruction(struct div_data *data, uint32_t instr_exec_offs, uint32_t cur_mis_id) {
	//debug_print("instr_exec_offs: %d, cur_mis_id: %d\n", instr_exec_offs, cur_mis_id);
	uint32_t bt_offs, instr_load_offs;
	int is_jump;
	is_jump = 0;
	instr_load_offs = instr_exec_offs + data->mis_code_load_offs[cur_mis_id] -
			data->mis_code_exec_offs[cur_mis_id];

	// search branch table: is instruction a jump?
	for (bt_offs = 0; bt_offs < BT_SIZE; bt_offs++) {
		if (data->bt[bt_offs].instr_offset == instr_load_offs) {
			is_jump = 1;
			break;
		}
	}

	if (is_jump) {
		// check if upper 2 bytes stayed the same
		if ( (data->code_exec_addr[instr_exec_offs] & INSTR_JUMP_INSTR_MASK) !=
				(data->code_load_addr[instr_load_offs] & INSTR_JUMP_INSTR_MASK)) {
			fprintf(stderr, " Error Jump instruction encoding is different: load(%d:%x) != exec(%d:%x) \n",
			 		instr_load_offs, data->code_load_addr[instr_load_offs],
			 		instr_exec_offs, data->code_exec_addr[instr_exec_offs]);

			return 0;
		} else if(!verify_jump(data, instr_exec_offs, instr_load_offs, cur_mis_id)) {
			fprintf(stderr, " Error jump %u: 0x%08X != %u: 0x%08X ",
				instr_exec_offs, data->code_exec_addr[instr_exec_offs],
			 	instr_load_offs, data->code_load_addr[instr_load_offs]);

			return 0;
		}

	} else {
		if (data->code_load_addr[instr_load_offs] != data->code_exec_addr[instr_exec_offs])
		{
			fprintf(stderr, " Error non jump instruction encoding is different: load(%d:%x) != exec(%d:%x)\n", instr_load_offs, data->code_load_addr[instr_load_offs], instr_exec_offs, data->code_exec_addr[instr_exec_offs]);
			return 0;
		}
	}
	return 1;
}

// Verify jump: Check if target in load code and exec both
//     1) land in same MIS
//     2) land on same offset in their MIS
int verify_jump(struct div_data *data, uint32_t jmp_instr_exec_offs,
		uint32_t jmp_instr_load_offs, uint32_t cur_mis_id) {
	uint32_t mis_load, mis_exec, offs_mis_instr_load, offs_mis_instr_exec,
			instr_exec_offs, instr_load_offs;

	instr_exec_offs = ((int32_t)jmp_instr_exec_offs + (int16_t)(data->code_exec_addr[jmp_instr_exec_offs] & INSTR_JUMP_OFFS_MASK));
	instr_load_offs = ((int32_t)jmp_instr_load_offs + (int16_t)(data->code_load_addr[jmp_instr_load_offs] & INSTR_JUMP_OFFS_MASK));

	mis_exec = code_get_mis_id(instr_exec_offs, &data->mis_code_exec_offs[0], &data->mis_code_size[0]);
	mis_load = code_get_mis_id(instr_load_offs, &data->mis_code_load_offs[0], &data->mis_code_size[0]);

	if (MIS_AMOUNT == mis_exec || MIS_AMOUNT == mis_load) {
		fprintf(stderr, "Error: instr at exec offset %d out of MIS bounds!\n", jmp_instr_exec_offs);
		return 0;
	}
	offs_mis_instr_load = instr_load_offs - data->mis_code_load_offs[mis_load];

	offs_mis_instr_exec = instr_exec_offs - data->mis_code_exec_offs[mis_exec];

	if ((mis_load == mis_exec) && (offs_mis_instr_load == offs_mis_instr_exec))
	{
		return 1;
	} else {
		fprintf(stderr, "Jump target's MIS or offset in MIS does not match in exec and load\n");
		fprintf(stderr, "load: Instruction offset: %u, MIS: %u, MIS offset: %u\n", instr_load_offs,
		 		mis_load, offs_mis_instr_load);
		fprintf(stderr, "exec: Instruction offset: %u, MIS: %u, MIS offset: %u\n", instr_exec_offs,
				 mis_exec, offs_mis_instr_exec);
		return 0;
	}
}

uint32_t code_get_mis_id(uint32_t instr_offs, uint32_t *mis_code_offs, uint32_t *mis_code_size)
{
	// iterate through all MIS. Check, if instruction at offset instr_offs
	// is in current MIS. Return the MIS or MIS_AMOUNT when MIS not found.
	uint32_t mis = 0;
	while (! (mis_code_offs[mis] <= instr_offs && instr_offs < (mis_code_offs[mis] + mis_code_size[mis]) ))
	{
		mis++;
		if (MIS_AMOUNT == mis) break;
	}
	return mis;
}

uint64_t div_get_seed() {
	return seed_g;
}
