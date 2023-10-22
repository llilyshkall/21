#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define SPRINTF 1
#define SSCANF 0
#define WIDTH_ASTERISK -1
#define WIDTH_NONE 0
#define PRECISION_ASTERISK -2
#define PRECISION_NONE -1

struct flags {  // 0 - нет флага, 1 - стоит
  int plus;     // +
  int minus;    // -
  int space;    // ' '
  int hash;     // #
  int zero;     // 0
};

struct spec {
  int len;    // длина hh = -2; h = -1; none = 0; l = 1; ll or L = 2;
  int width;  // ширина 0 - нет такой характеристики иначе размер  "области"
  int precision;  // точность (-1 если не указана, иначе количество знаков после
                  // запятой)
  int specifier;  // спецификатор c, d, i, ... (тот символ который не
                  // удовлетворяет ни одному из характеристик или флагов)
  struct flags flag;  // флаги (для sprintf)
};

int s21_sscanf(const char* str, const char* format, ...);

int check(char** str, char** format, int res);
// проверяем совпали ли строки,
// после удачного выполнения функции check
// copy_str указывает на начало данных для считывания по
// спецификатору, который начинается с  указателя copy_format

struct spec parser(char** format, int mode);
// получаем следующий спецификатор
// вводимые значения: char** format -  адрес указателя на строку, следующей
// после %
//                    int    mode   -  режим: значение SPRINTF или SSCANF
//                    (макросы)
int proc_specifier(const char* orig, char** str, va_list* data, struct spec q);

int read_c(char** str, va_list* data, struct spec q);
int read_d(char** str, va_list* data, struct spec q);
int read_i(char** str, va_list* data, struct spec q);
int read_oux(char** str, va_list* data, struct spec q, int base);
void spec_d(char** str, va_list* data, struct spec q, int base, int sign);
void spec_odux(char** str, va_list* data, struct spec q, int base, int sign);
int read_real(char** str, va_list* data, struct spec q);
long double spec_real(char** str, struct spec q, int sign);
int read_s(char** str, va_list* data, struct spec q);
int read_p(char** str, va_list* data, struct spec q);
int read_proc(char** str);
int read_n(const char* begin, const char* end, va_list* data, struct spec q);
int empty(char* copy_str);

int sign_num(char c);
int cipher16(char c);
long double pow_10(int n);
void space(char** str);
int inf_check(const char* str);
int nan_check(const char* str);
#endif
