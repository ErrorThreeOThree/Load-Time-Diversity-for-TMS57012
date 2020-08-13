
ENTRY(_c_int00)

MEMORY
{
	VECTORS (RWX) : ORIGIN = 0x00000000, LENGTH = 0x00000020
	FLASH  (rx)   : ORIGIN = 0x00000020, LENGTH = 0x0013FFE0
	RAM (xrw)     : ORIGIN = 0x08000000, LENGTH = 0x0002EB00
	STACK (rw)    : ORIGIN = 0x0802EB00, LENGTH = 0x00001500 /* Stack is configured in sys_core.asm */
}

SECTIONS
{
	.intvecs : {} > VECTORS

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
	} > FLASH

	_sidata = LOADADDR(.data);

	/* Initialized data sections goes into RAM, load LMA copy after code */
	.data :
	{
		. = ALIGN(4);
		_sdata = .;        /* create a global symbol at data start */

		. = ALIGN(4);
		_edata = .;        /* define a global symbol at data end */
	} >RAM AT> FLASH


	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
    	. = ALIGN(4);
		*(.rodata_div_data)
    	. = ALIGN(4);
		*(.rodata*)
    	. = ALIGN(4);
    	KEEP(*(.user_text))
	} > FLASH


	/* Uninitialized data section */
	. = ALIGN(4);
	.bss :
	{
		/* This is used by the startup in order to initialize the .bss secion */
		_sbss = .;         /* define a global symbol at bss start */
		__bss_start__ = _sbss;

		. = ALIGN(4);
		_ebss = .;         /* define a global symbol at bss end */
		__bss_end__ = _ebss;
	} >RAM

}
