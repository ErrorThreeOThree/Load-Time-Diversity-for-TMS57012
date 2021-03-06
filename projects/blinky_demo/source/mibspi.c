/** @file mibspi.c 
*   @brief MIBSPI Driver Implementation File
*   @date 15.Mar.2012
*   @version 03.01.00
*
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */

#include "mibspi.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void mibspiInit(void)
*   @brief Initializes the MIBSPI Driver
*
*   This function initializes the MIBSPI module.
*/
void mibspiInit(void)
{
int i ;

/* USER CODE BEGIN (2) */
/* USER CODE END */

    
    /** @b intalise @b MIBSPI1 */

    /** bring MIBSPI out of reset */
    mibspiREG1->GCR0 = 1U;
	
    /** enable MIBSPI RAM Parity */
    mibspiREG1->EDEN = 0x00000005U;
	
    /** enable MIBSPI1 multibuffered mode and enable buffer RAM */
    mibspiREG1->MIBSPIE = 1U;

    /** MIBSPI1 master mode and clock configuration */
    mibspiREG1->GCR1 = (1 << 1)  /* CLOKMOD */
                  | 1;  /* MASTER */

    /** MIBSPI1 enable pin configuration */
    mibspiREG1->ENAHIGHZ = 0;  /* ENABLE HIGHZ */

    /** - Delays */
    mibspiREG1->DELAY = (0 << 24)  /* C2TDELAY */
                   | (0 << 16)  /* T2CDELAY */
                   | (0 << 8)  /* T2EDELAY */
                   | 0;  /* C2EDELAY */

    /** - Data Format 0 */
    mibspiREG1->FMT0 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (79 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 1 */
    mibspiREG1->FMT1 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (79 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 2 */
    mibspiREG1->FMT2 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (79 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 3 */
    mibspiREG1->FMT3 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (79 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - wait for buffer inialisation complete before accessing MibSPI registers */
    while ((mibspiREG1->BUFINIT) != 0) { /* wait */ } 

    /** - inialise transfer groups */
    mibspiREG1->TGCTRL[0] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (0 << 8);  /* start buffer */

    mibspiREG1->TGCTRL[1] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (8 << 8);  /* start buffer */

    mibspiREG1->TGCTRL[2] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0) << 8);  /* start buffer */

    mibspiREG1->TGCTRL[3] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0) << 8);  /* start buffer */

    mibspiREG1->TGCTRL[4] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0) << 8);  /* start buffer */

    mibspiREG1->TGCTRL[5] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0+0) << 8);  /* start buffer */

    mibspiREG1->TGCTRL[6] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0+0+0) << 8);  /* start buffer */

    mibspiREG1->TGCTRL[7] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0+0+0+0) << 8);  /* start buffer */

    
    mibspiREG1->TGCTRL[8] = 8+0+0+0+0+0+0+0 << 8;

    mibspiREG1->LTGPEND = 8+0+0+0+0+0+0+0-1;

    /** - initialize buffer ram */
    {   
        i = 0;
        if (8 > 0)
        {
            while (i < 8-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_0;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_0;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_1;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_1;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_2;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_2;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0+0+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0+0+0+0-1)
            {
                mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            mibspiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
    }

    /** - set interrupt levels */
    mibspiREG1->LVL = (0 << 9)  /* TXINT */
                 | (0 << 8)  /* RXINT */
                 | (0 << 6)  /* OVRNINT */
                 | (0 << 4)  /* BITERR */
                 | (0 << 3)  /* DESYNC */
                 | (0 << 2)  /* PARERR */
                 | (0 << 1) /* TIMEOUT */
                 | (0);  /* DLENERR */

    /** - clear any pending interrupts */
    mibspiREG1->FLG = 0xFFFFU;

    /** - enable interrupts */
    mibspiREG1->INT0 = (0 << 9)  /* TXINT */
                  | (0 << 8)  /* RXINT */
                  | (0 << 6)  /* OVRNINT */
                  | (0 << 4)  /* BITERR */
                  | (0 << 3)  /* DESYNC */
                  | (0 << 2)  /* PARERR */
                  | (0 << 1) /* TIMEOUT */
                  | (0);  /* DLENERR */

    /** @b initialize @b MIBSPI1 @b Port */

    /** - MIBSPI1 Port output values */
    mibspiREG1->PCDOUT =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11) /* SOMI */
	 | (0 << 4)  
	 | (0 << 5) 
	 | (0 << 25) 
	 | (0 << 17); 

    /** - MIBSPI1 Port direction */
    mibspiREG1->PCDIR  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (1 << 2)  /* SCS[2] */
                    | (1 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (0 << 11) /* SOMI */
	 | (1 << 4)  
	 | (1 << 5) 
 	| (0 << 25) 
	 | (0 << 17); 
    /** - MIBSPI1 Port open drain enable */
    mibspiREG1->PCPDR  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11) /* SOMI */
	 | (0 << 4)  
	 | (0 << 5) 
	 | (0 << 25) 
	 | (0 << 17) ;

    /** - MIBSPI1 Port pullup / pulldown selection */
    mibspiREG1->PCPSL  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (1 << 2)  /* SCS[2] */
                    | (1 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11) /* SOMI */
 	| (1 << 4)  
	 | (1 << 5) 
	 | (1 << 25) 
	 | (1 << 17) ;
    /** - MIBSPI1 Port pullup / pulldown enable*/
    mibspiREG1->PCDIS  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11) /* SOMI */
 	| (0 << 4)  
	 | (0 << 5) 
	 | (0 << 25) 
	| (0 << 17) ;

    /* MIBSPI1 set all pins to functional */
    mibspiREG1->PCFUN  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (1 << 2)  /* SCS[2] */
                    | (1 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11) /* SOMI */
	 | (1 << 4)  
 	| (1 << 5) 
 	| (1 << 25) 
 	| (1 << 17); 

    /** - Finaly start MIBSPI1 */
    mibspiREG1->ENA = 1U;




/* USER CODE BEGIN (3) */
/* USER CODE END */

}


/** @fn void mibspiSetFunctional(mibspiBASE_t *mibspi, uint32_t port)
*   @brief Change functional behaviour of pins at runtime.
*   @param[in] mibspi   - mibspi module base address
*   @param[in] port  - Value to write to PCFUN register
*
*   Change the value of the PCFUN register at runtime, this allows to
*   dynaimcaly change the functionality of the MIBSPI pins between functional
*   and GIO mode.
*/
void mibspiSetFunctional(mibspiBASE_t *mibspi, uint32_t port)
{
/* USER CODE BEGIN (4) */
/* USER CODE END */

    mibspi->PCFUN = port;

/* USER CODE BEGIN (5) */
/* USER CODE END */
}


/** @fn void mibspiSetData(mibspiBASE_t *mibspi, uint32_t group, uint16_t data[])
*   @brief Set Buffer Data
*   @param[in] mibspi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*   @param[in] data  - new data for transfer group
*
*   This function updates the data for the specified transfer group,
*   the length of the data must match the length of the transfer group.
*/
void mibspiSetData(mibspiBASE_t *mibspi, uint32_t group, uint16_t data[])
{
/* USER CODE BEGIN (6) */
/* USER CODE END */

    mibspiRAM_t *ram    = mibspiRAM1 ;
    uint32_t start  = (mibspi->TGCTRL[group] >> 8) & 0xFF;
    uint32_t end    = group == 7 ? (mibspi->LTGPEND + 1) : (mibspi->TGCTRL[group+1] >> 8) & 0xFF;

    if (end < start) {end = 128;}

    while (start < end)
    {
        ram->tx[start].data = *data++;
        start++;
    }
/* USER CODE BEGIN (7) */
/* USER CODE END */
}


/** @fn void mibspiGetData(mibspiBASE_t *mibspi, uint32_t group, uint16_t data[])
*   @brief Retrieves Buffer Data fro receive buffer
*   @param[in]  mibspi   - Spi module base address
*   @param[in]  group - Transfer group (0..7)
*   @param[out] data  - pointer to data array
*
*   @return error flags from data buffer, if there was a receive error on
*           one of the buffers this will be rerflected in the return value.
*
*   This function transfers the data from the specified transfer group receve
*   buffers to the data array,  the length of the data must match the length 
*   of the transfer group.
*/
uint32_t mibspiGetData(mibspiBASE_t *mibspi, uint32_t group, uint16_t data[])
{
/* USER CODE BEGIN (8) */
/* USER CODE END */

    mibspiRAM_t *ram    =  mibspiRAM1 ;
    uint32_t start  = (mibspi->TGCTRL[group] >> 8) & 0xFF;
    uint32_t end    = group == 7 ? (mibspi->LTGPEND + 1) : (mibspi->TGCTRL[group+1] >> 8) & 0xFF;
    uint32_t flags  = 0;

    if (end < start) {end = 128;}

    while (start < end)
    {
        flags  |= ram->rx[start].flags;
        *data++ = ram->rx[start].data;
        start++;
    }

/* USER CODE BEGIN (9) */
/* USER CODE END */

    return (flags >> 8) & 0x5F;
}


/** @fn void mibspiTransfer(mibspiBASE_t *mibspi, uint32_t group)
*   @brief Transmit Transfer Group
*   @param[in] mibspi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*
*   Initiates a transfer for the specified transfer group.
*/
void mibspiTransfer(mibspiBASE_t *mibspi, uint32_t group)
{
/* USER CODE BEGIN (10) */
/* USER CODE END */

    mibspi->TGCTRL[group] |= 0x80000000;

/* USER CODE BEGIN (11) */
/* USER CODE END */
}


/** @fn int mibspiIsTransferComplete(mibspiBASE_t *mibspi, uint32_t group)
*   @brief Check for Transfer Group Ready
*   @param[in] mibspi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*
*   @return 1 is transfer complete, otherwise 0.
*
*   Checks to see if the transfer for the specified transfer group
*   has finished.
*/
int mibspiIsTransferComplete(mibspiBASE_t *mibspi, uint32_t group)
{
/* USER CODE BEGIN (12) */
/* USER CODE END */
    return (mibspi->INTFLGRDY >> group) & 1;
}


/** @fn void mibspiEnableLoopback(mibspiBASE_t *mibspi, Loopbacktype_t Loopbacktype)
*   @brief Enable Loopback mode for self test
*   @param[in] mibspi        - Mibspi module base address
*   @param[in] Loopbacktype  - Digital or Analog
*
*   This function enables the Loopback mode for self test.
*/
void mibspiEnableLoopback(mibspiBASE_t *mibspi, Loopbacktype_t Loopbacktype)
{
/* USER CODE BEGIN (13) */
/* USER CODE END */
    
	/* Clear Loopback incase enabled already */
	mibspi->IOLPKTSTCR = 0;
	
	/* Enable Loopback either in Analog or Digital Mode */
    mibspi->IOLPKTSTCR = 0x00000A00
					   | Loopbacktype << 1;
	
/* USER CODE BEGIN (14) */
/* USER CODE END */
}

/** @fn void mibspiDisableLoopback(mibspiBASE_t *mibspi)
*   @brief Enable Loopback mode for self test
*   @param[in] mibspi        - Mibspi module base address
*
*   This function disable the Loopback mode.
*/
void mibspiDisableLoopback(mibspiBASE_t *mibspi)
{
/* USER CODE BEGIN (15) */
/* USER CODE END */
    
	/* Disable Loopback Mode */
    mibspi->IOLPKTSTCR = 0x000005000;
	
/* USER CODE BEGIN (16) */
/* USER CODE END */
}


/** @fn void mibspiEnableGroupNotification(mibspiBASE_t *mibspi, uint32_t group, uint32_t level)
*   @brief Enable Transfer Group interrupt
*   @param[in] mibspi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*   @param[in] level - Interrupt level
*
*   This function enables the transfer group finished interrupt.
*/
void mibspiEnableGroupNotification(mibspiBASE_t *mibspi, uint32_t group, uint32_t level)
{
/* USER CODE BEGIN (17) */
/* USER CODE END */

    if (level != 0)
    {
        mibspi->SETINTLVLRDY = 1 << group;
    }
    else
    {
        mibspi->CLRINTLVLRDY = 1 << group;
    }
    mibspi->SETINTENARDY = 1 << group;

/* USER CODE BEGIN (18) */
/* USER CODE END */
}


/** @fn void mibspiDisableGroupNotification(mibspiBASE_t *mibspi, uint32_t group)
*   @brief Disable Transfer Group interrupt
*   @param[in] mibspi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*
*   This function disables the transfer group finished interrupt.
*/
void mibspiDisableGroupNotification(mibspiBASE_t *mibspi, uint32_t group)
{
/* USER CODE BEGIN (19) */
/* USER CODE END */

    mibspi->CLRINTENARDY = 1 << group;

/* USER CODE BEGIN (20) */
/* USER CODE END */
}



