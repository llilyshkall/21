
#include "s21_string.h"
/*
  If trim chars is empty, trim whitespaces
  Else trim every char from trim_chars
*/

void *s21_trim(const char *src, const char *trim_chars) {
  char *cpy = S21_NULL;
  // If trim_chars is empty or is NULL - trim whitespaces
  char *trim_chars_local =
      (trim_chars && *trim_chars) ? (char *)trim_chars : "";
  char *temp_trim = trim_chars_local;
  if (src) cpy = calloc(s21_strlen(src) + 1, sizeof(char));
  if (cpy) {
    for (; *src; src++) {  // Trim at the beggining
      int found = 0;
      for (; *trim_chars_local; trim_chars_local++) {
        if (*src == *trim_chars_local) {
          found = 1;
        }
      }
      trim_chars_local = temp_trim;
      if (!found) break;
    }
    s21_strcpy(cpy, src);                             // copy source to cpy
    for (int i = s21_strlen(cpy) - 1; i >= 0; i--) {  // Trim at the end
      int found = 0;
      for (; *trim_chars_local; trim_chars_local++) {
        if (cpy[i] == *trim_chars_local) {
          found = 1;
          cpy[i] = '\0';
        }
      }
      trim_chars_local = temp_trim;
      if (!found) break;
    }
  }
  return cpy;
}
