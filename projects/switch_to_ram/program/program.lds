ENTRY(main)

MEMORY
{
  FLASH  (rx)     : ORIGIN = 0x08008020, LENGTH = 0x00057FE0
  CPU_STACK (rw)  : ORIGIN = 0x08000000, LENGTH = 0x00000800 /* Stack is configured in sys_core.asm */
  KRAM (xrw)      : ORIGIN = 0x08000800, LENGTH = 0x00000800
  RAM (xrw)       : ORIGIN = 0x00000000, LENGTH = (0x00007800 - 0x00000800)
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
