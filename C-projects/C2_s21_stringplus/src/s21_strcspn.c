#include "s21_string.h"

s21_size_t s21_strcspn(const char *s1, const char *s2) {
  int len1 = s21_strlen(s1);
  int len2 = s21_strlen(s2);
  int index = -1;
  for (int i = 0; i < len1 && index == -1; i++) {
    for (int j = 0; j < len2; j++) {
      if (s1[i] == s2[j]) {
        index = i;
      }
    }
  }
  return index == -1 ? len1 : index;
}
