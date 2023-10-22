/**
 * @file s21_sub.c
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
 * Sbstraction of two variables of type decimal.
 * If variable result is NULL, result will not be recorded and
 * it will be checked whether it is possible to sub them.
 * Variables convert into array of 12 unsigned elements.
 * Sub 2 arrays element by element, including overflow.
 * Convert the resulting array to a variable of type decimal.
 *
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int ret = 0;
  if (result) decimal_zeroing(result);
  if (decimal_sign(value_1) == decimal_sign(value_2)) {  // equal signs case
    unsigned ans[12], sign_res = decimal_sign(value_1);
    if (decimal_sign(value_1)) {
      // if negative substract negative then change signs and
      // change sign and change answer sign
      // value_1 - value_2 = - (|value_1| - (-|value_2|))
      s21_negate(value_1, &value_1);
      s21_negate(value_2, &value_2);
    }
    if (s21_is_less(value_1, value_2)) {  // if second is greater than first
      sign_res = !sign_res;  // change answer sign and substract first from
                             // second value_1 - value_2 = -(value_2 - value_1)
      decimal_sub(value_2, value_1, ans);  // element-by-element subtraction
    } else {
      decimal_sub(value_1, value_2, ans);  // element-by-element subtraction
    }
    from_array_to_decimal(ans, result, 0);          // reverse conversion
    if (result && sign_res && !is_null_array(ans))  // if variables is negate
      s21_negate(*result, result);                  // change sign
  } else {                                          // equal signs case
    s21_negate(value_2, &value_2);                  // change second sign
    ret = s21_add(value_1, value_2, result);        // and addition
  }
  return ret;
}

/**
 * convert two variables of type decimal to array and
 * elementwise substraction, taking into account overflow
 */
void decimal_sub(s21_decimal value_1, s21_decimal value_2, unsigned ans[12]) {
  unsigned arr_1[12], arr_2[12];
  from_decimal_to_array(value_1, arr_1);
  from_decimal_to_array(value_2, arr_2);

  array_sub(arr_1, arr_2, ans);
}

/**
 * inverting the second array and elementwise addition
 * of the second array with the first array,
 * taking into account overflow
 */
void array_sub(unsigned arr_1[12], unsigned arr_2[12], unsigned ans[12]) {
  unsigned long long over = 1;
  array_zeroing(ans);
  for (int i = 0; i < 12; ++i) arr_2[i] = ~arr_2[i];
  for (int i = 0; i < 12; ++i) {
    unsigned long long calc = (unsigned long long)arr_1[i] + arr_2[i] + over;
    over = calc >> 32;
    ans[i] = calc & 0xFFFFFFFF;
  }
}
