#ifndef SRC_S21_SPRINTF_H
#define SRC_S21_SPRINTF_H

#include <math.h>

#include "s21_sscanf.h"
#include "s21_string.h"

typedef struct spec spec;
int s21_sprintf(char *str, const char *format, ...);

void *arg_s(va_list *variables, spec specifier);
unsigned long long int arg_ns(va_list *variables, spec specifier);
unsigned long long int arg_nu(va_list *variables, spec specifier);
long long int arg_p(va_list *va);

void reverse(char *str_arg);
void add_padding(char **str, spec *specifier);
void add_zero(char **str, spec *sp);
void asterisk(va_list *variables, spec *specifier);
void nilPtr(char **str, spec *sp);

void left_shift(char *str);
const char *hash(spec sp);
const char *appended_sign(spec specifier);
int base_u(spec sp);
void printNum(char **str, long long int val, spec *sp);
void to_upperX(char *tmp);
s21_size_t s21_wtlen(wchar_t *str);
void s21_wtstrncat(char *dest, wchar_t *src, s21_size_t n);

char *print_val(char **str, va_list *variables, spec specifier, int *error);

void print_d(char **str, va_list *variables, spec specifier);
void print_u(char **str, va_list *variables, spec specifier);
void print_p(char **str, va_list *variables, spec specifier);
void print_s(char **str, va_list *variables, spec specifier);
void print_percent(char **str);
void print_num(char **str, spec specifier, unsigned long long int val);
void print_str(char **str, spec specifier, void *val);

int print_c(char **str, va_list *data, spec *q);
void get_char_arg(int *ch_arg, wchar_t *wa_arg, va_list *data, int len);

void print_f_or_e(char **str, va_list *data, spec *q);
void handle_float_specifiers(char **str, spec *q, long double *db_arg);
void get_float_num(long double *next_arg, va_list *data, int len);
void get_sign(int *sign, long double *db_arg);
int count_e_flag(long double *e_arg, int *width);
void set_g_precision(int *copy_pres, spec *q, int *flag_g);
void set_g_flag(spec *q, int copy_pres, int e);
int set_float_width(int *width, int sign, long double *db_arg,
                    long double *drob, long double *copy, spec *q);
int set_precision(spec *q);
int rounded_precision(int *pres, long double db_arg);
int count_symbols(unsigned long long int d_arg);
void my_itoa_symbol(int new_num, char **str);

void recursive_long_int(long double d_arg, int symbols, char **str);
void recursive_precision(char **str, spec *q, long double db_arg, int next);
void print_sign(char **str, spec *q, int sign);
void print_space_before(char **str, spec *q, int sign);
void print_zero_before(char **str, spec *q);
void print_precision(char **str, spec *q, long double drob);
void print_e_flag(char **str, spec *q, long long int e);
void print_space_after(char **str, spec *q);

#endif  // SRC_S21_SPRINTF_H