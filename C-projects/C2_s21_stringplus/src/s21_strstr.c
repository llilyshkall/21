#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;

  // Просто решил попробовать написать одним циклом, вроде получилось, твоё
  // решение правильнее всё равно кмк
  /*int found = 0;
  char *tmp = (char*)needle;
  char *res_temp = (char*)haystack;
  while (*haystack && *needle && *(tmp + found)) {
    if (*haystack == *needle) {
      found++;
      needle++;
      haystack++;
    } else {
      found = 0;
      haystack = res_temp + 1;
      res_temp = (char*)haystack;
      needle = tmp;
    }
  }
  if (!*(tmp + found))
    res = res_temp;
  */

  int res_ind = 0;
  int found = 0;
  int len = s21_strlen(haystack);
  int lned = s21_strlen(needle);

  // в принципе решение логичное, но чуть громоздкое, надо подумать хотим ли мы
  // упрощать

  for (int i = 0; i < len && lned && !found; i++) {
    // заменил found == 0 на !found
    // убрал n полностью, ведь мы всегда должны зайти во второй цикл, если
    // совпадает даже с 1м элементом
    if (haystack[i] == needle[0]) {
      int i2 = i, n2 = 0;
      res_ind = i;
      while (needle[n2] && haystack[i2]) {  // убрал лишние условия
        if (haystack[i2] == needle[n2]) {
          i2++;
          n2++;
        } else {
          break;
        }
      }
      if (!needle[n2]) found = 1;  // упростил
    }
  }
  if (found) res = (char *)haystack + res_ind;
  if (!lned) res = (char *)haystack;  // упростил
  return res;
}
