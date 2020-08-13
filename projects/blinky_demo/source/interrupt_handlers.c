#include "sci.h"
#include "adc.h"
#include "can.h"
#include "het.h"
#include "gio.h"
#include "spi.h"
#include "mibspi.h"
#include "esm.h"

extern unsigned char receive_command[12];
extern unsigned int Task_Number;
extern unsigned int SubTask_Number;
extern unsigned int task_data;

void EMACCore0TxIsr(void);
void EMACCore0RxIsr(void);

/** @fn void sciNotification(unsigned flags) */
void sciNotification(sciBASE_t *sci, unsigned flags)
{
	/** Check for the Valid Command 
	 * 	* - Starter 
	 *  ! - End of Command 
	 */
	if(receive_command[0] == '*' && receive_command[11] == '!')
	{	
		/** - 4th and 5th byte received are Task Number, 
		 * combine them to form one decimal Number */
		Task_Number =  (unsigned int)(((receive_command[3] - 48) * 10) + (receive_command[4] - 48));

		/** - 6th and 7th byte received are Sub Task Number, 
		 * combine them to form one decimal Number */
		SubTask_Number =  (unsigned int)(((receive_command[5] - 48) * 10) + (receive_command[6] - 48));
		
		/** - 7th and 8th byte recieved ar data which can be used by demo 
		 * combine then to form a decimal number*/
		task_data      =  (unsigned int)(((receive_command[7] - 48) * 10) + (receive_command[8] - 48));
		task_data      =  (task_data<<8)|((unsigned int)(((receive_command[9] - 48) * 10) + (receive_command[10] - 48)));
		
		/** - Get ready to receive the next Command */
		sciReceive	(scilinREG, 12, receive_command);
		
		/** - Acknowledge once the Valid Command is received */
		sciSend		(scilinREG, 8, (unsigned char *) "*VALID#!");
	}
	else
	{
		/** - Get ready to receive the next Command */
		sciReceive	(scilinREG, 12, receive_command);
		/** - Acknowledge once the InValid Command is received */
		sciSend		(scilinREG, 8, (unsigned char *) "WHO R U?");
	}
}

/* ADC interrupt notification */
void adcNotification(adcBASE_t *adc, unsigned group)
{
	return;
}

/* Pwm interrupt notification (Not used but must be provided) */
void        pwmNotification(hetBASE_t * hetREG,uint32_t pwm, uint32_t notification)
{
    return;
}

/* Edge interrupt notification (Not used but must be provided) */
void edgeNotification(hetBASE_t * hetREG,uint32_t edge)
{
	return;
}

/* GIO interrupt notification (Not used but must be provided) */
void gioNotification(int bit)
{
	/*used only in case of corona launchpad*/
	/*set task number 9 and task number 7 so as to toggle the LED connected to GIO on pressing the user button connected to GIO7*/
	if(7 == bit)
	{
	Task_Number =  9;
    SubTask_Number =  7;
	}
	return;
}

/* SPI interrupt notification (Not used but must be provided) */
void spiNotification(spiBASE_t *spi, unsigned flags)
{
	return;
}

/* SPI interrupt notification (Not used but must be provided) */
void spiGroupNotification(spiBASE_t *spi, unsigned group)
{
	return;
}

/* CAN Error notification */
void canErrorNotification(canBASE_t *node, unsigned notification)
{
	return;
}

/* CAN Message Notification */
void canMessageNotification(canBASE_t *node, unsigned messageBox)
{
	return;
}

void memoryPort0TestFailNotification(void)
{
	return;
}

void memoryPort1TestFailNotification(void)
{
	return;
}

void rtiNotification(unsigned notification)
{
	return;
}
void mibspiNotification(mibspiBASE_t *mibspi, uint32_t flags)
{
	
}

void mibspiGroupNotification(mibspiBASE_t *mibspi, uint32_t group)
{
	
}

void esmGroup1Notification(uint32_t channel)
{
}
void esmGroup2Notification(uint32_t channel)
{
}

