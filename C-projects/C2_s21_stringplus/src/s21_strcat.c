#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *tmp = dest;
  dest += s21_strlen(dest);
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return tmp;
}
