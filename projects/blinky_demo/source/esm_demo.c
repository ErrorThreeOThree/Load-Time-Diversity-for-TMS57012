#include "esm_demo.h"



/* External Variables */
extern unsigned int SubTask_Number;

/* External Functions */
extern void DCAN1_Parity(void);
extern void DCAN2_Parity(void);
extern void DCAN3_Parity(void);
extern void MIBSPI1_Parity(void);
extern void MIBADC1_Parity(void);
extern void MIBADC2_Parity(void);
extern void NHET_Parity(void);
extern void VIMRAM_Parity(void);
extern void ATCM_Correctable_Error(void);

/* Global Variables */
unsigned int ESM_High_Int_Flag = 0;

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);



extern unsigned int 	SubTask_Number;
extern unsigned int 	Task_Number;

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


/** @fn void esm_test(void)
 *   
 *   This function is called when a ESM test command is received. 
 * 	 In ESM, required channel test is selected based on the sub task   
 *  
 */
void esm_test(void)
{

	esmClearErrPin();

	switch(SubTask_Number)
	{
		case 0:
				break;
		case 1:
				/** - DCAN 1 Parity error Test */
				DCAN1_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DCAN1_parity_ESM_Channel);
				break;
		case 2:
				/** - DCAN 2 Parity error Test */
				DCAN2_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DCAN2_parity_ESM_Channel);
				break;

		case 4:
				/** - HTU Parity error Test */
				HTU_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(HETTU_parity_ESM_Channel);
				break;
		case 5:
				/** - MIBSPI 1 Parity error Test */
				MIBSPI1_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibSPI1_parity_ESM_Channel);
				break;

		case 8:
				/** - MIBADC 1 Parity error Test */
				MIBADC1_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibADC1_parity_ESM_Channel);
				break;
		case 9:
				/** - MIBADC 2 Parity error Test */
				MIBADC2_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(MibADC2_parity_ESM_Channel);
				break;
		case 10:
				/** - NHET Memory Parity error Test */
				NHET_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(NHET_parity_ESM_Channel);
				break;
		case 11:
				/** - VIM RAM Parity error Test */
				VIMRAM_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(VIM_RAM_parity_ESM_Channel);
				break;
		case 12:
				/** - Flexray Message RAM Parity error Test */
				FRAY_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(Flexray_parity_ESM_Channel);
				break;
		case 13:
				/** - FTU Parity error Test */
				FTU_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(FTU_parity_ESM_Channel);
				break;
		case 14:
				/** - Core Compare Module Compare fail error Test */
				CCM_R4_Compare();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(CCM_R4_compare_ESM_Channel);
				break;
		case 15:
				/** - DMA Parity error Test */
				DMA_Parity();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DMA_parity_ESM_Channel);
				break;
		case 16:
				/** - DMA MPU Violation error Test */
				DMA_MPU();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(DMA_MPU_ESM_Channel);
				break;
		case 17:
				/** - FTU MPU Violation error Test */
				FTU_MPU();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(FTU_MPU_ESM_Channel);
				break;
		case 18:
				/** - HTU MPU Violation error Test */
				//HTU_MPU();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(HETTU_MPU_ESM_Channel);
				break;
		case 19:
				/** - Flash Single Bit Error detection Test */
				ATCM_Correctable_Error();
				/** - Check for corresponding ESM channel error */
				esmCheckstatus(ATCM_correctable_error_ESM_Channel);
				break;
	}

}	
/** @fn void esmClearErrPin(void)
*   @brief function clears the ESM error pin 
*/
void esmClearErrPin(void)
{
	/** - clear only when the error PIN are set	  	*/
	if(!esmREG->EPSTATUS)					

	/** - clear the error using Error Key Register  */	
	esmREG->KEY  	= 0x5;			

	/** - Wait till the error pin is reset		 	*/
 	while(!esmREG->EPSTATUS);
 	
 	sciSend_32bitdata(scilinREG, 1U);		
}

/** @fn esmCheckstatus(unsigned int channel)
 *  @breif Check ESM channel status 
 *   
 */
void esmCheckstatus(unsigned int channel)
{

	if(esmREG->ESTATUS1[0] == (1 << channel))
	{
		/** - Clear the corresponding channel Group 1 ESM  error */
		esmREG->ESTATUS1[0] =  (1 << channel);
		
		sciSend_32bitdata(scilinREG, PASS);
	}
	else if(esmREG->ESTATUS1[1] == (1 << channel)) // For CCMR4 compare
	{
		/** - Clear the corresponding channel Group 2 ESM  error */
		esmREG->ESTATUS1[1] = (1 << channel);
		
		sciSend_32bitdata(scilinREG, PASS);
	} 
	else
	{
		sciSend_32bitdata(scilinREG, FAIL);
	}

}
