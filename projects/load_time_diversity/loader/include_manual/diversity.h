/** @file
*   @brief Header file for diversity.h including structure definitions
*   @date 19-06-07
*   @version 0.1
*
*   Header file for diversity.h including structures struct bt_entry and struct div_data
*/

#ifndef DIVERSITY_H
#define DIVERSITY_H

#include "div_data.h"
#include "stdint.h"

/*** Struct definition ***/

/**
 * @brief branch table entry
 * Stores one branch table entry
 */
struct __attribute__((__packed__)) bt_entry {
	uint32_t instr_offset; /**< load offset of the jump instruction */
	uint32_t jump_dst_mis; /**< jump targets MIS id */
};

/**
 * @brief diversification data struct
 * Stores all the data for program diversification
 */
struct __attribute__((__packed__)) div_data {

	uint32_t mis_code_load_offs[MIS_AMOUNT]; /**< array storing MIS load offset of its first instruction */
	uint32_t mis_code_size[MIS_AMOUNT];      /**< array storing MIS code size in instructions */
	struct bt_entry bt[BT_SIZE];             /**< array storing branch table */

	const uint32_t *code_load;               /**< address where the code is loaded from */
	uint32_t *code_exec;                     /**< address where the shuffled code will be loaded to and executed */

	uint32_t id_to_pos[MIS_AMOUNT];          /**< array mapping the MIS id to its MIS offset when executed */
	uint32_t pos_to_id[MIS_AMOUNT];          /**< array mapping the MIS position when executed to the MIS id */
	uint32_t mis_code_exec_offs[MIS_AMOUNT]; /**< array mapping the MIS id to the offset of its first instruction when executed */
};

void div_load_data(struct div_data *data, const uint32_t *code_load, uint32_t *code_exec, const uint32_t *data_load);

void div_generate_MIS_order(struct div_data *data);

void div_load_user_program(struct div_data *data);

void div_data_set_zeros(struct div_data *data);

int div_verify_exec_code(const struct div_data *data);

#endif
