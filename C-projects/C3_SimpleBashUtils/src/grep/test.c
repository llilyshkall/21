#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 8

void grep(char* flag1, char* flag2, char* str);
void s21_grep(char* flag1, char* flag2, char* str);
int check(char* file1, char* file2);

int main() {
  int i, j;
  // close(2);
  char test[][20] = {
      "-e for", "-e ^int", "-fpattern.txt", "-i", "-v", "-c", "-l", "-n", "-h",
      "-s",     "-o"};
  char str[][10] = {"for", "q", "qwertyu", "\0"};
  for (i = 0; i < N; ++i) {
    for (j = 0; j < N; ++j) {
      if (i != j) {
        int k = 0;
        while (k < 3) {
          if (i < 3 || j < 3) k = 3;

          int pid_grep, pid_s21_grep, status;
          pid_grep = fork();
          if (!pid_grep) grep(test[i], test[j], str[k]);

          pid_s21_grep = fork();
          if (!pid_s21_grep) s21_grep(test[i], test[j], str[k]);

          waitpid(pid_grep, &status, 0);
          waitpid(pid_s21_grep, &status, 0);
          printf("test %3d grep %s %s %s grep.c ", i * N + j, test[i], test[j],
                 str[k]);
          if (check("grep.txt", "s21_grep.txt"))
            printf("\nsuccses\n");
          else
            printf("\nfail\n");
          k++;
        }
      }
    }
  }
}

void grep(char* flag1, char* flag2, char* str) {
  int fd = open("grep.txt", O_CREAT | O_WRONLY, 0777);
  dup2(fd, 1);
  close(fd);
  if (*str)
    execlp("grep", "grep", flag1, flag2, str, "grep.c", NULL);
  else
    execlp("grep", "grep", flag1, flag2, "grep.c", NULL);
}

void s21_grep(char* flag1, char* flag2, char* str) {
  int fd = open("s21_grep.txt", O_CREAT | O_WRONLY, 0777);
  dup2(fd, 1);
  close(fd);
  if (*str)
    execlp("./s21_grep", "./s21_grep", flag1, flag2, str, "grep.c", NULL);
  else
    execlp("./s21_grep", "./s21_grep", flag1, flag2, "grep.c", NULL);
}

int check(char* file1, char* file2) {
  FILE* fp1 = fopen(file1, "r");
  FILE* fp2 = fopen(file2, "r");
  int c1, c2;
  while ((c1 = fgetc(fp1)) == (c2 = fgetc(fp2)) && c1 != EOF && c2 != EOF)
    ;
  return c1 == EOF && c2 == EOF;
  fclose(fp1);
  fclose(fp2);
  remove(file1);
  remove(file2);
}