#include "chars.h"

// добавление новой строки (шаблона) в массив
void addstr(char ***substring, int *size, char *s) {
  *substring = realloc(*substring, sizeof(char *) * (*size + 1));
  // перевыделение памяти
  (*substring)[*size] = malloc(sizeof(char) * (strlen(s) + 1));
  // выделение памяти для новой строки
  strcpy((*substring)[*size], s);  // копирование строки
  (*size)++;  // увеличение количества строк в массиве
}

char *input_string(FILE *fp) {
  char *s = malloc(BLOCK * sizeof(char)), c;
  *s = '\0';
  int i = 0;
  c = getc(fp);

  if (c == EOF) {
    free(s);
    s = NULL;
  } else {
    while (c != EOF && c != '\n') {
      s[i++] = c;
      if ((i + 1) % BLOCK == 0)
        s = realloc(s, ((i + 1) + BLOCK) * sizeof(char));
      c = getc(fp);
    }
    s[i] = '\0';
  }
  return s;
}

void clear(char ***A, int n) {
  int i;
  for (i = 0; i < n; ++i) free((*A)[i]);
  free(*A);
}

void fall(char *s) {
  while (*s) {
    if (*s >= 'A' && *s <= 'Z') *s = *s - 'A' + 'a';
    s++;
  }
}