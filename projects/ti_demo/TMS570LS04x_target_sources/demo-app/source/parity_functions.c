#include "can.h"
#include "mibspi.h"
#include "adc.h"

#define canMEM1 0xFF1E0000U
#define canMEM2 0xFF1C0000U
#define canMEM3 0xFF1A0000U
#define adcMEM1 0xFF3E0000U
#define adcMEM2 0xFF3A0000U

extern void adcStartConversion_selChn(adcBASE_t *adc, unsigned channel, unsigned fifo_size, unsigned group);
extern void adcGetSingleData(adcBASE_t *adc, unsigned group, adcData_t *data);

/** @struct spiRamBase
*   @brief SPI Buffer RAM Definition
*
*   This structure is used to access the SPI buffer memory.
*/
/** @typedef spiRAM_t
*   @brief SPI RAM Type Definition
*
*   This type is used to access the SPI RAM.
*/
typedef volatile struct spiRamBase
{
    struct 
    {
        unsigned short control;  /**< tx buffer control */
        unsigned short data;     /**< tx buffer data */
    } tx[128];
    struct
    {
        unsigned short flags;    /**< rx buffer flags */
        unsigned short data;     /**< rx buffer data */
    } rx[128];
} spiRAM_t;


/** @def spiRAM1
*   @brief SPI1 Buffer RAM Pointer
*
*   This pointer is used by the SPI driver to access the spi buffer memory.
*/
#define spiRAM1 ((spiRAM_t *)0xFF0E0000U)


/** @def spiRAM3
*   @brief SPI3 Buffer RAM Pointer
*
*   This pointer is used by the SPI driver to access the spi buffer memory.
*/
#define spiRAM3 ((spiRAM_t *)0xFF0C0000U)


/** @def spiRAM5
*   @brief SPI5 Buffer RAM Pointer
*
*   This pointer is used by the SPI driver to access the spi buffer memory.
*/
#define spiRAM5 ((spiRAM_t *)0xFF0A0000U)




/** @fn void DCAN1_Parity(void)
*   @brief DCAN 1 Parity Error creation and check routines.
*/

void DCAN1_Parity(void)
{
	unsigned int *mailbox;

	/** - Fill MailBox data with 0 */
	canREG1->IF1DATx[0] = 0;
	canREG1->IF1DATx[1] = 0;
	canREG1->IF1DATx[2] = 0;
	canREG1->IF1DATx[3] = 0;
	canREG1->IF1DATx[4] = 0;
	canREG1->IF1DATx[5] = 0;
	canREG1->IF1DATx[6] = 0;
	canREG1->IF1DATx[7] = 0;

	/** - Initialize Command Registers and select Message Number 1 */
	canREG1->IF1CMD 	= 0xFF;
	canREG1->IF1NO 		= 1;
		
	/** - wait for Busy Flag to set, IF[1] contents will be moved to Mailbox 1 */ 	
	while((canREG1->IF1STAT & 0x80) == 0x80);

	/** - Disable Parity PMD = 0x5 */
	canREG1->CTL  |= 0x00001400;

	/** - Enable Test Mode */
	canREG1->CTL |= 0x80;

	/** - Enable Direct Access to DCAN RAM */
	canREG1->TEST |= 0x200;

	/** - Corrupt Mail Box1 data locations to generate Parity Error */
	mailbox  = (unsigned int*)(canMEM1+ 0x20);
	*mailbox = *mailbox | 1;

	/** - Disable Direct access to DCAN RAM */
	canREG1->TEST &= 0xFFFFFDFF;

	/** - Enter Init Mode and Disable Test Mode and Enable Parity*/
	canREG1->CTL &= 0xFFFFEB7E;

	/** - Configure the Transfer direction to be from the 
	 *	  message object 1 to the IF1 Register and start the read  */
	canREG1->IF1CMD 	= 0x7F;
	canREG1->IF1NO = 1;

	/** - wait for Busy Flag to set, Mailbox[1] contents will be moved to IF[1] */ 	
	while((canREG1->IF1STAT & 0x80) == 0x80);

	/* Wait for the DCAN Parity Error Bit to get set */
	while((canREG1->ES & 0x100) != 0x100); 
	
}

/** @fn void DCAN2_Parity(void)
*   @brief DCAN 2 Parity Error creation and check routines.
*/

void DCAN2_Parity(void)
{
	unsigned int *mailbox;

	/** - Fill MailBox data with 0 */
	canREG2->IF1DATx[0] = 0;
	canREG2->IF1DATx[1] = 0;
	canREG2->IF1DATx[2] = 0;
	canREG2->IF1DATx[3] = 0;
	canREG2->IF1DATx[4] = 0;
	canREG2->IF1DATx[5] = 0;
	canREG2->IF1DATx[6] = 0;
	canREG2->IF1DATx[7] = 0;

	/** - Initialize Command Registers and select Message Number 1 */
	canREG2->IF1CMD 	= 0xFF;
	canREG2->IF1NO 		= 1;
		
	/** - wait for Busy Flag to set, IF[1] contents will be moved to Mailbox 1 */ 	
	while((canREG2->IF1STAT & 0x80) == 0x80);

	/** - Disable Parity PMD = 0x5 */
	canREG2->CTL  |= 0x00001400;

	/** - Enable Test Mode */
	canREG2->CTL |= 0x80;

	/** - Enable Direct Access to DCAN RAM */
	canREG2->TEST |= 0x200;

	/** - Corrupt Mail Box1 data locations to generate Parity Error */
	mailbox  = (unsigned int*)(canMEM2+ 0x20);
	*mailbox = *mailbox | 1;

	/** - Disable Direct access to DCAN RAM */
	canREG2->TEST &= 0xFFFFFDFF;

	/** - Enter Init Mode and Disable Test Mode and Enable Parity*/
	canREG2->CTL &= 0xFFFFEB7E;

	/** - Configure the Transfer direction to be from the 
	 *	  message object 1 to the IF1 Register and start the read  */
	canREG2->IF1CMD 	= 0x7F;
	canREG2->IF1NO = 1;

	/** - wait for Busy Flag to set, Mailbox[1] contents will be moved to IF[1] */ 	
	while((canREG2->IF1STAT & 0x80) == 0x80);

	/* Wait for the DCAN Parity Error Bit to get set */
	while((canREG2->ES & 0x100) != 0x100); 
	
}


/** @fn void MIBSPI1_Parity(void)
*   @brief MIBSPI 1 RAM Parity Error creation and check routines.
*/
void MIBSPI1_Parity(void)
{
	unsigned short data[8]= {0x1234,0x2345,0x3456,0x4567,0x5678,0x6789,0x789A,0x89AB};
	unsigned char  *TXRamParity  = (unsigned char *)(mibspiRAM1) + 0x400;

    /** - Initialize MIBSPI Module */
	mibspiInit();
    
    /** - Initialize Data Buffer */
	mibspiSetData(mibspiREG1, 0, data);
	
	/** - Memory Map parity bits */ 
	mibspiREG1->PTESTEN = 1;
	
	/** - Disable paritt error detection logic */
 	mibspiREG1->EDEN = 0x5;
 	
 	/** - Introduce Parity Error by flipping one bit in TXRAM parity */
 	TXRamParity++;
 	TXRamParity++;
 	*TXRamParity = ~(*TXRamParity);
 	
 	/** - Enable paritt error detection logic */
 	mibspiREG1->EDEN = 0xA;
	
	/** - Remove Memory Map of parity bits */
	mibspiREG1->PTESTEN = 0;

	/** - Trigger the transfer group0, since Parity is corrupted Parity 
	 * error will be triggered */
	mibspiTransfer(mibspiREG1, 0);

    asm("	nop");
    asm("	nop");
    asm("	nop");

    /** Reset SPI once Test is complete */
    mibspiREG1->GCR0 = 0U;
	
			
}


/** @fn void MIBADC2_Parity(void)
*   @brief MIBADC 2 Parity Error creation and check routines.
*/
void MIBADC2_Parity(void)
{
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;

	unsigned int *temp;

 	/** - Start Group1 ADC Conversion */
	adcInit();

 	/** - Start Group1 ADC Conversion */
	adcStartConversion_selChn(adcREG1, 1, 1, adcGROUP1);

 	/** - Wait for ADC conversion to complete */
 	while(!adcIsConversionComplete(adcREG1, adcGROUP1));

	/** - Stop ADC Conversion  */
 	adcStopConversion(adcREG1, adcGROUP1);
 	
 	/** - Enable parity and Memory Map Parity Bits */
    adcREG1->PARCR = 0x0000000AU | 0x00000100U;
    
    /** - Enable RAM test Mode */
    adcREG1->OPMODECR |= 0x00010000;

    /** - Flip one bit in the ADC data in ADC RAM before reading
    *	  to create a Parity error while reading 
    */
    temp = (unsigned int *)adcMEM2;
    *temp = 0xFFF;
    temp = temp + 0x400;
    *temp ^= 0x000001;
   
    /** - Enable RAM test Mode */
    adcREG1->OPMODECR &= 0xFFFEFFFF;
    
    /** - Enable parity and Undo Memory Map Parity Bits */
    adcREG1->PARCR = 0x0000000AU;
     
	/** - Read the conversion result
    *	  Must generate an Error Since a Parity error is introduced
    */
	adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
	temp = (unsigned int *)adcMEM2;
	adc_data.value=*temp;

	/** - Disable parity and Memory Map Parity Bits */
    adcREG1->PARCR = 0x00000005U | 0x00000100U;
}

/** @fn void MIBADC1_Parity(void)
*   @brief MIBADC 1 Parity Error creation and check routines.
*/
void MIBADC1_Parity(void)
{
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;

	unsigned int *temp;

 	/** - Start Group1 ADC Conversion */
	adcInit();

 	/** - Start Group1 ADC Conversion */
	adcStartConversion_selChn(adcREG1, 1, 1, adcGROUP1);

 	/** - Wait for ADC conversion to complete */
 	while(!adcIsConversionComplete(adcREG1, adcGROUP1));

	/** - Stop ADC Conversion  */
 	adcStopConversion(adcREG1, adcGROUP1); 	
 	
 	/** - Enable parity and Memory Map Parity Bits */
    adcREG1->PARCR = 0x0000000AU | 0x00000100U;
    
    /** - Enable RAM test Mode */
    adcREG1->OPMODECR |= 0x00010000;

    /** - Flip one bit in the ADC data in ADC RAM before reading
    *	  to create a Parity error while reading 
    */
    temp = (unsigned int *)adcMEM1;
    *temp = 0xFFF;
    temp = temp + 0x400;
    *temp ^= 0x000001;
   
    /** - Enable RAM test Mode */
    adcREG1->OPMODECR &= 0xFFFEFFFF;
    
    /** - Enable parity and Undo Memory Map Parity Bits */
    adcREG1->PARCR = 0x0000000AU;    
     
	/** - Read the conversion result
    *	  Must generate an Error Since a Parity error is introduced
    */
	adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);

	temp = (unsigned int *)adcMEM1;
	adc_data.value=*temp;
	/** - Disable parity and Memory Map Parity Bits */
    adcREG1->PARCR = 0x00000005U | 0x00000100U;
}
