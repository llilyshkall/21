#include "s21_string.h"

s21_size_t s21_strspn(const char *s1, const char *s2) {
  int len1 = s21_strlen(s1);
  int len2 = s21_strlen(s2);
  int index = 0, i = 0;
  for (; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      if (s1[i] == s2[j]) {
        index += 1;
      }
    }
    if (index == 0) {
      break;
    }
    index = 0;
  }
  return i;
}
