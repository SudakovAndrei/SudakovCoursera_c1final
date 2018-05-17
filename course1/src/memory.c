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
  unsigned int i;
  uint8_t * buf;
  /* Allocate memory for buffer */
  buf = (uint8_t *)malloc(length*sizeof(uint8_t));
  for(i = 0; i < length; i++) {
    /* Move data from src to dst through buffer */
    *buf = *src;
    *dst = *buf;
    /* Increment pointers */
    src ++;
    dst ++;
    buf ++;
  }
  /* Free memory and return dst pounter */
  free (buf);
  return (dst);
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  unsigned int i;

  for(i = 0; i < length; i++) {
    /* Copy data from src to dst */
    *dst = *src;
    /* Increment pointers */
    src ++;
    dst ++;
  }
  /* Return dst pounter */
  return (dst);
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  unsigned int i;

  for(i = 0; i < length; i++) {
    /* Set to value */
    *src = value;
    /* Increment pointer */
    src ++;
  }
  /* Return src pounter */
  return (src);
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  unsigned int i;

  for(i = 0; i < length; i++) {
    /* Set to zero */
    *src = NULL;
    /* Increment pointer */
    src ++;
  }
  /* Return src pounter */
  return (src);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  unsigned int i;
  uint8_t * buf;

  /* Allocate memory for buffer */
  buf = (uint8_t *)malloc(length*sizeof(uint8_t));
  /* Set src pointer to end of allocation */
  src += length;
  for(i = 0; i < length; i++) {
    /* Copy src to buf in reverse order */
    *buf = *src;
    /* Decrement src and increment buf pointers */
    src --;
    buf ++;
  }
  /* Set buf pointer to begin of allocation */
  buf -= length;
  for(i = 0; i < length; i++) {
    /* Copy data from buffer to src */
    *src = *buf;
    /* Increment pointers */
    src ++;
    buf ++;
  }
  /* Free memory and return src pounter */
  free (buf);
  return (src);
}

int32_t * reserve_words(size_t length){
  uint8_t * buf;
  /* Allocate memory for buffer */
  buf = malloc(length*sizeof(int32_t));
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

