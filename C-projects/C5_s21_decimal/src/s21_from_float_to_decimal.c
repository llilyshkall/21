/**
 * @file s21_from_float_to_decimal.c
 * @author coriemis
 * @brief s21_from_float_to_decimal converter
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "s21_from_float_to_decimal.h"

#include "s21_decimal.h"

/**
 * Set the value of a decimal from a reverse binary string
 */
void set_value_str(s21_decimal *dst, char *s) {
  for (int i = strlen(s) - 1; i >= 0; i--)
    if (s[i] - '0') dst->bits[i / 32] |= (1UL << (i % 32));
}

int frac_exp(float src) {
  int x = 0;
  while (src < 1) {
    src *= 10;
    x++;
  }
  return x;
}

int whole_exp(float src) {
  int x = 0;
  while (src > 1) {
    src /= 10;
    x++;
  }
  return x;
}

void removeE(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] == 'e') str[i] = '\0';
  }
}

/**
 * Handle really small floats. Round the float to 28 decimal places.
 */
int smallFloat(char *str, int f_exp) {
  long double f = atof(str);
  int k = f_exp;
  for (int i = 0; i < 28 - k; i++) {
    f *= 10.L;
    f_exp++;
  }
  f = roundl(f);
  while ((int)f % 10 == 0) {
    f = f / 10;
    f_exp--;
  }
  sprintf(str, "%d", (int)f);
  return f_exp;
}

/**
 * Multiply a binary string by 10.
 * First we multiply by 2^3, then by 2.
 * And then we sum the results.
 */
void mul10_96(char *src) {  // multiply binary by 10
  char a3[97] = {'\0'};
  memset(a3, '0', 96);
  memcpy(a3 + 3, src, 93);
  for (unsigned int i = 95; i > 0; i--) src[i] = src[i - 1];  // refactor
  src[0] = '0';
  int carry = 0;
  for (unsigned int i = 0; i < strlen(src); i++) {
    int sum = src[i] + a3[i] - 96 + carry;
    carry = sum > 1 ? 1 : 0;
    src[i] = sum % 2 + '0';
  }
}

void mul10mul_96(char *src, int n) {
  for (int i = 0; i < n; i++) mul10_96(src);
}

void toBin_96(int x, char *s) {
  memset(s, '0', 96);
  for (int i = 0; x > 0; i++) {
    s[i] = x % 2 ? '1' : '0';
    x /= 2.;
  }
}

/**
 * Convert a float to a string to 7 digit accuracy.
 * Handle really small floats.
 * Return the exponent of the float.
 */
int floatToStr(char *str, long double tmp, int *w_exp) {
  *w_exp = whole_exp(tmp);     // get exponent of whole
  int f_exp = frac_exp(tmp);   // get exponet of fraction
  sprintf(str, "%.7Lg", tmp);  // write to buffer
  char *tstr = str;
  int beforep = 0, zeroes = 0, ex;
  removeE(str);
  if (f_exp > 21) f_exp = smallFloat(str, f_exp);
  while (*tstr && *tstr != '.') {
    tstr++;  // move to point if there is one
    beforep++;
  }
  if (*tstr) tstr++;  // move after point
  zeroes += strlen(tstr);
  ex = f_exp > 4 ? zeroes + f_exp : zeroes;
  ex = *w_exp > 7 ? 0 : ex;
  char res[129] = {'\0'};
  if (str[0] != '0') strncpy(res, str, beforep);
  strcat(res, tstr);  // append the numbers after
  strcpy(str, res);
  return ex;
}

/**
 * Convert a float to a decimal using string magic.
 * Extreme values of src are handled.
 * Return 1 if src is out of range or dst is NULL.
 * Return 0 if successful.
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int status = 0;
  if (dst && fabs(src) >= 1e-28 && fabs(src) <= MAX_DECIMAL) {
    decimal_zeroing(dst);                    // clear decimal
    char str[129] = {'\0'}, s[97] = {'\0'};  // create buffers
    long double tmp = fabsl(src);            // copy the float
    int w_exp;
    int ex = floatToStr(str, tmp, &w_exp);  // convert float to string
    int x = atoi(str);                      // convert string to int
    toBin_96(x, s);                         // convert int to binary string
    mul10mul_96(s, w_exp - strlen(str));    // multiply by 10^exponent
    if (src < 0) decimal_set_sign(dst);
    set_value_str(dst, s);       // set the value of the decimal
    decimal_set_scale(dst, ex);  // set the scale of the decimal
  } else {
    if (dst) decimal_zeroing(dst);
    status = 1;
  }
  return status;
}
