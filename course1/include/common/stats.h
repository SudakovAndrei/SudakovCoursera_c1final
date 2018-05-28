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
 * @file stats.h
 * @brief Statistics of an array functions
 *
 * This header file provides an statistics of an array function calls. 
 *
 * @author Andrei Sudakov
 * @date April 15 2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdio.h>
#include "platform.h"

/**
 * @brief Find maximum value of an array
 *
 * Given a pointer to a char data set and its size. This will 
 * find maximum value of an array.
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return unsigned char.
 */
unsigned char find_maximum(unsigned char * ptr, unsigned int size);

/**
 * @brief Find minimum value of an array
 *
 * Given a pointer to a char data set and its size. This will 
 * find minimum value of an array.
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return unsigned char.
 */
unsigned char find_minimum(unsigned char * ptr, unsigned int size);

/**
 * @brief Find median value of an array
 *
 * Given a pointer to a char data set and its size. This will 
 * find median value of an array.
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return unsigned char.
 */
unsigned char find_median(unsigned char * ptr, unsigned int size);

/**
 * @brief Find mean value of an array
 *
 * Given a pointer to a char data set and its size. This will 
 * find mean value of an array.
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return unsigned char.
 */
unsigned char find_mean(unsigned char * ptr, unsigned int size);

/**
 * @brief Prints the statistic of an array to the screen
 *
 * Given a pointer to a char data set and its size. This will 
 * prints the statistic of an array including minimum, 
 * maximum, mean, and median.
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return void.
 */
void print_statistics(unsigned char * ptr, unsigned int size);

/**
 * @brief Prints the array to the screen
 *
 * Given a pointer to a char data set and its size. This will 
 * prints the array to the screen.
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return void.
 */
void print_array(unsigned char * ptr, unsigned int size);

/**
 * @brief Sorts the array from largest to smallest 
 *
 * Given a pointer to a char data set and its size. This will 
 * sorts the array from largest to smallest (the zeroth
 * element should be the largest value, and the last element
 * should be the smallest value).
 *
 * @param ptr Pointer to data array
 * @param size Size of the data array
 *
 * @return void.
 */
void sort_array(unsigned char * ptr, unsigned int size);

#endif /* __STATS_H__ */
