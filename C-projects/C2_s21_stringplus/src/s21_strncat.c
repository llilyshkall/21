#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  dest += s21_strlen(dest);
  s21_size_t count = 0;
  while (count < n && *src) {
    *dest = *src;
    count++;
    dest++;
    src++;
  }
  *dest = '\0';
  return tmp;
}
