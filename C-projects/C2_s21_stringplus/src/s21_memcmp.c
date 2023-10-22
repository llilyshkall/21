#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  unsigned char *line1 = (unsigned char *)str1;
  unsigned char *line2 = (unsigned char *)str2;
  while (n > 0) {
    // if (!line1 || !line2) break;
    // как не выйти за границу памяти?
    // если убрать проверку на строки, то будет 100% покрытие, но ... типо ты
    // идешь по чужой памяти?
    if (*line1 != *line2) {
      result = *line1 - *line2;
      break;
    }
    line1++;
    line2++;
    n--;
  }
  return result;
}
