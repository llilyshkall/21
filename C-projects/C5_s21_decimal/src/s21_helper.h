/**
 * @file s21_helper.h
 * @author coriemis, chatayap
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SRC_S21_HELPER_H
#define SRC_S21_HELPER_H

#include "s21_decimal.h"

/**
 * @name Macros
 * @addtogroup Internal
 * @{
 */

/**
 * @brief Check if decimal is zero
 * @param Decimal
 */
#define IS_ZERO(a) (!(a).bits[0] && !(a).bits[1] && !(a).bits[2])

/**
 * @brief Copy decimal
 * @param source
 * @param destination
 */
#define COPY(a, b)             \
  {                            \
    (a).bits[0] = (b).bits[0]; \
    (a).bits[1] = (b).bits[1]; \
    (a).bits[2] = (b).bits[2]; \
    (a).bits[3] = (b).bits[3]; \
  }

/**
 * @}
 *
 */

/**
 * @name Simple Decimal Operations
 * @addtogroup Internal
 *
 * @{
 */

/**
 * @brief get the sign of a decimal
 *
 * @param value Decimal
 * @retval 1 if negative
 * @retval 0 if positive
 */
int decimal_sign(s21_decimal value);

/**
 * @brief Set the sign of a decimal to 1
 *
 * @param dst Input decimal
 */
void decimal_set_sign(s21_decimal *dst);

/**
 * @brief get the scale of a decimal
 *
 * @param value Decimal
 * @return int scale
 */
int decimal_scale(s21_decimal value);

/**
 * @brief Set the scale of a decimal
 *
 * @param dst Input decimal
 * @param exp Scale
 */
void decimal_set_scale(s21_decimal *dst, int exp);

/**
 * @brief zeroing an decimal
 *
 * @param value decimal to be zeroed
 */
void decimal_zeroing(s21_decimal *value);

/**
 * @}
 *
 */

/**
 * @name Array Converters
 * @addtogroup Internal
 *
 * @{
 */

/**
 * @brief
 * convert decimal to array of 12 elements with scale 12
 *
 * @param value
 * variable which need convert to array
 * @param arr
 * array that will contain the answer
 *
 */
void from_decimal_to_array(s21_decimal value, unsigned arr[12]);

/**
 * @brief
 * convert decimal to array of 12 elements with scale 12
 *
 * @param val
 * array which need convert to decimal
 * @param result
 * variable that will contain answer
 * @param mod
 * 1 - there was a discard of the remainder
 * 0 - otherwise
 * @retval 0 - success
 * @retval 1 - overflow
 *
 */
int from_array_to_decimal(unsigned val[12], s21_decimal *result, int mod);

/**
 * @}
 *
 */

/**
 * @name Array Operations
 * @addtogroup Internal
 * @{
 */

/**
 * @brief
 * zeroing an array of 12 elements
 *
 * @param arr
 * array to be nulled
 *
 */
void array_zeroing(unsigned arr[12]);

/**
 * @brief
 * copying array a to array b
 *
 * @param a
 * copied array
 * @param b
 * result array
 *
 */
void array_copy(const unsigned a[12], unsigned b[12]);

/**
 * @}
 *
 */

/**
 * @name Array Checks
 * @addtogroup Internal
 * @{
 */

/**
 * @brief
 * check if all elements of an array are null
 *
 * @param arr
 * checkable array
 * @retval 0 if arr != 0
 * @retval 1 if arr == 0
 *
 */
int is_null_array(const unsigned arr[12]);

/**
 * @brief
 * check for equality to zero of elements from 3 to 11
 *
 * @param arr
 * checkable array
 * @retval 0 if arr != 0
 * @retval 1 if arr == 0
 *
 */
int is_null_array_high(const unsigned arr[12]);

/**
 * @brief
 * divisibility of an array by 10
 *
 * @param arr
 * checkable array
 * @retval 0 if arr % 10 != 0
 * @retval 1 if arr % 10 == 0
 *
 */
int is_divisible_by_10(unsigned arr[12]);

/**
 * @brief arrays equality check
 *
 * @param arr_1 first array
 * @param arr_2 second array
 * @retval 0 if arr_1 != arr_2
 * @retval 1 if arr_1 == arr_2
 */
int is_equal_arrays(const unsigned arr_1[12], const unsigned arr_2[12]);

/**
 * @brief check if the first array is less than the second
 *
 * @param arr_1 first array
 * @param arr_2 second array
 * @retval 0 if arr_1 >= arr_2
 * @retval 1 if arr_1 < arr_2
 */
int is_array_less(const unsigned arr_1[12], const unsigned arr_2[12]);

/**
 * @}
 *
 */

/**
 * @name Array Operations
 * @addtogroup Internal
 * @{
 */

/**
 * @brief
 * adding an array with 1
 *
 * @param arr
 * an array that adds up to 1
 */
void add_to_array_1(unsigned arr[12]);

/**
 * @brief
 * multiply an array elements by 10 with overflow
 *
 * @param arr
 * array which need to multiply
 *
 */
void multiply_array_by_10(unsigned arr[12]);

/**
 * @brief
 * each element of array divide by 10 and modulo
 * move to next element
 *
 * @param arr
 * array which need to divide
 * @return int
 * remainder of the division
 *
 */
int divide_array_by_10(unsigned arr[12]);

/**
 * @}
 *
 */

/**
 * @name Array Extras
 * @addtogroup Internal
 * @{
 */

/**
 * @brief find the middle of two arrays
 *
 * @param left Left array
 * @param right Right array
 * @param mid Middle array
 */
void find_mid(unsigned left[12], unsigned right[12], unsigned mid[12]);

/**
 * @}
 *
 */

#endif  // SRC_S21_HELPER_H
