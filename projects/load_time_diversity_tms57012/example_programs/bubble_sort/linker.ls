ENTRY(_init)
MEMORY
{
  KERNEL_RAM (xr) : ORIGIN = 0x00000000, LENGTH = 0x00000100
  USER_RAM (xrw)  : ORIGIN = 0x00000100, LENGTH = 0x0002EF00
  STACK (rw)      : ORIGIN = 0x0002F000, LENGTH = 0x00001000 /* Stack is configured in address.h */
}

SECTIONS
{
	.kernelTEXT :
	{
		KEEP (*(.ivt))
		KEEP (*(.kernelTEXT))
	} > KERNEL_RAM

	.text :
	{
	  . = ALIGN(0x100);
	  KEEP (*(.init))
      KEEP (*(.text) )          /* .text sections (code) */
      KEEP (*(.text*))          /* .text* sections (code) */
      KEEP (*(.glue_7) )        /* glue arm to thumb code */
      KEEP (*(.glue_7t) )       /* glue thumb to arm code */
      KEEP (*(.eh_frame))


      . = ALIGN(4);
	} > USER_RAM

	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata*)
	} > USER_RAM

	.data :
	{
		. = ALIGN(4);
		*(.data)
		*(.data*)
	} > USER_RAM

}
