# Combines the program files to one assembly file. Compiles the assembly file.
# Analyzes combined file and creates a new combined file + additional binary files.
# Compiles the combined file again, extracting all the important sections.
# Those sections are embedded to the loader, which is then compiled.

EXEC = load_time_diversity.out
# tools

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
READELF = arm-none-eabi-readelf
WORKSPACE_PATH = /home/jh/workspace
SCALAPATH= $(WORKSPACE_PATH)/asm_load_time_diversity/bin
SCALA_EXEC = scala
F021_LIB = loader/source/F021_API_CortexR4_BE.lib
F021_LIB = loader/source/F021_API_CortexR4_BE_V3D16.lib

F021_PATH = /home/jh/F021_Flash_API/02.01.01/include
CG_TOOL_ROOT = /home/jh/ti/ccsv8/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include/

##############
### PATHES ###
##############
# Userprogram source file pathes. Customize to diversify and execute different programs.
#USER_PROGRAM_PATH = example_programs/blinky
#USER_PROGRAM_NAME = blinky

# USER_PROGRAM_PATH = example_programs/sort
# USER_PROGRAM_NAME = sort

# USER_PROGRAM_PATH = example_programs/sieb
# USER_PROGRAM_NAME = sieb

# USER_PROGRAM_PATH = example_programs/haar
# USER_PROGRAM_NAME = haar

USER_PROGRAM_PATH = example_programs/bubble_sort
USER_PROGRAM_NAME = bubble_sort

PROG_SHUFFLESECTIONS = .text
PROG_SECTIONS = .data .rodata .kernelTEXT .bss
PROG_LABEL_MAIN_OFFS = start_mis_offset
USER_PROGRAM_SRC_PATH = $(USER_PROGRAM_PATH)/source
USER_PROGRAM_INCL_PATH = $(USER_PROGRAM_PATH)/include
USER_PROGRAM_LS = $(USER_PROGRAM_PATH)/linker.ls

# Static pathes
## pathes for program work
PROGRAM_BUILD_PATH = program
PROGRAM_PRE_ANA_PATH = $(PROGRAM_BUILD_PATH)/pre_analysis
PROGRAM_PRE_ANA_OBJ_PATH = $(PROGRAM_PRE_ANA_PATH)/obj
PROGRAM_POST_ANA_PATH = $(PROGRAM_BUILD_PATH)/post_analysis
PROGRAM_POST_ANA_OBJ_PATH = $(PROGRAM_POST_ANA_PATH)/obj
PROGRAM_ANA_PATH = $(PROGRAM_BUILD_PATH)/analysis
PROGRAM_WRAPPER_PATH = $(PROGRAM_BUILD_PATH)/obj_wrapper
PROGRAM_OUTPUT_OBJ_PATH = $(PROGRAM_BUILD_PATH)/objs
PROGRAM_POST_ANA_DEBUG = $(PROGRAM_POST_ANA_PATH)/debug
PROGRAM_ANA_DEBUG = $(PROGRAM_ANA_PATH)/debug

## loader compile pathes
LOADER_PATH = loader
LOADER_SRC_PATH = $(LOADER_PATH)/source
LOADER_SRC_MANUAL_PATH = $(LOADER_PATH)/source_manual
LOADER_INCL_PATH = $(LOADER_PATH)/include
LOADER_INCL_MANUAL_PATH = $(LOADER_PATH)/include_manual

# source files
USER_PROGRAM_SRCS_C = $(wildcard $(USER_PROGRAM_SRC_PATH)/*.c)
USER_PROGRAM_SRCS_S = $(wildcard $(USER_PROGRAM_SRC_PATH)/*.S)
USER_PROGRAM_SRCS = $(USER_PROGRAM_SRCS_C) $(USER_PROGRAM_SRCS_S)
USER_PROGRAM_SRCS = $(USER_PROGRAM_SRCS_C) $(USER_PROGRAM_SRCS_S)

LOADER_SRCS_C = $(wildcard $(LOADER_SRC_PATH)/*.c) $(wildcard $(LOADER_SRC_MANUAL_PATH)/*.c)
LOADER_SRCS_S = $(wildcard $(LOADER_SRC_PATH)/*.s) $(wildcard $(LOADER_SRC_MANUAL_PATH)/*.s)
LOADER_SRCS = $(LOADER_SRC_C) $(LOADER_SRC_S)
LOADER_SECTION_INFO_H = $(LOADER_INCL_PATH)/section_info.h
LOADER_FLAG_HEADER = $(LOADER_INCL_PATH)/loader_flags.h

PROGRAM_DIV_DATA_WRAPPER = $(PROGRAM_WRAPPER_PATH)/div_data_wrapper.S
PROGRAM_SHUFFLESECTIONS_WRAPPER = $(PROGRAM_WRAPPER_PATH)/shuffle_section_wrapper.S
PROGRAM_SECTION_WRAPPER = $(PROGRAM_WRAPPER_PATH)/section_wrapper.S

LOADER_LS = linker.lds

# workchain generated files
PROGRAM_PRE_ANA_COMBINED_S = $(PROGRAM_PRE_ANA_PATH)/$(USER_PROGRAM_NAME).s
PROGRAM_PRE_ANA_USER_IRS = \
	$(USER_PROGRAM_SRCS_C:%.c=%.ll)
PROGRAM_PRE_ANA_COMBINED_IR = $(PROGRAM_PRE_ANA_PATH)/$(USER_PROGRAM_NAME).ll
PROGRAM_PRE_ANA_EXEC = $(PROGRAM_PRE_ANA_PATH)/$(USER_PROGRAM_NAME).out

PROGRAM_ANA_S = $(PROGRAM_ANA_PATH)/$(USER_PROGRAM_NAME).s
PROGRAM_ANA_ADDRESSES = $(PROGRAM_ANA_PATH)/$(USER_PROGRAM_NAME)
PROGRAM_ANA_EXEC = $(PROGRAM_ANA_PATH)/$(USER_PROGRAM_NAME)
PROGRAM_ANA_DIV_DATA = $(PROGRAM_ANA_PATH)/div_data.bin

PROGRAM_POST_ANA_EXEC = $(PROGRAM_POST_ANA_PATH)/ram.out
PROGRAM_SHUFFLE_TEXT_BIN = $(PROGRAM_POST_ANA_PATH)/text_shuffle.bin

PROGRAM_SHUFFLESECTIONS_BIN = $(addsuffix .bin,$(subst .,$(PROGRAM_POST_ANA_PATH)/section_,$(PROG_SHUFFLESECTIONS)))
PROGRAM_SECTION_BIN = $(addsuffix .bin,$(subst .,$(PROGRAM_POST_ANA_PATH)/section_,$(PROG_SECTIONS)))

PROGRAM_DIV_DATA_WRAPPER_OBJ = $(PROGRAM_DIV_DATA_WRAPPER:%.S=%.o)
PROGRAM_SHUFFLESECTIONS_WRAPPER_OBJ = $(PROGRAM_SHUFFLESECTIONS_WRAPPER:%.S=%.o)
PROGRAM_SECTION_WRAPPER_OBJ = $(PROGRAM_SECTION_WRAPPER:%.S=%.o)

LOADER_OBJS = $(LOADER_SRCS_C:%.c=%.o) $(LOADER_SRCS_S:%.s=%.o)

spaceWithBracket :=
spaceWithBracket += (# $space is a space
comma := ,

# parameters for tools
CFLAGS =-marm -fno-exceptions -O0 -g -Wall -mcpu=cortex-r4f -nostartfiles -nodefaultlibs -nostdlib -static -std=c11 -mbig-endian -mfpu=vfpv3-d16 -mfloat-abi=hard
LDFLAGS = -nostdlib -EB --no-gc-sections --no-wchar-size-warning
LOADER_INCDIRS = -I $(LOADER_INCL_PATH) -I $(LOADER_INCL_MANUAL_PATH) -I $(F021_PATH) -I $(CG_TOOL_ROOT)

.PHONY: all clean clean_dep no_shuffle
all: pre_analysis analyze post_analysis program_objs loader_creation

no_shuffle:
	@printf "creating %s with no shuffle flag\n" $(LOADER_FLAG_HEADER)
	@echo "#define NO_SHUFFLE" > $(LOADER_FLAG_HEADER)

verify:
	@printf "creating %s with verify flag\n" $(LOADER_FLAG_HEADER)
	@echo "#define VERIFY" > $(LOADER_FLAG_HEADER)

################################
### PHASE 1: Pre Analyzation ###
################################
.PHONY: pre_analysis pre_analysis_start
pre_analysis: $(PROGRAM_PRE_ANA_EXEC)
	@echo
	@echo pre-analysis phase successfull!

pre_analysis_start:
	@echo
	@echo Starting pre-analysis phase:

# creates LLVM-IR files from separate .c source files
%.ll: %.c
	@echo Building file: $<
	@echo Invoking: clang
	clang -x c -S -g -emit-llvm -nodefaultlibs -mcpu=cortex-r4 -mbig-endian --target=armv7r-none--eabi -I$(USER_PROGRAM_INCL_PATH) -I$(BINCLUDE) -D$(BDEFINE) -O0 -ffunction-sections -Wall -mcpu=cortex-r4 -c -MD -MP -MF "$(@:%.ll=%.d)" -MT"$(@:%.ll=%.d)" -MT"$(@:%.ll=%.ll)" -mbig-endian  -o "$@" "$<"
	@echo Finished building: $<

%.ll: %.s
	@echo Building file: $<
	@echo Invoking: clang
	clang -x c -S -g -emit-llvm -nodefaultlibs -mcpu=cortex-r4 -mbig-endian --target=armv7r-none--eabi -I$(USER_PROGRAM_INCL_PATH) -I$(BINCLUDE) -D$(BDEFINE) -O0 -ffunction-sections -Wall -mcpu=cortex-r4 -c -MD -MP -MF "$(@:%.ll=%.d)" -MT"$(@:%.ll=%.d)" -MT"$(@:%.ll=%.ll)" -mbig-endian  -o "$@" "$<"
	@echo Finished building: $<
%.ll: %.S
	@echo Building file: $<
	@echo Invoking: clang
	clang -x c -S -g -emit-llvm -nodefaultlibs -mcpu=cortex-r4 -mbig-endian --target=armv7r-none--eabi -I$(USER_PROGRAM_INCL_PATH) -I$(BINCLUDE) -D$(BDEFINE) -O0 -ffunction-sections -Wall -mcpu=cortex-r4 -c -MD -MP -MF "$(@:%.ll=%.d)" -MT"$(@:%.ll=%.d)" -MT"$(@:%.ll=%.ll)" -mbig-endian  -o "$@" "$<"
	@echo Finished building: $<
# combines all temporal LLVM-IR files together in one .s file
# clang file labels are different from GCC. For later compilation, these are translated using sed
$(PROGRAM_PRE_ANA_COMBINED_S): pre_analysis_start $(PROGRAM_PRE_ANA_USER_IRS)
	@echo Combining all .ll \($(PROGRAM_PRE_ANA_USER_IRS)\) to $(PROGRAM_PRE_ANA_COMBINED_S)
	mkdir -p $(PROGRAM_BUILD_PATH)/tmp
	llvm-link -S $(PROGRAM_PRE_ANA_USER_IRS) -o $(PROGRAM_PRE_ANA_COMBINED_IR)
	clang -S -g -O0 --target=armv7r-none--eabi -mcpu=cortex-r4 -mbig-endian -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fno-verbose-asm  $(PROGRAM_PRE_ANA_COMBINED_IR) -o $(PROGRAM_PRE_ANA_COMBINED_S)
	sed 's|^\s\.file\(\s[0-9]*.*\)\" \"\(.*\)$$|\t.file\1\/\2|g' $(PROGRAM_PRE_ANA_COMBINED_S) > $(PROGRAM_PRE_ANA_COMBINED_S)tmp
	mv $(PROGRAM_PRE_ANA_COMBINED_S)tmp $(PROGRAM_PRE_ANA_COMBINED_S)


$(PROGRAM_PRE_ANA_EXEC): $(PROGRAM_PRE_ANA_COMBINED_S)
	@echo Compiling $(PROGRAM_PRE_ANA_COMBINED_S) to $(PROGRAM_PRE_ANA_EXEC)
	$(CC) $(CFLAGS) -Wl,-Map,"$(PROGRAM_PRE_ANA_PATH)/$(USER_PROGRAM_NAME).map" -Wl,--gc-sections -o$@ $< $(USER_PROGRAM_SRCS_S) -I$(USER_PROGRAM_INCL_PATH) -Wl,-T$(USER_PROGRAM_LS)
	@echo pre-analysis phase successfully completed!

############################
### PHASE 2: analysis ###
############################
.PHONY: analyze analyze_start
analyze: $(PROGRAM_ANA_S)
	@echo analysis phase successfully completed!

analyze_start: $(PROGRAM_PRE_ANA_EXEC) $(PROGRAM_PRE_ANA_COMBINED_S)
	@echo
	@echo Starting analysis phase:


$(PROGRAM_ANA_S): analyze_start
	$(SCALA_EXEC) -classpath $(SCALAPATH) control.Main -off $(PROGRAM_ANA_ADDRESSES) -ipath . -ias $(PROGRAM_PRE_ANA_COMBINED_S) -oas $(PROGRAM_ANA_S) -ibin $(PROGRAM_PRE_ANA_EXEC) -obin $(PROGRAM_ANA_EXEC) $(ASMSHUFFLEARGS) -job "addresses" -offDebug $(PROGRAM_ANA_DEBUG) -hOutputPath $(LOADER_INCL_MANUAL_PATH) -divFile $(PROGRAM_ANA_DIV_DATA) >> $(USER_PROGRAM_NAME).result

#################################
### PHASE 3: post analysis ###
#################################
.PHONY: post_analysis post_analysis_start
post_analysis: post_analysis_start $(PROGRAM_POST_ANA_EXEC) $(PROGRAM_SHUFFLESECTIONS_BIN) $(PROGRAM_SECTION_BIN)
	@echo post-analysis phase successfull!

post_analysis_start: $(PROGRAM_ANA_S)
	@echo
	@echo Starting post-analysis phase:

# extract static sections out of user_elf
$(PROGRAM_SHUFFLESECTIONS_BIN): $(PROGRAM_POST_ANA_EXEC)
	touch $@
	$(OBJCOPY) --dump-section $(PROG_SHUFFLESECTIONS)=$@ $<

# extract sections to be shuffled out of user_elf
$(PROGRAM_SECTION_BIN): $(PROGRAM_POST_ANA_EXEC)
	touch $@
	$(OBJCOPY) --dump-section $(notdir $(basename $(subst section_,.,$@)))=$@ $<

# $(PROGRAM_SHUFFLE_TEXT_BIN): $(PROGRAM_POST_ANA_EXEC)
# 	touch $<
# 	$(OBJCOPY) --dump-section $(basename $(subst section_,.,$@))=$@ $<

$(PROGRAM_POST_ANA_EXEC): $(PROGRAM_ANA_S)
	$(CC) $(CFLAGS) -Wl,-Map,"$(PROGRAM_POST_ANA_PATH)/$(USER_PROGRAM_NAME).map" -Wl,--gc-sections -o$@ $(PROGRAM_ANA_S) $(USER_PROGRAM_SRCS_S) -I$(USER_PROGRAM_INCL_PATH) -Wl,-T$(USER_PROGRAM_LS)
	$(OBJDUMP) -d $(PROGRAM_POST_ANA_EXEC) > $(PROGRAM_POST_ANA_DEBUG)/text_dump

$(PROGRAM_BUILD_PATH)/%.o: %.s
	@echo ha
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

$(PROGRAM_BUILD_PATH)/%.o: %.asm
	@echo ha
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

$(PROGRAM_BUILD_PATH)/%.o: %.c
	@echo ha
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -o $@ -c $<

$(PROGRAM_POST): $(PROGRAM_ELF)
	@echo HEAR YE!
	$(OBJCOPY) --dump-section .text=$@ $<

################################
### PHASE 4: program objects ###
################################
.PHONY: program_objs program_objs_start
program_objs: program_objs_start $(PROGRAM_DIV_DATA_WRAPPER_OBJ) $(PROGRAM_SHUFFLESECTIONS_WRAPPER_OBJ) $(PROGRAM_SECTION_WRAPPER_OBJ) $(LOADER_SECTION_INFO_H)

program_objs_start: $(PROGRAM_ANA_DIV_DATA) $(WRAPPER_BIN)
	@echo
	@echo Creating program output object files:

$(PROGRAM_SHUFFLESECTIONS_WRAPPER):
	printf ".section .rodata\n" > $@
	printf "$(foreach SECTION,$(PROG_SHUFFLESECTIONS),\n.global $(subst .,_,$(SECTION))_begin)" >> $@
	printf "$(foreach SECTION,$(PROG_SHUFFLESECTIONS),\n.global $(subst .,_,$(SECTION))_end)\n" >> $@
	printf "$(foreach SECTION,$(PROG_SHUFFLESECTIONS),\n$(subst .,_,$(SECTION))_begin:\t.incbin \"$(abspath $(addsuffix .bin,$(subst .,$(PROGRAM_POST_ANA_PATH)/section_,$(SECTION))))\"\n$(subst .,_,$(SECTION))_end:)\n" >> $@

$(PROGRAM_SECTION_WRAPPER):
	printf ".section .rodata\n" > $@
	printf "$(foreach SECTION,$(PROG_SECTIONS),\n.global $(subst .,_,$(SECTION))_begin)" >> $@
	printf "$(foreach SECTION,$(PROG_SECTIONS),\n.global $(subst .,_,$(SECTION))_end)\n" >> $@
	printf "$(foreach SECTION,$(PROG_SECTIONS),\n$(subst .,_,$(SECTION))_begin:\t.incbin \"$(abspath $(addsuffix .bin,$(subst .,$(PROGRAM_POST_ANA_PATH)/section_,$(SECTION))))\"\n$(subst .,_,$(SECTION))_end:)\n" >> $@

$(PROGRAM_DIV_DATA_WRAPPER_OBJ): $(PROGRAM_DIV_DATA_WRAPPER) $(PROGRAM_ANA_DIV_DATA)
	$(CC) $(CFLAGS) -o $@ -c $(PROGRAM_DIV_DATA_WRAPPER)

$(PROGRAM_SHUFFLESECTIONS_WRAPPER_OBJ): $(PROGRAM_SHUFFLESECTIONS_BIN) $(PROGRAM_SHUFFLESECTIONS_WRAPPER)
	$(CC) $(CFLAGS) -o $@ -c $(PROGRAM_SHUFFLESECTIONS_WRAPPER)

$(PROGRAM_SECTION_WRAPPER_OBJ): $(PROGRAM_SECTION_BIN) $(PROGRAM_SECTION_WRAPPER)
	$(CC) $(CFLAGS) -o $@ -c $(PROGRAM_SECTION_WRAPPER)

$(PROGRAM_OBJ_DIV_DATA): $(PROGRAM_DIV_DATA_WRAPPER) $(PROGRAM_ANA_DIV_DATA)
	$(CC) $(CFLAGS) -o $@ -c $(PROGRAM_DIV_DATA_WRAPPER)

$(LOADER_SECTION_INFO_H):
	echo "$(shell ./print_label_addr.sh $(PROGRAM_POST_ANA_EXEC) $(PROG_LABEL_MAIN_OFFS))"
	echo "$(PROG_SECTIONS)"
	printf "#include \"stdint.h\"\n\n" > $@
	printf "#define NUM_SHUFFLE_SECTIONS $(words $(PROG_SHUFFLESECTIONS))\n" >> $@
	printf "#define NUM_STATIC_SECTIONS $(words $(PROG_SECTIONS))\n" >> $@
	printf "#define PROG_LABEL_MAIN_OFFS 0x$(shell ./print_label_addr.sh $(PROGRAM_POST_ANA_EXEC) $(PROG_LABEL_MAIN_OFFS))\n" >> $@
	printf "/* non shuffle sections */\n" >> $@
	printf "$(foreach SECTION,$(PROG_SECTIONS),\nextern void * $(subst .,_,$(SECTION))_begin, *$(subst .,_,$(SECTION))_end;)\n" >> $@
	printf "/* shuffle sections */\n" >> $@
	printf "$(foreach SECTION,$(PROG_SHUFFLESECTIONS),extern void * $(subst .,_,$(SECTION))_begin, *$(subst .,_,$(SECTION))_end;\n\)n" >> $@
	printf "extern void * _div_data_begin, * _div_data_end;\n\n" >> $@
	printf "/* array with sart addres of all static sections */\n" >> $@
	printf "const uint32_t sections_shuffle_start_addr_g = $(subst ${spaceWithBracket},${comma}${spaceWithBracket},$(addprefix (const uint32_t) &,$(strip $(subst .,_,$(addsuffix _begin,$(PROG_SHUFFLESECTIONS))))));\n\n" >> $@
	printf "const uint32_t sections_shuffle_end_addr_g = $(subst ${spaceWithBracket},${comma}${spaceWithBracket},$(addprefix (const uint32_t) &,$(strip $(subst .,_,$(addsuffix _end,$(PROG_SHUFFLESECTIONS))))));\n\n" >> $@
	printf "const uint32_t sections_static_start_addr_g[NUM_STATIC_SECTIONS]   = {$(subst ${spaceWithBracket},${comma}${spaceWithBracket},$(addprefix (const uint32_t) &,$(strip $(subst .,_,$(addsuffix _begin,$(PROG_SECTIONS))))))};\n\n" >> $@
	printf "const uint32_t sections_static_end_addr_g[NUM_STATIC_SECTIONS]   = {$(subst ${spaceWithBracket},${comma}${spaceWithBracket},$(addprefix (const uint32_t) &,$(strip $(subst .,_,$(addsuffix _end,$(PROG_SECTIONS))))))};\n\n" >> $@
	printf "const uint32_t sections_static_ram_addr_g[NUM_STATIC_SECTIONS]    = {$(shell ./print_section_addr.sh $(PROGRAM_POST_ANA_EXEC) $(foreach section, $(PROG_SECTIONS), $(section)) ) };\n\n" >> $@
	printf "const uint32_t sections_shuffle_ram_addr_g    = $(shell ./print_section_addr.sh $(PROGRAM_POST_ANA_EXEC) $(foreach section, $(PROG_SHUFFLESECTIONS), $(section)) );\n\n" >> $@




################################
### PHASE 5: loader creation ###
################################
.PHONY: loader_creation loader_creation_start
loader_creation: loader_creation_start $(LOADER_FLAG_HEADER) $(EXEC)
	@echo loader succesfully created and linked!

loader_creation_start: $(WRAPPER_OBJ)
	@echo
	@echo Starting loader creation phase:

$(WRAPPER_O)
%.o: %.s
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LOADER_INCDIRS)  -o $@ -c $<

%.o: %.asm
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LOADER_INCDIRS) -o $@ -c $<

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LOADER_INCDIRS) -MMD -MP -o $@ -c $<

$(LOADER_FLAG_HEADER):
	touch  $(LOADER_FLAG_HEADER)

$(EXEC): loader_creation_start $(WRAPPER_OBJ) $(LOADER_OBJS) $(LOADER_LS)
	@echo
	$(LD) $(LDFLAGS) -Map "loader.map" -o $@ $(LOADER_OBJS) $(PROGRAM_OBJ_DIV_DATA) $(PROGRAM_SHUFFLESECTIONS_WRAPPER_OBJ) $(PROGRAM_SECTION_WRAPPER_OBJ) $(PROGRAM_DIV_DATA_WRAPPER_OBJ) $(F021_LIB) -T $(LOADER_LS)
	@echo self-diversificating binary successfull created!


clean: clean_dep
	@echo
	@echo Cleaning up
	rm $(EXEC)

clean_dep:
	@echo $(PROGRAM_SHUFFLESECTIONS_BIN)
	@echo Cleaning up all depency file of the executable
	rm $(PROGRAM_PRE_ANA_COMBINED_S) $(PROGRAM_PRE_ANA_USER_IRS) $(PROGRAM_PRE_ANA_COMBINED_IR) $(PROGRAM_PRE_ANA_EXEC)\
		$(PROGRAM_ANA_S) $(PROGRAM_ANA_EXEC) $(PROGRAM_ANA_DIV_DATA)\
		$(PROGRAM_POST_ANA_EXEC)\
		$(LOADER_OBJS)\
		$(PROGRAM_PRE_ANA_PATH)/$(USER_PROGRAM_NAME).map $(PROGRAM_POST_ANA_PATH)/$(USER_PROGRAM_NAME).map $(PROGRAM_POST_ANA_DEBUG)/text_dump $(USER_PROGRAM_NAME).result\
		loader.map stats\
		$(LOADER_SECTION_INFO_H) $(PROGRAM_OBJ_DIV_DATA) $(PROGRAM_SECTION_WRAPPER_OBJ) $(PROGRAM_SECTION_BIN) $(PROGRAM_SECTION_WRAPPER)\
		$(PROGRAM_SHUFFLESECTIONS_WRAPPER_OBJ) $(PROGRAM_SHUFFLESECTIONS_BIN) $(PROGRAM_SHUFFLESECTIONS_WRAPPER)\
		$(PROGRAM_DIV_DATA_WRAPPER_OBJ) $(LOADER_FLAG_HEADER)
