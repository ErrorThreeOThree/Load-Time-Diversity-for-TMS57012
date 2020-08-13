/** @file led_demo.c 
*   @brief led demo implementation File
*   @date 11.August.2009
*   @version 1.00.000
*
*   (c) Texas Instruments 2009, All rights reserved.
*/

#include "het.h"
#include "gio.h"
#include "sci.h"
#include "adc.h"

extern unsigned int 	SubTask_Number;
extern unsigned int 	Task_Number;
extern unsigned int 	task_data;

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);
extern unsigned int Get_Ambient_Light_Data(void);
uint32_t map_led_pins[4] = {2,4,6,3};

	 

/** @fn void Running_LED_demo(void)
*   
*   This function is used for LED demo based on the SCI
*   command different LED's are turned on and a running 
*	LED demo is included
*/
void Running_LED_demo(void)
{
	unsigned led_no,on_off;
	unsigned int temp;		/** - Temporary Variable */
	unsigned int pwm,brightness_level;		/** - Variable to count the width */
	unsigned int count;		/** - Vaiable to toggle the pulse width*/


 	/** - This if statment is a placeholder for ArgoBoard/USBStick check */
	if(1)
	{
		switch(SubTask_Number)
		{

			case 0:
				gioSetPort(gioPORTA,0);
				break;
			case 1:
					pwm = 0;
					count = 0;
					/** - Do the LED Demo Toggle, until another task selected
					 *  - The below loop generates a varying pulse width at
					 *    HET pins[0,2,4,5,15,16,17,18,20,27,29,31]
					 * 	  which helps in blinking LED demo */

					while((Task_Number == 9) && (SubTask_Number ==1))
					{

						/*This turns all the LEDs  off*/
						gioSetPort(gioPORTA,0x5c);

						for(temp=0;temp<pwm;temp++);

						if((pwm == 0x800))
						{
							for(temp=0;temp<0x100000;temp++);
						}
						/** - Clr all GIO port A pins */
						gioSetPort(gioPORTA,0x00);

						for(temp=0;temp<(0x800 - pwm);temp++);

						if((pwm == 0x00))
						{
							for(temp=0;temp<0x100000;temp++);
						}

						if(pwm == 0x800)
						{
							count = 1;

						}
						if(pwm == 0)
						{
							count = 0;
						}

						if(count != 0)
						{
							pwm--;
						}
						else
						{
							pwm++;
						}
					}

					/** - Clear GIO port A pins end of the demo */
					gioSetPort(gioPORTA,0x00);
					break;
			case 2:
					/* set different leds or clear different leds*/
					led_no = (task_data & 0x0000FF00)>>8;
					on_off = (task_data & 0x000000FF);

					gioSetBit(gioPORTA,map_led_pins[led_no],on_off);

					break;

			/*Cases for the corona launchpad*/
			case 3:
					/* set different leds or clear different leds*/
				hetREG1->DIR = 0x000000100;
				gioSetBit(gioPORTA,2, 0);
				hetREG1->DCLR = 0x000000100;
				pwmStop(hetRAM1,0);

					break;
			case 4:
				hetREG1->DIR = 0x00000100;
				pwmStop(hetRAM1,0);
				pwm = 0;
				count = 0;
				/** - Do the LED Demo Toggle, until another task selected
				 *  - The below loop generates a varying pulse width at
				 *    HET pins[0,2,4,5,15,16,17,18,20,27,29,31]
				 * 	  which helps in blinking LED demo */

				while((Task_Number == 9) && (SubTask_Number ==4))
				{

					/*This turns all the LEDs  off*/
					hetREG1->DSET = 0x000000100;
					gioSetBit(gioPORTA,2, 1);

					for(temp=0;temp<pwm;temp++);

					if((pwm == 0x800))
					{
						for(temp=0;temp<0x100000;temp++);
					}
					/** - Clr all leds */
					gioSetBit(gioPORTA,2, 0);
					hetREG1->DCLR = 0x000000100;

					for(temp=0;temp<(0x800 - pwm);temp++);

					if((pwm == 0x00))
					{
						for(temp=0;temp<0x100000;temp++);
					}

					if(pwm == 0x800)
					{
						count = 1;

					}
					if(pwm == 0)
					{
						count = 0;
					}

					if(count != 0)
					{
						pwm--;
					}
					else
					{
						pwm++;
					}
				}

				/** - Clear GIO port A pins end of the demo */
				gioSetBit(gioPORTA,2, 0);
				hetREG1->DCLR = 0x000000100;

			case 5:
					/* set different leds or clear different leds*/
					led_no = (task_data & 0x0000FF00)>>8;
					on_off = (task_data & 0x000000FF);
					pwmStop(hetRAM1,0);

					if(0 == led_no)
					{
						if(0 == on_off)
						{
							gioSetBit(gioPORTA,2,0);
						}
						else
						{
							gioSetBit(gioPORTA,2,1);
						}
					}
					else
					{
						hetREG1->DIR = 0x00000100;
						if(0 == on_off)
						{
							hetREG1->DCLR = 0x000000100;
						}
						else
						{
							hetREG1->DSET = 0x000000100;
						}
					}
					break;

			case 6:
				hetREG1->DIR = 0x00000100;
				pwmStart(hetRAM1,0);
                brightness_level = task_data;
				pwm = (brightness_level*409);
				/* - Set PWM duty cycles as a percent of sensor data */
				pwmSetDuty(hetRAM1,0, ((100*pwm)/0x1000));
				break;

			case 7:
				gioToggleBit(gioPORTA, 2);
				break;

			case 8:
				sciSend_32bitdata(scilinREG,gioGetBit(gioPORTA, 2));
				break;


		}
	}
	
	else
	{
	}
}


/** @fn run_LED_StartUp(void)
*   
*   This function is called during the start up, LED's are turned on 
*   in a sequence to indicate the board is powerd up and ready to run
*   the demo software.  
*   
*/
void run_LED_StartUp(void)
{
   	int temp,delay;
	hetREG1->DIR = 0x000000100;

	/** - Delay Parameter */
	delay				= 0x200000;


	/** - This if statment is a placeholder for ArgoBoard/USBStick check */
	if(1)
	{
		/** - Set only GIOA[2,3] */
		gioSetPort(gioPORTA,0x0c);
		hetREG1->DCLR = 0x000000100;
		/** - Simple Delay */
		for(temp=0;temp<delay;temp++);
		
		/** - Set only GIOA[3,4] */
		gioSetPort(gioPORTA,0x18);
		hetREG1->DSET = 0x000000100;

		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		
		/** - Set only GIOA[4,6] */
		gioSetPort(gioPORTA,0x50);
		hetREG1->DCLR = 0x000000100;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);

		/** - Set only GIOA[6,2] */
		gioSetPort(gioPORTA,0x44);
		hetREG1->DSET = 0x000000100;
		
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);

		/** - Clear all GIO pins */
		gioSetPort(gioPORTA,0x5c);
		hetREG1->DCLR = 0x000000100;
		/** - Simple Dealy */
		for(temp=0;temp<delay;temp++);
		
		/** - Clr all GIO pins */
		gioSetPort(gioPORTA,0x00);
		hetREG1->DCLR = 0x000000100;
		pwmStop(hetRAM1,0);

	}
	
	else
	{
	}
}


/** @fn void Running_Light_Balance(void)
*   
*   This function reads the light sensor data
*   and sets to light PWM to create a facimile
*	of an ambient light reaciton system
*/
void Running_Light_Balance(void)
{
	//unsigned int temp;		/** - Temporary Variable */
	unsigned int pwm, i;		/** - Variable to count the width */
    /** - NHET is configured as Master 
     *  - NHET is turned On */    
   	hetREG1->GCR     	= 0x01000001; 
	
	/** - PULL functinality is enabled */
	hetREG1->PULDIS	= 0x00000000;
	 
	/* - Start all 6 pwm channels */
	for(i=0; i<6; i++){pwmStart(hetRAM1,i);}
	 
	/** - This if statment is a placeholder for ArgoBoard/USBStick check */
	if(1)
	{
   		/** - Configure NHET pins as output 
   		 *  - These pins are connected to the LED's */
   		hetREG1->DIR   	= 0xAA178035; 
   		
		switch(SubTask_Number)
		{
			case 0:
				/* Send current PWM value */
				sciSend_32bitdata(scilinREG, (unsigned int)(0x1000 - Get_Ambient_Light_Data()));
				
				/* Maintain PWM loop while PC responds */
				SubTask_Number = 3;
				break;
				
			case 1:
				/*Send current Light Sensor Data */
				sciSend_32bitdata(scilinREG, Get_Ambient_Light_Data());
				
				/* Maintain PWM loop while PC responds */
				SubTask_Number = 3;
				break;
				
			case 2:
				hetREG1->DIR   	= 0xAA178035;
				hetREG1->DOUT   	= 0x08110034;
				/* turn off all PWMs */
				for(i=0; i<6; i++){pwmStop(hetRAM1,i);}
				/* Reset the task number to reenter main loop */
				Task_Number = 0;
				break;
				
			case 3:
				while((Task_Number == 16) && (SubTask_Number == 3))
				{
					/* Fetch light sensor data */
					pwm = Get_Ambient_Light_Data(); 
					
					/* Invert sensor data for LEDs */
					pwm = 0x1000 - pwm;
					
					/* - Set PWM duty cycles as a percent of sensor data */
					for(i=0; i<6; i++){pwmSetDuty(hetRAM1,i, ((100*pwm)/0x1000));}
				}
				break;	
		}
	}
}

/** @fn void SDC_alert(int input)
*   This function temporarialy turns on
* 	red or green LEDs to report status of
* 	SDC initalization   
*/
void SDC_alert(int input)
{
	int i;
	
	if(input == 1)       /* 1 means PASSED */
	{
		sciSend_32bitdata(scilinREG, 1U);
		hetREG1->DCLR   	= 0x00110000;
		for(i=0; i<0x2000000; i++);
		hetREG1->DSET	= 0x00110000;
		
	}
	else  /* 0 means FAILED */
	{
		sciSend_32bitdata(scilinREG, 0U);
		hetREG1->DCLR   	= 0x00000014;
		for(i=0; i<0x2000000; i++);
		hetREG1->DSET	= 0x00000014;
	}
}
