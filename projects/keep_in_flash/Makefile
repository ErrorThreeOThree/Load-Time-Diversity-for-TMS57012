EXEC = keep_in_flash.out

LSCRIPT = linker.lds

LOADER_DIR = LOADER
LOADER_SRC_DIR = $(LOADER_DIR)/source
LOADER_BUILD_DIR = $(LOADER_DIR)/build

LOADER_SRCS_C = $(wildcard $(LOADER_SRC_DIR)/*.c)
LOADER_SRCS_S = $(wildcard $(LOADER_SRC_DIR)/*.asm) $(wildcard $(LOADER_SRC_DIR)/*.s)

OBJS = $(SRCS_C:.c=.o) $(SRCS_S:.s=.o)
DEP = $(OBJS:.o=.d)

OBJ = flash.o


#

# Konfiguration

#



#DEBUG = -DDEBUG

CC = arm-none-eabi-gcc

LD = arm-none-eabi-ld

OBJCOPY = arm-none-eabi-objcopy



CFLAGS =-marm -fno-exceptions -O0 -g -Wall -mcpu=cortex-r4 -nostartfiles -nodefaultlibs -nostdlib -static -std=c11 -mbig-endian  -mfloat-abi=hard


CG_TOOL_ROOT = /home/jh/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.4.LTS

INCDIRS = -static -nostdlib -I $(SRCS)/include

DEP = $(OBJ:.o=.d)



#

# Regeln

#

.PHONY: all

all: $(EXEC)



-include $(DEP)



%.o: %.s
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCDIRS) -o $(LOADER_BUILD_DIR)/$@ -c $<

%.o: %.asm
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCDIRS) -o $(LOADER_BUILD_DIR)/$@ -c $<



%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCDIRS) -MMD -MP $(LOADER_BUILD_DIR)/-o $@ -c $<


$(EXEC): $(LSCRIPT) $(OBJS)
	$(CC) $(CFLAGS) -Wl,-Map,"TITest.map" -Wl,--gc-sections -o$(EXEC) $(LOADER_BUILD_DIR)/$^ -Wl,-T"$(LSCRIPT)"

#$(OBJ): $(OBJS)
#	$(LD) -r $^ -o $@


.PHONY: clean

clean:

	rm -f FLASH/source/*.d FLASH/source/*.o $(EXEC)

	rm -f $(OBJ)

	rm -f $(DEP)
