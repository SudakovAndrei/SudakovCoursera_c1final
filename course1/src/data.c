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
 * @file data.c
 * @brief Type convertion functions
 *
 * This implementation file provides an convertion from a standard integer 
 * type into an ASCII string and vice versa.
 *
 * @author Andrei Sudakov
 * @date May 17 2018
 *
 */
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  int32_t sign=0;
  int8_t digit;
  uint8_t length = 0;
  uint8_t *start_ptr;
  uint8_t *end_ptr;
  
  /* Save sign, If negative number */
  if (data < 0) { 
    data = (-1 * data);
    sign = 1;
  }
   
  do {
    /* Calculate digits */
    digit = data%base;
    if (digit < 10)
    {
      /* Add ASCII '0', if less 10 */
      *ptr= digit + '0';
    }
    else if (digit < 16)
    {
      /* Add ASCII 'a', if more 10 and less 16 */
      *ptr = digit - 10 + 'a';
    }
    /* Increment length_str and result_str pointer */
    length ++;
    ptr ++;
    data -= data % base;
  }
  /* Do cycle if number more 0 */
  while ((data /= base) > 0);

  if (sign == 1) {
    /* Add minus sign if negative number */
    *ptr = '-';
    /* Increment length_str and result_str pointer */
    ptr ++;
    length ++;
  }
  /* Add NULL termintor */
  *ptr = '\0';
  /* Set pointers for reverse bytes */
  start_ptr = ptr - length - 1;
  end_ptr = ptr - 0;
  /* reverse untill end_ptr > start_ptr */
  while(end_ptr > start_ptr){
    /* Save value from left side of array */
    digit = *start_ptr;
    /* Move value from rigth side of array to left */
    *start_ptr++ = *end_ptr;
    /* Move value from temp to rigth side of array */
    *end_ptr-- = digit;
  }
  /* Set ptr to start offff allocation */
  ptr -= length - 1;
  /* Return length of string (without NULL termintor) */
  return (length);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int32_t sign=0;
  int32_t current_digit;
  int32_t result_number = 0; 
  int32_t i;

  if (*ptr == '-'){
    /* Save sign, If negative number */
    sign = 1; 
    /* Increment ptr pointer */
    ptr ++;
    /* Decrement size of array */
    digits--;
  }

  for (i = 0; i < digits; i ++){
    if (*ptr >= '0' && *ptr <= '9')
    {
      /*  if digit from 0 to 9 */
      current_digit = *ptr - '0';
    }
    else if (*ptr >= 'a' && *ptr <= 'f')
    {
      /*  if digit from a to f */
      current_digit = 10 + *ptr - 'a';
    } 
    else if (*ptr >= 'A' && *ptr <= 'F')
    {
      /*  if digit from A t0 F */
      current_digit = 10 + *ptr - 'A';
    }
    /* Calculate number */
    result_number = result_number * base + current_digit;
    /* Increment ptr pointer */
    ptr ++;
  }

  if (sign == 1) {
    /* do negative if sign == 1 */
    result_number *= -1;
  }
  /* return result number */  
  return (result_number); 
}

