#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t count = 0;
  char *tmp = dest;
  while (count < n) {
    *dest = *src;
    if (*src) {
      src++;
    }
    dest++;
    count++;
  }
  return tmp;
}
