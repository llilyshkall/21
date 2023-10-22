#include "s21_string.h"

int s21_strncmp(const char *s1, const char *s2, s21_size_t n) {
  int diff = 0;
  while (n > 0 && (*s1 != '\0' || *s2 != '\0')) {
    if (*s1 != *s2) {
      diff = *s1 - *s2;
      break;
    }
    s1++;
    s2++;
    n--;
  }
  return diff;
}
