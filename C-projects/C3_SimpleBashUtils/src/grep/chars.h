#ifndef CHARS_H
#define CHARS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 4

void addstr(char ***substring, int *size, char *s);
char *input_string(FILE *fp);
void fall(char *);
// char* check(char* string, char* substring);
void clear(char ***A, int n);

#endif