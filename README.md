# Compiler-Based Load-Time Diversity for Embedded Systems

### by Julian Hartmer

This repository contains files used in my bachelor's thesis "Compiler-Based Load-Time
Diversity for Embedded Systems" handed in on July 5, 2019. In this thesis I propose a new compiler-guided load-time artificial software diversity approach designed for embedded systems, showcase and evaluate a prototype implementation.

Folders:
* [__projects__](projects): This is my Code Composer Studio. Notes for each project can be found in the project's README file. It contains the projects:
  * [__blinky_demo__](projects/blinky_demo): My first LED blinking demo. It is compiled with the TI Compiler.
  * [__eeprom_prng_demo__](projects/eeprom_prng_demo): The demo of the PRNG with the seed stored in the emulated EEPROM (FLASH Bank 7). It uses the TI Compiler.
  * [__entropy__](projects/entropy): This project simulates the prototype's MIS order generation process and evaluates the entropy of the prototype. The executable outputs the data in CSV format to the console. We process the data piped to result2.csv with libre office.
  * [__flash_write_demo__](projects/flash_write_demo): This is the FLASH Write example from HalCoGen.
  * [__keep_in_flash__](projects/keep_in_flash): This unfinished project should showcase the ability to write and execute the user program to FLASH. However, due to compatibility problems with the F021 Library and GCC, this project was abandoned early. It is still in a very early, unfinished status.
  * [__load_time_diversity__](projects/load_time_diversity): This is the prototype project. It analyzes the user program and creates a binary which loads and diversifies the user program writing it to RAM. I provide 5 example user programs. Additional information such as bugs are listed in the README file inside this project.
  * [__rand__](projects/rand): This is the PRNG used in the load_time_diversity project and the entropy simulator.
  * [__shuffle_sim__](projects/shuffle_sim): A small simulator for the MIS reordering algorithm. I used this prototype to test my shuffling algorithm as debugging on the board is very hard and time-consuming.
  * [__switch_to_ram__](projects/switch_to_ram): Similiar to keep_in_flash, this projects showcases the ability to write the user program to RAM and execute it. It only supports my blinky program.
  * [__testBlinky__](projects/testBlinky): Another TI blinky example project.
  * [__ti_demo__](projects/ti_demo): This is the TI advanced LED demo.
