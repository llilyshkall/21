/**
 * @file s21_is_equal.c
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
 * convert two variables of decimal to array and
 * element-by-element comparison
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  unsigned arr_1[12], arr_2[12];
  if (IS_ZERO(value_1)) value_1.bits[3] = 0;
  if (IS_ZERO(value_2)) value_2.bits[3] = 0;
  from_decimal_to_array(value_1, arr_1);
  from_decimal_to_array(value_2, arr_2);
  int ret = 1;
  for (int i = 0; i < 12; ++i) ret = ret && (arr_1[i] == arr_2[i]);
  return (ret && (decimal_sign(value_1) == decimal_sign(value_2)));
}
