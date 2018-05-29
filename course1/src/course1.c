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
 * @file course1.h
 * @brief Type convertion functions
 *
 * This implementation file provides an test function. 
 *
 * @author Andrei Sudakov
 * @date May 17 2018
 *
 */

#include "course1.h"

int32_t test_number = 123456789;
uint8_t array1[32];
uint8_t array2[32];

#define	src_str_size		(16)
#define	overlap_str_size	(8)
uint8_t src_str[src_str_size] = 	{ 201,   6,  12,  60,   8,   2,   5,  67,
                                  	    7,  87, 250, 230,  99,   3, 100,  90};
uint8_t dst_str1[src_str_size] = 	{   1,   2,   3,   4,   5,   6,   7,   8,
                                   	    9,  10,  11,  12,  13,  14,  15,  16};
uint8_t dst_str2[src_str_size] = 	{   1,   2,   3,   4,   5,   6,   7,   8,
                                   	    9,  10,  11,  12,  13,  14,  15,  16};
uint8_t dst_str3[src_str_size] = 	{   1,   2,   3,   4,   5,   6,   7,   8,
                                   	    9,  10,  11,  12,  13,  14,  15,  16};
uint8_t dst_str4[src_str_size] = 	{   1,   2,   3,   4,   5,   6,   7,   8,
                                   	    9,  10,  11,  12,  13,  14,  15,  16};

uint8_t overlap_str[overlap_str_size] = {   5,   6,   7,   8,   9,   10,  11,  12};

#define memset_test_value	(19)

#define	str_even_size		(8)
uint8_t str_even[8] = 			{  45,  98,  71,   2,  37,  62, 123, 205};
uint8_t reverse_str_even[8] = 		{ 205, 123,  62,  37,   2,  71,  98,  45};
#define	str_odd_size		(7)
uint8_t str_odd[str_odd_size] = 	{ 200, 122, 150,  90,  92,  87, 177};
uint8_t reverse_str_odd[str_odd_size] = { 177,  87,  92,  90, 150, 122, 200};

int8_t course1(void){
int8_t result=0; 
int8_t err_code=0;

  err_code = test_data1();
  if (err_code){
    result |= 1 << 0;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  err_code = test_data2();
  if (err_code){
    result |= 1 << 1;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  err_code = test_memmove1();
  if (err_code){
    result |= 1 << 2;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  err_code = test_memmove2();
  if (err_code){
    result |= 1 << 3;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  err_code = test_memmove3();
  if (err_code){
    result |= 1 << 4;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }  
  err_code = test_memcopy();
  if (err_code){
    result |= 1 << 5;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  err_code = test_memset();
  if (err_code){
    result |= 1 << 6;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  err_code = test_reverse(); 
  if (err_code){
    result |= 1 << 7;
    PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Error code = 0x%x\n",err_code);
  }
  
  if (result == 0){
    PRINTF("!!!!!!!!!!!!!!!! All functions tested successfully !!!!!!!!!!!!!!!!!\n");
  } 
    
  return(0);
}

int8_t test_data1(void){
  int8_t Error = 0;
  int32_t i;
  uint8_t length_str=0;
  int32_t res_int=0;

  PRINTF("**************** Test my_itoa and my atoi functions ****************\n");
  for (i = 2; i <= 16; i ++ ){
    length_str = my_itoa(test_number, array1, i);
    PRINTF("Number %d in base=%d is %s \n", test_number, i, array1);
    PRINTF("Length of result string is %d \n", length_str);
    res_int = my_atoi(array1, length_str, i);
    PRINTF("Result of my_atoi is %d \n", res_int);
    if (res_int != test_number){
      Error |= 1 << i;
    }
    PRINTF("--------------------------------------------------------------------\n");
  }

  for (i = 2; i <= 16; i ++ ){
    length_str = my_itoa(-1*test_number, array1, i);
    PRINTF("Number %d in base=%d is %s \n", -1*test_number, i, array1);
    PRINTF("Length of result string is %d \n", length_str);
    res_int = my_atoi(array1, length_str, i);
    PRINTF("Result of my_atoi is %d \n", res_int);
    if (res_int != -1*test_number){
      Error |= 1 << (i+16);
    }
    PRINTF("--------------------------------------------------------------------\n");
  }
  
  if (Error == 0){ 
    PRINTF("************* Test my_itoa and my atoi functions pass **************\n");
  }
  else{
    PRINTF("************* Test my_itoa and my atoi functions fail **************\n");
  }
  return (Error);
}

int8_t test_data2(void){
  int8_t Error = 0;
  int32_t i;
  uint8_t length_str;
  int32_t test_int = 1;
  int32_t res_int;

  PRINTF("**************** Test my_itoa and my atoi functions ****************\n");

  for (i = 1; i <= 31; i ++ ){
    test_int = test_int * 2;
    length_str = my_itoa(test_int - 1, array2, 2);
    PRINTF("Number %d in base=%d is %s \n", test_int - 1, 2, array2);
    PRINTF("Length of result string is %d \n", length_str);
    res_int = my_atoi(array2, length_str, 2);
    PRINTF("Result of my_atoi is %d \n", res_int);
    if (res_int != (test_int - 1) || length_str != i){
      Error |= 1 << i;
    }
    PRINTF("--------------------------------------------------------------------\n");
  }

  if (Error == 0){ 
    PRINTF("************* Test my_itoa and my atoi functions pass **************\n");
  }
  else{
    PRINTF("************* Test my_itoa and my atoi functions fail **************\n");
  }
  return (Error);
}

int8_t test_memmove1(void){
  int8_t Error = 0;
  uint8_t * dst_str_out;
  int32_t i;

  PRINTF("************ Test my_memmove function (non-overlapped) *************\n");
  PRINTF("Source string:\n");
  print_array(src_str, src_str_size);
  PRINTF("Destination string:\n");
  print_array(dst_str1, src_str_size);
  dst_str_out = my_memmove(src_str, dst_str1, src_str_size);
  PRINTF("Source string after my_memmove:\n");
  print_array(src_str, src_str_size);
  PRINTF("Destination string after my_memmove (input parameter):\n");
  print_array(dst_str1, src_str_size);
  PRINTF("Destination string after my_memmove (output value):\n");
  print_array(dst_str_out, src_str_size);
  for (i = 0; i < src_str_size; i++){
    if (src_str[i] != dst_str1[i]){
      Error |= 1 << 0;
    }
    if (src_str[i] != dst_str_out[i]){
      Error |= 1 << 1;
    }
  }
  if (Error == 0){ 
    PRINTF("********** Test my_memmove function (non-overlapped) pass **********\n");
  }
  else{
    PRINTF("********** Test my_memmove function (non-overlapped) fail **********\n");
  }
  return (Error);
}

int8_t test_memmove2(void){
  int8_t Error = 0;
  uint8_t * dst_str_out;
  int32_t i;

  PRINTF("************** Test my_memmove function (overlapped) ***************\n");
  PRINTF("Source string:\n");
  print_array(dst_str2+4, overlap_str_size);
  PRINTF("Destination string:\n");
  print_array(dst_str2+0, overlap_str_size);
  dst_str_out = my_memmove(dst_str2+4, dst_str2+0, overlap_str_size);
  PRINTF("Source string after my_memmove:\n");
  print_array(dst_str2+4, overlap_str_size);
  PRINTF("Destination string after my_memmove (input parameter):\n");
  print_array(dst_str2+0, overlap_str_size);
  PRINTF("Destination string after my_memmove (output value):\n");
  print_array(dst_str_out, overlap_str_size);
  for (i = 0; i < overlap_str_size; i++){
    if (dst_str2[i] != overlap_str[i]){
      Error |= 1 << 0;
    }
    if (dst_str_out[i] != overlap_str[i]){
      Error |= 1 << 1;
    }
  }
  if (Error == 0){ 
    PRINTF("************ Test my_memmove function (overlapped) pass ************\n");
  }
  else{
    PRINTF("************ Test my_memmove function (overlapped) fail ************\n");
  }
  return (Error);
}

int8_t test_memmove3(void){
  int8_t Error = 0;
  uint8_t * dst_str_out;
  int32_t i;

  PRINTF("************** Test my_memmove function (overlapped) ***************\n");
  PRINTF("Source string:\n");
  print_array(&dst_str3[4], overlap_str_size);
  PRINTF("Destination string:\n");
  print_array(&dst_str3[8], overlap_str_size);
  dst_str_out = my_memmove(&dst_str3[4], &dst_str3[8], overlap_str_size);
  PRINTF("Source string after my_memmove:\n");
  print_array(&dst_str3[4], overlap_str_size);
  PRINTF("Destination string after my_memmove (input parameter):\n");
  print_array(&dst_str3[8], overlap_str_size);
  PRINTF("Destination string after my_memmove (output value):\n");
  print_array(dst_str_out, overlap_str_size);
  for (i = 0; i < overlap_str_size; i++){
    if (dst_str3[8+i] != overlap_str[i]){
      Error |= 1 << 0;
    }
    if (dst_str_out[i] != overlap_str[i]){
      Error |= 1 << 1;
    }
  }
  if (Error == 0){ 
    PRINTF("************ Test my_memmove function (overlapped) pass ************\n");
  }
  else{
    PRINTF("************ Test my_memmove function (overlapped) fail ************\n");
  }
  return (Error);
}

int8_t test_memcopy(void){
  int8_t Error = 0;
  uint8_t * dst_str_out;
  int32_t i;

  PRINTF("********************* Test my_memcopy function *********************\n");
  PRINTF("Source string:\n");
  print_array(src_str, src_str_size);
  PRINTF("Destination string:\n");
  print_array(dst_str4, src_str_size);
  dst_str_out = my_memcopy(src_str, dst_str4, src_str_size);
  PRINTF("Source string after memcopy:\n");
  print_array(src_str, src_str_size);
  PRINTF("Destination string after memcopy (input parameter):\n");
  print_array(dst_str4, src_str_size);
  PRINTF("Destination string after memcopy (output value):\n");
  print_array(dst_str_out, src_str_size);
  for (i = 0; i < src_str_size; i++){
    if (src_str[i] != dst_str4[i]){
      Error |= 1 << 0;
    }
    if (src_str[i] != dst_str_out[i]){
      Error |= 1 << 1;
    }
  }
  if (Error == 0){ 
    PRINTF("****************** Test my_memcopy function pass *******************\n");
  }
  else{
    PRINTF("****************** Test my_memcopy function fail *******************\n");
  }
  return (Error);
}

int8_t test_memset(void){
  int8_t Error = 0;
  uint8_t * src_str_out;
  int32_t i;

  PRINTF("************** Test my_memset & my_memzero functions ***************\n");
  PRINTF("Source string:\n");
  src_str_out = my_memset(src_str, src_str_size, memset_test_value);
  PRINTF("Source string after memset %d (input parameter):\n", memset_test_value);
  print_array(src_str, src_str_size);
  PRINTF("Source string after memset %d (output value): \n", memset_test_value);
  print_array(src_str_out, src_str_size);
  for (i = 0; i < src_str_size; i++){
    if (src_str[i] != memset_test_value){
      Error |= 1 << 0;
    }
    if (src_str_out[i] != memset_test_value){
      Error |= 1 << 1;
    }
  }
  PRINTF("Source string:\n");
  src_str_out = my_memzero(src_str, src_str_size);
  PRINTF("Source string after memzero (input parameter):\n");
  print_array(src_str, src_str_size);
  PRINTF("Source string after memzero (output value):\n");
  print_array(src_str_out, src_str_size);
  for (i = 0; i < src_str_size; i++){
    if (src_str[i] != '\0'){
      Error |= 1 << 2;
    }
    if (src_str_out[i] != '\0'){
      Error |= 1 << 3;
    }
  }
  if (Error == 0){ 
    PRINTF("************ Test my_memset & my_memzero functions pass ************\n");
  }
  else{
    PRINTF("************ Test my_memset & my_memzero functions fail ************\n");
  }
  return (Error);
}

int8_t test_reverse(void){
  int8_t Error = 0;
  uint8_t * str_even_out;
  uint8_t * str_odd_out;
  int32_t i;

  PRINTF("********************* Test my_reverse function *********************\n");
  PRINTF("Source string:\n");
  print_array(str_even, str_even_size);
  str_even_out = my_reverse(str_even, str_even_size);
  PRINTF("Reverse string (input parameter): \n");
  print_array(str_even, str_even_size);
  PRINTF("Reverse string (output value): \n");
  print_array(str_even_out, str_even_size);
  for (i = 0; i < str_even_size; i++){
    if (str_even[i] != reverse_str_even[i]){
      Error |= 1 << 0;
    }
    if (str_even_out[i] != reverse_str_even[i]){
      Error |= 1 << 1;
    }
  }
  PRINTF("Source string:\n");
  print_array(str_odd, str_odd_size);
  str_odd_out = my_reverse(str_odd, str_odd_size);
  PRINTF("Reverse string (input parameter): \n");
  print_array(str_odd, str_odd_size);
  PRINTF("Reverse string (output value): \n");
  print_array(str_odd_out, str_odd_size);
  for (i = 0; i < str_odd_size; i++){
    if (str_odd[i] != reverse_str_odd[i]){
      Error |= 1 << 2;
    }
    if (str_odd_out[i] != reverse_str_odd[i]){
      Error |= 1 << 3;
    }
  }
  if (Error == 0){ 
    PRINTF("****************** Test my_reverse function pass *******************\n");
  }
  else{
    PRINTF("****************** Test my_reverse function fail ****************** \n");
  }
  return (Error);
}


