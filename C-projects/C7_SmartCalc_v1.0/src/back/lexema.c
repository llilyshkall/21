/**
 * @file lexema.c
 * @author chatayap
 * @brief Lexeme
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "lexema.h"

#include <stdio.h>
#include <string.h>

/**
 * function to set the pointer to the first non-blank character
 */
int close_space(char** str) {
  while (**str && (**str == ' ' || **str == '\t' || **str == '\n')) (*str)++;
  return **str;
}

/**
 * reading a token from a string
 */
int next_lexema(char** str, lexema* ans, long double value) {
  long double num;
  int ret = 1, shift;
  close_space(str);
  if ((**str != '+' && **str != '-') &&
      sscanf(*str, "%Lf%n", &num, &shift) > 0) {
    ans->type = LEXEMA_NUMBER;
    ans->data.num = num;
    (*str) += shift;
  } else {
    if (**str == 'x' || **str == 'X') {
      ans->type = LEXEMA_NUMBER;
      ans->data.num = value;
      (*str)++;
    } else {
      ret = short_operator(str, ans) || long_operator(str, ans);
    }
  }
  return ret;
}

/**
 * short statement initialization
 */
int short_operator(char** str, lexema* ans) {
  ans->data.oper = NONE;
  ans->type = LEXEMA_OPERATOR;
  if (**str == '+') ans->data.oper = ADD;
  if (**str == '-') ans->data.oper = SUB;
  if (**str == '*') ans->data.oper = MUL;
  if (**str == '/') ans->data.oper = DIV;
  if (**str == '(') ans->data.oper = OPEN_SCOPE;
  if (**str == ')') ans->data.oper = CLOSE_SCOPE;
  if (**str == '^') ans->data.oper = EXP;
  if (ans->data.oper != NONE) (*str)++;
  return ans->data.oper != NONE;
}

/**
 * long statement initialization
 */
int long_operator(char** str, lexema* ans) {
  int shift = 0;
  ans->data.oper = NONE;
  ans->type = LEXEMA_OPERATOR;
  if (!strncmp(*str, "mod", 3)) {
    shift = 3;
    ans->data.oper = MOD;
  }
  if (!strncmp(*str, "cos(", 4)) {
    shift = 4;
    ans->data.oper = COS;
  }
  if (!strncmp(*str, "sin(", 4)) {
    shift = 4;
    ans->data.oper = SIN;
  }
  if (!strncmp(*str, "tan(", 4)) {
    shift = 4;
    ans->data.oper = TAN;
  }
  if (!strncmp(*str, "acos(", 5)) {
    shift = 5;
    ans->data.oper = ACOS;
  }
  if (!strncmp(*str, "asin(", 5)) {
    shift = 5;
    ans->data.oper = ASIN;
  }
  if (!strncmp(*str, "atan(", 5)) {
    shift = 5;
    ans->data.oper = ATAN;
  }
  if (!strncmp(*str, "sqrt(", 5)) {
    shift = 5;
    ans->data.oper = SQRT;
  }
  if (!strncmp(*str, "ln(", 3)) {
    shift = 3;
    ans->data.oper = LN;
  }
  if (!strncmp(*str, "log(", 4)) {
    shift = 4;
    ans->data.oper = LOG;
  }
  (*str) += shift;
  return shift;
}

/**
 * changing uppercase characters to lowercase
 */
void strlow(char* str) {
  while (*str) {
    *str = *str >= 'A' && *str <= 'Z' ? *str - 'A' + 'a' : *str;
    str++;
  }
}

/**
 * getting operator precedence
 */
int prior(lexema value) { return value.data.oper & 7; }
