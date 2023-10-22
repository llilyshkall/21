#ifndef S21_GREP_H
#define S21_GREP_H

#include <limits.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chars.h"

#define GREP_E 1
#define GREP_I 2
#define GREP_V 4
#define GREP_C 8
#define GREP_L 16
#define GREP_N 32
#define GREP_H 64
#define GREP_S 128
#define GREP_F 256
#define GREP_O 512
#define FILES 1024
#define ERR_USAGE                                                            \
  fprintf(stderr,                                                            \
          "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] "   \
          "[-C[num]]\n"                                                      \
          "\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n" \
          "\t[--context[=num]] [--directories=action] [--label] "            \
          "[--line-buffered]\n"                                              \
          "\t[--null] [pattern] [file ...]\n");
#define ERR_FILE(s) fprintf(stderr, "grep: %s: No such file or directory\n", s);
#define ERR_OPTION(c) fprintf(stderr, "grep: invalid option -- %c\n", c);
#include "s21_grep.h"

int indicate(int argc, char **argv,
             int *flags,  // функция обработки всех флагов, файлов, шаблонов
             char ***substring, int *num_substrings, char ***filenames,
             int *num_filenames);
int indicate_flag(int argc, char **argv, char ***substring, int *num_substrings,
                  int *i);

int indicate_flag_e(int argc, char **argv, char *str, int *i, char ***substring,
                    int *num_substrings);
int indicate_flag_f(int argc, char **argv, char *str, int *i, char ***substring,
                    int *num_substrings);
void s21_grep(int flags, char **substring, int num_substrings, char **filenames,
              int num_filenames);
void s21_grep_file(char *file_name, int flags, char **substring,
                   int num_substrings);
int file_line(int flags, char *s_file, char *file_name, int num_str,
              char **substring, int num_substrings);
int file_line_pattern(int flags, char *str_file, char *file_name, int num_str,
                      char **substring, int num_substrings);
int file_line_str(int flags, char *str_file, char *file_name, int num_str,
                  char *copy_sub);

#endif