#include "s21_string.h"

int s21_strcmp(const char *s1, const char *s2) {
  int diff = 0;
  while (*s1 != '\0' || *s2 != '\0') {
    if (*s1 != *s2) {
      diff = *s1 - *s2;
      break;
    }
    s1++;
    s2++;
  }
  return diff;
}
