/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t * sour = src;
  uint8_t * dest = dst;
  
  /* If non-overlapped copy from begin of allocations */
  if (dest <= sour || dest >= (sour + length)){
    while (length--){
      /* Copy and increment pointers */ 
      *dest++ = *sour++;
    }
  }
  /* If overlapped copy from end of allocations */
  else{
    /* Set pounter to end of allocations*/
    dest += length - 1;
    sour += length - 1;
    while (length--){
      /* Copy and decrement pointers */
      *dest-- = *sour--;
    } 
  }
  /* Return dst pounter */
  return (dst);
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  unsigned int i;
  uint8_t * sour = src;
  uint8_t * dest = dst;

  for(i = 0; i < length; i++) {
    /* Copy data and icrement pointers */
    *dest++ = *sour++;
  }
  /* Return dst pounter */
  return (dst);
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  unsigned int i;
  uint8_t * sour = src;

  for(i = 0; i < length; i++) {
    /* Set to value */
    *sour = value;
    /* Increment pointer */
    sour ++;
  }
  /* Return src pounter */
  return (src);
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  unsigned int i;
  uint8_t * sour = src;

  for(i = 0; i < length; i++){
    /* Set to zero */
    *sour = '\0';
    /* Increment pointer */
    sour ++;
  }
  /* Return src pounter */
  return (src);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t temp;
  uint8_t *start_ptr = src;
  uint8_t *end_ptr = src + length-1;

  if(start_ptr == NULL){
    /* if Null pointer return */
    return (src);
  }
  else
  {
    /* reverse untill end_ptr > start_ptr */
    while(end_ptr > start_ptr){
      /* Save value from left side of array */
      temp = *start_ptr;
      /* Move value from rigth side of array to left */
      *start_ptr++ = *end_ptr;
      /* Move value from temp to rigth side of array */
      *end_ptr-- = temp;
    }
  }
  /* Return src pounter */
  return (src);
}

int32_t * reserve_words(size_t length){
  int32_t * buf;
  /* Allocate memory for buffer */
  buf = (int32_t *)malloc(length*sizeof(int32_t));
  if (buf == NULL) {
    /* if not allocated return Null pointer */
    return (NULL);
  }
  else {
    /* if allocated return pointer to memory*/
    return ((int32_t *)buf);
  }
}

void free_words(int32_t * src){
  /* Free memory from src allocation */
  free (src);
}

