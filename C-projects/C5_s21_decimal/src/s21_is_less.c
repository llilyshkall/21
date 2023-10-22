/**
 * @file s21_is_less.c
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
 * convert two variables of type decimal to array and
 * search for the first mismatch including sign
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  unsigned arr_1[12], arr_2[12];
  from_decimal_to_array(value_1, arr_1);
  from_decimal_to_array(value_2, arr_2);
  int i = 11, ret;
  while (i > 0 && (arr_1[i] == arr_2[i])) i--;
  if (decimal_sign(value_1) && decimal_sign(value_2)) ret = arr_1[i] > arr_2[i];
  if (!decimal_sign(value_1) && !decimal_sign(value_2))
    ret = arr_1[i] < arr_2[i];
  if (decimal_sign(value_1) != decimal_sign(value_2))
    ret = decimal_sign(value_1) > decimal_sign(value_2);

  return ret;
}
