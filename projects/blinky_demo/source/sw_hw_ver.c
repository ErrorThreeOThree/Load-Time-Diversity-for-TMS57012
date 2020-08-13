/** @file sw_hw_ver.c 
*   @brief Software and Hardware Information Source File
*   @date 10.August.2009
*   @version 1.00.000
*
*   This file contains:
*   - Funcions that are used to find the Software and the Harware information
*/
/* Include Files */
#include "sys_common.h"
#include "system.h"
#include "sci.h"
/*
#define LOT_NUM 		(*(volatile unsigned int *) 0x06040B4)
#define WAFER_NUM 		(*(volatile unsigned int *) 0x06040B8)
#define DIE_LOC 		(*(volatile unsigned int *) 0x06040BC)
#define PACKAGE_MEM	 	(*(volatile unsigned int *) 0x06040AC)
*/

#define DIE_ID1 		(*(volatile unsigned int *) 0xFFFFE1F0)
#define DIE_ID2 		(*(volatile unsigned int *) 0xFFFFE1F4)
#define DIE_ID3 		(*(volatile unsigned int *) 0xFFFFE1F8)
#define DIE_ID4	 	    (*(volatile unsigned int *) 0xFFFFE1FC)

extern void sciSend_32bitdata(sciBASE_t *sci, unsigned int data);

/** @fn get_software_Version(void)
*   @brief Get the Software Version of the Demo
*/
void get_software_Version(void)
{
	sciSend(scilinREG,8, (unsigned char *)"VER 3.2 ");
}

/** @fn get_hardware_Info(void)
*   @brief Get the Hardware Information of the Micro
*		- Device ID
*  		- LOT Number
*  		- WAFFER Number + DIE Locations ( X & Y)
* 		- Package Type + Flash Memory 
*	@note: The above Hardware informations are stored in the OTP locations	
*/
void get_hardware_Info(void)
{
	unsigned int LOT_NUM, WAFER_LOC_NUM;
	LOT_NUM   =  ((DIE_ID1 & 0xFFC00000) >> 22) | ((DIE_ID2 & 0x00003FFF) << 10);
	WAFER_LOC_NUM = (DIE_ID1 & 0x003FFFFF);
	
	
	sciSend_32bitdata(scilinREG, systemREG1->DEV);
	sciSend_32bitdata(scilinREG, LOT_NUM);
	sciSend_32bitdata(scilinREG,(WAFER_LOC_NUM));
//	sciSend_32bitdata(scilinREG, PACKAGE_MEM);                                // PACAGE(16 bits) + MEMORY(16 bits).
}
