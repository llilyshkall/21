#include "s21_string.h"

// https://habr.com/ru/post/272269/

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *line = (unsigned char *)str;
  while (n > 0) {  // while (n > 0 && *line1) ?
    *line = c;
    line++;
    n--;
  }
  return str;
}
