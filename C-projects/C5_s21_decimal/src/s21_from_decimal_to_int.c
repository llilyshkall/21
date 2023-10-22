/**
 * @file s21_from_decimal_to_int.c
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
 * Convert decimal to int.
 * Discard the remainder and check
 * if the resulting number fits into an int.
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int ret = 0;
  s21_truncate(src, &src);
  if (!src.bits[1] && !src.bits[2] &&
      ((((unsigned)src.bits[0] < 0x80000000) && !decimal_sign(src)) ||
       (((unsigned)src.bits[0] <= 0x80000000) && decimal_sign(src)))) {
    if (dst) {
      *dst = src.bits[0];
      if (decimal_sign(src)) *dst *= -1;
    }
  } else {
    if (dst) *dst = 0;
    ret = 1;
  }
  return ret;
}
