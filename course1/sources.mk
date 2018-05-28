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
ifeq ($(PLATFORM),HOST)
SOURCES = 	src/main.c \
	  	src/course1.c \
	  	src/stats.c \
	  	src/memory.c \
	  	src/data.c
OBJS = 		main.o \
	  	course1.o \
	  	stats.o \
	  	memory.o \
	  	data.o

INCLUDES=	-Iinclude/common
else ifeq ($(PLATFORM),MSP432)
SOURCES=	src/main.c \
	  	src/course1.c \
	  	src/stats.c \
	  	src/memory.c \
	  	src/data.c \
		src/interrupts_msp432p401r_gcc.c \
		src/startup_msp432p401r_gcc.c \
		src/system_msp432p401r.c
INCLUDES=	-Iinclude/CMSIS \
		-Iinclude/msp432 \
		-Iinclude/common
OBJS = 		main.o \
	  	course1.o \
	  	stats.o \
	  	memory.o \
	  	data.o \
		interrupts_msp432p401r_gcc.o \
		startup_msp432p401r_gcc.o \
		system_msp432p401r.o
else
  $(error Unsupported platform: $(PLATFORM))
endif

