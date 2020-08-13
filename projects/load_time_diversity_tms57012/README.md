This is the prototype implementation. You can specify the user program source file path in the Makefile.

To build the project, use the Makefile. We provide three different build options:
1. `make` creates the normal memory image. The loader code prepares a new user program variant and switches execution to RAM.
1. `make no_shuffle` forces the loader to load the original user program instead of creating a new variant.
1. `make verify` turns on the loader's verification algorithm: The loader verifies the variant. If verification somehow fails, the loader does not execute the variant.
1. `make clean` cleans up this project.

To build a different user program, change the `USER_PROGRAM_PATH` and `USER_PROGRAM_NAME` values in the Makefile.

To integrate the project into your system, follow the following steps:
1. Install the `arm-none-eabi` GCC cross compiler.
1. Turn on the execution permissions of the shell scripts: `chmod +x *.sh`
1. Change the tool pathes in the Makefile such as the path to the ASM_DIVERSITY scala project, the F021 library (and the header files), the scala execution path.


Bugs:
* The loader is unable to fetch and write the PRNG seed located in the emulated EEPROM (FLASH bank 7). This is probably the case due to the F021 library. The library was originally compiled with TI's own compiler, but we use GCC. To fix this, we can write our own library using the documentation inside the F021 library information PDF.
* We have a bug with the **.bss** section. This section is empty in the user ELF file. Our Makefile copies each section from the ELF file, however the __.bss__ is empty and initialized by the ELF file's startup code. To fix this, our loader has to fetch the initialized values of the __.bss__ section from the ELF file. This could be done with the scripts in this folder.
