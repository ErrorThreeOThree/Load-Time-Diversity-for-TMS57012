/** @file sys_pcr.c
*   @brief PCR Driver Implementation File
*   @date 15.Aug.2012
*   @version 03.02.00
*
*/
/* (c) Texas Instruments 2009-2012, All rights reserved. */

#include "sys_pcr.h"

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void peripheral_Frame_Protection_Set(peripheral_Frame_t peripheral_Frame);
*   @brief Set the peripheral protection of the selected frame 
*   @param[in] Peripheral frame to be protected
*
*   This function sets the protection for the selected frame.
*/
void peripheral_Frame_Protection_Set(peripheral_Frame_t peripheral_Frame)
{

/* USER CODE BEGIN (2) */
/* USER CODE END */

	uint8_t chip_select_grp;
	uint32_t Quarant_selct;

	chip_select_grp = (peripheral_Frame.Peripheral_CS >> 3);
	Quarant_selct  = (uint32_t)(peripheral_Frame.Peripheral_Quadrant << ((peripheral_Frame.Peripheral_CS & 7) << 2));

    if (chip_select_grp >= 3)
    {
        pcrREG->PPROTSET3 = Quarant_selct;
    }
    else if (chip_select_grp >= 2)
    {
        pcrREG->PPROTSET2 = Quarant_selct;
    }
    else if (chip_select_grp >= 1)
    {
        pcrREG->PPROTSET1 = Quarant_selct;
    }
	else
    {
        pcrREG->PPROTSET0 = Quarant_selct;
    }
	
/* USER CODE BEGIN (3) */
/* USER CODE END */
}

/* USER CODE BEGIN (4) */
/* USER CODE END */

/** @fn void peripheral_Frame_Protection_Clr(peripheral_Frame_t peripheral_Frame)
*   @brief Clear the peripheral protection of the selected frame 
*   @param[in] Peripheral frame to be out of protection
*
*   This function clears the protection set for the selected frame.
*/
void peripheral_Frame_Protection_Clr(peripheral_Frame_t peripheral_Frame)
{

/* USER CODE BEGIN (5) */
/* USER CODE END */

	uint8_t chip_select_grp;
	uint32_t Quarant_selct;

	chip_select_grp = (peripheral_Frame.Peripheral_CS >> 3);
	Quarant_selct  = (uint32_t)(peripheral_Frame.Peripheral_Quadrant << ((peripheral_Frame.Peripheral_CS & 7) << 2));

    if (chip_select_grp >= 3)
    {
        pcrREG->PPROTCLR3 = Quarant_selct;
    }
    else if (chip_select_grp >= 2)
    {
        pcrREG->PPROTCLR2 = Quarant_selct;
    }
    else if (chip_select_grp >= 1)
    {
        pcrREG->PPROTCLR1 = Quarant_selct;
    }
	else
    {
        pcrREG->PPROTCLR0 = Quarant_selct;
    }
	
/* USER CODE BEGIN (6) */
/* USER CODE END */
}

/* USER CODE BEGIN (7) */
/* USER CODE END */

/** @fn void peripheral_Frame_Powerdown_Set(peripheral_Frame_t peripheral_Frame)
*   @brief Take the selected peripheral to powerdown
*   @param[in] Peripheral frame to be taken to powerdown
*
*   This function will set the selected peripheral frame to powerdown.
*/
void peripheral_Frame_Powerdown_Set(peripheral_Frame_t peripheral_Frame)
{

/* USER CODE BEGIN (8) */
/* USER CODE END */

	uint8_t chip_select_grp;
	uint32_t Quarant_selct;

	chip_select_grp = (peripheral_Frame.Peripheral_CS >> 3);
	Quarant_selct  = (uint32_t)(peripheral_Frame.Peripheral_Quadrant << ((peripheral_Frame.Peripheral_CS & 7) << 2));
	
    if (chip_select_grp >= 3)
    {
        pcrREG->PSPWRDWNSET3 = Quarant_selct;
    }
    else if (chip_select_grp >= 2)
    {
        pcrREG->PSPWRDWNSET2 = Quarant_selct;
    }
    else if (chip_select_grp >= 1)
    {
        pcrREG->PSPWRDWNSET1 = Quarant_selct;
    }
	else
    {
        pcrREG->PSPWRDWNSET0 = Quarant_selct;
    }
	
/* USER CODE BEGIN (9) */
/* USER CODE END */
}

/* USER CODE BEGIN (10) */
/* USER CODE END */

/** @fn void peripheral_Frame_Powerdown_Clr(peripheral_Frame_t peripheral_Frame)
*   @brief Bring the selected peripheral frame out of powerdown
*   @param[in] Peripheral frame to be taken out of powerdown
*
*   This function will bring the selected peripheral frame out of powerdown.
*/
void peripheral_Frame_Powerdown_Clr(peripheral_Frame_t peripheral_Frame)
{

/* USER CODE BEGIN (11) */
/* USER CODE END */

	uint8_t chip_select_grp;
	uint32_t Quarant_selct;

	chip_select_grp = (peripheral_Frame.Peripheral_CS >> 3);
	Quarant_selct  = (uint32_t)(peripheral_Frame.Peripheral_Quadrant << ((peripheral_Frame.Peripheral_CS & 7) << 2));
	
    if (chip_select_grp >= 3)
    {
        pcrREG->PSPWRDWNCLR3 = Quarant_selct;
    }
    else if (chip_select_grp >= 2)
    {
        pcrREG->PSPWRDWNCLR2 = Quarant_selct;
    }
    else if (chip_select_grp >= 1)
    {
        pcrREG->PSPWRDWNCLR1 = Quarant_selct;
    }
	else
    {
        pcrREG->PSPWRDWNCLR0 = Quarant_selct;
    }
/* USER CODE BEGIN (12) */
/* USER CODE END */
}

/* USER CODE BEGIN (13) */
/* USER CODE END */

/** @fn void peripheral_Memory_Frame_Protection_Set(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
*   @brief Set the peripheral memory protection of the selected frame 
*   @param[in] Peripheral memory frame to be protected
*
*   This function sets the protection for the selected peripheral memory frame.
*/
void peripheral_Memory_Frame_Protection_Set(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
{

/* USER CODE BEGIN (14) */
/* USER CODE END */

	uint8_t chip_select_grp;

	chip_select_grp = (peripheral_Memory_Frame_CS >> 5);

	if (chip_select_grp >= 1)
    {
        pcrREG->PMPROTSET1 = (1U << (peripheral_Memory_Frame_CS & 0xF));
    }
	else
    {
        pcrREG->PMPROTSET0 = (1U << peripheral_Memory_Frame_CS);
    }
	
/* USER CODE BEGIN (15) */
/* USER CODE END */
}

/* USER CODE BEGIN (16) */
/* USER CODE END */

/** @fn void peripheral_Memory_Frame_Protection_Clr(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
*   @brief Clear the peripheral memory protection of the selected frame 
*   @param[in] Peripheral memory frame to be cleared from protection
*
*   This function clears the protection set for the selected peripheral memory frame.
*/
void peripheral_Memory_Frame_Protection_Clr(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
{

/* USER CODE BEGIN (17) */
/* USER CODE END */

	uint8_t chip_select_grp;

	chip_select_grp = (peripheral_Memory_Frame_CS >> 5);

	if (chip_select_grp >= 1)
    {
        pcrREG->PMPROTCLR1 = (1U << (peripheral_Memory_Frame_CS & 0xF));
    }
	else
    {
        pcrREG->PMPROTCLR0 = (1U << peripheral_Memory_Frame_CS);
    }

/* USER CODE BEGIN (18) */
/* USER CODE END */
}

/* USER CODE BEGIN (19) */
/* USER CODE END */

/** @fn void peripheral_Memory_Frame_Powerdown_Set(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
*   @brief Take the selected peripheral memory frame to powerdown
*   @param[in] Peripheral memory frame to be taken to powerdown
*
*   This function will set the selected peripheral memory frame to powerdown.
*/
void peripheral_Memory_Frame_Powerdown_Set(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
{

/* USER CODE BEGIN (20) */
/* USER CODE END */

	uint8_t chip_select_grp;

	chip_select_grp = (peripheral_Memory_Frame_CS >> 5);

	if (chip_select_grp >= 1)
    {
        pcrREG->PSPWRDWNSET1 = (1U << (peripheral_Memory_Frame_CS & 0xF));
    }
	else
    {
        pcrREG->PSPWRDWNSET0 = (1U << peripheral_Memory_Frame_CS);
    }
	
/* USER CODE BEGIN (21) */
/* USER CODE END */
}

/* USER CODE BEGIN (22) */
/* USER CODE END */

/** @fn void peripheral_Memory_Frame_Powerdown_Clr(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
*   @brief Bring the selected peripheral Memory frame out of powerdown
*   @param[in] Peripheral memory frame to be taken out of powerdown
*
*   This function will bring the selected peripheral memory frame out of powerdown.
*/
void peripheral_Memory_Frame_Powerdown_Clr(peripheral_MemoryFrame_CS peripheral_Memory_Frame_CS)
{

/* USER CODE BEGIN (23) */
/* USER CODE END */

	uint8_t chip_select_grp;

	chip_select_grp = (peripheral_Memory_Frame_CS >> 5);

	if (chip_select_grp >= 1)
    {
        pcrREG->PSPWRDWNCLR1 = (1U << (peripheral_Memory_Frame_CS & 0xF));
    }
	else
    {
        pcrREG->PSPWRDWNCLR0 = (1U << peripheral_Memory_Frame_CS);
    }
	
/* USER CODE BEGIN (24) */
/* USER CODE END */
}

/* USER CODE BEGIN (25) */
/* USER CODE END */

/** @fn void peripheral_Protection_Set(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
*   @brief Set the peripheral protection of all the selected frames 
*   @param[in] All Peripheral frames to be protected
*
*   This function sets the protection for all the selected frames.
*/
void peripheral_Protection_Set(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
{

/* USER CODE BEGIN (26) */
/* USER CODE END */

    pcrREG->PPROTSET0 = peripheral_Quad_CS.Peripheral_Quad0_3_CS0_7;
    pcrREG->PPROTSET1 = peripheral_Quad_CS.Peripheral_Quad4_7_CS8_15;
    pcrREG->PPROTSET2 = peripheral_Quad_CS.Peripheral_Quad8_11_CS16_23;
    pcrREG->PPROTSET3 = peripheral_Quad_CS.Peripheral_Quad12_15_CS24_31;
	
/* USER CODE BEGIN (27) */
/* USER CODE END */
}

/* USER CODE BEGIN (28) */
/* USER CODE END */

/** @fn void peripheral_Protection_Clr(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
*   @brief Clear the peripheral protection of all the selected frames 
*   @param[in] All Peripheral frames to be out of protection.
*
*   This function clears the protection set for all the selected frame.
*/
void peripheral_Protection_Clr(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
{

/* USER CODE BEGIN (29) */
/* USER CODE END */

    pcrREG->PPROTCLR0 = peripheral_Quad_CS.Peripheral_Quad0_3_CS0_7;
    pcrREG->PPROTCLR1 = peripheral_Quad_CS.Peripheral_Quad4_7_CS8_15;
    pcrREG->PPROTCLR2 = peripheral_Quad_CS.Peripheral_Quad8_11_CS16_23;
    pcrREG->PPROTCLR3 = peripheral_Quad_CS.Peripheral_Quad12_15_CS24_31;

/* USER CODE BEGIN (30) */
/* USER CODE END */
}

/* USER CODE BEGIN (31) */
/* USER CODE END */

/** @fn void peripheral_Powerdown_Set(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
*   @brief Take all the selected peripheral memory frame to powerdown
*   @param[in] Peripheral memory frames to be taken to powerdown
*
*   This function will set all the selected peripheral memory frame to powerdown.
*/
void peripheral_Powerdown_Set(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
{

/* USER CODE BEGIN (32) */
/* USER CODE END */

    pcrREG->PSPWRDWNSET0 = peripheral_Quad_CS.Peripheral_Quad0_3_CS0_7;
    pcrREG->PSPWRDWNSET1 = peripheral_Quad_CS.Peripheral_Quad4_7_CS8_15;
    pcrREG->PSPWRDWNSET2 = peripheral_Quad_CS.Peripheral_Quad8_11_CS16_23;
    pcrREG->PSPWRDWNSET3 = peripheral_Quad_CS.Peripheral_Quad12_15_CS24_31;

/* USER CODE BEGIN (33) */
/* USER CODE END */
}

/* USER CODE BEGIN (34) */
/* USER CODE END */

/** @fn void peripheral_Powerdown_Clr(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
*   @brief Bring all the selected peripheral Memory frame out of powerdown
*   @param[in] Peripheral memory frames to be taken out of powerdown
*
*   This function will bring all the selected peripheral memory frame out of powerdown.
*/
void peripheral_Powerdown_Clr(peripheral_Quad_ChipSelect_t peripheral_Quad_CS)
{

/* USER CODE BEGIN (35) */
/* USER CODE END */

    pcrREG->PSPWRDWNCLR0 = peripheral_Quad_CS.Peripheral_Quad0_3_CS0_7;
    pcrREG->PSPWRDWNCLR1 = peripheral_Quad_CS.Peripheral_Quad4_7_CS8_15;
    pcrREG->PSPWRDWNCLR2 = peripheral_Quad_CS.Peripheral_Quad8_11_CS16_23;
    pcrREG->PSPWRDWNCLR3 = peripheral_Quad_CS.Peripheral_Quad12_15_CS24_31;

/* USER CODE BEGIN (36) */
/* USER CODE END */
}

/* USER CODE BEGIN (37) */
/* USER CODE END */

/** @fn void peripheral_Memory_Protection_Set(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
*   @brief Set the peripheral memory protection of all the selected frame 
*   @param[in] Peripheral memory frames to be protected
*
*   This function sets the protection for all the selected peripheral memory frame.
*/
void peripheral_Memory_Protection_Set(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
{

/* USER CODE BEGIN (38) */
/* USER CODE END */

    pcrREG->PMPROTSET0 = peripheral_Memory_CS.Peripheral_Mem_CS0_31;
    pcrREG->PMPROTSET1 = peripheral_Memory_CS.Peripheral_Mem_CS32_63;

/* USER CODE BEGIN (39) */
/* USER CODE END */
}

/* USER CODE BEGIN (40) */
/* USER CODE END */

/** @fn void peripheral_Memory_Protection_Clr(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
*   @brief Clear the peripheral memory protection of all the selected frame 
*   @param[in] Peripheral memory frames to be cleared from protection
*
*   This function clears the protection set for all the selected peripheral memory frame.
*/
void peripheral_Memory_Protection_Clr(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
{

/* USER CODE BEGIN (41) */
/* USER CODE END */

    pcrREG->PMPROTCLR0 = peripheral_Memory_CS.Peripheral_Mem_CS0_31;
    pcrREG->PMPROTCLR1 = peripheral_Memory_CS.Peripheral_Mem_CS32_63;

/* USER CODE BEGIN (42) */
/* USER CODE END */
}

/* USER CODE BEGIN (43) */
/* USER CODE END */

/** @fn void peripheral_Memory_Powerdown_Set(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
*   @brief Take all the selected peripheral memory frame to powerdown
*   @param[in] Peripheral memory frames to be taken to powerdown
*
*   This function will set all the selected peripheral memory frame to powerdown.
*/
void peripheral_Memory_Powerdown_Set(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
{

/* USER CODE BEGIN (44) */
/* USER CODE END */

    pcrREG->PSPWRDWNSET0 = peripheral_Memory_CS.Peripheral_Mem_CS0_31;
    pcrREG->PSPWRDWNSET1 = peripheral_Memory_CS.Peripheral_Mem_CS32_63;
	
/* USER CODE BEGIN (45) */
/* USER CODE END */
}

/* USER CODE BEGIN (46) */
/* USER CODE END */

/** @fn void peripheral_Memory_Powerdown_Clr(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
*   @brief Bring all the selected peripheral Memory frame out of powerdown
*   @param[in] Peripheral memory frames to be taken out of powerdown
*
*   This function will bring all the selected peripheral memory frame out of powerdown.
*/
void peripheral_Memory_Powerdown_Clr(peripheral_Memory_ChipSelect_t peripheral_Memory_CS)
{

/* USER CODE BEGIN (47) */
/* USER CODE END */

    pcrREG->PSPWRDWNCLR0 = peripheral_Memory_CS.Peripheral_Mem_CS0_31;
    pcrREG->PSPWRDWNCLR1 = peripheral_Memory_CS.Peripheral_Mem_CS32_63;

/* USER CODE BEGIN (48) */
/* USER CODE END */
}

/* USER CODE BEGIN (49) */
/* USER CODE END */
