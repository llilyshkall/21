/**
 * @file s21_from_int_to_decimal.c
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
 * Convert int to decimal.
 * The dst is always zeroed first.
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int ret = 1;
  if (dst) {
    decimal_zeroing(dst);
    if (src < 0) {
      dst->bits[0] = src * (-1);
      dst->bits[3] = 1U << 31;
    } else {
      dst->bits[0] = src;
    }
    ret = 0;
  }
  return ret;
}
