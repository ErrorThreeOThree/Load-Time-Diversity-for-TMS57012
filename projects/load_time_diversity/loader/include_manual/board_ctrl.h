/** @file
*   @brief Header file for board_ctrl.c with macros for functions parameters
*   @date 19-06-07
*   @version 0.1
*
*   Header file for board_ctrl.c with macros for board_ctrl_switch_execution_mode
*/

#ifndef BOARD_CTRL_H
#define BOARD_CTRL_H

/**
 * mode value to set execution mode to RAM
 */
#define RAM_EXEC_MODE 0x5

/**
 * mode value to set execution mode to FLASH
 */
#define FLASH_EXEC_MODE 0xA

void delay(void);

uint16_t board_ctrl_init_eeprom(void);

void board_ctrl_load_seed_from_eeprom(void);

void board_ctrl_save_seed_to_eeprom(void);

void board_ctrl_switch_execution_mode(int mode);

void board_clear_seed();

#endif
