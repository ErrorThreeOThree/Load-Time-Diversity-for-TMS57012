/** @example example_TI_Fee_Write_Read.c
*   This is an example which descibes the steps to use TI-Fee Driver for simple Write Sync, Write Async,
*   Read, Invalidate and Full Format of EEPROM bank.
*
*   @b Step @b 1:
*
*   Create a new project.
*
*   Navigate: -> File -> New -> Project -> TMS570xx / RMx
*
*   @b Step @b 2:
*
*   Configure driver code generation:
*   - Enable TI-FEE driver
*   - Disable others
*
*   Navigate: -> TMS570xx / RMx -> Driver Enable
*
*   @b Step @b 3:
*
*   Navigate: -> TMS570xx / RMx -> TI-FEE
*
*   Configure FEE settings ( Leave Default for below Example)
*
*   @b Step @b 4:
*
*   Navigate: -> File -> Generate Code
*
*   @b Step @b 5:
*
*   Copy source code below into your application.
*
*   @b Step @b 6:
*
*   Add F021 Library files to CCS Project
*   - Add/Link F021_API_CortexR4_BE.lib from folder C:/ti/Hercules/F021 Flash API/2.01.01 to CCS Project
*   - Add Path C:/ti/Hercules/F021 Flash API/2.01.01/include to Include Path in CCS Project
*
*   The example file example_TI_Fee_Write_Read.c can also be found in the examples folder: ../HALCoGen/examples
*
*   @note HALCoGen generates an enpty main function in sys_main.c,
*         please make sure that you link in the right main function or copy the source into the user code sections of this file.
*
*/


/* (c) Texas Instruments 2009-2015, All rights reserved. */

/* 
* Copyright (C) 2009-2015 Texas Instruments Incorporated - www.ti.com
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/* USER CODE BEGIN (0) */
#include "ti_fee.h"
#include "rand.h"
/* USER CODE END */

/* Include Files */
#include "sys_common.h"
/* USER CODE BEGIN (1) */


uint16 u16JobResult,Status;
Std_ReturnType oResult=E_OK;
unsigned char read_data[100]={0};

uint8 SpecialRamBlock[100];

unsigned char pattern;
uint16 u16writecounter;

unsigned int  FeeVirtualSectorNumber;
unsigned char VsState, u8EEPIndex;
unsigned char u8VirtualSector;
uint8 Test_Recovery;
uint8 Test_Cancel;

void delay(void)
{
	unsigned int dummycnt=0x0000FFU;
	do
	{
		dummycnt--;
	}
	while(dummycnt>0);
}
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void main(void)
{
/* USER CODE BEGIN (3) */
	unsigned int BlockNumber;
	unsigned int BlockOffset, Length;
    uint64_t seed = 0;
	rand_set_seed(seed);

	unsigned int loop;
	
	/* Initialize RAM array.*/
	uint32_t prn = rand();
	uint64_t seedRead;

	/* Initialize FEE. This will create Virtual sectors, initialize global variables etc.*/
	TI_Fee_Init();
	do
	{
		TI_Fee_MainFunction();
		delay();
		Status=TI_Fee_GetStatus(0 );
	} while(Status!= IDLE);

    BlockNumber=0x1;
//    TI_Fee_WriteSync(BlockNumber, &data);
    BlockOffset = 0;
    Length = 0x8;

    for(loop =0 ; loop < 10; loop++){


        prn = rand();

        seed = rand_get_seed();
        TI_Fee_WriteSync(BlockNumber, (uint8_t *)&seed);
        oResult=TI_Fee_ReadSync(BlockNumber, BlockOffset, (uint8_t *) &seedRead, Length);
        seed = seedRead;
    }

    while(1);
/* USER CODE END */
}

/* USER CODE BEGIN (4) */
/* USER CODE END */
