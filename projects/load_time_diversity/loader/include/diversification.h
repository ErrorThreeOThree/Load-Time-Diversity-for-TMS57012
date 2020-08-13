#ifndef DIVERSIFICATION_H
#define DIVERSIFICATION_H

#include <stdint.h>
#include "rand.h"

#define DEBUG 0
#define debug_print(...) \
	do { if (DEBUG) printf(__VA_ARGS__); } while (0)

#define RAND_FUNC (rand_custom)
#define MIS_AMOUNT 100

#define BT_SIZE (MIS_AMOUNT * (MIS_AMOUNT - 1))
//#define BT_SIZE (MIS_AMOUNT * (MIS_AMOUNT))

#define CODE_SIZE (MIS_AMOUNT * MIS_AMOUNT)

// Struct declarations
struct div_data;
struct instruction;
struct bt_entry;

// Global Variables
extern uint32_t code_load_g[CODE_SIZE];
extern uint32_t code_exec_g[CODE_SIZE];

// Struct definitions
struct bt_entry {
	uint32_t instr_offset;         // address of the jump instruction
	uint32_t jump_dst_mis;          // id of jump target's MIS
};

struct div_data {
	uint32_t *code_load_addr;           // address of original code
	uint32_t *code_exec_addr;           // code execution address

	uint32_t mis_code_load_offs[MIS_AMOUNT]; // array of code array offsets for each MIS
	struct bt_entry bt[BT_SIZE];        // branch table, array size mis_num
	uint32_t mis_code_exec_offs[MIS_AMOUNT]; // array of code array offsets for each MIS
	uint32_t mis_code_size[MIS_AMOUNT]; // array of MIS's code sizes

	uint32_t id_to_pos[MIS_AMOUNT];     //
	uint32_t pos_to_id[MIS_AMOUNT];
};

// Function declarations

void init_div_data(struct div_data *data);
// Generates a new mis order. Stores it in id_to_position and position_to_id

// Sets a new sequence for generation
void div_shffl_order(struct div_data *data);

// Updates the start addresses of each block given by order id_to_position.
// Stores the start addresses in mis_shffl_order;
void div_load_exec_code(struct div_data *data);

// Prints the load instr to stdout
void print_load_code(const struct div_data *data);

// Prints exec instr to stdout
void print_exec_code(const struct div_data *data);

// Prints div_data to stdout
void print_div_data(const struct div_data *data);

// Initialize simulation: data, load code and exec code
void simulation_init(struct div_data *data, uint64_t seed);

// Returns -1 if verification is successfull or the instruction offset in exec,
// in which verification failed
int div_verify_exec_code(struct div_data *data);

uint64_t div_get_seed();
#endif
