/**
 * @file s21_truncate.c
 * @author chatayap
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_decimal.h"

/**
 * element-wise division by 10, taking into account the remainder.
 * Division occurs until the scale is zero
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  while (decimal_scale(value)) {  // check scale
    unsigned long long mod = 0;
    for (int i = 2; i >= 0; --i) {  // element-wise division by 10
      unsigned long long calc = (unsigned)value.bits[i] + (mod << 32);
      mod = calc % 10;
      value.bits[i] = calc / 10;
    }
    value.bits[3] -= 1 << 16;  // scale down by 1
  }
  if (IS_ZERO(value)) value.bits[3] = 0;
  if (result) COPY(*result, value);  // copying a variable
  return 0;
}
