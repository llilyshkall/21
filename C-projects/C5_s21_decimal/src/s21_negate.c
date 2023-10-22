/**
 * @file s21_negate.c
 * @author chatayap
 * @brief
 * @version 0.1
 * @date 2023-02-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_decimal.h"

/**
 * copying the variable and inverting the 31st bit
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  int ret = 1;
  if (result) {
    decimal_zeroing(result);
    int sign = (((unsigned)value.bits[3] >> 31) & 1U) ^ 1U;
    for (int i = 0; i < 3; ++i) result->bits[i] = value.bits[i];
    result->bits[3] =
        ((unsigned)sign << 31) | ((unsigned)value.bits[3] & 0xFF0000);
    ret = 0;
  }
  return ret;
}
