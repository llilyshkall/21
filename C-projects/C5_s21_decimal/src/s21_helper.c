/**
 * @file s21_helper.c
 * @author chatayap, coriemis
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_decimal.h"

void decimal_set_sign(s21_decimal *dst) { dst->bits[3] |= 1UL << 31; }

/**
 * Set the exponent by first clearing the exponent bits, then setting the
 * exponent bits to the value of the input parameter
 */
void decimal_set_scale(s21_decimal *dst, int exp) {
  int sign = decimal_sign(*dst);
  dst->bits[3] = 0;
  if (sign) decimal_set_sign(dst);
  dst->bits[3] |= (exp << 16);
}

int decimal_sign(s21_decimal value) {
  return ((unsigned)value.bits[3] >> 31) & 1;
}

int decimal_scale(s21_decimal value) {
  return ((unsigned)value.bits[3] & 0xFF0000) >> 16;
}

void decimal_zeroing(s21_decimal *value) {
  for (int i = 0; i < 4; ++i) value->bits[i] = 0;
}

/**
 * Copy field bits[0..2] and multiply by 10
 * until we reach the desired scale
 */
void from_decimal_to_array(s21_decimal value, unsigned arr[12]) {
  array_zeroing(arr);
  for (int i = 0; i < 3; ++i) arr[i] = value.bits[i];
  for (int i = 0; i < 28 - decimal_scale(value); ++i) multiply_array_by_10(arr);
}

/**
 * Divide by 10 until high elements is not equal to zero.
 * Copy the array into decimal
 *
 */
int from_array_to_decimal(unsigned arr[12], s21_decimal *result, int mod) {
  int shift = is_null_array(arr) ? 28 : 0;
  while (is_divisible_by_10(arr) && shift < 28 && !mod) {
    divide_array_by_10(arr);
    shift++;
  }
  while (!is_null_array_high(arr) && shift < 28) {
    int tmp = divide_array_by_10(arr);
    shift++;
    mod |= tmp;
  }
  if (mod && (arr[0] & 1)) add_to_array_1(arr);

  if (result) {
    if (is_null_array_high(arr) && !is_null_array(arr)) {
      for (int i = 0; i < 3; ++i) result->bits[i] = arr[i];
      result->bits[3] = (28 - shift) << 16;
    } else {
      decimal_zeroing(result);
    }
  }
  return !is_null_array_high(arr);
}

void array_zeroing(unsigned arr[12]) {
  for (int i = 0; i < 12; ++i) arr[i] = 0;
}

void array_copy(const unsigned a[12], unsigned b[12]) {
  for (int i = 0; i < 12; ++i) b[i] = a[i];
}

int is_null_array(const unsigned arr[12]) {
  int ret = 1;
  for (int i = 0; i < 12; ++i) ret = ret && !arr[i];
  return ret;
}

/**
 * Check if the array elements from 3 to 11 are equal to zero
 *
 */
int is_null_array_high(const unsigned arr[12]) {
  int ret = 1;
  for (int i = 3; i < 12; ++i) ret = ret && !arr[i];
  return ret;
}

int is_divisible_by_10(unsigned arr[12]) {
  unsigned tmp[12];
  array_copy(arr, tmp);
  return !divide_array_by_10(tmp);
}

int is_equal_arrays(const unsigned arr_1[12], const unsigned arr_2[12]) {
  int ret = 1;
  for (int i = 0; i < 12; ++i) ret = ret && (arr_1[i] == arr_2[i]);
  return ret;
}

int is_array_less(const unsigned arr_1[12], const unsigned arr_2[12]) {
  int i = 11;
  while (i && (arr_1[i] == arr_2[i])) i--;
  return arr_1[i] < arr_2[i];
}

void add_to_array_1(unsigned arr[12]) {
  unsigned tmp[12], ans[12];
  array_zeroing(tmp);
  tmp[0] = 1;
  array_add(arr, tmp, ans);
  array_copy(ans, arr);
}

void multiply_array_by_10(unsigned arr[12]) {
  unsigned long long over = 0;
  for (int j = 0; j < 12; ++j) {
    // multiply element and add overflow
    unsigned long long calc = (unsigned long long)arr[j] * 10 + over;
    // save overflow
    over = calc >> 32;
    // select 32 bits
    arr[j] = calc & 0xFFFFFFFF;
  }
}

int divide_array_by_10(unsigned arr[12]) {
  unsigned long long mod = 0;
  for (int i = 11; i >= 0; --i) {
    // init element
    unsigned long long calc = ((unsigned long long)mod << 32) + arr[i];
    // save overflow
    mod = calc % 10;
    // divide element by 10
    arr[i] = calc / 10;
  }
  return mod;
}

void find_mid(unsigned left[12], unsigned right[12], unsigned mid[12]) {
  array_add(left, right, mid);
  unsigned mod = 0;
  for (int i = 11; i >= 0; --i) {
    unsigned tmp = mod;
    mod = mid[i] & 1;
    mid[i] = (mid[i] >> 1) | (tmp << 31);
  }
}
