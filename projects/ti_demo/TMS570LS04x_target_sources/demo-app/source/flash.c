/** @file flash.c 
*   @brief flash Driver Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*/

/* (c) Texas Instruments 2009, All rights reserved. */

/* USER CODE BEGIN (0) */
extern void _coreEnableFlashEcc_(void);
extern void _coreDisableFlashEcc_(void);
/* USER CODE END */

/** @enum testStatus
*   @brief pass or fail status for the test performed
*   This enumeration is used to provide alias names for the test pass/fail status:
*     - PASS
*     - Fail 
*/

enum testStatus
{
    FAIL = 0x00000000, /**< Alias for FAIL */
    PASS = 0x00000001 /**< Alias for PASS */
};



/* Include Files */

#include "system.h"
#include "sci.h"

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);

/*
enum testStatus
{
    FAIL = 0x00000000, 
    PASS = 0x00000001 
};
*/
/** @fn void ATCM_Correctable_Error(void)
*   @brief Flash Single Bit ECC error creation and check routines.
*/

void ATCM_Correctable_Error(void)
{
	unsigned int Single_Bit_Err_Loc;

    /** - 0xF00803F4 is TI OTP location which has corrupted data "0x9ABCDEF1" */
	unsigned int * Single_Bit_Err_Loc_ptr = (unsigned int *)(0xF00803F4);
	
    /** - Setup Flash ECC  
    *     - Error Detection / Correction Enable
    *     - Errors from OTP memory regions unblocked
    *     - Correctable Interrupt Enabled
    */
	flashWREG->FEDACCTRL1 = 0x20D;

    /** Enable Flash ECC in Cortex R4*/
	_coreEnableFlashEcc_();

    /** - Read data from the Single Bit Error location 
	 *	  - ESM error will be triggered after this read
	 *	  - Data will be corrected and stored in the variable Single_Bit_Err_Loc
	 */
	Single_Bit_Err_Loc = * Single_Bit_Err_Loc_ptr;

    /** - Verify that corrected data is stored in the variable
     *  - Transmit back 0x0000000 to PC incase of failure
     */
	if(Single_Bit_Err_Loc != 0x9ABCDEF0)
	{
		sciSend_32bitdata(scilinREG, FAIL);
	}

    /** - Clear the Flash Single Bit error Flag */
	flashWREG->FEDACSTATUS = 2;

    /** - Disable Flash Error Detection / Correction */
	flashWREG->FEDACCTRL1 = 0x005;

    /** Disable Flash ECC in Cortex R4*/
	_coreDisableFlashEcc_();

}
