#******************************************************************************
# Copyright (C) 2018 by Sudakov Andrei - AO PKK MILANDR
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [COURSE] [PRINT] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	<FILE.i> - Builds <FILE.i> preprocessed output file
#	<FILE.asm> - Builds <FILE.asm> assembly output file
#	<FILE.o> - Builds <FILE.o> object output file
#	<compile-all> - Compile all object files, but do not link
#	<build> - Compile all object files, but do not link
#	<clean> - Remove all compiled objects, preprocessed outputs, 
#		  assembly outputs, executable files and build 
#		  output files
#
# Platform Overrides:
#	PLATFORM - Type of platform (HOST - native, MSP432 - MCU)
#	COURSE   - Switch deliverable function to call (COURSE1 - course1.c, Other #                  values - no functions to call)
#	PRINT    - Define behavior of print_array func (VERBOSE - print as normal,
#                  Other values - nothing should print)
#
#------------------------------------------------------------------------------
PLATFORM = HOST
COURSE = COURSE1
PRINT = VERBOSE
include sources.mk
BASENAME = course1

# Architectures Specific Flags
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
LINKER_FILE = msp432p401r.lds

# Compiler Flags and Defines
ifeq ($(PLATFORM),HOST)
	CC=	gcc
	CFLAGS=	-Wall -Werror -g -O0 -std=c99
	LDFLAGS= -Wl,-Map=$(BASENAME).map
	SIZE= size
	OBJDUMP=objdump
else ifeq ($(PLATFORM),MSP432)
	CC=	arm-none-eabi-gcc
	CFLAGS=	-Wall -Werror -g -O0 -std=c99 \
		-mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) \
		-march=armv7e-m  -mfloat-abi=hard -mfpu=fpv4-sp-d16 
	LDFLAGS= -T$(LINKER_FILE) -Wl,-Map=$(BASENAME).map
	SIZE= arm-none-eabi-size
	OBJDUMP=arm-none-eabi-objdump
else
  	$(error Unsupported platform: $(PLATFORM))
endif
 
LD= arm-none-eabi-ld
CPPFLAGs= -MD -D$(PLATFORM) -D$(PRINT) -D$(COURSE)

%.o : src/%.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGs) $(INCLUDES) -o $@

%.i : src/%.c
	$(CC) -E $(CPPFLAGs) $(INCLUDES) -o $@ $<

%.asm : src/%.c
	$(CC) -S $(CFLAGS) $(CPPFLAGs) $(INCLUDES) -o $@ $<

$(BASENAME).asm: $(BASENAME).out
	$(OBJDUMP) -d $< >$@

.PHONY: compile-all
compile-all:
	$(CC) -c $(SOURCES) $(CFLAGS) $(CPPFLAGs) $(INCLUDES)

.PHONY: build
build: $(BASENAME).out
$(BASENAME).out : $(OBJS)
	$(CC) $(SOURCES) $(CFLAGS) $(CPPFLAGs) $(INCLUDES) $(LDFLAGS) -o $@
	$(SIZE) -Atd $@

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.i
	rm -f *.d
	rm -f *.asm
	rm -f *.map
	rm -f *.out


