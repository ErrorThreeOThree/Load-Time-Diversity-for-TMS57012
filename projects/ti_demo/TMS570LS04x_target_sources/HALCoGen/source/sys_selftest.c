/** @file sys_selftest.c 
*   @brief Selftest Source File
*   @date 15.Mar.2012
*   @version 03.01.00
*
*   This file contains:
*   - Selftest API's
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */

#include "sys_selftest.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void ccmSelfCheck(void)
*   @brief CCM module self check Driver
*
*   This function self checks the CCM module.
*/
void ccmSelfCheck(void)
{
/* USER CODE BEGIN (2) */
/* USER CODE END */

	/* Run a diagnostic check on the CCM-R4F module */
	/* This step ensures that the CCM-R4F can actually indicate an error */

	/* Configure CCM in self-test mode */
	CCMKEYR = 0x6;								
	/* Wait for CCM self-test to complete */
	while ((CCMSR & 0x100) != 0x100);

/* USER CODE BEGIN (3) */
/* USER CODE END */
	
	/* Check if there was an error during the self-test */
	if ((CCMSR & 0x1) == 0x1)
	{
		/* STE is set */
		ccmFail(0);								
	}
	else
	{
		/* Check CCM-R4 self-test error flag by itself (without compare error) */
		if ((esmREG->ESTATUS1[0] & 0x80000000) != 0x80000000)
		{
			/* ESM flag is not set */
			ccmFail(1);						
		}
		else
		{
			/* clear ESM group1 channel 31 flag */
			esmREG->ESTATUS1[0] = 0x80000000;	
			
			/* Configure CCM in error-forcing mode */
			CCMKEYR = 0x9;
			
            /* check if compare error flag is set */
			if ((esmREG->ESTATUS1[1] & 0x4) != 0x4)
			{
				/* ESM flag is not set */
				ccmFail(2);
			}
			else
			{
		        /* Check FIQIVEC to ESM High Interrupt flag is set */ 
				if(vimREG->FIQIVEC != 1)
				{
				   /* ESM High Interrupt flag is not set in VIM*/
				   ccmFail(3);				
				}
				/* clear ESM group2 channel 2 flag */ 
				esmREG->ESTATUS1[1] = 0x4;
				
				/* clear ESM group2 shadow status flag */
				esmREG->ESTATUS5EMU = 0x4;				
				
				/* ESM self-test error needs to also be cleared */
				esmREG->ESTATUS1[0] = 0x80000000;		
				
				/* Clear CCM-R4 CMPE flag */
				CCMSR = 0x00010000;

				/* Return CCM-R4 to lock-step mode */
				CCMKEYR = 0x0;
				
				/* The nERROR pin will become inactive once the LTC counter expires */
				esmREG->KEY = 0x5;	
			}
		}
	}
}

/* USER CODE BEGIN (4) */
/* USER CODE END */

/** @fn void ccmFail(unsigned int x)
*   @brief CCM module fail service routine
*
*   This function is called if CCM module selftest fail.
*/
void ccmFail(unsigned int x)
{
/* USER CODE BEGIN (5) */
/* USER CODE END */
	if (x == 0)
	{
		/* CCM-R4 is not able to flag a compare error in self-test mode.
		 * Lock-step operation cannot be verified.
		 */
/* USER CODE BEGIN (6) */
/* USER CODE END */
	}
	else if (x == 1)
	{
		/* CCM-R4 self-test error flag is not set in ESM register.
		 * Could be due to a connection issue inside the part.
		 */
/* USER CODE BEGIN (7) */
/* USER CODE END */
	}
	else if (x == 2)
	{
		/* CCM-R4 compare error flag is not set in ESM.
		 * Lock-step operation cannot be verified.
		 */
/* USER CODE BEGIN (8) */
/* USER CODE END */
	}
	else if (x == 3)
	{
		/* ESM High Interrupt Flag is not set in VIM.
		 */
/* USER CODE BEGIN (9) */
/* USER CODE END */
	}	
}

/** @fn void _memoryInit_(unsigned int ram)
*   @brief Memory Initialization Driver
*
*   This function is called to perform Memory initialization of selected RAM's.
*/
void _memoryInit_(unsigned int ram)
{
/* USER CODE BEGIN (10) */
/* USER CODE END */
	/* Enable Memory Hardware Initialization */
	systemREG1->MINITGCR = 0xA;	
	
    /* Enable Memory Hardware Initialization for selected RAM's */
	systemREG1->MSINENA  = ram;
    
	/* Wait until Memory Hardware Initialization complete */
	while( systemREG1->MSTCGSTAT & 0x00000100 != 1);
	
	/* Disable Memory Hardware Initialization */
	systemREG1->MINITGCR = 0xA;	
/* USER CODE BEGIN (11) */
/* USER CODE END */
}

/** @fn void stcSelfCheck(void)
*   @brief STC module self check Driver
*
*   This function is called to perform STC module self check.
*/
void stcSelfCheck(void)
{
/* USER CODE BEGIN (12) */
/* USER CODE END */
	volatile int i = 0;

	/* Run a diagnostic check on the CPU self-test controller */
	/* First set up the STC clock divider as STC is only supported up to 90MHz */
	
	/* STC clock is now normal mode CPU clock frequency/2 = 180MHz/2 */
	systemREG2->STCCLKDIV = 0x01000000;	
	
	/* Select one test interval, restart self-test next time, 0x00010001 */
	stcREG->STCGCR0 = 0x00010001;						
	
	/* Enable comparator self-check and stuck-at-0 fault insertion in CPU, 0x1A */
	stcREG->STCSCSCR = 0x1A;							
	
	/* Maximum time-out period */
	stcREG->STCTPR = 0xFFFFFFFF;						

	/* wait for 16 VBUS clock cycles at least */
	for (i=0; i<16; i++);								

	/* Enable self-test */
	stcREG->STCGCR1 = 0xA;								
	
	/* wait for 16 VBUS clock cycles at least */
	for (i=0; i<16; i++);								

/* USER CODE BEGIN (13) */
/* USER CODE END */
	
	/* Idle the CPU so that the self-test can start */
	_gotoCPUIdle_();

/* USER CODE BEGIN (14) */
/* USER CODE END */
}

/** @fn void cpuSelfTest(unsigned int no_of_intervals, unsigned int max_timeout, boolean_t restart_test)
*   @brief CPU self test Driver
*   @param[in] no_of_intervals - Number of Test Intervals to be 
*   @param[in] max_timeout     - Maximun Timeout to complete selected test Intervals
*   @param[in] restart_test    - Restart the test from Interval 0 or Continue from where it stopped.
*
*   This function is called to perform CPU self test using STC module.
*/
void cpuSelfTest(unsigned int no_of_intervals, unsigned int max_timeout, boolean_t restart_test)
{
	volatile int i = 0;

/* USER CODE BEGIN (15) */
/* USER CODE END */
	
	/* Run specified no of test intervals starting from interval 0 */
	/* Start test from interval 0 or continue the test. */ 
	stcREG->STCGCR0 = no_of_intervals << 16             
	                | (unsigned int) restart_test;						
	
	/* Configure Maximum time-out period */
	stcREG->STCTPR = max_timeout;						
	
	/* wait for 16 VBUS clock cycles at least */
	for (i=0; i<16; i++);								

	/* Enable self-test */
	stcREG->STCGCR1 = 0xA;								

/* USER CODE BEGIN (16) */
/* USER CODE END */
	/* Idle the CPU so that the self-test can start */
	
	_gotoCPUIdle_();
	
}

/** @fn void pbistSelfCheck(void)
*   @brief PBIST self test Driver
*
*   This function is called to perform PBIST self test.
*/
void pbistSelfCheck(void)
{
	int i = 0;
/* USER CODE BEGIN (17) */
/* USER CODE END */
	/* Run a diagnostic check on the memory self-test controller */
	/* First set up the PBIST ROM clock as this clock frequency is limited to 90MHz */
	
	/* PBIST ROM clock frequency = HCLK frequency /2 */
	systemREG1->MSTGCR |= 0x00000100;				
	
	/* Enable PBIST controller */
	systemREG1->MSINENA = 0x1;							
	
	/* clear MSTGENA field */
	systemREG1->MSTGCR &= ~(0xF);						
	
	/* Enable PBIST self-test */
	systemREG1->MSTGCR |= 0xA;							
	
	/* software loop to wait at least 32 VCLK cycles */
	for (i = 0; i < 32; i++);							

/* USER CODE BEGIN (18) */
/* USER CODE END */
	
	/* Enable PBIST clocks and ROM clock */
	pbistREG->PACT = 0x3;								
	
	/* Select algo#3, march13n to be run */
	pbistREG->ALGO = 0x00000004;						
	
	/* Select RAM Group 1, which is actually the PBIST ROM */
	pbistREG->RINFOL = 0x1;								
	
	/* ROM contents will not override ALGO and RINFOx settings */
	pbistREG->OVER = 0x0;								
	
	/* Algorithm code is loaded from ROM */
	pbistREG->ROM = 0x3;								
	
	/* Start PBIST */
	pbistREG->DLR = 0x14;								
	
	/* wait until memory self-test done is indicated */
	while ((systemREG1->MSTCGSTAT & 0x1) != 0x1);		
	
	/* Check for the failure */
	if (((pbistREG->FSRF0 & 0x1) != 0x1) & ((pbistREG->FSRF1 & 0x1) != 0x1))
	{
		/* no failure was indicated even if the march13n algorithm was run on a ROM */
		pbistSelfCheckFail();
/* USER CODE BEGIN (19) */
/* USER CODE END */
	}
	else												
	{
	    /* PBIST self-check has passed */
		
		/* Disable PBIST clocks and ROM clock */
		pbistREG->PACT = 0x0;							
		
		/* Disable PBIST */
		systemREG1->MSTGCR &= ~(0xF);					
		systemREG1->MSTGCR |= 0x5;
		
/* USER CODE BEGIN (20) */
/* USER CODE END */
    }
}

/** @fn void pbistSelfCheckFail(void)
*   @brief PBIST self test Driver failure service routine
*
*   This function is called on PBIST self test failure.
*/
void pbistSelfCheckFail(void)
{
	/* The PBIST controller is not capable of reporting a failure.
	 * PBIST cannot be used to verify memory integrity.
	 * Need custom handler here.
	 */
/* USER CODE BEGIN (21) */
/* USER CODE END */
}

/** @fn void pbistRun(unsigned int raminfoL, unsigned int algomask)
*   @brief CPU self test Driver
*   @param[in] raminfoL   - Select the list of RAM to be tested.
*   @param[in] algomask   - Select the list of Algorithm to be run.
*
*   This function performs Memory Built-in Self test using PBIST module.
*/
void pbistRun(unsigned int raminfoL, unsigned int algomask)
{
	int i = 0;

/* USER CODE BEGIN (22) */
/* USER CODE END */

	/* PBIST ROM clock frequency = HCLK frequency /2 */
	systemREG1->MSTGCR |= 0x00000100;					
	
	/* Enable PBIST controller */
	systemREG1->MSINENA = 0x1;							 
	
	/* clear MSTGENA field */
	systemREG1->MSTGCR &= ~(0xF);						 
	
	/* Enable PBIST self-test */
	systemREG1->MSTGCR |= 0xA;							 
	
	/* software loop to wait at least 32 VCLK cycles */
	for (i = 0; i < 32; i++);							 

/* USER CODE BEGIN (23) */
/* USER CODE END */
	
	/* Enable PBIST clocks and ROM clock */
	pbistREG->PACT = 0x3;								 
	
	/* Select all algorithms to be tested */
	pbistREG->ALGO = algomask;						     
	
	/* Select RAM groups */
	pbistREG->RINFOL = raminfoL;						 
	
	/* Select all RAM groups */
	pbistREG->RINFOU = 0x00000000;						
	
	/* ROM contents will not override RINFOx settings */
	pbistREG->OVER = 0x0;								 
	
	/* Algorithm code is loaded from ROM */
	pbistREG->ROM = 0x3;								 
	
	/* Start PBIST */
	pbistREG->DLR = 0x14;								 

/* USER CODE BEGIN (24) */
/* USER CODE END */
}

/** @fn void pbistStop(void)
*   @brief Routine to stop PBIST test enabled.
*
*   This function is called to stop PBIST after test is performed.
*/
void pbistStop(void)
{
/* USER CODE BEGIN (25) */
/* USER CODE END */
    /* disable pbist clocks and ROM clock */
	pbistREG->PACT = 0x0;							
	systemREG1->MSTGCR &= ~(0xF);
	systemREG1->MSTGCR |= 0x5;
/* USER CODE BEGIN (26) */
/* USER CODE END */
}

/** @fn boolean_t pbistIsTestCompleted(void)
*   @brief Checks to see if the PBIST test is completed.
*   @return 1 if PBIST test completed, otherwise 0.
*
*   Checks to see if the PBIST test is completed.
*/
boolean_t pbistIsTestCompleted(void)
{
/* USER CODE BEGIN (27) */
/* USER CODE END */

	return ((systemREG1->MSTCGSTAT & 0x1) != 0);
/* USER CODE BEGIN (28) */
/* USER CODE END */
}

/** @fn boolean_t pbistIsTestPassed(void)
*   @brief Checks to see if the PBIST test is completed sucessfully.
*   @return 1 if PBIST test passed, otherwise 0.
*
*   Checks to see if the PBIST test is completed sucessfully.
*/
boolean_t pbistIsTestPassed(void)
{
/* USER CODE BEGIN (29) */
/* USER CODE END */

	return  ((pbistREG->FSRF0 || pbistREG->FSRF1) == 0);
/* USER CODE BEGIN (30) */
/* USER CODE END */
}

/** @fn boolean_t pbistPortTestStatus(uint32_t port)
*   @brief Checks to see if the PBIST Port test is completed sucessfully.
*   @param[in] port   - Select the port to get the status.
*   @return 1 if PBIST Port test completed sucessfully, otherwise 0.
*
*   Checks to see if the selected PBIST Port test is completed sucessfully.
*/
boolean_t pbistPortTestStatus(uint32_t port)
{
    boolean_t status;
/* USER CODE BEGIN (31) */
/* USER CODE END */

    if(port == PBIST_PORT0)
	{
	  status =  (pbistREG->FSRF0 == 0);
	}
	else
	{
	  status =  (pbistREG->FSRF1 == 0);	
	}
	
	return  status;
}

/** @fn void efcCheck(void)
*   @brief EFUSE module self check Driver
*
*   This function self checks the EFSUE module.
*/
void efcCheck(void)
{
	unsigned int efcStatus = 0;

/* USER CODE BEGIN (32) */
/* USER CODE END */
	
	/* read the EFC Error Status Register */
	efcStatus = efcREG->ERROR;						

/* USER CODE BEGIN (33) */
/* USER CODE END */
	
	if (efcStatus == 0x0)
	{
	    /* run stuck-at-zero test and check if it passed */
		if (efcStuckZeroTest())						
		{
		    /* start EFC ECC logic self-test */
			efcSelfTest();							
		}
		else
		{
		    /* EFC output is stuck-at-zero, device operation unreliable */
			efcClass2Error();						
		}
	}
	/* EFC Error Register is not zero */
	else											
	{
		/* one-bit error detected during autoload */
		if (efcStatus == 0x15)						
		{
		    /* start EFC ECC logic self-test */
			efcSelfTest();							
		}
		else
		{
		    /* Some other EFC error was detected */
		    efcClass2Error();					
		}
	}
}

/** @fn boolean_t efcStuckZeroTest(void)
*   @brief Checks to see if the EFUSE Stuck at zero test is completed sucessfully.
*   @return 1 if EFUSE Stuck at zero test completed, otherwise 0.
*
*   Checks to see if the EFUSE Stuck at zero test is completed sucessfully.
*/
boolean_t efcStuckZeroTest(void)
{
/* USER CODE BEGIN (34) */
/* USER CODE END */

	boolean_t result = FALSE;
  	unsigned int error_checks = EFC_INSTRUCTION_INFO_EN  | 
							  	EFC_INSTRUCTION_ERROR_EN | 
							  	EFC_AUTOLOAD_ERROR_EN 	 | 
							  	EFC_SELF_TEST_ERROR_EN   ;
	
	/* configure the output enable for auto load error , instruction info,
  	   instruction error, and self test error using boundary register 
  	   and drive values one across all the errors */
  	efcREG->BOUNDARY = (OUTPUT_ENABLE | error_checks);
  	
	/* Read from the pin register. This register holds the current values 
  	   of above errors. This value should be 0x5c00.If not at least one of
  	   the above errors is stuck at 0. */
	if ((efcREG->PINS & 0x5C00) == 0x5C00)
	{
		/* check if the ESM group1 channels 40 is set and group3 channel 2 is set */
		if (((esmREG->ESTATUS4[0] & 0x200) == 0x200) & ((esmREG->ESTATUS1[2] & 0x2) == 0x2))
		{
           /* stuck-at-zero test passed */
		   result = TRUE;									
		}
	}
	
	/* put the pins back low */
	efcREG->BOUNDARY = OUTPUT_ENABLE;
	
	/* clear group1 flags */
	esmREG->ESTATUS4[0] = 0x300;
	
	/* clear group3 flag */
	esmREG->ESTATUS1[2] = 0x2;					
	
	/* The nERROR pin will become inactive once the LTC counter expires */
	esmREG->KEY = 0x5;							

	return result;
}

/** @fn void efcSelfTest(void)
*   @brief EFUSE module self check Driver
*
*   This function self checks the EFSUE module.
*/
void efcSelfTest(void)
{
/* USER CODE BEGIN (35) */
/* USER CODE END */
	/* configure self-test cycles */
	efcREG->SELF_TEST_CYCLES = 0x258;
	
	/* configure self-test signature */
	efcREG->SELF_TEST_SIGN = 0x5362F97F;
	
	/* configure boundary register to start ECC self-test */
	efcREG->BOUNDARY = 0x0000200F;
}

/** @fn boolean_t checkefcSelfTest(void)
*   @brief EFUSE module self check Driver
*
*   This function self checks the EFSUE module.
*/
boolean_t checkefcSelfTest(void)
{
/* USER CODE BEGIN (36) */
/* USER CODE END */
	boolean_t result = FALSE;
	
	/* wait until EFC self-test is done */
	while(!(efcREG->PINS & EFC_SELF_TEST_DONE));
	
	/* check if EFC self-test error occurred */
	if (!(efcREG->PINS & EFC_SELF_TEST_ERROR) & !(efcREG->ERROR & SELF_TEST_ERROR))
	{
		/* check if EFC self-test error is set */
		if ((esmREG->ESTATUS4[0] & 0x100) != 0x100)		
		{
			result = TRUE;
		}
	}
	return result;
}

/** @fn void efcClass1Error(void)
*   @brief EFUSE Class1 Error service routine
*
*   This function is called if EFC ECC logic self-test.
*/
void efcClass1Error(void)
{
/* USER CODE BEGIN (37) */
/* USER CODE END */
	/* Autoload error was detected during device power-up, and device operation is not reliable. */
	while(1);
/* USER CODE BEGIN (38) */
/* USER CODE END */
}

/** @fn void efcClass2Error(void)
*   @brief EFUSE Class2 Error service routine
*
*   This function is called if EFC output is stuck-at-zero.
*/
void efcClass2Error(void)
{
/* USER CODE BEGIN (39) */
/* USER CODE END */
	/* The ECC logic inside the eFuse controller is not operational. Device operation is not reliable. */
	while(1);
/* USER CODE BEGIN (40) */
/* USER CODE END */
}

/** @fn void fmcBus2Check(void)
*   @brief Self Check Flash Bus2 Interface
*
*   This function self checks Flash Bus2 Interface
*/
void fmcBus2Check(void)
{
/* USER CODE BEGIN (41) */
/* USER CODE END */
    /* enable ECC logic inside FMC */
	flashWREG->FEDACCTRL1 = 0x000A060A;		

	if (esmREG->ESTATUS1[0] & 0x40)
	{
		/* a 1-bit error was detected during flash OTP read by flash module
		   run a self-check on ECC logic inside FMC */
		
		/* clear ESM group1 channel 6 flag */
		esmREG->ESTATUS1[0] = 0x40;	
		
		fmcECCcheck();
	}
	
	/* no 2-bit or 1-bit error detected during power-up */
	else										
	{
		fmcECCcheck();
	}
/* USER CODE BEGIN (42) */
/* USER CODE END */
}

/** @fn void fmcECCcheck(void)
*   @brief Check Flash ECC Single Bit and multi Bit errors detection logic.
*
*   This function Checks Flash ECC Single Bit and multi Bit errors detection logic.
*/
void fmcECCcheck(void)
{
	volatile unsigned int otpread;
	volatile unsigned int temp;

/* USER CODE BEGIN (43) */
/* USER CODE END */

	/* read location with deliberate 1-bit error */
	otpread = flash1bitError;				
	if (esmREG->ESTATUS1[0] & 0x40)
	{
		/* 1-bit failure was indicated and corrected */
		flashWREG->FEDACSTATUS = 0x00010006;
		
		/* clear ESM group1 channel 6 flag */
		esmREG->ESTATUS1[0] = 0x40;			
		
        /* read location with deliberate 2-bit error */
		otpread = flash2bitError;			
		if (esmREG->ESTATUS1[2] & 0x80)
		{
			/* 2-bit failure was detected correctly */
			temp = flashWREG->FUNCERRADD;
			flashWREG->FEDACSTATUS = 0x00020100;
			
			/* clear ESM group3 channel 7 */
			esmREG->ESTATUS1[2] = 0x80;		
			
			/* The nERROR pin will become inactive once the LTC counter expires */
			esmREG->KEY = 0x5;				

		}
		else
		{
		    /* ECC logic inside FMC cannot detect 2-bit error */
			fmcClass2Error();				
		}
	}
	else
	{
	    /* ECC logic inside FMC cannot detect 1-bit error */
		fmcClass2Error();					
	}
/* USER CODE BEGIN (44) */
/* USER CODE END */
}

/** @fn void fmcClass1Error(void)
*   @brief Flash Multi bit ECC error service routine detected during reset configuration.
*
*   This function is called if Flash Multi bit ECC error detected during reset configuration.
*/
void fmcClass1Error(void)
{
/* USER CODE BEGIN (45) */
/* USER CODE END */
	/* there was a multi-bit error detected during the reset configuration word read from the OTP */
	/* This affects the device power domains, endianness, and exception handling ISA */
	/* Device operation is not reliable. */
	while(1);
/* USER CODE BEGIN (46) */
/* USER CODE END */
}

/** @fn void fmcClass2Error(void)
*   @brief Flash OTP or EEPROM read Multi bit ECC error service routine
*
*   This function is called if Flash OTP or EEPROM read Multi bit ECC error detected.
*/
void fmcClass2Error(void)
{
/* USER CODE BEGIN (47) */
/* USER CODE END */
	/* The ECC logic inside FMC used to protect against 1-bit and 2-bit errors in OTP and EEPROM banks */
	/* is not operational. Device operation is not reliable. */
	while(1);
/* USER CODE BEGIN (48) */
/* USER CODE END */
}

/** @fn void checkB0RAMECC(void)
*   @brief Check TCRAM1 ECC error detection logic.
*
*   This function checks TCRAM1 ECC error detection logic.
*/
void checkB0RAMECC(void)
{
	volatile unsigned int ramread = 0;
/* USER CODE BEGIN (49) */
/* USER CODE END */
	/* enable writes to ECC RAM, enable ECC error response */
	tcram1REG->RAMCTRL = 0x0005010A;			
	tcram2REG->RAMCTRL = 0x0005010A;

	/* the first 1-bit error will cause an error response */
	tcram1REG->RAMTHRESHOLD = 0x1;				
	tcram2REG->RAMTHRESHOLD = 0x1;

	/* allow SERR to be reported to ESM */
	tcram1REG->RAMINTCTRL = 0x1;				
	tcram2REG->RAMINTCTRL = 0x1;
    
	/* cause a 1-bit ECC error */
	tcramA1bitError ^= 0x1;		
	
	/* disable writes to ECC RAM */
	tcram1REG->RAMCTRL = 0x0005000A;			
	tcram2REG->RAMCTRL = 0x0005000A;

	/* read from location with 1-bit ECC error */
	ramread = tcramA1bit;		
	
	/* SERR not set in TCRAM1 or TCRAM2 modules */
	if (!((tcram1REG->RAMERRSTATUS & 1) || (tcram2REG->RAMERRSTATUS & 1)))	
	{
		/* TCRAM module does not reflect 1-bit error reported by CPU */
		tcramClass2Error();						
	}
	else
	{
	    /* clear SERR flag */
		tcram1REG->RAMERRSTATUS = 0x1;			
		tcram2REG->RAMERRSTATUS = 0x1;
		
		/* clear status flags for ESM group1 channels 26 and 28 */
		esmREG->ESTATUS1[0] = 0x14000000;		
	}

	/* enable writes to ECC RAM, enable ECC error response */
	tcram1REG->RAMCTRL = 0x0005010A;			
	tcram2REG->RAMCTRL = 0x0005010A;

	/* cause a 2-bit ECC error */
	tcramA2bitError ^= 0x3;						
	ramread = tcram1REG->RAMCTRL;
	ramread = tcram2REG->RAMCTRL;

	/* read from location with 2-bit ECC error this will cause a data abort to be generated */
	ramread = tcramA2bit;						
/* USER CODE BEGIN (50) */
/* USER CODE END */
}

/** @fn void checkB1RAMECC(void)
*   @brief Check TCRAM2 ECC error detection logic.
*
*   This function checks TCRAM2 ECC error detection logic.
*/
void checkB1RAMECC(void)
{
	volatile unsigned int ramread = 0;
/* USER CODE BEGIN (51) */
/* USER CODE END */

	/* enable writes to ECC RAM, enable ECC error response */
	tcram1REG->RAMCTRL = 0x0005010A;			
	tcram2REG->RAMCTRL = 0x0005010A;
    
	/* the first 1-bit error will cause an error response */
	tcram1REG->RAMTHRESHOLD = 0x1;				
	tcram2REG->RAMTHRESHOLD = 0x1;

	/* allow SERR to be reported to ESM */
	tcram1REG->RAMINTCTRL = 0x1;				 
	tcram2REG->RAMINTCTRL = 0x1;

	/* cause a 1-bit ECC error */
	tcramB1bitError ^= 0x1;						 
	
	/* disable writes to ECC RAM */
	tcram1REG->RAMCTRL = 0x0005000A;			 
	tcram2REG->RAMCTRL = 0x0005000A;

	/* read from location with 1-bit ECC error */
	ramread = tcramB1bit;						 
	
	/* SERR not set in TCRAM1 or TCRAM2 modules */
	if (!((tcram1REG->RAMERRSTATUS & 1) || (tcram2REG->RAMERRSTATUS & 1)))	
	{
		/* TCRAM module does not reflect 1-bit error reported by CPU */
		tcramClass2Error();						
	}
	else
	{
		/* clear SERR flag */
		tcram1REG->RAMERRSTATUS = 0x1;			 
		tcram2REG->RAMERRSTATUS = 0x1;
		
		/* clear status flags for ESM group1 channels 26 and 28 */
		esmREG->ESTATUS1[0] = 0x14000000;		 
	}

	/* enable writes to ECC RAM, enable ECC error response */
	tcram1REG->RAMCTRL = 0x0005010A;			 
	tcram2REG->RAMCTRL = 0x0005010A;
	
	/* cause a 2-bit ECC error */
	tcramB2bitError ^= 0x3;						 
	
	/* disable writes to ECC RAM */
	tcram1REG->RAMCTRL = 0x0005000A;			 
	tcram2REG->RAMCTRL = 0x0005000A;

/* USER CODE BEGIN (52) */
/* USER CODE END */
}

/** @fn void tcramClass1Error(void)
*   @brief Error service routine called if TCRAM module cannot capture 2-bit error.
*
*   Error service routine called if TCRAM module cannot respond to 2-bit error.
*/
void tcramClass1Error(void)
{
/* USER CODE BEGIN (53) */
/* USER CODE END */
	/* TCRAM module is not capable of responding to 2-bit error indicated by CPU.
	 * Device operation is not reliable and not recommended.
	 */
	while(1);

/* USER CODE BEGIN (54) */
/* USER CODE END */
}

/** @fn void tcramClass2Error(void)
*   @brief Error service routine called if TCRAM module cannot capture 1-bit error.
*
*   Error service routine called if TCRAM module cannot respond to 1-bit error.
*/
void tcramClass2Error(void)
{
/* USER CODE BEGIN (55) */
/* USER CODE END */
	/* TCRAM module is not capable of responding to 1-bit error indicated by CPU.
	 * Device operation is possible, but is prone to future multi-bit errors not being detected.
	 * Need custom handler here instead of the infinite loop.
	 */
	while(1);
/* USER CODE BEGIN (56) */
/* USER CODE END */
}

/** @fn void checkFlashECC(void)
*   @brief Check Flash ECC error detection logic.
*
*   This function checks Flash ECC error detection logic.
*/
void checkFlashECC(void)
{
	/* Routine to check operation of ECC logic inside CPU for accesses to program flash */
	volatile unsigned int flashread = 0;

/* USER CODE BEGIN (57) */
/* USER CODE END */
	
	/* Flash Module ECC Response enabled */
	flashWREG->FEDACCTRL1 = 0x000A060A;			
    
	/* Enable diagnostic mode and select diag mode 7 */
	flashWREG->FDIAGCTRL = 0x00050007;			
	
	/* Select ECC diagnostic mode, single-bit to be corrupted */
	flashWREG->FPAROVR = 0x00005401;			
	
	/* Set the trigger for the diagnostic mode */
	flashWREG->FDIAGCTRL |= 0x01000000;			
    
	/* read a flash location from the mirrored memory map */
	flashread = flashBadECC;	
	
	/* disable diagnostic mode */
	flashWREG->FDIAGCTRL = 0x000A0007;			

	/* this will have caused a single-bit error to be generated and corrected by CPU */
	/* single-bit error not captured in flash module */
	if (!(flashWREG->FEDACSTATUS & 0x2))		
	{
		flashClass2Error();
	}
	else
	{
        /* clear single-bit error flag */
		flashWREG->FEDACSTATUS = 0x2;				

		/* clear ESM flag */
		esmREG->ESTATUS1[0] = 0x40;					

		/* Enable diagnostic mode and select diag mode 7 */
		flashWREG->FDIAGCTRL = 0x00050007;			
		
		/* Select ECC diagnostic mode, two bits of ECC to be corrupted */
		flashWREG->FPAROVR = 0x00005A03;			
		
		/* Set the trigger for the diagnostic mode */
		flashWREG->FDIAGCTRL |= 0x01000000;			

		/* read from flash location from mirrored memory map this will cause a data abort */
		flashread = flashBadECC;					
	}

/* USER CODE BEGIN (58) */
/* USER CODE END */
}

/** @fn void flashClass1Error(void)
*   @brief Error service routine called if Flash module cannot capture 2-bit error.
*
*   Error service routine called if Flash module cannot capture 2-bit error.
*/
void flashClass1Error(void)
{
/* USER CODE BEGIN (59) */
/* USER CODE END */
	/* Flash module not able to capture 2-bit error from CPU.
	 * Device operation not reliable.
	 */
	while(1);

/* USER CODE BEGIN (60) */
/* USER CODE END */

}

/** @fn void flashClass2Error(void)
*   @brief Error service routine called if Flash module cannot capture 1-bit error.
*
*   Error service routine called if Flash module cannot capture 1-bit error.
*/
void flashClass2Error(void)
{
	/* Flash module not able to capture 1-bit error from CPU.
	 * Device operation possible if this weakness in diagnostic is okay.
	 */
/* USER CODE BEGIN (61) */
/* USER CODE END */
}

/** @fn void custom_dabort(void)
*   @brief Custom Data abort routine for the application.
*
*   Custom Data abort routine for the application.
*/
void custom_dabort(void)
{
	/* Need custom data abort handler here.
	 * This data abort is not caused due to diagnostic checks of flash and TCRAM ECC logic.
	 */
/* USER CODE BEGIN (62) */
/* USER CODE END */
}

/** @fn void stcSelfCheckFail(void)
*   @brief STC Self test check fail service routine
*
*   This function is called if STC Self test check fail.
*/
void stcSelfCheckFail(void)
{
/* USER CODE BEGIN (63) */
/* USER CODE END */
	/* CPU self-test controller's own self-test failed.
	 * It is not possible to verify that STC is capable of indicating a CPU self-test error.
	 * It is not recommended to continue operation.
	 */
	while(1);
/* USER CODE BEGIN (64) */
/* USER CODE END */
}

/** @fn void cpuSelfTestFail(void)
*   @brief CPU Self test check fail service routine
*
*   This function is called if CPU Self test check fail.
*/
void cpuSelfTestFail(void)
{
/* USER CODE BEGIN (65) */
/* USER CODE END */
	/* CPU self-test has failed.
	 * CPU operation is not reliable.
	 */
	while(1);
/* USER CODE BEGIN (66) */
/* USER CODE END */
}

