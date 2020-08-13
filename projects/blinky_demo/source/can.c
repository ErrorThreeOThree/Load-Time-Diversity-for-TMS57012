/** @file can.c 
*   @brief CAN Driver Source File
*   @date 15.Mar.2012
*   @version 03.01.00
*
*   This file contains:
*   - API Functions
*   - Interrupt Handlers
*   .
*   which are relevant for the CAN driver.
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */


/* USER CODE BEGIN (0) */
/* USER CODE END */


/* Include Files */

#include "can.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */


/* Global and Static Variables */

#ifndef __little_endian__
    static const uint32_t s_canByteOrder[] = {3U, 2U, 1U, 0U, 7U, 6U, 5U, 4U};
#endif

/* USER CODE BEGIN (2) */
/* USER CODE END */


/** @fn void canInit(void)
*   @brief Initializes CAN Driver
*
*   This function initializes the CAN driver.
*
*/

/* USER CODE BEGIN (3) */
/* USER CODE END */

void canInit(void)
{
/* USER CODE BEGIN (4) */
/* USER CODE END */
    /** @b Initialize @b CAN1: */

    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Enable/Disable parity or ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrups
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    canREG1->CTL = 0x00000000U 
	             | 0x00000000U 
				 | 0x00000005U 
                 | 0x000200043U;

    /** - Clear all pending error flags and reset current status */
    canREG1->ES = 0x0000031FU;

    /** - Assign interrupt level for messages */
    canREG1->INTMUXx[0U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    canREG1->INTMUXx[1U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    /** - Setup auto bus on timer pewriod */
    canREG1->ABOTR = 0U;

    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x80000000U | 0x40000000U | 0x00000000U | ((1U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 1;

    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((2U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 2;

    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((3U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 3;

    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((4U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 4;

    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((5U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 5;

    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((6U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 6;

    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((7U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 7;

    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((8U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 8;

    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((9U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 9;

    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((10U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 10;

    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((11U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 11;

    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((12U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 12;

    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((13U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 13;

    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((14U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 14;

    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((15U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 15;

    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((16U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 16;

    /** - Initialize message 17 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((17U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 17;

    /** - Initialize message 18 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((18U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 18;

    /** - Initialize message 19 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((19U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 19;

    /** - Initialize message 20 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((20U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 20;

    /** - Initialize message 21 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((21U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 21;

    /** - Initialize message 22 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((22U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 22;

    /** - Initialize message 23 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((23U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 23;

    /** - Initialize message 24 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((24U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 24;

    /** - Initialize message 25 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((25U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 25;

    /** - Initialize message 26 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((26U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 26;

    /** - Initialize message 27 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((27U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 27;

    /** - Initialize message 28 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((28U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 28;

    /** - Initialize message 29 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((29U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 29;

    /** - Initialize message 30 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((30U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 30;

    /** - Initialize message 31 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((31U & 0x1FFFFFFFU) << 0U);
    canREG1->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF1CMD  = 0xF8;
    canREG1->IF1NO   = 31;

    /** - Initialize message 32 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG1->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((32U & 0x1FFFFFFFU) << 0U);
    canREG1->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG1->IF2CMD  = 0xF8;
    canREG1->IF2NO   = 32;


    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while (canREG1->IF1STAT & 0x80);

    canREG1->IF1CMD  = 0x87;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while (canREG1->IF2STAT & 0x80);

    canREG1->IF2CMD = 0x17;
    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    canREG1->BTR = (0U << 16U) |
                   ((2U - 1U) << 12U) |
                   (((3U + 2U) - 1U) << 8U) |
                   ((2U - 1U) << 6U) |
                   19U;

     /** - CAN1 Port output values */
    canREG1->TIOC = (1  << 18 )
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )    
                   | (0 << 1 )  
                   | (0  );     
    canREG1->RIOC = (1  << 18 )    
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )
                   | (0 <<1 )  
                   | (0  );        


    /** - Leave configuration and initialization mode  */
    canREG1->CTL &= ~0x00000041U;


    /** @b Initialize @b CAN2: */

    /** - Setup control register
    *     - Disable automatic wakeup on bus activity
    *     - Local power down mode disabled
    *     - Disable DMA request lines
    *     - Enable global Interrupt Line 0 and 1
    *     - Disable debug mode
    *     - Release from software reset
    *     - Enable/Disable parity or ECC
    *     - Enable/Disable auto bus on timer
    *     - Setup message completion before entering debug state
    *     - Setup normal operation mode
    *     - Request write access to the configuration registers
    *     - Setup automatic retransmission of messages
    *     - Disable error interrups
    *     - Disable status interrupts
    *     - Enter initialization mode
    */
    canREG2->CTL = 0x00000000U 
	             | 0x00000000U 
				 | 0x00000005U 
                 | 0x000200043U;

    /** - Clear all pending error flags and reset current status */
    canREG2->ES = 0x0000031FU;


    /** - Assign interrupt level for messages */
    canREG2->INTMUXx[0U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;

    canREG2->INTMUXx[1U] = 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U
                         | 0x00000000U;


    /** - Setup auto bus on timer pewriod */
    canREG2->ABOTR = 0U;

    /** - Initialize message 1 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((1U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 1;

    /** - Initialize message 2 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((2U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 2;

    /** - Initialize message 3 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((3U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 3;

    /** - Initialize message 4 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((4U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 4;

    /** - Initialize message 5 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((5U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 5;

    /** - Initialize message 6 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((6U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 6;

    /** - Initialize message 7 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((7U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 7;

    /** - Initialize message 8 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((8U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 8;

    /** - Initialize message 9 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((9U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 9;

    /** - Initialize message 10 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((10U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 10;

    /** - Initialize message 11 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((11U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 11;

    /** - Initialize message 12 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((12U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 12;

    /** - Initialize message 13 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((13U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 13;

    /** - Initialize message 14 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((14U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 14;

    /** - Initialize message 15 
    *     - Wait until IF1 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF1 control byte
    *     - Set IF1 message number
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF1ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((15U & 0x1FFFFFFFU) << 0U);
    canREG2->IF1MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF1CMD  = 0xF8;
    canREG2->IF1NO   = 15;

    /** - Initialize message 16 
    *     - Wait until IF2 is ready for use 
    *     - Set message mask
    *     - Set message control word
    *     - Set message arbitration
    *     - Set IF2 control byte
    *     - Set IF2 message number
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2MSK  = 0xC0000000U | ((0x000007FFU & 0x1FFFFFFFU) << 0U);
    canREG2->IF2ARB  = 0x00000000U | 0x40000000U | 0x20000000U | ((16U & 0x1FFFFFFFU) << 0U);
    canREG2->IF2MCTL = 0x00001080U | 0x00000000U | 8U;
    canREG2->IF2CMD  = 0xF8;
    canREG2->IF2NO   = 16;

    /** - Setup IF1 for data transmission 
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while (canREG2->IF1STAT & 0x80);

    canREG2->IF1CMD  = 0x87;

    /** - Setup IF2 for reading data
    *     - Wait until IF1 is ready for use 
    *     - Set IF1 control byte
    */
    while (canREG2->IF2STAT & 0x80);

    canREG2->IF2CMD = 0x17;
    /** - Setup bit timing 
    *     - Setup baud rate prescaler extension
    *     - Setup TSeg2
    *     - Setup TSeg1
    *     - Setup sample jump width
    *     - Setup baud rate prescaler
    */
    canREG2->BTR = (0U << 16U) |
                   ((2U - 1U) << 12U) |
                   (((3U + 2U) - 1U) << 8U) |
                   ((2U - 1U) << 6U) |
                   19U;

   /** - CAN2 Port output values */
    canREG2->TIOC = (1  << 18 )
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )    
                   | (0 << 1 )  
                   | (0  );     
    canREG2->RIOC = (1  << 18 )    
                   | (0  << 17 )   
                   | (1  << 3 )  
                   | (0  << 2 )
                   | (0 <<1 )  
                   | (0  );       

    /** - Leave configuration and initialization mode  */
    canREG2->CTL &= ~0x00000041U;


    /**   @note This function has to be called before the driver can be used.\n
    *           This function has to be executed in priviledged mode.\n
    */

/* USER CODE BEGIN (5) */
/* USER CODE END */
}


/** @fn uint32_t canTransmit(canBASE_t *node, uint32_t messageBox, const uint8_t *data)
*   @brief Transmits a CAN message
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @param[in] data Pointer to CAN TX data
*   @return The function will return:
*           - 0: When the setup of the TX message box wasn't successful   
*           - 1: When the setup of the TX message box was successful   
*
*   This function writes a CAN message into a CAN message box.
*
*/

/* USER CODE BEGIN (6) */
/* USER CODE END */

uint32_t canTransmit(canBASE_t *node, uint32_t messageBox, const uint8_t *data)
{
    uint32_t i;
    uint32_t success  = 0U;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (7) */
/* USER CODE END */

    /** - Check for pending message:
    *     - pending message, return 0
    *     - no pending message, start new transmission 
    */
    if (node->TXRQx[regIndex] & bitIndex)
    {
        return success;
    }

    /** - Wait until IF1 is ready for use */
    while (node->IF1STAT & 0x80);

    /** - Copy TX data into IF1 */
    for (i = 0U; i < 8U; i++)
    {
#ifdef __little_endian__
        node->IF1DATx[i] = *data++;
#else
        node->IF1DATx[s_canByteOrder[i]] = *data++;
#endif
    }

    /** - Copy TX data into mesasge box */
    node->IF1NO = messageBox;

    success = 1U; 

    /**   @note The function canInit has to be called before this function can be used.\n
    *           The user is responsible to initialize the message box.
    */

/* USER CODE BEGIN (8) */
/* USER CODE END */

    return success;
}


/** @fn uint32_t canGetData(canBASE_t *node, uint32_t messageBox, uint8_t * const data)
*   @brief Gets received a CAN message
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @param[out] data Pointer to store CAN RX data
*   @return The function will return:
*           - 0: When RX message box hasn't received new data   
*           - 1: When RX data are stored in the data buffer   
*           - 3: When RX data are stored in the data buffer and a message was lost   
*
*   This function writes a CAN message into a CAN message box.
*
*/


/* USER CODE BEGIN (9) */
/* USER CODE END */

uint32_t canGetData(canBASE_t *node, uint32_t messageBox, uint8_t * const data)
{
    uint32_t       i;
    uint32_t       size;
    uint8_t *pData    = (uint8_t *)data;
    uint32_t       success  = 0U;
    uint32_t       regIndex = (messageBox - 1U) >> 5U;
    uint32_t       bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (10) */
/* USER CODE END */

    /** - Check if new data have been arrived:
    *     - no new data, return 0
    *     - new data, get received message 
    */
    if (!(node->NWDATx[regIndex] & bitIndex))
    {
        return success;
    }

    /** - Wait until IF2 is ready for use */
    while (node->IF2STAT & 0x80);

    /** - Copy data into IF2 */
    node->IF2NO = messageBox;

    /** - Wait until data are copied into IF2 */
    while (node->IF2STAT & 0x80);

    /** - Get number of received bytes */
    size = node->IF2MCTL & 0xFU;

    /** - Copy RX data into destination buffer */
    for (i = 0U; i < size; i++)
    {
#ifdef __little_endian__
        *pData++ = node->IF2DATx[i];
#else
        *pData++ = node->IF2DATx[s_canByteOrder[i]];
#endif
    }

    success = 1U;

    /** - Check if data have been lost:
    *     - no data lost, return 1
    *     - data lost, return 3 
    */
    if (node->IF2MCTL & 0x4000U)
    {
        success = 3U;
    }

    /**   @note The function canInit has to be called before this function can be used.\n
    *           The user is responsible to initialize the message box.
    */

/* USER CODE BEGIN (11) */
/* USER CODE END */

    return success;
}


/** @fn uint32_t canIsTxMessagePending(canBASE_t *node, uint32_t messageBox)
*   @brief Gets Tx message box transmission status
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return the tx request flag
*
*   Checks to see if the Tx message box has a pending Tx request, returns
*   0 is flag not set otherwise will return the Tx request flag itself.
*/


/* USER CODE BEGIN (12) */
/* USER CODE END */

uint32_t canIsTxMessagePending(canBASE_t *node, uint32_t messageBox)
{
    uint32_t flag;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (13) */
/* USER CODE END */

    /** - Read Tx request reigster */
    flag = node->TXRQx[regIndex] & bitIndex;

/* USER CODE BEGIN (14) */
/* USER CODE END */

    return flag;
}


/** @fn uint32_t canIsRxMessageArrived(canBASE_t *node, uint32_t messageBox)
*   @brief Gets Rx message box reception status
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return the new data flag
*
*   Checks to see if the Rx message box has pending Rx data, returns
*   0 is flag not set otherwise will return the Tx request flag itself.
*/


/* USER CODE BEGIN (15) */
/* USER CODE END */

uint32_t canIsRxMessageArrived(canBASE_t *node, uint32_t messageBox)
{
    uint32_t flag;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (16) */
/* USER CODE END */

    /** - Read Tx request register */
    flag = node->NWDATx[regIndex] & bitIndex;

/* USER CODE BEGIN (17) */
/* USER CODE END */

    return flag;
}


/** @fn uint32_t canIsMessageBoxValid(canBASE_t *node, uint32_t messageBox)
*   @brief Chechs if message box is valid
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] messageBox Message box number of CAN node:
*              - canMESSAGE_BOX1: CAN message box 1
*              - canMESSAGE_BOXn: CAN message box n [n: 1-64]
*              - canMESSAGE_BOX64: CAN message box 64
*   @return The function will return the new data flag
*
*   Checks to see if the message box is valid for operation, returns
*   0 is flag not set otherwise will return the validation flag itself.
*/


/* USER CODE BEGIN (18) */
/* USER CODE END */

uint32_t canIsMessageBoxValid(canBASE_t *node, uint32_t messageBox)
{
    uint32_t flag;
    uint32_t regIndex = (messageBox - 1U) >> 5U;
    uint32_t bitIndex = 1U << ((messageBox - 1U) & 0x1FU);

/* USER CODE BEGIN (19) */
/* USER CODE END */

    /** - Read Tx request register */
    flag = node->MSGVALx[regIndex] & bitIndex;

/* USER CODE BEGIN (20) */
/* USER CODE END */

    return flag;
}


/** @fn uint32_t canGetLastError(canBASE_t *node)
*   @brief Gets last RX/TX-Error of CAN message traffic
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @return The function will return:
*           - canERROR_OK (0): When no CAN error occured   
*           - canERROR_STUFF (1): When a stuff error occured on RX message    
*           - canERROR_FORMAT (2): When a form/format error occured on RX message   
*           - canERROR_ACKNOWLEDGE (3): When a TX message wasn't acknowledged  
*           - canERROR_BIT1 (4): When a TX message monitored dominant level where recessive is expected   
*           - canERROR_BIT0 (5): When a TX message monitored recessive level where dominant is expected   
*           - canERROR_CRC (6): When a RX message has wrong CRC value   
*           - canERROR_NO (7): When no error occured since last call of this function   
*
*   This function returns the last occured error code of an RX or TX message,
*   since the last call of this function.
*
*/


/* USER CODE BEGIN (21) */
/* USER CODE END */

uint32_t canGetLastError(canBASE_t *node)
{
    uint32_t errorCode;

/* USER CODE BEGIN (22) */
/* USER CODE END */

    /** - Get last error code */
    errorCode = node->ES & 7U;

    /**   @note The function canInit has to be called before this function can be used. */

/* USER CODE BEGIN (23) */
/* USER CODE END */

    return errorCode;
}


/** @fn uint32_t canGetErrorLevel(canBASE_t *node)
*   @brief Gets error level of a CAN node
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @return The function will return:
*           - canLEVEL_ACTIVE (0x00): When RX- and TX error counters are below 96   
*           - canLEVEL_WARNING (0x40): When RX- or TX error counter are between 96 and 127     
*           - canLEVEL_PASSIVE (0x20): When RX- or TX error counter are between 128 and 255     
*           - canLEVEL_BUS_OFF (0x80): When RX- or TX error counter are above 255     
*
*   This function returns the current error level of a CAN node.
*
*/


/* USER CODE BEGIN (24) */
/* USER CODE END */

uint32_t canGetErrorLevel(canBASE_t *node)
{
    uint32_t errorLevel;

/* USER CODE BEGIN (25) */
/* USER CODE END */

    /** - Get error level */
    errorLevel = node->ES & 0xE0U;

    /**   @note The function canInit has to be called before this function can be used. */

/* USER CODE BEGIN (26) */
/* USER CODE END */

    return errorLevel;
}


/** @fn void canEnableErrorNotification(canBASE_t *node)
*   @brief Enable error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*
*   This function will enable the notification for the reaching the error levels warning, passive and bus off.
*/

/* USER CODE BEGIN (27) */
/* USER CODE END */

void canEnableErrorNotification(canBASE_t *node)
{
/* USER CODE BEGIN (28) */
/* USER CODE END */

    node->CTL |= 8U;

    /**   @note The function canInit has to be called before this function can be used. */

/* USER CODE BEGIN (29) */
/* USER CODE END */
}


/** @fn void canDisableErrorNotification(canBASE_t *node)
*   @brief Disable error notification
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*
*   This function will disable the notification for the reaching the error levels warning, passive and bus off.
*/

/* USER CODE BEGIN (30) */
/* USER CODE END */

void canDisableErrorNotification(canBASE_t *node)
{
/* USER CODE BEGIN (31) */
/* USER CODE END */

    node->CTL &= ~8U;

    /**   @note The function canInit has to be called before this function can be used. */

/* USER CODE BEGIN (32) */
/* USER CODE END */
}

/** @fn void canIoSetDirection(canBASE_t *node,uint32_t TxDir,uint32_t RxDir)
*   @brief Set Port Direction
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] TxDir - TX Pin direction
*   @param[in] RxDir - RX Pin direction
*
*   Set the direction of CAN pins at runtime when configured as IO pins.
*/
void canIoSetDirection(canBASE_t *node,uint32_t TxDir,uint32_t RxDir)
{
    node->TIOC = TxDir << 2;
    node->RIOC = RxDir << 2;
}

/** @fn void canIoSetPort(canBASE_t *node, uint32_t TxValue, uint32_t RxValue)
*   @brief Write Port Value
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*   @param[in] TxValue - TX Pin value 0 or 1
*   @param[in] RxValue - RX Pin value 0 or 1
*
*   Writes a value to TX and RX pin of a given CAN module when configured as IO pins.
*/
void canIoSetPort(canBASE_t *node, uint32_t TxValue, uint32_t RxValue)
{
/* USER CODE BEGIN (33) */
/* USER CODE END */

    node->TIOC = TxValue << 1;
    node->RIOC = RxValue << 1;

/* USER CODE BEGIN (34) */
/* USER CODE END */
}

/** @fn uint32_t canIoTxGetBit(canBASE_t *node)
*   @brief Read TX Bit
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*
*   Reads a the current value from the TX pin of the given CAN port
*/
uint32_t canIoTxGetBit(canBASE_t *node)
{
/* USER CODE BEGIN (35) */
/* USER CODE END */

    return (node->TIOC >> 0) & 1U;
}

/** @fn uint32_t canIoRxGetBit(canBASE_t *node)
*   @brief Read RX Bit
*   @param[in] node Pointer to CAN node:
*              - canREG1: CAN1 node pointer
*              - canREG2: CAN2 node pointer
*              - canREG3: CAN3 node pointer
*
*   Reads a the current value from the RX pin of the given CAN port
*/
uint32_t canIoRxGetBit(canBASE_t *node)
{
/* USER CODE BEGIN (36) */
/* USER CODE END */

    return (node->RIOC >> 0) & 1U;
}

