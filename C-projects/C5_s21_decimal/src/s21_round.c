/**
 * @file s21_round.c
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
 * subtraction modulo 0.5, discarding the fractional part
 * and adding 1
 */
int s21_round(s21_decimal value, s21_decimal *result) {
  if (result) {
    if (decimal_scale(value) != 0) {
      s21_decimal zero = {{0, 0, 0, 0}}, half = {{5, 0, 0, 1U << 16}},
                  minus_half = {{5, 0, 0, (1U << 16) | (1U << 31)}},
                  one = {{1, 0, 0, 0}};
      if (s21_is_less(value, half) &&
          s21_is_greater(value, minus_half))  // -0.5 < value < 0.5
        COPY(*result, zero)                   // rounding down to zero

      if (s21_is_greater_or_equal(value, half)) {  // value >= 0.5
        s21_sub(value, half, &value);              // subtract 0.5
        s21_truncate(value, &value);  // discard the fractional part
        s21_add(value, one, result);  // add 1
      }

      if (s21_is_less_or_equal(value, minus_half)) {
        s21_add(value, half, &value);  // add 0.5
        s21_truncate(value, &value);   // discard the fractional part
        s21_sub(value, one, result);   // substract 1
      }
    } else {
      COPY(*result, value);
    }
  }
  return 0;
}
