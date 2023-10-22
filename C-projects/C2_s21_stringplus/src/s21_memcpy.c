#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *line1 = (unsigned char *)dest;
  unsigned char *line2 = (unsigned char *)src;
  // same question about memory
  while (n > 0) {  // while (n > 0 && *line1) ?
    *line1 = *line2;
    line1++;
    line2++;
    n--;
  }
  return dest;
}
