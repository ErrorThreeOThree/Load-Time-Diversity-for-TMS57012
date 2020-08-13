/** @file pinmux.c 
*   @brief PINMUX Driver Implementation File
*   @date 15.Mar.2012
*   @version 03.01.00
*
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

/* Include Files */

#include "pinmux.h"

#define PINMUX_SET(REG, BALLID, MUX)								\
				pinMuxReg->PINMUX##REG## = (pinMuxReg->PINMUX##REG## & PINMUX_BALL_##BALLID##_MASK) | (PINMUX_BALL_##BALLID##_##MUX##)


#define PINMUX_GIOB_DISABLE_HET2_ENABLE	\
			pinMuxReg->PINMUX29 = (pinMuxReg->PINMUX29 & PINMUX_GIOB_DISABLE_HET2_MASK) | PINMUX_GIOB_DISABLE_HET2
			
#define PINMUX_ALT_ADC_TRIGGER_SELECT(num)	\
			pinMuxReg->PINMUX30 = (pinMuxReg->PINMUX30 & PINMUX_ALT_ADC_TRIGGER_MASK) | (PINMUX_ALT_ADC_TRIGGER_##num##)
			

/* USER CODE BEGIN (0) */
/* USER CODE END */

void muxInit(void){

/* USER CODE BEGIN (1) */
/* USER CODE END */

	/* Enable Pin Muxing */
	kickerReg->KICKER0 = 0x83E70B13;
	kickerReg->KICKER1 = 0x95A4F1E0;
	
/* USER CODE BEGIN (2) */
/* USER CODE END */

        pinMuxReg->PINMUX0 = PINMUX_PIN_1_GIOA_0;
	
	pinMuxReg->PINMUX1 = PINMUX_PIN_2_GIOA_1 | PINMUX_PIN_5_GIOA_2 | PINMUX_PIN_8_GIOA_3 | PINMUX_PIN_9_GIOA_4;
	
	pinMuxReg->PINMUX2 = PINMUX_PIN_10_GIOA_5 | PINMUX_PIN_12_GIOA_6 | PINMUX_PIN_18_GIOA_7;
	
	pinMuxReg->PINMUX3 = PINMUX_PIN_27_MIBSPI1nCS_2 | PINMUX_PIN_36_SPI3CLK | PINMUX_PIN_37_SPI3nENA;
	
	pinMuxReg->PINMUX4 = PINMUX_PIN_38_SPI3nCS_0 | PINMUX_PIN_39_MIBSPI1nCS_3 | PINMUX_PIN_58_ADEVT;
	
	pinMuxReg->PINMUX5 = PINMUX_PIN_68_MIBSPI1nENA;
	
	pinMuxReg->PINMUX6 = PINMUX_PIN_93_MIBSPI1nCS_1;
	
	
/* USER CODE BEGIN (3) */
/* USER CODE END */
	
	/* Disable Pin Muxing */
	kickerReg->KICKER0 = 0x00000000;
	kickerReg->KICKER1 = 0x00000000;
	
/* USER CODE BEGIN (4) */
/* USER CODE END */
}

/* USER CODE BEGIN (5) */
/* USER CODE END */
