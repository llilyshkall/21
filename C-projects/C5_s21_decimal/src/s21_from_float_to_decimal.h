/**
 * @file s21_from_float_to_decimal.h
 * @author coriemis
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef S21_FROM_FLOAT_TO_DECIMAL_H
#define S21_FROM_FLOAT_TO_DECIMAL_H

#include "s21_decimal.h"

/**
 * @name Utility methods for float conversion
 * @addtogroup Internal
 * @{
 */

/**
 * @brief Set the mantissa of decimal from binary string
 * The string is in reverse order
 * @param dst Decimal
 * @param s Binary string
 */
void set_value_str(s21_decimal *dst, char *s);

/**
 * @brief Get exponent of fraction part
 *
 * @param src Input float number
 * @return int Exponent in int value
 */
int frac_exp(float src);

/**
 * @brief Get exponent of integer part
 *
 * @param src Input float number
 * @return int Exponent as int value
 */
int whole_exp(float src);

/**
 * @brief Remove 'e' from string and replaces it with a null character
 *
 * @param str Input string
 */
void removeE(char *str);

/**
 * @brief Handle small float value rounding
 *
 * @param str String that contains the float value
 * @param f_exp Fractional exponent
 * @return int Modified fractional exponent
 */
int smallFloat(char *str, int f_exp);

/**
 * @brief Convert float to string rounded to 7 decimal places
 *
 * @param str String buffer to use
 * @param tmp The long double that holds the float value
 * @param w_exp Exponent of the integer part
 * @return int The total exponent
 */
int floatToStr(char *str, long double tmp, int *w_exp);

/**
 * @brief Multipy a binary string by 10
 *
 * @param src Source binary string of size 96
 */
void mul10_96(char *src);

/**
 * @brief Multiply a binary string by 10 n times
 *
 * @param src Source binary string of size 96
 * @param n Number of times to multiply
 */
void mul10mul_96(char *src, int n);

/**
 * @brief Convert an int to a binary string
 *
 * @param x Int to be converted
 * @param s Buffer with size of 96
 */
void toBin_96(int x, char *s);

/**
 * @}
 *
 */

#endif /* S21_FROM_FLOAT_TO_DECIMAL_H */
