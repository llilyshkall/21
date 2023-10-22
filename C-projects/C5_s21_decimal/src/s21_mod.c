/**
 * @file s21_mod.c
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
 * Get the remainder of the division of two numbers
 * stored in s21_decimal format.
 */
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = IS_ZERO(value_2) * 3;  // check division by zero
  if (result) decimal_zeroing(result);
  if (!ret) {
    unsigned arr_1[12], arr_2[12], int_part[12], mul_int_part[12], ans[12];
    s21_decimal trunc;
    from_decimal_to_array(value_1, arr_1);
    from_decimal_to_array(value_2, arr_2);
    if (!s21_div(value_1, value_2, &trunc)) {
      s21_truncate(trunc, &trunc);
      from_decimal_to_array(trunc, int_part);
    } else {
      decimal_div(value_1, value_2, int_part, 1);

      for (int i = 0; i < 28; ++i) divide_array_by_10(int_part);
      for (int i = 0; i < 28; ++i) multiply_array_by_10(int_part);
    }
    array_mul(int_part, arr_2, mul_int_part);
    array_sub(arr_1, mul_int_part, ans);
    from_array_to_decimal(ans, result, 0);
    if (decimal_sign(value_1) && !is_null_array(ans) && result)
      s21_negate(*result, result);
  }
  return ret;
}
