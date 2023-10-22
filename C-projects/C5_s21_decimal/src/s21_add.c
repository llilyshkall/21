/**
 * @file s21_add.c
 * @author chatayap
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_decimal.h"

/**
 * Sum of two decimals.
 * If the result variable is NULL, the result will not be recorded, but it will
 * still be calculated, if possible. Variables are converted to an array of 12
 * unsigned elements. The 2 arrays are converted element by element, including
 * overflow. The resulting array is converted to a variable of type decimal.
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = 0;
  if (result) decimal_zeroing(result);
  if (decimal_sign(value_1) == decimal_sign(value_2)) {  // same signs
    unsigned ans[12];
    decimal_add(value_1, value_2, ans);
    ret = from_array_to_decimal(ans, result, 0);
    if (result && decimal_sign(value_1))  // if variable is negative
      s21_negate(*result, result);
    if (ret) ret += decimal_sign(value_1);  // Sign of the overflow
  } else {                                  // different signs
    if (decimal_sign(value_1)) {            // if value_1 is negative
      s21_negate(value_1, &value_1);
      ret = s21_sub(value_2, value_1, result);
    } else {  // if value_2 is negative
      s21_negate(value_2, &value_2);
      ret = s21_sub(value_1, value_2, result);
    }
  }
  return ret;
}

/**
 * Convert two decimals to arrays and add them with
 * array_add function
 */
void decimal_add(s21_decimal value_1, s21_decimal value_2, unsigned ans[12]) {
  unsigned arr_1[12], arr_2[12];
  from_decimal_to_array(value_1, arr_1);
  from_decimal_to_array(value_2, arr_2);

  array_add(arr_1, arr_2, ans);
}

/**
 * Add two arrays of 12 unsigned elements.
 * Account for overflow.
 */
void array_add(unsigned arr_1[12], const unsigned arr_2[12], unsigned ans[12]) {
  unsigned long long over = 0;
  array_zeroing(ans);
  for (int i = 0; i < 11; ++i) {
    unsigned long long calc = (unsigned long long)arr_1[i] + arr_2[i] + over;
    over = calc >> 32;
    ans[i] = calc & 0xFFFFFFFF;
  }
}
