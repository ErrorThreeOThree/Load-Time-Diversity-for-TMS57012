/** @file
*   @brief Header file for rand.c
*   @date 19-06-07
*   @version 0.1
*
*   Header file for board_ctrl.c with macros for board_ctrl_switch_execution_mode
*/

#ifndef RAND_H
#define RAND_H

#include <stdint.h>


void rand_set_seed(uint64_t seed);

uint64_t rand_get_seed(void);

uint32_t rand_custom(void);
#endif /* RAND_H */
