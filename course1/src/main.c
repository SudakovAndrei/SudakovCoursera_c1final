/******************************************************************************
 * Copyright (C) 2018 by Andrei Sudakov - AO PKK MILANDR
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Andrei Sudakov and the AO PKK MILANDR are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main function.
 *
 * This implementation file provides a run of course1 function. 
 *
 * @author Andrei Sudakov
 * @date May 17 2018
 *
 */

#include "platform.h"
#include "course1.h"

/* A pretty boring main file */
int main(void) {

#ifdef COURSE1
  course1();
#endif
  return 0;
}

