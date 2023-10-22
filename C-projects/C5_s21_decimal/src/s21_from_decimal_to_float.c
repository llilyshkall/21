/**
 * @file s21_from_decimal_to_float.c
 * @author coriemis
 * @brief s21_from_decimal_to_float converter
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_decimal.h"

/**
 * Convert s21_decimal to float. If dst is NULL, return 1.
 * multiply each byte by 1, 2^32 and 2^64, then divide by 10^exp
 * if the number is negative, multiply by -1.
 * Convert the result to a string, then convert the string to a float
 * to accurately round the number.
 *
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  if (!dst)
    status = 1;
  else {
    int sign = decimal_sign(src);
    int exp = decimal_scale(src);

    long double res = 0;
    res += (unsigned)src.bits[0];
    res += powl(2, 32) * (unsigned)src.bits[1];
    res += powl(2, 64) * (unsigned)src.bits[2];

    res /= powl(10.0, exp);
    if (sign) res *= -1;
    char buf[30] = {'\0'};
    sprintf(buf, "%.20Lg", res);
    sscanf(buf, "%f", dst);
  }
  return status;
}
