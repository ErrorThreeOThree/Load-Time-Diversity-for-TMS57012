#include "sci.h"
#include "adc.h"

#define Ambient_Light_Sensor 	9U
#define Temperature_Sensor 		8U

/* External Functions */
extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);
extern void adcStartConversion_selChn(adcBASE_t *adc, unsigned channel, unsigned fifo_size, unsigned group);
extern void adcGetSingleData(adcBASE_t *adc, unsigned group, adcData_t *data);

/** @fn void Ambient_Light_Sensor_demo(void)
*   @brief Ambien Light Sensor software
*/
void Ambient_Light_Sensor_demo(void)
{
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;

 	/** - Start Group1 ADC Conversion 
 	*     Select Channel 9 - Ambient Light Sensor for Conversion 
 	*/
	adcStartConversion_selChn(adcREG1, Ambient_Light_Sensor, 1, adcGROUP1);

 	/** - Wait for ADC Group1 conversion to complete */
 	while(!adcIsConversionComplete(adcREG1, adcGROUP1)); 

	/** - Read the conversion result
	*     The data contains the Ambient Light sensor data
    */
	adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
	
	/** - Transnmit the Conversion data to PC using SCI
    */
	sciSend_32bitdata(scilinREG, ((unsigned int) (adc_data_ptr->value)));
}

unsigned int Get_Ambient_Light_Data(void)
{
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;

 	/** - Start Group1 ADC Conversion 
 	*     Select Channel 9 - Ambient Light Sensor for Conversion 
 	*/
	adcStartConversion_selChn(adcREG1, Ambient_Light_Sensor, 1, adcGROUP1);

 	/** - Wait for ADC Group1 conversion to complete */
 	while(!adcIsConversionComplete(adcREG1, adcGROUP1)); 

	/** - Read the conversion result
	*     The data contains the Ambient Light sensor data
    */
	adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
	
	return(adc_data_ptr->value);
}


/** @fn void Temp_Sensor_demo(void)
*   @brief Temprature sensor demo software
*/
void Temp_Sensor_demo(void)
{
	adcData_t adc_data;
	adcData_t *adc_data_ptr = &adc_data;

 	/** - Start Group1 ADC Conversion 
 	*     Select Channel 8 - Temprature Sensor for Conversion 
 	*/
	adcStartConversion_selChn(adcREG1, Temperature_Sensor, 1, adcGROUP1);

 	/** - Wait for ADC Group1 conversion to complete */
 	while(!adcIsConversionComplete(adcREG1, adcGROUP1)); 

	/** - Read the conversion result
	*     The data contains the Temprature sensor data
    */
	adcGetSingleData(adcREG1, adcGROUP1, adc_data_ptr);
	
	/** - Transnmit the Conversion data to PC using SCI
    */
	sciSend_32bitdata(scilinREG, ((unsigned int) (adc_data_ptr->value)));
}
