#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = S21_NULL;
  unsigned char *line = (unsigned char *)str;
  // больше нуля ну потому что мало ли меньше введут
  while (n > 0) {
    // тоже самое что memcmp -> нужно ли проверять существование строки?
    // что скажет valgrind
    if (*line == c) {
      res = line;
      break;
    }
    line++;
    n--;
  }
  return res;
}
