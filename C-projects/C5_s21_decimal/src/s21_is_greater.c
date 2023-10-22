/**
 * @file s21_is_greater.c
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
 * swapping two variables and calling function s21_is_less
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_2, value_1);
}
