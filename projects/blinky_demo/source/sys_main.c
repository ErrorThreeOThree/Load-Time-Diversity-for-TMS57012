/** @file sys_main.c 
*   @brief Application main file
*   @date 15.Mar.2012
*   @version 03.01.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* (c) Texas Instruments 2009-2012, All rights reserved. */

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"
#include "system.h"

/* USER CODE BEGIN (1) */
#include "sci.h"
#include "adc.h"
#include "het.h"
#include "can.h"
#include "spi.h"
#include "sci.h"
#include "rti.h"
#include "stc.h"
#include "esm.h"
#include "esm_demo.h"
#include "swi_util.h"
#include "tms_types.h"


/* Global IP Address */
unsigned int GlobalIP;

/* SCI Variables */
unsigned char receive_command[12];
unsigned int Task_Number;
unsigned int SubTask_Number;
unsigned int task_data;

/* Acyl calibration */
unsigned int acyl_zero[3];
double acyl_zeroV[3];

/* External Demo Functions */
extern void run_LED_StartUp(void);
extern void Running_LED_demo(void);
extern void Running_Light_Balance(void);
extern void Digital_Level(void);
extern void Maze_Game(void);
extern void get_software_Version(void);
extern void get_hardware_Info(void);
extern void pbist_test(void);
extern void Ambient_Light_Sensor_demo(void);
extern void Temp_Sensor_demo(void);
extern Int16 emac_mii_test(void); 
extern void SDC_alert(int input);
extern void CAN_Demo();

/* External Support Functions */
extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);
extern void adcStartConversion_selChn(adcBASE_t *adc, unsigned channel, unsigned fifo_size, unsigned group);
extern void adcGetSingleData(adcBASE_t *adc, unsigned group, adcData_t *data);


void delay(void) {
	  static volatile unsigned int delayval;
	  delayval = 10000;   // 100000 are about 10ms
	  while(delayval--);
}

void small_delay(void) {
	  static volatile unsigned int delayval;
	  delayval = 10;
	  while(delayval--);
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




uint8_t		emacAddress[6] 	= 	{0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
uint32_t 	emacPhyAddress	=	0;

void main(void)
{
/* USER CODE BEGIN (3) */
	/** - Call RUN LED routine during the startup, signal PROC ready */

	/** - Configure GIO for LED demo Software */
	gioInit();

	run_LED_StartUp();
	
	/** - Enable IRQ and FIQ interrupt in Cortex R4 */
	swi_enable_fiq_irq();
	
	/** - Initialize SCI Routines to receive Command and transmit data */
	sciInit();
	
	/** - Configure SCI to receive 8 bytes of Command information */
	sciReceive(scilinREG, 12, receive_command);

	/** - Configure NHET for PWM application */
	hetInit();
	
	/** - Configure ADC to perform Temprature and Ambient Light Demo */
	adcInit();
	

	
	/** - Configure ESM module to capture esm errors on Error Pin */
	esmInit();
	esmClearErrPin();
	
	/** - Configure CAN1 for reader application */
	//canInit();
	canInit();
	
	/** - Configure MibSPI3 for SD card application */
	spiInit();
	esmClearErrPin();


	/** Turn off all PWM channels */
	hetREG1->DIR = 0x000000100;
	hetREG1->DCLR = 0x000000100;
	pwmStop(hetRAM1,0);
	
	/** - Clear the Task Number */
	Task_Number = 0;
	SubTask_Number = 0;
	
	while(1)
	{
		switch(Task_Number)
		{
			case 1:
				/** Get Software Version */
				get_software_Version();
				
				/** Reset the Task Number */
				Task_Number = 0;
				break;
				
			case 2:
				/** Get Hardware Informations */
				get_hardware_Info();
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break;
				
			case 3:
				/** Run Pbist Test */
				pbist_test();
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break;
				
			case 4:
				/** Run STC Test */
				stc_test();
				
				/** Enable IRQ and FIQ interrupt in Cortex R4 
				*   After STC test all Core registers have to be reinitialized */
				swi_enable_fiq_irq();
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break;
				
			case 5:
				/** Run ESM Test */
				esm_test();
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break;
				
			case 6:
				/** Clear ESM pin if set */
				esmClearErrPin();
				
				/** Respond Back to PC with 0x00000001 */
				sciSend_32bitdata(scilinREG, 1);
				
				/** Reset the Task Number */
				Task_Number = 0;
				break;
				
			case 7:
				/** Perform Temprature Sensor Demo */
				Temp_Sensor_demo();
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break; 
			 				
			case 8:
				/** Perform Ambient Light Sensor Demo */
				Ambient_Light_Sensor_demo();
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break;
				
			case 9:
				/** Perform LED Demo */
				Running_LED_demo();
				
				/** Respond Back to PC with 0x00000001 */
				sciSend_32bitdata(scilinREG, 1);
				
				/** Reset the Task Number */  				
				Task_Number = 0;
				break;

			case 10:
				/** Test SD Card */
				//SDC_alert(SDC_init());
				
				/** Reset the Task Number */
				Task_Number = 0;
				break;
				
			case 11:
                /* Run Loopback test and report result */
				//EMAC_Webserver_demo();
				/** Reset the Task Number */
				Task_Number = 0;
				break;
			case 12:
                /* Run OHCI and W2FC communication test and report result */
/*				if (!OHCI_W2FC_LoopBack())
					sciSend_32bitdata(scilinREG, 1U);
				else
					sciSend_32bitdata(scilinREG, 0U);
*/
				/** Reset the Task Number */
				Task_Number = 0;
				break;

			case 13:
  				/** Perform DCAN1, and DCAN2 external loopback Test */
                //canExtLoopTest(); //located in can12_loopback.c
  							
				/** Reset the Task Number */
				Task_Number = 0;
				break;
	
		/** - Configure EMIF for Sync and Async test */
		    case 14:
				//EMIF_Test();

				/** Reset the Task Number */
				Task_Number = 0;
				break;

		/** - Test main connectors */
		    case 15:
/*                if (!ExpConn_Test())
 					sciSend_32bitdata(scilinREG, 1U);
				else
					sciSend_32bitdata(scilinREG, 0U);
*/
 				/** Reset the Task Number */
				Task_Number = 0;
				break;
			case 16:
				Running_Light_Balance();
				break;
			case 17:
				CAN_Demo();
				Task_Number = 0;
				break;
			case 18:
				Digital_Level();
				Task_Number = 0;
				break;
			case 19:
				Maze_Game();
				Task_Number = 0;
				break;
		}
	}
	/* USER CODE END */
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
