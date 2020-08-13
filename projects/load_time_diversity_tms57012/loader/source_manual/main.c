#include "ti_fee.h"
#include "rand.h"
#include "sys_common.h"

#include "board_ctrl.h"
#include "diversity.h"
#include "rand.h"
#include "section_info.h"
#include "string_custom.h"
#include "loader_flags.h"

#define RAM_OFFSET 0x08000000
void load_all_static_sections(struct div_data *data);

void load_static_section();
void set_mis_offset(struct div_data *data);

int main(void)
{
    uint32_t *exec_addr = (uint32_t *) (sections_shuffle_ram_addr_g + RAM_OFFSET);
    uint32_t instr_exec_erro, instr_load_err;
    struct div_data data;
    int status;

    div_load_data(&data, &_text_begin, exec_addr, &_div_data_begin);

#ifdef NO_SHUFFLE

    //div_generate_MIS_order(&data);

    uint32_t code_size;
    int offs = 0;
    int instr;
    int i;
    uint32_t *code_load = data.code_load;
    uint32_t mis_offs;
    for (i = 0; i < MIS_AMOUNT; i++) {
        mis_offs = data.mis_code_load_offs[i];
        for (instr = 0; instr < data.mis_code_size[i]; instr++) {
            data.code_exec[offs+instr] = code_load[mis_offs + instr];
        }
        offs += instr;
    }
    load_all_static_sections(&data);
#else // NO_SHUFFLE

	if (IDLE != board_ctrl_init_eeprom()) {
		// ERROR init EEPROM
		while (1);
	}
	// load seed from eeprom
	board_ctrl_load_seed_from_eeprom();

	div_generate_MIS_order(&data);

    board_ctrl_save_seed_to_eeprom();

    /* cleaning up */
    board_clear_seed();

	div_load_user_program(&data);

    load_all_static_sections(&data);
    set_mis_offset(&data);

    #ifdef VERIFY
        status = div_verify_exec_code(&data);

        if (-1 != status) {
            while(1);
        }
    #endif // VERIFY

#endif // NO_SHUFFLE
    div_data_set_zeros(&data);

	board_ctrl_switch_execution_mode(RAM_EXEC_MODE);


    while(1);
}

void load_all_static_sections(struct div_data *data) {
	int i;
	for (i = 0; i < NUM_STATIC_SECTIONS; ++i) {
		load_static_section(data, sections_static_start_addr_g[i], sections_static_end_addr_g[i], sections_static_ram_addr_g[i] + RAM_OFFSET);
	}
}

void load_static_section(struct div_data *data, uint32_t flash_start_addr, uint32_t flash_end_addr, uint32_t addr_ram) {
    uint32_t * add_instr;
    uint32_t value_old, offset;
	memcpy_custom((void *) addr_ram, (void *) flash_start_addr, flash_end_addr - flash_start_addr);
}

void set_mis_offset(struct div_data *data) {
    uint32_t *start_mis_offs = PROG_LABEL_MAIN_OFFS + RAM_OFFSET;
    // write main offset
    *start_mis_offs = (data->mis_code_exec_offs[START_LABEL_MIS_ID] - data->mis_code_load_offs[START_LABEL_MIS_ID])<< 2;
}
