/**
 * @file s21_div.c
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
 * Dividing two decimals. Th input decimal is checked for division by zero.
 * If the result variable is NULL, the result will not be recorded, but it will
 * still be calculated, if possible.
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = IS_ZERO(value_2) * 3;
  if (result) decimal_zeroing(result);
  if (!ret) {
    // overflow check
    s21_decimal value_tmp = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    unsigned result_tmp[12], arr_tmp[12];
    from_decimal_to_array(value_1, arr_tmp);
    decimal_mul(value_2, value_tmp, result_tmp);
    if (is_array_less(result_tmp, arr_tmp))
      ret = (decimal_sign(value_1) != decimal_sign(value_2)) + 1;
  }
  if (!ret) {
    unsigned ans[12];
    int mod = decimal_div(value_1, value_2, ans, 0);
    from_array_to_decimal(ans, result, mod);
    // if result is negate
    if (result && (decimal_sign(value_1) != decimal_sign(value_2)))
      s21_negate(*result, result);  // change sign
  }
  return ret;
}

/**
 * Convert two decimals to arrays and divide them.
 */

int decimal_div(s21_decimal value_1, s21_decimal value_2, unsigned ans[12],
                int case_max) {
  unsigned arr_1[12], arr_2[12];
  from_decimal_to_array(value_1, arr_1);
  from_decimal_to_array(value_2, arr_2);
  return array_div(arr_1, arr_2, ans, case_max);
}

/**
 * Dividing two arrays by using binary search.
 * The ans is zeroed before the division.
 * The case_max is used to determine the maximum value of the result.
 */
int array_div(unsigned arr_1[12], unsigned arr_2[12], unsigned ans[12],
              int case_max) {
  unsigned left[12], right[12], mid[12], l[12], r[12], tmp_ans[12];
  s21_decimal min = {{0, 0, 0, 0}},
              max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  array_zeroing(l);
  array_zeroing(r);
  array_zeroing(ans);
  from_decimal_to_array(min, left);
  from_decimal_to_array(max, right);
  if (case_max) {
    for (int i = 0; i < 28; ++i) multiply_array_by_10(right);
  }
  while (!is_equal_arrays(l, left) || !is_equal_arrays(r, right)) {
    array_copy(left, l);
    array_copy(right, r);
    find_mid(left, right, mid);
    array_mul(mid, arr_2, tmp_ans);
    if (is_array_less(tmp_ans, arr_1))
      array_copy(mid, left);
    else
      array_copy(mid, right);
  }

  array_mul(right, arr_2, tmp_ans);
  if (is_equal_arrays(tmp_ans, arr_1))
    array_copy(right, ans);
  else
    array_copy(left, ans);
  return !is_equal_arrays(tmp_ans, arr_1);
}
