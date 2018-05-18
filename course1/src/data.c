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

#define MAX_STRING_LENGTH	32

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  char * result_str;
  int sign=0;
  int digit;
  int length_str = 0;
  
  /* Allocate memory for result string */
  result_str = (char *)malloc(MAX_STRING_LENGTH*sizeof(char));
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
      *result_str= digit + '0';
    }
    else if (digit < 16)
    {
      /* Add ASCII 'a', if more 10 and less 16 */
      *result_str = digit - 10 + 'a';
    }
    /* Increment length_str and result_str pointer */
    length_str ++;
    result_str ++;
    data -= data % 10;
  }
  /* Do cycle if number more 0 */
  while ((data /= base) > 0);

  if (sign == 1) {
    /* Add minus sign if negative number */
    *result_str = '-';
    /* Increment length_str and result_str pointer */
    result_str ++;
    length_str ++;
  }

  /* Allocate memory for buffer */
  buf = (char *)malloc(length*sizeof(char));
  for(i = 0; i < length_str; i++) {
    /* Copy result_str to buf in reverse order */
    *buf = *result_str;
    /* Decrement result_str and increment buf pointers */
    result_str --;
    buf ++;
  }
  /* Set buf pointer to begin of allocation */
  buf -= length_str;
  for(i = 0; i < length_str; i++) {
    /* Copy data from buffer to ptr */
    *ptr = *buf;
    /* Increment pointers */
    ptr ++;
    buf ++;
  }
  /* Add NULL terminator to end of string */
  *result_str = '\0';
  *ptr = '\0';
  /* Increment length_str and result_str pointer */
  result_str ++;
  ptr ++;
  length_str ++;
  /* Free memory */
  free (buf);
  free (result_str);
  /* Return length of string (without NULL termintor) */
  return (length_str-1);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int sign=0;
  int current_digit;
  int32_t result_number = 0; 

  if (*ptr == '-'){
    /* Save sign, If negative number */
    sign = 1; 
    /* Increment ptr pointer */
    ptr ++;
  }

  for (i = 0; i < digits; i ++){
    if (*ptr >= '0' && *ptr >= '9')
    {
      /*  if digit from 0 to 9 */
      current_digit = *ptr - '0';
    }
    else if (*ptr >= 'a' && *ptr >= 'f')
    {
      /*  if digit from a to f */
      *result_str = digit + 'a';
      current_digit = 10 + *ptr - 'a';
    } 
    else if (*ptr >= 'A' && *ptr >= 'F')
    {
      /*  if digit from A t0 F */
      *result_str = digit + 'a';
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

