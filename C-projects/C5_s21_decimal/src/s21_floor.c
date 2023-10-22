/**
 * @file s21_floor.c
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
 * Rounding towards negative infinity. If the number is positive,
 * then discard the fractional part. If the number is negative,
 * then subtract 1 and discard the remainder.
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result) {
    if (decimal_scale(value)) {
      if (decimal_sign(value) && !IS_ZERO(value)) {
        s21_decimal one = {{1, 0, 0, 0}}, tmp;
        s21_sub(value, one, &tmp);
        s21_truncate(tmp, result);
      } else {
        s21_truncate(value, result);
      }
    } else {
      COPY(*result, value);
    }
  }
  return 0;
}
