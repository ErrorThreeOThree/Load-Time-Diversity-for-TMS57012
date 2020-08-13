/** @file pinmux.h 
*   @brief PINMUX Driver Inmplmentation File
*   @date 15.Mar.2012
*   @version 03.01.00
*
*/

/* (c) Texas Instruments 2009-2011, All rights reserved. */

#include "sys_common.h"

#ifndef __PINMUX_H__
#define __PINMUX_H__

#define PINMUX_PIN_1_SHIFT	8
#define PINMUX_PIN_2_SHIFT	0
#define PINMUX_PIN_5_SHIFT	8
#define PINMUX_PIN_8_SHIFT	16
#define PINMUX_PIN_9_SHIFT	24
#define PINMUX_PIN_10_SHIFT	0
#define PINMUX_PIN_12_SHIFT	8
#define PINMUX_PIN_18_SHIFT	16
#define PINMUX_PIN_27_SHIFT	0
#define PINMUX_PIN_36_SHIFT	16
#define PINMUX_PIN_37_SHIFT	24
#define PINMUX_PIN_38_SHIFT	0
#define PINMUX_PIN_39_SHIFT	8
#define PINMUX_PIN_58_SHIFT	16
#define PINMUX_PIN_68_SHIFT	8
#define PINMUX_PIN_93_SHIFT	8

#define PINMUX_PIN_1_MASK		(~(0xFF << PINMUX_PIN_1_SHIFT)
#define PINMUX_PIN_2_MASK		(~(0xFF << PINMUX_PIN_2_SHIFT)
#define PINMUX_PIN_5_MASK		(~(0xFF << PINMUX_PIN_5_SHIFT)
#define PINMUX_PIN_8_MASK		(~(0xFF << PINMUX_PIN_8_SHIFT)
#define PINMUX_PIN_9_MASK		(~(0xFF << PINMUX_PIN_9_SHIFT)
#define PINMUX_PIN_10_MASK		(~(0xFF << PINMUX_PIN_10_SHIFT)
#define PINMUX_PIN_12_MASK		(~(0xFF << PINMUX_PIN_12_SHIFT)
#define PINMUX_PIN_18_MASK		(~(0xFF << PINMUX_PIN_18_SHIFT)
#define PINMUX_PIN_27_MASK		(~(0xFF << PINMUX_PIN_27_SHIFT)
#define PINMUX_PIN_36_MASK		(~(0xFF << PINMUX_PIN_36_SHIFT)
#define PINMUX_PIN_37_MASK		(~(0xFF << PINMUX_PIN_37_SHIFT)
#define PINMUX_PIN_38_MASK		(~(0xFF << PINMUX_PIN_38_SHIFT)
#define PINMUX_PIN_39_MASK		(~(0xFF << PINMUX_PIN_39_SHIFT)
#define PINMUX_PIN_58_MASK		(~(0xFF << PINMUX_PIN_58_SHIFT)
#define PINMUX_PIN_68_MASK		(~(0xFF << PINMUX_PIN_68_SHIFT)
#define PINMUX_PIN_93_MASK		(~(0xFF << PINMUX_PIN_93_SHIFT)



#define PINMUX_PIN_1_GIOA_0		(0x1 <<  PINMUX_PIN_1_SHIFT)
#define PINMUX_PIN_1_SPI3nCS_3		(0x2 <<  PINMUX_PIN_1_SHIFT)

#define PINMUX_PIN_2_GIOA_1		(0x1 <<  PINMUX_PIN_2_SHIFT)
#define PINMUX_PIN_2_SPI3nCS_2		(0x2 <<  PINMUX_PIN_2_SHIFT)

#define PINMUX_PIN_5_GIOA_2		(0x1 <<  PINMUX_PIN_5_SHIFT)
#define PINMUX_PIN_5_SPI3nCS_1		(0x2 <<  PINMUX_PIN_5_SHIFT)

#define PINMUX_PIN_8_GIOA_3		(0x1 <<  PINMUX_PIN_8_SHIFT)
#define PINMUX_PIN_8_SPI2nCS_3		(0x2 <<  PINMUX_PIN_8_SHIFT)

#define PINMUX_PIN_9_GIOA_4		(0x1 <<  PINMUX_PIN_9_SHIFT)
#define PINMUX_PIN_9_SPI2nCS_2		(0x2 <<  PINMUX_PIN_9_SHIFT)

#define PINMUX_PIN_10_GIOA_5		(0x1 <<  PINMUX_PIN_10_SHIFT)
#define PINMUX_PIN_10_EXTCLKIN		(0x2 <<  PINMUX_PIN_10_SHIFT)

#define PINMUX_PIN_12_GIOA_6		(0x1 <<  PINMUX_PIN_12_SHIFT)
#define PINMUX_PIN_12_SPI2nCS_1		(0x2 <<  PINMUX_PIN_12_SHIFT)
#define PINMUX_PIN_12_HET_31		(0x4 <<  PINMUX_PIN_12_SHIFT)

#define PINMUX_PIN_18_GIOA_7		(0x1 <<  PINMUX_PIN_18_SHIFT)
#define PINMUX_PIN_18_HET_29		(0x2 <<  PINMUX_PIN_18_SHIFT)

#define PINMUX_PIN_27_MIBSPI1nCS_2	(0x1 <<  PINMUX_PIN_27_SHIFT)
#define PINMUX_PIN_27_HET_20		(0x2 <<  PINMUX_PIN_27_SHIFT)
#define PINMUX_PIN_27_HET_19		(0x4 <<  PINMUX_PIN_27_SHIFT)

#define PINMUX_PIN_36_SPI3CLK		(0x1 <<  PINMUX_PIN_36_SHIFT)
#define PINMUX_PIN_36_EQEPA		(0x2 <<  PINMUX_PIN_36_SHIFT)

#define PINMUX_PIN_37_SPI3nENA		(0x1 <<  PINMUX_PIN_37_SHIFT)
#define PINMUX_PIN_37_EQEPB		(0x2 <<  PINMUX_PIN_37_SHIFT)

#define PINMUX_PIN_38_SPI3nCS_0		(0x1 <<  PINMUX_PIN_38_SHIFT)
#define PINMUX_PIN_38_EQEPI		(0x2 <<  PINMUX_PIN_38_SHIFT)

#define PINMUX_PIN_39_MIBSPI1nCS_3	(0x1 <<  PINMUX_PIN_39_SHIFT)
#define PINMUX_PIN_39_HET_26		(0x2 <<  PINMUX_PIN_39_SHIFT)

#define PINMUX_PIN_58_ADEVT		(0x1 <<  PINMUX_PIN_58_SHIFT)
#define PINMUX_PIN_58_HET_28		(0x2 <<  PINMUX_PIN_58_SHIFT)

#define PINMUX_PIN_68_MIBSPI1nENA	(0x1 <<  PINMUX_PIN_68_SHIFT)
#define PINMUX_PIN_68_HET_23		(0x2 <<  PINMUX_PIN_68_SHIFT)
#define PINMUX_PIN_68_HET_30		(0x4 <<  PINMUX_PIN_68_SHIFT)

#define PINMUX_PIN_93_MIBSPI1nCS_1	(0x1 <<  PINMUX_PIN_93_SHIFT)
#define PINMUX_PIN_93_EQEPS		(0x2 <<  PINMUX_PIN_93_SHIFT)
#define PINMUX_PIN_93_HET_17		(0x4 <<  PINMUX_PIN_93_SHIFT)


/** @struct pinMuxKicker
*   @brief Pin Muxing Kicker Register Definition
*
*   This structure is used to access the Pin Muxing Kicker registers.
*/
typedef volatile struct pinMuxKicker
{
    uint32_t KICKER0;       /* kicker 0 register */
    uint32_t KICKER1;       /* kicker 1 register */
} pinMuxKICKER_t;

/** @struct pinMuxBase
*   @brief PINMUX Register Definition
*
*   This structure is used to access the PINMUX module egisters.
*/
/** @typedef pinMuxBASE_t
*   @brief PINMUX Register Frame Type Definition
*
*   This type is used to access the PINMUX Registers.
*/
typedef volatile struct pinMuxBase
{
    uint32_t PINMUX0;		/**< 0xEB10 Pin Mux 0 register*/
    uint32_t PINMUX1;		/**< 0xEB14 Pin Mux 1 register*/
    uint32_t PINMUX2;		/**< 0xEB18 Pin Mux 2 register*/
    uint32_t PINMUX3;		/**< 0xEB1C Pin Mux 3 register*/
    uint32_t PINMUX4;		/**< 0xEB20 Pin Mux 4 register*/
    uint32_t PINMUX5;		/**< 0xEB24 Pin Mux 5 register*/
    uint32_t PINMUX6;		/**< 0xEB28 Pin Mux 6 register*/
    uint32_t PINMUX7;		/**< 0xEB2C Pin Mux 7 register*/
}pinMuxBASE_t;

	
/** @def kickerReg
*	@brief Pin Muxing Kicker Register Frame Pointer
*
*		This pointer is used to enable and disable muxing accross the device.
*/	
#define kickerReg ((pinMuxKICKER_t *) 0xFFFFEA38)

/** @def pinMuxReg
*	@brief Pin Muxing Control Register Frame Pointer
*
*		This pointer is used to set the muxing registers accross the device.
*/	
#define pinMuxReg ((pinMuxBASE_t *) 0xFFFFEB10)

/** @fn void muxInit(void)
*   @brief Initializes the PINMUX Driver
*
*   This function initializes the PINMUX module and configures the selected 
*   pinmux settings as per the user selection in the GUI
*/
void muxInit(void);

#endif
