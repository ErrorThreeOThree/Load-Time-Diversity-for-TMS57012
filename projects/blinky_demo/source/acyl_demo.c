/** @file accl.c 
*   @brief accelerometer implementation File
*   @date 11.August.2009
*   @version 1.00.000
*
*/
#include "math.h"
#include "gio.h"
#include "adc.h"
#include "sci.h"

#define Accl_X			 		18U
#define Accl_Y			 		17U
#define Accl_Z			 		16U

extern unsigned int 	SubTask_Number;
extern unsigned int 	Task_Number;
extern unsigned int 	acyl_zero[3];
extern double 			acyl_zeroV[3];

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);
extern void adcStartConversion_selChn(adcBASE_t *adc, unsigned channel, unsigned fifo_size, unsigned group);
extern void adcGetSingleData(adcBASE_t *adc, unsigned group, adcData_t *data);

/** @fn void Digital_Level(void)
*   
*   This function uses the accelerometer to calcualte
*   the angle of tilt of the development board.
*	Requires calibration to be ran initialy
*/
void Digital_Level(void)
{
	/* Variable and associated pointer to hold ADC data */
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;
	double theta, voltage, delta, gs;

	switch(SubTask_Number)
	{
		/* Calibration subroutine */
		case 0:
			/* start ADC conversion */
			adcStartConversion_selChn(adcREG1, 2U, 1, adcGROUP1);
			/* Wait for converison to complete */
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			/* Pull data from ADC */
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			/* Set voltage offset in global holder */
			acyl_zeroV[0] = adc_data_ptr->value * 0.000805;
			
			/* start ADC conversion */
			adcStartConversion_selChn(adcREG1, 1U, 1, adcGROUP1);
			/* Wait for converison to complete */
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			/* Pull data from ADC */
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			/* Set voltage offset in global holder */
			acyl_zeroV[1] = adc_data_ptr->value * 0.000805;
			
			/* Send calibration confirmation */
			sciSend_32bitdata(scilinREG, 1U);
			
			break;
			
		case 1:			
			/* start ADC conversion */
			adcStartConversion_selChn(adcREG1, 2U, 1, adcGROUP1);
			/* Wait for converison to complete */
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
		
			/* Pull data from ADC */
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			
			/* Convert reading to units of G
			 * utilizes calibration data offset */
			voltage = (double) adc_data_ptr->value * .000805;
			delta = acyl_zeroV[0] - voltage;
			gs = delta / 0.3;
			
			/* Sanity check for value of G */
			if(gs > 1) gs = 1;
			if(gs < -1) gs = -1;
			
			/* Trig functiont to cacluate tilt
			 * acos returns radians, converted to degrees */
			theta = acos(gs) * 57.2957;
			
			/* Send first data block */
			sciSend_32bitdata(scilinREG, (unsigned int) theta);
	
	
	
			/* start ADC conversion */
			adcStartConversion_selChn(adcREG1, 1U, 1, adcGROUP1);
			/* Wait for converison to complete */
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			
			/* Pull data from ADC */
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			
			/* Convert reading to units of G
			 * utilizes calibration data offset */
			voltage = (double) adc_data_ptr->value * .000805;
			delta = acyl_zeroV[1] - voltage;
			gs = delta / 0.3;
			
			/* Sanity check for value of G */
			if(gs > 1) gs = 1;
			if(gs < -1) gs = -1;
			
			/* Trig functiont to cacluate tilt
			 * acos returns radians, converted to degrees */
			theta = acos(gs) * 57.2957;
			
			/* Send first data block */
			sciSend_32bitdata(scilinREG, (unsigned int) theta);
			
			break;
	}
}


/** @fn void Maze_Game(void)
*   
*   This function finds a simple direction of the board's tilt
*   
*/
void Maze_Game(void)
{
	/* Variable and associated pointer to hold ADC data */
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;
	unsigned int x_val, y_val;
			
	switch(SubTask_Number)
	{
		case 0:
			adcStartConversion_selChn(adcREG1, 1U, 1, adcGROUP1);
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			acyl_zero[0] = adc_data_ptr->value;
			
			adcStartConversion_selChn(adcREG1, 2U, 1, adcGROUP1);
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			acyl_zero[1] = adc_data_ptr->value;
			
			sciSend_32bitdata(scilinREG, 1U);
			break;
		
		case 1:
			adcStartConversion_selChn(adcREG1, 1U, 1, adcGROUP1);
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			y_val = adc_data_ptr->value;
			
			adcStartConversion_selChn(adcREG1, 2U, 1, adcGROUP1);
			while(!adcIsConversionComplete(adcREG1, adcGROUP1));
			adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
			x_val = adc_data_ptr->value;
			
			if( y_val < (acyl_zero[0] - 200) )
			{
				sciSend		(scilinREG, 8, (unsigned char *) "*0RIGHT!");
				break;
			}
			
			if( y_val > (acyl_zero[0] + 200) )
			{
				sciSend		(scilinREG, 8, (unsigned char *) "*0LEFT0!");
				break;
			}
			
			if( x_val < (acyl_zero[1] - 200) )
			{
				sciSend		(scilinREG, 8, (unsigned char *) "*00UP00!");
				break;
			}
			
			if( x_val > (acyl_zero[1] + 200) )
			{
				sciSend		(scilinREG, 8, (unsigned char *) "*0DOWN0!");
				break;
			}
			
			else
			{
				sciSend		(scilinREG, 8, (unsigned char *) "**0STILL!");
				break;
			}
	}
}
