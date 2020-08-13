typedef unsigned long int uint32_t;

// CPU regs for switchting between ram and flash
#define BMMCR (*((volatile uint32_t *) 0xFFFFFFC4))
#define BMMCR_SET_FLASH_EXEC 0xA
#define BMMCR_SET_RAM_EXEC 0x5
#define CPURSTCR ((volatile uint32_t *) 0xFFFFFFCC)
#define CPU_RESET() (*CPURSTCR ^= 0x1)
#define DELAY 1000000
typedef volatile struct gioBase
{
    uint32_t GCR0;      /**< 0x0000: Global Control Register */
    uint32_t rsvd;    /**< 0x0004: Reserved*/
    uint32_t INTDET;    /**< 0x0008: Interrupt Detect Register*/
    uint32_t POL;       /**< 0x000C: Interrupt Polarity Register */
    uint32_t ENASET;    /**< 0x0010: Interrupt Enable Set Register */
    uint32_t ENACLR;    /**< 0x0014: Interrupt Enable Clear Register */
    uint32_t LVLSET;    /**< 0x0018: Interrupt Priority Set Register */
    uint32_t LVLCLR;    /**< 0x001C: Interrupt Priority Clear Register */
    uint32_t FLG;       /**< 0x0020: Interrupt Flag Register */
    uint32_t OFF1;      /**< 0x0024: Interrupt Offset A Register */
    uint32_t OFF2;      /**< 0x0028: Interrupt Offset B Register */
    uint32_t EMU1;      /**< 0x002C: Emulation 1 Register */
	uint32_t EMU2;      /**< 0x0030: Emulation 2 Register */
} gioBASE_t;

#define gioREG ((gioBASE_t *)0xFFF7BC00U)

typedef volatile struct gioPort
{
    uint32_t DIR;    /**< 0x0000: Data Direction Register */
    uint32_t DIN;    /**< 0x0004: Data Input Register */
    uint32_t DOUT;   /**< 0x0008: Data Output Register */
    uint32_t DSET;   /**< 0x000C: Data Output Set Register */
    uint32_t DCLR;   /**< 0x0010: Data Output Clear Register */
    uint32_t PDR;    /**< 0x0014: Open Drain Register */
    uint32_t PULDIS; /**< 0x0018: Pullup Disable Register */
    uint32_t PSL;    /**< 0x001C: Pull Up/Down Selection Register */
} gioPORT_t;

#define gioPORTA ((gioPORT_t *)0xFFF7BC34U)


int main() {
	/** bring GIO module out of reset */
	gioREG->GCR0   = 1U;
	gioREG->ENACLR = 0xFFU;
	gioREG->LVLCLR = 0xFFU;

	/** @b initialize @b Port @b A */

	/** - Port A output values */
	gioPORTA->DOUT = (uint32_t)((uint32_t)0U << 0U)  /* Bit 0 */
	| (uint32_t)((uint32_t)0U << 1U)  /* Bit 1 */
	| (uint32_t)((uint32_t)0U << 2U)  /* Bit 2 */
	| (uint32_t)((uint32_t)0U << 3U)  /* Bit 3 */
	| (uint32_t)((uint32_t)0U << 4U)  /* Bit 4 */
	| (uint32_t)((uint32_t)0U << 5U)  /* Bit 5 */
	| (uint32_t)((uint32_t)0U << 6U)  /* Bit 6 */
	| (uint32_t)((uint32_t)0U << 7U); /* Bit 7 */

	/** - Port A direction */
	gioPORTA->DIR  = (uint32_t)((uint32_t)0U << 0U)  /* Bit 0 */
	| (uint32_t)((uint32_t)0U << 1U)  /* Bit 1 */
	| (uint32_t)((uint32_t)1U << 2U)  /* Bit 2 */
	| (uint32_t)((uint32_t)0U << 3U)  /* Bit 3 */
	| (uint32_t)((uint32_t)0U << 4U)  /* Bit 4 */
	| (uint32_t)((uint32_t)0U << 5U)  /* Bit 5 */
	| (uint32_t)((uint32_t)0U << 6U)  /* Bit 6 */
	| (uint32_t)((uint32_t)0U << 7U); /* Bit 7 */

	/** - Port A open drain enable */
	gioPORTA->PDR  = (uint32_t)((uint32_t)0U << 0U)  /* Bit 0 */
	| (uint32_t)((uint32_t)0U << 1U)  /* Bit 1 */
	| (uint32_t)((uint32_t)0U << 2U)  /* Bit 2 */
	| (uint32_t)((uint32_t)0U << 3U)  /* Bit 3 */
	| (uint32_t)((uint32_t)0U << 4U)  /* Bit 4 */
	| (uint32_t)((uint32_t)0U << 5U)  /* Bit 5 */
	| (uint32_t)((uint32_t)0U << 6U)  /* Bit 6 */
	| (uint32_t)((uint32_t)0U << 7U); /* Bit 7 */

	/** - Port A pullup / pulldown selection */
	gioPORTA->PSL  = (uint32_t)((uint32_t)0U << 0U)  /* Bit 0 */
	| (uint32_t)((uint32_t)0U << 1U)  /* Bit 1 */
	| (uint32_t)((uint32_t)0U << 2U)  /* Bit 2 */
	| (uint32_t)((uint32_t)0U << 3U)  /* Bit 3 */
	| (uint32_t)((uint32_t)0U << 4U)  /* Bit 4 */
	| (uint32_t)((uint32_t)0U << 5U)  /* Bit 5 */
	| (uint32_t)((uint32_t)0U << 6U)  /* Bit 6 */
	| (uint32_t)((uint32_t)0U << 7U); /* Bit 7 */

	/** - Port A pullup / pulldown enable*/
	gioPORTA->PULDIS  = (uint32_t)((uint32_t)0U << 0U)  /* Bit 0 */
	| (uint32_t)((uint32_t)0U << 1U)  /* Bit 1 */
	| (uint32_t)((uint32_t)0U << 2U)  /* Bit 2 */
	| (uint32_t)((uint32_t)0U << 3U)  /* Bit 3 */
	| (uint32_t)((uint32_t)0U << 4U)  /* Bit 4 */
	| (uint32_t)((uint32_t)0U << 5U)  /* Bit 5 */
	| (uint32_t)((uint32_t)0U << 6U)  /* Bit 6 */
	| (uint32_t)((uint32_t)0U << 7U); /* Bit 7 */

		volatile gioPORT_t * port = gioPORTA;
		uint32_t bit = 2;

	while (1) {
		if ((port->DIN & (uint32_t)((uint32_t)1U << bit)) != 0U)
		{
			port->DCLR = (uint32_t)1U << bit;
		}
		else
		{
			port->DSET = (uint32_t)1U << bit;
		}
		for (volatile int j = 0; j < DELAY; j++);

	}


	BMMCR = BMMCR_SET_FLASH_EXEC;
	CPU_RESET();
	while(1);

	return 1;
}
