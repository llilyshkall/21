#include "s21_string.h"
// Полина, это лучший код который я видел
char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  while (*str && *str != c) str++;
  if (*str == c) res = (char *)str;
  return res;
}
