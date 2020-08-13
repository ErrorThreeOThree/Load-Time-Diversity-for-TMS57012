ENTRY(main)

MEMORY
{
  RAM (xrw)       : ORIGIN = 0x00000004, LENGTH = 0x000076DF
  STACK (rw)      : ORIGIN = 0x000077FF, LENGTH = 0x00000800 /* Stack is configured in sys_core.asm */
  FLASH  (rx)     : ORIGIN = 0x08008020, LENGTH = 0x00057FE0

}

SECTIONS
{
	.text :
	{
      . = ALIGN(4);
	  KEEP (*(.init))
      KEEP (*(.text) )          /* .text sections (code) */
      KEEP (*(.text*))          /* .text* sections (code) */
      KEEP (*(.glue_7) )        /* glue arm to thumb code */
      KEEP (*(.glue_7t) )       /* glue thumb to arm code */
      KEEP (*(.eh_frame))


      . = ALIGN(4);
	} > RAM

	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
	}

	.data :
	{
		. = ALIGN(4);
		*(.data)
		*(.data*)
	} > RAM

}
