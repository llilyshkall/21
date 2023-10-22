#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *cpy = S21_NULL;
  if (str) cpy = malloc(sizeof(char) * (s21_strlen(str) + 1));
  char *tmp = cpy;
  if (cpy) {
    while (*str != '\0') {
      if (*str >= 65 && *str <= 90) {
        *cpy = *str + 32;
      } else {
        *cpy = *str;
      }
      str++;
      cpy++;
    }
    *cpy = '\0';
  }
  return tmp;
}
