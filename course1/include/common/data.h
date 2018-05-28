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
 * @file data.h
 * @brief Type convertion functions
 *
 * This header file provides an convertion from a standard integer type into
 * an ASCII string and vice versa.
 *
 * @author Andrei Sudakov
 * @date May 17 2018
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH	32
/**
 * @brief Convert data from a standard integer type into an ASCII string. 
 *
 * Takes an integer number, a base for convertaion and allocation for 
 * result to convert input integer to ASCII string.
 *
 * @param data 32-bit signed number
 * @param ptr Pointer on allocation of result string
 * @param base base (2 to 16)
 *
 * @return uint8_t.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert data from a ASCII string into an standard integer type. 
 *
 * Takes an allocation of ASCII string, a number of digits and base of 
 * represented number to convert input ASCII string to integer.
 *
 * @param ptr Pointer on allocation of ASCII string
 * @param digits number of digits in input string
 * @param base base (2 to 16)
 *
 * @return int32_t.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */

