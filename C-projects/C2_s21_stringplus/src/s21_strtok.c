#include "s21_string.h"

char *clean(const char *delim, char *save_str);
int first_occurence(const char *delim, char *save_str);
void core(const char *delim, char **save_str, char **str);

char *s21_strtok(char *str, const char *delim) {
  static char *save_str = S21_NULL;
  if (str) {
    str = clean(delim, str);
    save_str = str;
    core(delim, &save_str, &str);
  } else if (save_str) {
    save_str = clean(delim, save_str);
    str = save_str;
    core(delim, &save_str, &str);
  }
  return str;
}

void core(const char *delim, char **save_str, char **str) {
  int len = **save_str ? first_occurence(delim, *save_str) : 0;
  if (**save_str) {
    *str = *save_str;
    *save_str += s21_strlen(*str);
    if (len)
      (*save_str)++;
    else
      *save_str = S21_NULL;
  } else {
    *save_str = S21_NULL;
    *str = S21_NULL;
  }
}

int first_occurence(const char *delim, char *save_str) {
  int end_str = 0;
  int len = s21_strlen(save_str);
  for (int i = 0; i < len; i++) {
    if (s21_strchr(delim, (save_str)[i])) {
      (save_str)[i] = '\0';
      end_str = len - i - 1;
      break;
    }
  }
  return end_str;
}

char *clean(const char *delim, char *save_str) {
  while (s21_strchr(delim, *save_str) && *save_str) save_str++;
  return save_str;
}
