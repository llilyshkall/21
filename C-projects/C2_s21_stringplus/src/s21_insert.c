#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *cpy = S21_NULL;
  if (src && str)
    cpy = calloc((s21_strlen(src) + s21_strlen(str)) + 1, sizeof(char));
  char *tmp = cpy;
  if (cpy) {
    if (s21_strlen(src) >= start_index) {
      s21_strncpy(cpy, src, start_index);
      cpy += start_index;
      s21_strcat(cpy, str);
      s21_strcat(cpy, src + start_index);
    } else {
      free(cpy);
      tmp = S21_NULL;
    }
  }
  return tmp;
}
