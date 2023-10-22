#include "s21_sprintf.h"
// Sprintf driver code
int s21_sprintf(char *str, const char *format, ...) {
  va_list variables;
  va_start(variables, format);
  int error = 0;
  char *tmp = str;
  while (*format) {
    if (*format != '%') {  // If we dont need to parse
      *str = *format;      // Just write the value
    } else {               // If we need to parse
      format++;            // Shift to parse
      spec specifier = parser((char **)&(format), SPRINTF);  // Parse format
      char *n = print_val(&str, &variables, specifier,
                          &error);  // Use the parsed data
      if (error) {  // На случай ошибки, но обработки ошибок нет :)))) Потому
                    // что
#if defined(__APPLE__)
        *tmp = '\0';  // они только в MUSL и их многа
#endif
        str++;
        break;
      }
      if (n) {  // If something was stored, that means n was reached
        int *address = va_arg(variables, int *);  // Read address to write to
        *address = (char *)n - tmp;               // Write the difference
      }
      format--;  // Move back since we will add format++ anyway
    }
    str++;
    format++;
  }
  *str = '\0';  // Don't forget the trailing \0 just in case!
  va_end(variables);
  return error ? -1 : str - tmp;
}

// Reverse string
void reverse(char *str) {
  int n = s21_strlen(str);
  for (int i = 0; i < n / 2; i++) {
    char temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
}

// Correctly choose size for signed number
unsigned long long int arg_nu(va_list *va, spec sp) {
  unsigned long long int val = 0;
  if (sp.len == 1) val = va_arg(*va, unsigned long int);
  if (sp.len == 0) val = va_arg(*va, unsigned int);
  if (sp.len == -1) val = (unsigned short int)va_arg(*va, int);
  return val;
}

// Correctly choose the size of unsigned number
unsigned long long int arg_ns(va_list *va, spec sp) {
  unsigned long long int val = 0;
  if (sp.len == 1) val = va_arg(*va, long int);
  if (sp.len == 0) val = va_arg(*va, int);
  if (sp.len == -1) val = (short int)va_arg(*va, int);
  return val;
}

// Correctly choose size for pointer
long long int arg_p(va_list *va) { return (long long int)va_arg(*va, void *); }

// Correctly choose size for str
void *arg_s(va_list *va, spec sp) {
  void *val = S21_NULL;
  if (sp.len == 1) val = (wchar_t *)va_arg(*va, wchar_t *);
  if (sp.len != 1) val = (char *)va_arg(*va, char *);
  if (!val) {
#if defined(__GLIBC__)
    if (sp.precision < 6 && sp.precision > -1)
      val = "";
    else
#endif
      val = "(null)";
  }
  return val;
}

// Get asterisk values
void asterisk(va_list *variables, spec *specifier) {
  if (specifier->width == WIDTH_ASTERISK)
    specifier->width = va_arg(*variables, unsigned int);
  if (specifier->precision == PRECISION_ASTERISK)
    specifier->precision = va_arg(*variables, unsigned int);
}

// Add zeroes
void add_zero(char **str, spec *sp) {
  while (sp->precision > 0) {
    **str = '0';
    (*str)++;
    sp->width--;
    sp->precision--;
  }
  **str = '\0';
}

// Add padding
void add_padding(char **str, spec *sp) {
  while (sp->width > 0) {
    **str = sp->flag.zero ? '0' : ' ';  // Flag ZERO
    (*str)++;
    sp->width--;
  }
  **str = '\0';
}

// Shift string to left side
void left_shift(char *str) {
  int n = 0;
  for (int i = 0; str[i]; i++)
    if (str[i] != ' ') str[n++] = str[i];

  for (int i = n; str[i]; i++) str[i] = ' ';
}

// Hash str return
const char *hash(spec sp) {
  const char *ret[] = {"", "0", "x0", "X0"};
  int index = 0;
  if (sp.flag.hash) {
    if (sp.specifier == 'o' && sp.precision < 0) index = 1;
    if (sp.specifier == 'x' || sp.specifier == 'p') index = 2;
    if (sp.specifier == 'X') index = 3;
  }
  return ret[index];
}

// Return appended sign
const char *appended_sign(spec specifier) {
  const char *ret[] = {"", "+", "-", "V"};
  int index = 0;
  if (specifier.flag.plus == 1) index = 1;
  if (specifier.flag.plus == -1) index = 2;
  if (specifier.flag.space && !specifier.flag.plus) index = 3;
  return ret[index];
}

// Select base for whole num
int base_u(spec sp) {
  int ret = 10;
  switch (sp.specifier) {
    case 'o':
      ret = 8;
      break;
    case 'x':
    case 'X':
    case 'p':
      ret = 16;
      break;
  }
  return ret;
}

// Appends number to str and shifts str to end
void printNumS(char **str, long long int val, spec *sp) {
  int base = base_u(*sp);
  if (val < 0) {
    if (val == LLONG_MIN) {
      printNumS(str, val % base, sp);
      val /= base;
    }
    val *= -1;
    sp->flag.plus = -1;
  }
  char *literal = "0123456789abcdef";
  while (val && base) {
    int i = val % base;
    **str = literal[i];
    val /= base;
    (*str)++;
    sp->precision--;
    sp->width--;
  }
  **str = '\0';
}

void printNumU(char **str, unsigned long long int val, spec *sp) {
  int base = base_u(*sp);
  char *literal = "0123456789abcdef";
  while (val && base) {
    int i = val % base;
    **str = literal[i];
    val /= base;
    (*str)++;
    sp->precision--;
    sp->width--;
  }
  **str = '\0';
}

// An in place toUpper
void to_upperX(char *tmp) {
  while (*tmp) {
    if (*tmp >= 'a' && *tmp <= 'z') *tmp = *tmp + 'A' - 'a';
    tmp++;
  }
}

// Wchar strlen
s21_size_t s21_wtlen(wchar_t *str) {
  s21_size_t len = 0;
  while (*str) {
    len++;
    str++;
  }
  return len;
}

// Append n wchar symbols to char* and convert
void s21_wtstrncat(char *dest, wchar_t *src, s21_size_t n) {
  dest += s21_strlen(dest);
  s21_size_t count = 0;
  // (Если есть желание делать полную обработку всех локалей - то делать тут)
  while (count < n && *src) {
    *dest = *src;
    count++;
    dest++;
    src++;
  }
  *dest = '\0';
}

// Handle nilPtr in GLIBC
void nilPtr(char **str, spec *sp) {
  sp->precision = -1;
  print_str(str, *sp, "(nil)");
}

// Print percent
void print_percent(char **str) {
  **str = '%';
  (*str)++;
  **str = '\0';
}

// Print unsigned
void print_u(char **str, va_list *variables, spec sp) {
  sp.flag.space = 0;  // Defaults
  sp.flag.plus = 0;   // Defaults
  print_num(str, sp, arg_nu(variables, sp));
}

// Print signed
void print_d(char **str, va_list *variables, spec sp) {
  print_num(str, sp, arg_ns(variables, sp));
}

// Print pointer
void print_p(char **str, va_list *variables, spec specifier) {
  specifier.len = -69;      // Defaults
  specifier.flag.hash = 1;  // Default
#if defined(__APPLE__)
  specifier.flag.plus = 0;
  specifier.flag.space = 0;
#endif
#if defined(__MUSL__) && defined(__linux__)
  specifier.flag.plus = 0;
  specifier.flag.space = 0;
  if (specifier.precision != -1)
    if (specifier.precision < 16) specifier.precision = 16;
#endif
  print_num(str, specifier,
            arg_p(variables));  // Print just like a normal number (sort of)
}

// Print string
void print_s(char **str, va_list *variables, spec specifier) {
#if defined(__linux__)
  specifier.flag.zero = 0;  // Default
#endif
  print_str(str, specifier, arg_s(variables, specifier));
}

// Print any number
void print_num(char **str, spec sp, unsigned long long int val) {
  **str = '\0';
  if (sp.precision == -1)  // Set default precision
    sp.precision = 1;
  char *tmp = *str;  // Store starting point
  sp.specifier == 'd' || sp.specifier == 'i' ? printNumS(str, val, &sp)
                                             : printNumU(str, val, &sp);
  int NullStr = 1;
  if (!val) {  // If value is zero, no hashes
    sp.flag.hash = 0;
#if defined(__APPLE__)
    if (sp.specifier == 'p') sp.flag.hash = 1;
#endif
  }
  if (!val &&
      sp.specifier == 'p') {  // If value is 0 for ptr in GLIBC - print (nil)
#if defined(__GLIBC__) && defined(__linux__)
    nilPtr(str, &sp);
    NullStr = 0;
#endif
  }
  if (NullStr) {                   // If we didnt move to nilPtr
    add_zero(str, &sp);            // Add zeroes
    s21_strcat(*str, hash(sp));    // Append hash
    *str += s21_strlen(hash(sp));  // Shift string
    sp.width -=
        s21_strlen(hash(sp)) + s21_strlen(appended_sign(sp));  // Minus width
    if (sp.flag.zero) add_padding(str, &sp);  // Add zeroes padding
    s21_strcat(*str, appended_sign(sp));      // Append sign
    *str += s21_strlen(appended_sign(sp));    // Shift string
    add_padding(str, &sp);                    // Add normal padding
    reverse(tmp);
    if (sp.flag.minus) left_shift(tmp);       // Left shift if needed
    if (sp.specifier == 'X') to_upperX(tmp);  // Convert to uppercase for X
    tmp = s21_strchr(tmp, 'V');               // Replace V with space for sign.
    if (tmp) *tmp = ' ';
  }
}

// Print string
void print_str(char **str, spec sp, void *val) {
  **str = '\0';            // Set beggining in case of empty str
  char *tmp = *str;        // Store beggining
  if (sp.precision == -1)  // set the precision
    sp.precision = sp.len == 1 ? s21_wtlen(val) : s21_strlen(val);
  if (sp.len == 1)  // Two types of cat depending on char type
    s21_wtstrncat(*str, val, sp.precision);
  else
    s21_strncat(*str, val, sp.precision);
  int len = s21_strlen(*str);        // Get len of ncatted
  *str += len;                       // Shif that len
  sp.width -= len;                   // Remove padding according to that len
  if (!sp.flag.minus) reverse(tmp);  // reverse to add padding if minus
  add_padding(str, &sp);             // Add padding
  if (!sp.flag.minus) reverse(tmp);
}

// Select correct function
char *print_val(char **str, va_list *variables, spec specifier, int *error) {
  char *tmp = S21_NULL;
  asterisk(variables, &specifier);  // Handle asterisks
  switch (specifier.specifier) {
    case 'c':  // символ
      *error = print_c(str, variables, &specifier);
      break;
    case 'g':
    case 'G':
    case 'e':
    case 'E':
    case 'f':
      print_f_or_e(str, variables, &specifier);
      break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
      print_u(str, variables, specifier);  // unsigned
      break;
    case 'd':
    case 'i':
      print_d(str, variables, specifier);  // signed
      break;
    case 'p':
      print_p(str, variables, specifier);  // pointer
      break;
    case 's':
      print_s(str, variables, specifier);  // string
      break;
    case '%':
      print_percent(str);  // percent
      break;
    case 'n':
      tmp = *str;  // Store beggining of str to return
      break;
      // Skipped default, because it differs in implementation
  }
  (*str)--;
  return tmp;
}
// 293

void get_char_arg(int *ch_arg, wchar_t *wa_arg, va_list *data, int len) {
  if (len == 1 || len == 2) {
    *wa_arg = va_arg(*data, wchar_t);
  } else {
    *ch_arg = va_arg(*data, int);
  }
}

int print_c(char **str, va_list *data, spec *q) {
  int error = 0;
  int ch_arg = 0;
  wchar_t wa_arg = 0;
  get_char_arg(&ch_arg, &wa_arg, data, q->len);
#if defined(__linux__)
  q->flag.zero = 0;
#endif
  if (q->len == 1 || q->len == 0)
    ch_arg %= 256;
  else {
#if defined(__MUSL__)
    error = 1;
#endif
  }
  if (!error) {
    if (q->flag.minus) {
      **str = (q->len == 1 || q->len == 2) ? wa_arg : ch_arg;
      (*str)++;
    }
    while (q->width > 1) {
      **str = q->flag.zero && !q->flag.minus ? '0' : ' ';
      (*str)++;
      q->width--;
    }
    if (!q->flag.minus) {
      **str = (q->len == 1 || q->len == 2) ? wa_arg : ch_arg;
      (*str)++;
    }
  }
  return error;
}

int count_e_flag(long double *e_arg, int *width) {
  int e = 0;
  while (*e_arg > 1) {
    *e_arg /= 10;
    e += 1;
  }
  while (*e_arg < 1 && *e_arg > 0) {
    *e_arg *= 10;
    e -= 1;
  }
  if (e > 99 || e < -99) {
    *width += count_symbols(e) - 2;
  }
  return e;
}

void print_e_flag(char **str, spec *q, long long int e) {
  **str = q->specifier;
  (*str)++;
  if (e < 0) {
    **str = '-';
    (*str)++;
    e *= -1;
  } else {
    **str = '+';
    (*str)++;
  }
  if (e < 10) {
    **str = '0';
    (*str)++;
  }
  recursive_long_int(e, 1, str);
}

int rounded_precision(int *pres, long double db_arg) {
  int y = 0;
  for (int i = *pres; i > 0; i--) {
    db_arg *= 10;
  }
  while (*pres && (int)fmodl(db_arg, 10) == 0) {
    (*pres)--;
    db_arg /= 10;
    y++;
  }
  return y;
}

void print_f_or_e(char **str, va_list *data, spec *q) {
  long double db_arg = 0;
  // printf("SPACE: %d\n", q->flag.space);
  get_float_num(&db_arg, data, q->len);
  if (db_arg == INFINITY) {
    **str = 'i';
    (*str)++;
    **str = 'n';
    (*str)++;
    **str = 'f';
    (*str)++;
  } else if (isnan(db_arg)) {
    **str = 'n';
    (*str)++;
    **str = 'a';
    (*str)++;
    **str = 'n';
    (*str)++;
  } else
    handle_float_specifiers(str, q, &db_arg);
}

void handle_float_specifiers(char **str, spec *q, long double *db_arg) {
  int copy_pres = q->precision;
  int flag_g = 0;
  int sign = 0;

  get_sign(&sign, db_arg);
  set_g_precision(&copy_pres, q, &flag_g);

  int width = 0;
  long double copy = 0;
  long double e_arg = *db_arg;
  long double drob = 0;

  int e = 0;
  if (q->specifier != 'F' && q->specifier != 'f')
    e = count_e_flag(&e_arg, &width);

  set_g_flag(q, copy_pres, e);

  if (q->specifier == 'E' || q->specifier == 'e') {
    width += 4;
    *db_arg = e_arg;
  }

  e += set_float_width(&width, sign, db_arg, &drob, &copy, q);
  if (flag_g) {
    if (!(q->flag.hash)) width -= rounded_precision(&(q->precision), copy);
  }
  q->width -= width;

  // Отдельно на печать
  print_space_before(str, q, sign);
  print_sign(str, q, sign);
  print_zero_before(str, q);
  recursive_long_int(copy, 1, str);
  print_precision(str, q, drob);
  if (q->specifier == 'E' || q->specifier == 'e') print_e_flag(str, q, e);
  print_space_after(str, q);
}

void get_sign(int *sign, long double *db_arg) {
  if (*db_arg < 0) {
    *db_arg *= -1;
    *sign = 1;
  }
}

void set_g_precision(int *copy_pres, spec *q, int *flag_g) {
  if (q->specifier == 'G' || q->specifier == 'g') {
    *flag_g = 1;
    if (*copy_pres == -1) {
      *copy_pres = 6;
    } else if (*copy_pres == 0) {
      *copy_pres = 1;
    }
  }
}

void set_g_flag(spec *q, int copy_pres, int e) {
  if (q->specifier == 'G' || q->specifier == 'g') {
    if (copy_pres > e && e >= -4) {
      q->precision = copy_pres - (e + 1);
    } else {
      q->specifier = 'e';
      q->precision = copy_pres - 1;
    }
  }
}

void get_float_num(long double *next_arg, va_list *data, int len) {
  if (len == 2) {
    *next_arg = va_arg(*data, long double);
  } else {
    *next_arg = va_arg(*data, double);
  }
}

int set_float_width(int *width, int sign, long double *db_arg,
                    long double *drob, long double *copy, spec *q) {
  int e_crutch = 0;
  int pres = q->precision;
  if (q->flag.plus || sign)
    (*width)++;
  else if ((q->flag.minus || q->flag.zero) && q->flag.space)
    (*width)++;

  if (q->specifier != 'g' && q->specifier != 'G') {
    *width += set_precision(q);
    pres = q->precision;
  } else if (pres > 0) {
    *width += pres;
    (*width)++;
  } else if (q->flag.hash)
    (*width)++;
  if (pres == -1) *width -= 1;

  *copy = roundl(((*db_arg) * powl(10, pres))) / powl(10, pres);
  if (*copy >= 10. && q->specifier == 'e') {
    e_crutch++;
    *copy /= 10;
  }

  if (pres <= 0) *db_arg = roundl(*db_arg);
  *drob = modfl(*db_arg, db_arg);
  if ((int)*copy)
    *width += count_symbols(*copy);
  else
    (*width)++;

  return e_crutch;
}

int set_precision(spec *q) {
  int width_counter = 0;
  if (q->precision < 0) {
    q->precision = 6;
  }
  if (q->precision) {
    width_counter += q->precision + 1;
  } else if (q->flag.hash)
    width_counter += 1;
  return width_counter;
}

void print_space_before(char **str, spec *q, int sign) {
  if ((q->flag.space || q->width) && !q->flag.zero && !q->flag.minus) {
    if (q->flag.space && !q->flag.plus && !sign && q->width < 1) q->width = 1;
    while (q->width > 0) {
      **str = ' ';
      (*str)++;
      q->width--;
    }
  }
}

void print_sign(char **str, spec *q, int sign) {
  if (sign) {
    **str = '-';
    (*str)++;
  } else if (q->flag.plus) {
    **str = '+';
    (*str)++;
  } else if ((q->flag.minus || q->flag.zero) && q->flag.space) {
    **str = ' ';
    (*str)++;
  }
}

void print_zero_before(char **str, spec *q) {
  if (q->flag.zero && !q->flag.minus) {
    while (q->width > 0) {
      **str = '0';
      (*str)++;
      q->width--;
    }
  }
}

void print_precision(char **str, spec *q, long double drob) {
  if (q->precision > 0 || q->flag.hash) {
    **str = '.';
    (*str)++;
  }
  if (q->precision) {
    long double temp = drob * powl(10, q->precision);
    long double next = roundl(temp);
    modfl(temp, &temp);
    modfl(next, &next);
    recursive_precision(str, q, drob, next != temp);
  }
}

void recursive_precision(char **str, spec *q, long double db_arg, int next) {
  if (q->precision == 1) {
    long double temp = db_arg * 10;
    modfl(temp, &temp);
    temp += next;
    temp = temp > 9 ? 0 : temp;
    my_itoa_symbol(temp, str);
  } else if (q->precision > 1) {
    q->precision--;
    long double temp = db_arg * powl(10, q->precision);
    long double drob = modfl(temp, &temp);
    drob *= 10;
    modfl(drob, &drob);
    drob += next;
    recursive_precision(str, q, db_arg, drob > 9);
    drob = drob > 9 ? 0 : drob;
    my_itoa_symbol(drob, str);
  }
}

void recursive_long_int(long double d_arg, int symbols, char **str) {
  long double divider = powl(10, symbols);
  int temp = (int)(fmodl(d_arg, divider) / (divider / 10.));
  if (d_arg / divider >= 1) {
    symbols++;
    recursive_long_int(d_arg, symbols, str);
  } else if ((int)d_arg == 0) {
    temp = 0;
  }
  my_itoa_symbol(temp, str);
}

void my_itoa_symbol(int new_num, char **str) {
  **str = new_num + '0';
  (*str)++;
  **str = '\0';
}

void print_space_after(char **str, spec *q) {
  if (q->flag.minus && (q->flag.space || q->width)) {
    while (q->width > 0) {
      **str = ' ';
      (*str)++;
      q->width--;
    }
  }
}

int count_symbols(unsigned long long int d_arg) {
  int n = 0;
  if (d_arg == 0) {
    n = 0;
  } else if ((d_arg / 10) == 0.) {
    n = 1;
  } else if ((d_arg / 10) >= 1.) {
    n = count_symbols(d_arg / 10) + 1;
  }
  return n;
}
