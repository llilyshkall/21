#include <limits.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chars.h"
#include "s21_grep.h"

int main(int argc, char **argv) {
  int pos = 0, flags = 0, size = 0, n = 0;
  char **substring = NULL;  // массив шаблонов нужен для флага е, иначе (*str) -
                            // искомая подстрока
  char **files = NULL;
  pos = indicate(argc, argv, &flags, &substring, &size, &files, &n);

  /*
  int j;
  printf("==SUBSTRINGS==%d\n", size);
  for (j = 0; j < size; ++j)
      printf("\"%s\"\n", substring[j]);
  printf("==FILES==%d\n", n);
  for (j = 0; j < n; ++j)
      printf("\"%s\"\n", files[j]);*/

  if (pos) s21_grep(flags, substring, size, files, n);
  clear(&substring, size);
  clear(&files, n);
}
