/*----------------------------------------------------------------------------*/
/* sys_link.ld                                                              */
/*                                                                            */
/* (c) Texas Instruments 2009-2014, All rights reserved.                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/* Entry Point */
ENTRY(_c_int00)

/* Highest address of the stack */
_estack = 0x8008000;    /* end of 32K RAM */

/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0x400;      /* required amount of heap  */

/* Specify the memory areas */
MEMORY
{
  VECTORS   (rx)     : ORIGIN = 0x00000000, LENGTH = 0x00000020
  FLASH     (rx)     : ORIGIN = 0x00000020, LENGTH = 0x00057FE0
  CPU_EXEC	(xrw)    : ORIGIN = 0x08000000, LENGTH = 0x00000800
  CPU_STACK (rw)     : ORIGIN = 0x08000800, LENGTH = 0x00000800 /* Stack is configured in sys_core.asm */
  RAM       (xrw)    : ORIGIN = (0x08000800 + 0x00000800), LENGTH = (0x00007800 - 0x00000800)
}

/* Define output sections */
SECTIONS
{
  /* The ISR vector goes first into RAM */
  .intvecs :
  {
    . = ALIGN(4);
    KEEP(loader.o(.intvecs)) /* ISR vector */
    . = ALIGN(4);
  } >VECTORS

  .rawdata :
  {
  } >FLASH

  /* The program code and other data goes into RAM */
  .text :
  {
    . = ALIGN(4);

/*
    PROVIDE(_user_code_begin = .);
    KEEP (user.o(.rawdata*))
    KEEP (user.o(.rawdata))
    PROVIDE(_user_code_end = .);
    ASSERT(_user_code_end - _user_code_begin, "Linker dropped user program");
*/
    loader.o(.text)           /* .text sections (code) */
    loader.o(.text*)          /* .text* sections (code) */
    loader.o(.glue_7)         /* glue arm to thumb code */
    loader.o(.glue_7t)        /* glue thumb to arm code */
    loader.o(.eh_frame)

    KEEP (loader.o(.init))
    KEEP (loader.o(.fini))

    KEEP (loader.o(.init))
    KEEP (loader.o(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
  } >FLASH


  /* Constant data goes into RAM */
  .rodata :
  {
    . = ALIGN(4);
    PROVIDE(_user_code_begin = .);
    user.o(.rawdata*)
    user.o(.rawdata)
    PROVIDE(_user_code_end = .);
    ASSERT(_user_code_end - _user_code_begin, "Linker dropped user program");

    loader.o(.rodata)         /* .rodata sections (constants, strings, etc.) */
    loader.o(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
  } >FLASH



   .ARM.extab   : { loader.o(.ARM.extab* .gnu.linkonce.armextab.*) } >RAM
    .ARM : {
    __exidx_start = .;
      loader.o(.ARM.exidx*)
      __exidx_end = .;
    } >FLASH

  .preinit_array     :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (loader.o(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >FLASH
  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (loader.o(SORT(.init_array.*)))
    KEEP (loader.o(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >FLASH
  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (loader.o(SORT(.fini_array.*)))
    KEEP (loader.o(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >FLASH

  /* used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data :
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    loader.o(.data)           /* .data sections */
    loader.o(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */
  } >RAM AT> FLASH


  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data :
  {
    . = ALIGN(4);
    _ksdata = .;        /* create a global symbol at data start */
    loader.o(.data)           /* .data sections */
    loader.o(.data*)          /* .data* sections */

    . = ALIGN(4);
    _kedata = .;        /* define a global symbol at data end */
  } >RAM AT> FLASH


  /* Uninitialized data section */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    loader.o(.bss)
    loader.o(.bss*)
    loader.o(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM

  PROVIDE ( end = _ebss );
  PROVIDE ( _end = _ebss );

  .ARM.attributes 0 : { loader.o(.ARM.attributes) }
}
