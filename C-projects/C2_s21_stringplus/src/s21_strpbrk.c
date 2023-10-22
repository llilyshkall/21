#include "s21_string.h"

char *s21_strpbrk(const char *s1, const char *s2) {
  int len1 = s21_strlen(s1);
  int len2 = s21_strlen(s2);
  const char *index = s21_NULL;
  for (int i = 0; i < len1 && NULL == index; i++) {
    for (int j = 0; j < len2; j++) {
      if (s1[i] == s2[j]) {
        index = &s1[i];
      }
    }
  }
  return (char *)index;
}
