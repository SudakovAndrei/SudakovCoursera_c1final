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
 * This header file provides an test function. 
 *
 * @author Andrei Sudakov
 * @date May 17 2018
 *
 */
#ifndef __COURSE1_H__
#define __COURSE1_H__

/**
 * @brief Call a handful of functions and test function outputs. 
 *
 * Call each of the following functions once. 
 *
 * @return uint8_t.
 */
int8_t course1(void);

/**
 * @brief Test atoi and itoa conversions functions. 
 *
 *  
 *
 * @return uint8_t.
 */
int8_t test_data1(void);

/**
 * @brief Test atoi and itoa conversions functions. 
 *
 *  
 *
 * @return uint8_t.
 */
int8_t test_data2(void);

/**
 * @brief Test non-overlapped memmove function. 
 *
 *
 *
 * @return uint8_t.
 */
int8_t test_memmove1(void);

/**
 * @brief Test overlapped memmove function. 
 *
 * In this test overlap overlap start of destination and end
 * of the source regions. 
 *
 * @return uint8_t.
 */
int8_t test_memmove2(void);

/**
 * @brief Test overlapped memmove function. 
 *
 * In this test overlap end of destination and start of the 
 * source regions.
 *
 * @return uint8_t.
 */
int8_t test_memmove3(void);

/**
 * @brief Test memcopy function. 
 *
 *
 *
 * @return uint8_t.
 */
int8_t test_memcopy(void);

/**
 * @brief Test memset function. 
 *
 *
 *
 * @return uint8_t.
 */
int8_t test_memset(void);

/**
 * @brief Test reverse function. 
 *
 *
 *
 * @return uint8_t.
 */
int8_t test_reverse(void);

#endif /* __COURSE1_H__ */

