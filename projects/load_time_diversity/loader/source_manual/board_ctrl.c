/** @file
*   @brief Source file some capsuling functions to control the TMS570 board
*   @date 19-06-07
*   @version 0.1
*
*   Source files to functions to control the TMS570 board.
*   Capsules HalCoGen functions to make them more user-friendly.
*   Functions for:
*   - EEPROM control
*   - CPU control registers
*   - delay function
*/
#include <stdint.h>

#include "board_ctrl.h"
#include "ti_fee.h"
#include "rand.h"

/**
 * EEPROM block number for seed storage
 */
#define SEED_BLOCK_NR 1

/**
 * EEPROM block offset for seed storage
 */
#define SEED_BLOCK_OFFSET 0


/**
 * @brief simple delay function
 * Simple delay function, counts to 0xFFF
 */
void delay(void) {
	volatile uint32_t cnt;
	for (cnt = 0; cnt < 0xFFF; cnt++);
}

/**
 * @brief Initializes EEPROM
 * @return status code TI_FeeModuleStatusType
 */
uint16_t board_ctrl_init_eeprom(void) {
	uint16_t status;

	TI_Fee_Init();

	do
	{
		TI_Fee_MainFunction();
		status = TI_Fee_GetStatus(0);
	} while(IDLE != status);

	return status;
}

/**
 * @brief loads seed from EEPROM
 * Loads seed from EEPROM to seed_g
 */
void board_ctrl_load_seed_from_eeprom(void) {
	uint64_t seed;
	TI_Fee_ReadSync(SEED_BLOCK_NR, SEED_BLOCK_OFFSET, (uint8_t *) &seed, 8);
	seed = 0xeeeeee;
	rand_set_seed(seed);
}

/**
 * @brief saves seed to EEPROM
 * Saves seed_g to EEPROM
 */
void board_ctrl_save_seed_to_eeprom(void) {
	uint64_t seed = rand_get_seed();
	TI_Fee_WriteSync(SEED_BLOCK_NR, (uint8_t *)&seed);
}

/**
 * @brief Switches the execution mode according to argument @p mode
 * @param[in] mode Either RAM_EXEC_MODE or FLASH_EXEC_MODE
 *
 * Switches the execution mode to @p mode and resets the CPU.
 * @p mode:
 * - RAM_EXEC_MODE: execution from RAM with RAM starting at 0x00000000
 * - FLASH_EXEC_MODE: execution from FLASH with FLASH starting at 0x00000000
 */
void board_ctrl_switch_execution_mode(int mode) {
	// registers  from page 128 (BMMCR) and 129 (CPURSTCR)
    volatile uint32_t *BMMCR =  (uint32_t *) 0xFFFFFFC4;
    volatile uint32_t *CPURSTCR =  (uint32_t *) 0xFFFFFFCC;

	if (RAM_EXEC_MODE != mode && FLASH_EXEC_MODE != mode) {
		// mode error
		while (1);
	}
	*BMMCR = mode;

	// CPU reset
	*CPURSTCR ^= 0x1;
}

/**
 * @brief Sets the seed to zero
 *
 * Sets the seed to zero so that attackers cannot read it.
 */
void board_clear_seed() {
    rand_set_seed(0);
}
