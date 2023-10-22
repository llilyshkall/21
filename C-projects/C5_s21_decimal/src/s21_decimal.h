/**
 * @file s21_decimal.h
 * @author 69 Team
 * @brief Implementation of decimal library
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SRC_S21_DECIMAL_H
#define SRC_S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @addtogroup Types
 * @{
 */

/**
 * @brief Decimal structure
 * The structure is used to store a big number
 * The number is stored in the following format:
 * bits[0] - bits[2] - a 96 bit integer
 * bits[3] - contains the exponent of the number at base 10 in the third byte
 * and the sign of the number in the fourth byte at pos 31
 *
 */
typedef struct {
  int bits[4]; /**< 96 bit integer + 32 bit exponent + 1 bit sign */
} s21_decimal;

/**
 * @}
 *
 */

#include "s21_helper.h"

/**
 * @addtogroup Constants
 * @{
 */

/**
 * @brief Decimal constant
 * @param MAX_DECIMAL - Maximum decimal number
 */
#define MAX_DECIMAL 79228162514264337593543950335.L

/**
 * @brief Decimal constant
 * @param MIN_DECIMAL - Minimum decimal number
 */
#define MIN_DECIMAL -79228162514264337593543950335.L

/**
 * @}
 *
 */

/**
 * @addtogroup Operators
 * @{
 */

/**
 * @brief Adds two specified s21_decimal values
 *
 * @param value_1 The first input decimal to add
 * @param value_2 The second input decimal to add
 * @param result The sum of value_1 and value_2
 * If the pointer is zero, the record will not be placed in the variable
 * @retval 0 OK
 * @retval 1 Error: the number is too large or equal to infinity
 * @retval 2 Error: the number is too small or equal to negative infinity
 * @retval 3 Error: division by 0
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief substraction two variables of type decimal
 *
 * @param value_1 minuend variable
 * @param value_2 subtrahend variable
 * @param result variable in which the response is written.
 * If the pointer is zero, the record will not be placed in the variable
 * @retval 0 OK
 * @retval 1 Error: the number is too large
 * @retval 2 Error: the number is too small
 *
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief multiplication of two variables of type decimal
 *
 * @param value_1 first multiplier variable
 * @param value_2 second multiplier variable
 * @param result variable in which the response is written.
 * If the pointer is zero, the record will not be placed in the variable
 * @retval 0 OK
 * @retval 1 Error: the number is too large
 * @retval 2 Error: the number is too small
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief division of two variables of type decimal
 *
 * @param value_1 dividend variable
 * @param value_2 divisor variable
 * @param result quotient variable
 * @retval 0 OK
 * @retval 1 Error: the quotient is too large
 * @retval 2 Error: the quotient is too small
 * @retval 3 Error: division by 0
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @brief Modulo of two variables of type decimal
 * If the pointer is zero, the record will not be placed in the variable
 * @param value_1 dividend variable
 * @param value_2 divisor variable
 * @param result remainder variable
 * @retval 0 OK
 * @retval 1 Error: the quotient is too large
 * @retval 2 Error: the quotient is too small
 * @retval 3 Error: division by 0
 */
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/**
 * @}
 *
 */

/**
 * @addtogroup Comparators
 * @{
 */

/**
 * @brief Less than comparison of two decimal numbers
 *
 * @param value_1 The first decimal to compare
 * @param value_2 The second decimal to compare
 * @retval 1 if value_1 < value_2
 * @retval 0 if value_1 >= value_2
 */
int s21_is_less(s21_decimal, s21_decimal);

/**
 * @brief Less than or equal comparison of two decimal numbers
 *
 * @param value_1 The first decimal to compare
 * @param value_2 The second decimal to compare
 * @retval 1 if value_1 <= value_2
 * @retval 0 if value_1 > value_2
 */
int s21_is_less_or_equal(s21_decimal, s21_decimal);

/**
 * @brief Greater than comparison of two decimal numbers
 *
 * @param value_1 The first decimal to compare
 * @param value_2 The second decimal to compare
 * @retval 1 if value_1 > value_2
 * @retval 0 if value_1 <= value_2
 */
int s21_is_greater(s21_decimal, s21_decimal);

/**
 * @brief Greater than or equal comparison of two decimal numbers
 *
 * @param value_1 The first decimal to compare
 * @param value_2 The second decimal to compare
 * @retval 1 if value_1 >= value_2
 * @retval 0 if value_1 < value_2
 */
int s21_is_greater_or_equal(s21_decimal, s21_decimal);

/**
 * @brief Equal comparison of two decimal numbers
 *
 * @param value_1 The first decimal to compare
 * @param value_2 The second decimal to compare
 * @retval 1 if value_1 == value_2
 * @retval 0 if value_1 != value_2
 */
int s21_is_equal(s21_decimal, s21_decimal);

/**
 * @brief Not equal comparison of two decimal numbers
 *
 * @param value_1 The first decimal to compare
 * @param value_2 The second decimal to compare
 * @retval 1 if value_1 != value_2
 * @retval 0 if value_1 == value_2
 */
int s21_is_not_equal(s21_decimal, s21_decimal);

/**
 * @}
 *
 */

/**
 * @addtogroup Converters
 * @{
 */

/**
 * @brief Converts integer to decimal
 *
 * @param src Input integer
 * @param dst Destination pointer to the s21_decimal type
 * @retval 0 OK
 * @retval 1 Сonvertation error
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst);  // из int

/**
 * @brief Converts float to decimal
 *
 * @param src Input float
 * @param dst Destination pointer to the s21_decimal type
 * @retval 0 OK
 * @retval 1 Сonvertation error
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst);

/**
 * @brief Converts decimal to integer
 *
 * @param src Input decimal
 * @param dst Destination pointer to the integer type
 * @retval 0 OK
 * @retval 1 Сonvertation error
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst);  // в int

/**
 * @brief Converts decimal to float
 *
 * @param src Input decimal
 * @param dst Destination pointer to the float type
 * @retval 0 OK
 * @retval 1 Сonvertation error
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/**
 * @}
 *
 */

/**
 * @addtogroup Other
 * @{
 */

/**
 * @brief Rounds a specified Decimal number to the closest integer toward
 * negative infinity.
 *
 * @param value Input decimal
 * @param result Destination decimal
 * @retval 0 OK
 * @retval 1 Calculation error
 */
int s21_floor(s21_decimal value, s21_decimal *result);

/**
 * @brief Rounds a specified Decimal number to the closest integer
 *
 * @param value Input decimal
 * @param result Destination decimal
 * @retval 0 OK
 * @retval 1 Calculation error
 */
int s21_round(s21_decimal value, s21_decimal *result);

/**
 * @brief Returns the integral digits of a specified Decimal number.
 *
 * @param value Input decimal
 * @param result Destination decimal
 * @retval 0 OK
 * @retval 1 Calculation error
 */
int s21_truncate(s21_decimal value, s21_decimal *result);

/**
 * @brief Returns the inverse of the specified Decimal number.
 *
 * @param value Input decimal
 * @param result Destination decimal
 * @retval 0 OK
 * @retval 1 Calculation error
 */
int s21_negate(s21_decimal value, s21_decimal *result);

/**
 * @}
 *
 */

/**
 * @name Operations with arrays
 * @addtogroup Internal
 *
 * @{
 */

/**
 * @brief convert two variables of type decimal to array and adds them up
 *
 * @param value_1 first term
 * @param value_2 second term
 * @param ans array for record answer
 */
void decimal_add(s21_decimal value_1, s21_decimal value_2, unsigned ans[12]);

/**
 * @brief element-wise addition of two arrays, taking into account overflow
 *
 * @param arr_1 first array-term
 * @param arr_2 second array-term
 * @param ans array for record answer
 */
void array_add(unsigned arr_1[12], const unsigned arr_2[12], unsigned ans[12]);

/**
 * @brief convert two variables of type decimal to array and substracting them
 *
 * @param value_1 minuend variable
 * @param value_2 subtrahend variable
 * @param ans array for record answer
 */
void decimal_sub(s21_decimal value_1, s21_decimal value_2, unsigned ans[12]);

/**
 * @brief element-wise substraction of two arrays, taking into account overflow
 *
 * @param arr_1 minuend array
 * @param arr_2 subtrahend array
 * @param ans array for record answer
 */
void array_sub(unsigned arr_1[12], unsigned arr_2[12], unsigned ans[12]);

/**
 * @brief convert two variables of type decimal to array and multiply them
 *
 * @param value_1 first multiplier variable
 * @param value_2 second multiplier variable
 * @param ans array for record answer
 * @retval 1 - there was a rejection of the fractional part
 * @retval 0 - otherwise
 */
int decimal_mul(s21_decimal value_1, s21_decimal value_2, unsigned ans[12]);

/**
 * @brief element-by-element multiplication of two arrays "in a column"
 * taking into account overflow
 *
 * @param arr_1 first multiplier array
 * @param arr_2 second multiplier array
 * @param ans array for record answer
 * @retval 1 - there was a rejection of the fractional part
 * @retval 0 - otherwise
 */
int array_mul(unsigned arr_1[12], const unsigned arr_2[12], unsigned ans[12]);

/**
 * @brief convert two variables of type decimal to array and divide them
 *
 * @param value_1 first division variable
 * @param value_2 second division variable
 * @param ans array for storing the answer
 * @param case_max Calculation limit
 * @retval 1 - there was a rejection of the fractional part
 * @retval 0 - otherwise
 */
int decimal_div(s21_decimal value_1, s21_decimal value_2, unsigned ans[12],
                int case_max);

/**
 * @brief element-by-element division of two arrays "in a column"
 * taking into account overflow
 *
 * @param arr_1 first division array
 * @param arr_2 second division array
 * @param ans array for storing the answer
 * @param case_max Calculation limit
 * @retval 1 - there was a rejection of the fractional part
 * @retval 0 - otherwise
 */
int array_div(unsigned arr_1[12], unsigned arr_2[12], unsigned ans[12],
              int case_max);

/**
 * @}
 *
 */

#endif  // SRC_S21_DECIMAL_H
