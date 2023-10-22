/**
 * @file s21_mul.c
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
 * convert variables of type decimal to array and
 * element-wise multiplication of arrays with overflow.
 * convert back to decimal and select sign.
 * in case of overflow, set the variable to zero
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = 0;
  unsigned ans[12];
  int mod = decimal_mul(value_1, value_2, ans);
  if (result) decimal_zeroing(result);
  ret = from_array_to_decimal(ans, result, mod);
  if (decimal_sign(value_1) != decimal_sign(value_2)) {
    if (ret) {
      ret++;
    } else {
      if (result) {
        s21_negate(*result, result);
        if (IS_ZERO(*result)) decimal_zeroing(result);
      }
    }
  }
  return ret;
}

/**
 * convert two variables of type decimal to array and multiply them
 *
 */
int decimal_mul(s21_decimal value_1, s21_decimal value_2, unsigned ans[12]) {
  unsigned arr_1[12], arr_2[12];
  from_decimal_to_array(value_1, arr_1);
  from_decimal_to_array(value_2, arr_2);

  return array_mul(arr_1, arr_2, ans);
}

/**
 * element-by-element multiplication of two arrays "in a column"
 * taking into account overflow
 */
int array_mul(unsigned arr_1[12], const unsigned arr_2[12], unsigned ans[12]) {
  array_zeroing(ans);
  for (int i = 0; i < 11; ++i) {
    for (int j = 0; j < 11; ++j) {
      if (i + j < 12) {
        unsigned long long calc =
            (unsigned long long)arr_1[i] * arr_2[j] + ans[i + j];
        ans[i + j] = (calc & 0xFFFFFFFF);
        unsigned long long over = calc >> 32;
        for (int k = i + j + 1; k < 12; ++k) {
          calc = (unsigned long long)ans[k] + over;
          over = calc >> 32;
          ans[k] = calc & 0xFFFFFFFF;
        }
      }
    }
  }
  int mod = 0;
  for (int i = 0; i < 28; ++i) mod = divide_array_by_10(ans) ? 1 : mod;
  return mod;
}
