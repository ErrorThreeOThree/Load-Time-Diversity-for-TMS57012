# Pathes for installed tools

# tools
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
READELF = arm-none-eabi-readelf
WORKSPACE_PATH = /home/jh/workspace
SCALAPATH= $(WORKSPACE_PATH)/asm_load_time_diversity/bin
SCALA_EXEC = scala

# Pathes for source files
PROGRAM_PATH = program
PROGRAM_NAME = program
PROGRAM = $(PROGRAM_PATH)/$(PROGRAM_NAME)
EXTRACTOR_PATH = extractor
LOADER_PATH = loader
PROGRAM_SRC_PATH = $(PROGRAM_PATH)/source
LOADER_SRC_PATH = $(LOADER_PATH)/source
PROGRAM_INCL_PATH = $(PROGRAM_PATH)/include
LOADER_INCL_PATH = $(LOADER_PATH)/include

EXEC = switch_to_ram.out

# Source files and Linkder script
LOADER_SRCS_C = $(wildcard $(LOADER_SRC_PATH)/*.c)
LOADER_SRCS_S = $(wildcard $(LOADER_SRC_PATH)/*.s)
LOADER_SRCS = $(LOADER_SRC_C) $(LOADER_SRC_S)
PROGRAM_SRCS_C = $(wildcard $(PROGRAM_SRC_PATH)/*.c)
PROGRAM_SRCS_S = $(wildcard $(PROGRAM_SRC_PATH)/*.s)
PROGRAM_SRCS = $(PROGRAM_SRCS_C) $(PROGRAM_SRCCS_S)
EXTRACTOR_SRC = $(EXTRACTOR_PATH)/ram_template.S

LOADER_OBJS = $(LOADER_SRCS_C:.c=.o) $(LOADER_SRCS_S:.s=.o)
PROGRAM_OBJS = $(PROGRAM_SRCS:.c=.o) #(PROGRA
PROGRAM_LLVM_IR = $(PROGRAM_SRCS:.c=.ll)
PROGRAM_LLVM_COMBINED = $(PROGRAM).ll
PROGRAM_COMBINED_S = $(PROGRAM).s
PROGRAM_S_SHUFFLE_READY = $(PROGRAM)_shuffle_rdy.s
PROGRAM_ELF = $(PROGRAM).out
LOADER_COMBINED_OBJ = loader.o
EXTRACTOR_OBJ = user.o
LSCRIPT = linker.lds
PROGRAM_LS = $(PROGRAM).lds
EXTRACTOR_EXTRACTED = ram.bin

# parameters for tools
CFLAGS =-marm -fno-exceptions -O0 -g -Wall -mcpu=cortex-r4 -nostartfiles -nodefaultlibs -nostdlib -static -std=c11 -mbig-endian  -mfloat-abi=hard
LDFLAGS = -nostdlib -EB --no-gc-sections
LOADER_INCDIRS = -static -nostdlib -I $(LOADER_INCL_PATH)

.PHONY: all
all: $(EXEC)

.PHONY: noshuffle
all: $(EXEC_NO_SHUFFLE)

%.o: %.s
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LOADER_INCDIRS) -o $@ -c $<

%.o: %.asm
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LOADER_INCDIRS) -o $@ -c $<

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LOADER_INCDIRS) -MMD -MP -o $@ -c $<

##############################################
############## Program creation ##############
##############################################

# creates LLVM-IR files from sperate .c program source files
%.ll: %.c
	@echo Building file: $<
	@echo Invoking: clang
	clang -x c -S -g -emit-llvm -nodefaultlibs -mcpu=cortex-r4 -mbig-endian --target=armv7r-none--eabi -I$(LOADER_INCL_PATH) -I$(BINCLUDE) -D$(BDEFINE) -O0 -ffunction-sections -Wall -mcpu=cortex-r4 -c -MD -MP -MF "$(@:%.ll=%.d)" -MT"$(@:%.ll=%.d)" -MT"$(@:%.ll=%.ll)" -mbig-endian  -o "$@" "$<"
	@echo Finished building: $<
toir: $(PROGRAM_LLVM_IR) $(PROGRAM_BOBS)

# combines all temporal LLVM-IR files together in one .s file
# clang file labels are different from GCC. For later compilation, these are translated using sed
link: $(PROGRAM_COMBINED_S)
$(PROGRAM_COMBINED_S): $(PROGRAM_LLVM_IR) $(PROGRAM_BOBS)
	@echo Combining all .ll to $(PROGRAM_COMBINED_S)
	mkdir -p $(PROGRAM_PATH)/tmp
	cp $(PROGRAM_LLVM_IR) $(PROGRAM_BOBJS) $(PROGRAM_PATH)/tmp
	llvm-link -S $(PROGRAM_PATH)/tmp/*.ll -o $(PROGRAM_LLVM_COMBINED)
	echo $(PROGRAM_COMBINED_S)
	clang -S -g -O0 --target=armv7r-none--eabi -mcpu=cortex-r4 -mbig-endian -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fno-verbose-asm  $(PROGRAM_LLVM_COMBINED) -o $(PROGRAM_COMBINED_S)
	sed 's|^\s\.file\(\s[0-9]*.*\)\" \"\(.*\)$$|\t.file\1\/\2|g' $(PROGRAM_COMBINED_S) > $(PROGRAM_COMBINED_S)rep.s
	mv $(PROGRAM_COMBINED_S)rep.s $(PROGRAM_COMBINED_S)


# Extracts binary code from user elf file
$(EXTRACTOR_OBJ): $(EXTRACTOR_SRC) $(EXTRACTOR_EXTRACTED)
	@echo
	@echo Extracting binary code from program elf file $^
	$(CC) $(CPPFLAGS) $(CFLAGS) -I $(EXTRACTOR_PATH) -o $@ -c $(EXTRACTOR_SRC)

# extract instructions out of user_elf
$(EXTRACTOR_EXTRACTED): $(PROGRAM_ELF)
	@echo HERE YE!
	$(OBJCOPY) --dump-section .text=$@ $<

# creates program elf file
$(PROGRAM_ELF): $(PROGRAM_OBJS) $(PROGRAM_LS)
	@ls $(PROGRAM_SRC_PATH)/*.c
	@echo $(PROGRAM_OBJS) $(PROGRAM_SRCS) $(PROGRAM_SRC_PATH)
	@echo Compiling program elf file $< from files: $^
	$(LD) $(LDFLAGS) -Map "$(PROGRAM_PATH)/program.map" -o $@ $(PROGRAM_OBJS) -T $(PROGRAM_LS)

# TODO: compile $(PROGRAM_COMBINED_S)S.s to memory image, copy text section out of image

# invokes scala
address: $(PROGRAM_COMBINED_S)
	$(SCALA_EXEC) -classpath $(SCALAPATH) control.Main -ipath . -ias $(PROGRAM_COMBINED_S) -oas $(PROGRAM_S_SHUFFLE_READY)	-ibin $(PROGRAM)S -obin $(PROGRAM)S $(ASMSHUFFLEARGS) -job "addresses" >> $(PROGRAM).result
##############################################
############## loader creation ###############
##############################################

# combine loader object files to one object file
$(LOADER_COMBINED_OBJ): $(LOADER_OBJS)
	@echo
	@echo Merging to loader object file $<: $^
	$(LD) -EB -r $^ -o $@

# Creates memory image from user.o and loader.o
$(EXEC): $(LSCRIPT) $(LOADER_COMBINED_OBJ) $(EXTRACTOR_OBJ)
	@echo
	@echo Linking memory image $< from files: $^
	$(LD) $(LDFLAGS) -Map "switch_to_ram.map" -o $(EXEC) $(LOADER_COMBINED_OBJ) $(EXTRACTOR_OBJ) -T "$(LSCRIPT)"

# dump different objdumps and readelfs
.PHONY: dump
dump: $(EXEC)
	@echo
	@echo Dumping aditional informations...
	$(READELF) $(EXEC) -a > switch_to_ram_read_elf
	$(OBJDUMP) $(EXEC) -D > switch_to_ram_objdump
	$(OBJDUMP) $(LOADER_COMBINED_OBJ) -D > loader_objdump
	$(OBJDUMP) $(EXTRACTOR_OBJ) -D > user_objdump

.PHONY: clean

clean:
	@echo
	@echo Cleaning up
	rm $(PROGRAM)/*.ll $(PROGRAM_PATH)/*.s $(PROGRAM_PATH)/*.s $(PROGRAM_PATH)/*.out $(PROGRAM_PATH)/*.ll | true
	rm $(LOADER_OBJS) $(LOADER_COMBINED_OBJ) $(PROGRAM_OBJS) $(PROGRAM_LLVMS) $(PROGRAM_ELF) $(PROGRAM_OBJS) $(EXTRACTOR_OBJ) $(EXTRACTOR_EXTRACTED) $(EXTRA) switch_to_ram_read_elf switch_to_ram_objdump loader_objdump user_objdump $(PROGRAM_PATH)/program.map switch_to_ram.map | true
