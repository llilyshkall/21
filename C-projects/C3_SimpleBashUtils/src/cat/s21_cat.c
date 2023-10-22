#include <stdio.h>
#include <string.h>

#define CAT_B 1
#define CAT_E 2
#define CAT_N 4
#define CAT_S 8
#define CAT_T 16
#define CAT_V 32

int indicate(char* s);
void s21_cat(int flags, FILE* fp);
int print(int flags, int pred2, int pred, int c, int i);

int main(int argc, char** argv) {
  int i, j = 0, flags = 0;
  FILE* fp = NULL;
  for (i = 1; (i < argc) && (argv[i][0] == '-') && flags != -1; ++i) {
    j = i;
    flags |= indicate(argv[i]);
  }

  if (flags != -1) {
    if ((flags & (CAT_B | CAT_N)) == (CAT_B | CAT_N)) flags -= CAT_N;

    if (j + 1 == argc) s21_cat(flags, stdin);

    for (i = j + 1; i < argc; ++i) {
      if ((fp = fopen(argv[i], "r")) != NULL) {
        s21_cat(flags, fp);
      } else {
        fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
      }
    }
  }
}

int indicate(char* s) {
  int flags = 0;
  if (!strcmp(s, "--number-nonblank")) return CAT_B;
  if (!strcmp(s, "--number")) return CAT_N;
  if (!strcmp(s, "--squeeze-blank")) return CAT_B;
  s++;
  while (*s) {
    if (*s == 'b') flags |= CAT_B;
    if (*s == 'e' || *s == 'E') flags |= CAT_E;
    if (*s == 'n') flags |= CAT_N;
    if (*s == 's') flags |= CAT_S;
    if (*s == 't' || *s == 'T') flags |= CAT_T;
    if (*s == 'v' || *s == 'e' || *s == 't') flags |= CAT_V;
    if (!((*s == 'b') || (*s == 'e' || *s == 'E') || (*s == 'n') ||
          (*s == 's') || (*s == 't' || *s == 'T') || (*s == 'v'))) {
      fprintf(stderr, "cat: illegal option -- %c\n", *s);
      flags = -1;
    }
    s++;
  }
  return flags;
}

/*void s21_cat_stdin(int flags) {
  int pred2 = '\n', pred = '\n', c, i = 1;
  while ((c = getchar()) != EOF) {
    i = print(flags, pred2, pred, c, i);
    pred2 = pred;
    pred = c;
  }
}*/

void s21_cat(int flags, FILE* fp) {
  int pred2 = 0, pred = '\n', c, i = 1;
  while ((c = fgetc(fp)) != EOF) {
    i = print(flags, pred2, pred, c, i);
    pred2 = pred;
    pred = c;
  }
}

int print(int flags, int pred2, int pred, int c, int i) {
  int q = 0;
  if (flags & CAT_S)
    if (pred2 == '\n' && pred == '\n' && c == '\n') return i;
  if (flags & CAT_B)
    if (pred == '\n' && c != '\n') printf("%6d\t", i++);
  if (flags & CAT_N)
    if (pred == '\n') printf("%6d\t", i++);
  if (flags & CAT_E)
    if (c == '\n') printf("$");
  if (flags & (CAT_T | CAT_V)) {
    if (flags & CAT_T) {
      if (c == '\t') {
        c = 'I';
        q = 1;
      }
    }
    if (flags & CAT_V) {
      if ((c >= 0 && c <= 31 && c != '\n' && c != '\t') || c >= 127) {
        if (c >= 0 && c <= 31 && c != '\n' && c != '\t') {
          c = c + 64;
          q = 1;
        }
        if (c > 127 && c <= 159) {
          c = (c & 31) + 64;
          printf("M-^");
        }
        if (c == 127) {
          c = '?';
          q = 1;
        }
      }
    }
  }
  if (q)
    printf("^%c", c);
  else
    printf("%c", c);
  return i;
}
