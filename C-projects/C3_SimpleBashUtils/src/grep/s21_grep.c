#include "s21_grep.h"
// функция обработки всех флагов, файлов, шаблонов
int indicate(int argc, char **argv, int *flags, char ***substring,
             int *num_substrings, char ***filenames, int *num_filenames) {
  int i = 1;  // индекс обрабатываемого аргумента командной строки
  *num_filenames = 0;  // количество файлов

  while (0 < i && i < argc) {  // случай i == 0 рассматривается как ошибка
    if (argv[i][0] == '-')  // добавляем флаги, если строка начинается с -
      *flags |= indicate_flag(argc, argv, substring, num_substrings, &i);
    else
      addstr(filenames, num_filenames,
             argv[i]);  // иначе это файл и добавляем в массив с именами файлов
    i++;
  }

  if (i == argc &&
      !((GREP_E | GREP_F) & *flags)) {  // если не встретилось флагов шаблонов
    if (*num_filenames >= 1) {
      int j;
      addstr(
          substring, num_substrings,
          **filenames);  // добавляем первую строку в качестве искомой подстроки
      free(**filenames);
      for (j = 1; j < *num_filenames; ++j)
        (*filenames)[j - 1] = (*filenames)[j];
      (*num_filenames)--;  // корректируем массив с именам файлов
      if (!(*num_filenames)) *filenames = NULL;
    } else {
      ERR_USAGE  // ошибка: недостаточно аргументов
    }
  }
  if (((GREP_E | GREP_F) & *flags) && *substring == NULL) i = 0;

  return i;
}

// случай обработки флагов
int indicate_flag(int argc, char **argv, char ***substring, int *num_substrings,
                  int *i) {
  char *str = argv[*i] + 1;  // обрабатываем очередной параметр командной строки
  int flags = 0;
  while (*str) {  // рассматриваем все флаги
    if (*str == 'e')
      flags |= indicate_flag_e(argc, argv, str, i, substring, num_substrings);
    // добавляем флаг и заносим строку в массив подстрок
    if (*str == 'f')
      flags |= indicate_flag_f(argc, argv, str, i, substring, num_substrings);
    // добавляем флаг и добавляем все шаблоны из файла в массив substring
    // обработка остальных флагов
    if (*str == 'i') flags |= GREP_I;
    if (*str == 'v') flags |= GREP_V;
    if (*str == 'c') flags |= GREP_C;
    if (*str == 'l') flags |= GREP_L;
    if (*str == 'n') flags |= GREP_N;
    if (*str == 'h') flags |= GREP_H;
    if (*str == 's') flags |= GREP_S;
    if (*str == 'o') flags |= GREP_O;
    if (!((*str == 'e') || (*str == 'i') || (*str == 'v') || (*str == 'c') ||
          (*str == 'l') || (*str == 'n') || (*str == 'h') || (*str == 's') ||
          (*str == 'f') || (*str == 'o'))) {  // случай ошибки: был обнаружен
                                              // некорректный флаг неверный флаг
      ERR_OPTION(*str)
      *i = -1;
      *(str + 1) = '\0';
    }
    str++;
  }
  return flags;
}

int indicate_flag_e(int argc, char **argv, char *str, int *i, char ***substring,
                    int *num_substrings) {
  if (*(str + 1)) {
    // шаблон может находиться в этом же аргументе командной строки
    addstr(substring, num_substrings, str + 1);  // добавляем шаблон в массив
  } else {
    if (*i + 1 < argc) {  // или в след параметре
      addstr(substring, num_substrings,
             argv[++(*i)]);  // добавляем шаблон в массив
    } else {
      fprintf(stderr, "grep: option requires an argument -- f\n");
      ERR_USAGE
      *i = -1;  // если ни один из случаев не был обработан, то ошибка
    }
  }
  *(str + 1) = '\0';  // дальше этот аргумент командной строки не должен
                      // обрабатываться, т е выход из цикла
  return GREP_E;
}

int indicate_flag_f(int argc, char **argv, char *str, int *i, char ***substring,
                    int *num_substrings) {
  char *file_name = NULL, *sub;
  FILE *fp;
  if (*(str + 1)) {  // имя файла может находиться в этом же аргументе командной
                     // строки
    file_name = str + 1;
  } else {
    if (*i + 1 < argc)  // или в след параметре
      file_name = argv[++(*i)];
    else
      *i = -1;  // если ни один из случаев не был обработан, то ошибка
  }
  if (file_name != NULL) {
    if ((fp = fopen(file_name, "r")) != NULL) {
      while ((sub = input_string(fp)) != NULL) {
        addstr(substring, num_substrings, sub);
        free(sub);
      }
      fclose(fp);
    } else {
      ERR_FILE(file_name);
    }
  } else {
    *i = -1;
    fprintf(stderr, "grep: option requires an argument -- f\n");
    ERR_USAGE
  }
  *(str + 1) = '\0';  // дальше этот аргумент командной строки не должен
                      // обрабатываться, т е выход из цикла
  return GREP_F;
}
void s21_grep(int flags, char **substring, int num_substrings, char **filenames,
              int num_filenames) {
  int i;
  if ((flags & GREP_V) && (flags & GREP_O))
    flags -= GREP_O;  // взаимоисключающие флаги

  if (!num_filenames)
    // если не было найдено ни одного файла в командной строке
    s21_grep_file(NULL, flags, substring, num_substrings);
  // то обработка со стандартного ввода

  if (num_filenames >= 2)
    // ставим флаг нескольких файлов (для последующего вывода)
    flags |= FILES;
  // printf("%d\n", flags);

  for (i = 0; i < num_filenames; ++i) {  // проходимся по всем файлам
    char *file_name = filenames[i];
    FILE *fp;
    if ((fp = fopen(file_name, "r")) !=
        NULL) {  // если файл доступен для чтения
      fclose(fp);
      s21_grep_file(file_name, flags, substring,
                    num_substrings);  // вызываем функцию grep для одного файла
    } else {
      ERR_FILE(file_name)  // ошибка: файл не открылся
    }
  }
}
void s21_grep_file(char *file_name, int flags, char **substring,
                   int num_substrings) {
  FILE *fp;
  int num_str = 1, count = 0;
  char *str_file;

  if (file_name)  // открытие файла или стандартного потока ввода
    fp = fopen(file_name, "r");
  else
    fp = stdin;

  while ((str_file = input_string(fp)) != NULL) {  // пока ест строка для чтения
    count += file_line(flags, str_file, file_name, num_str, substring,
                       num_substrings);
    // добавляем либо количество вхождений (для флага О),
    // либо 1, если было хотя бы одно вхождение, 0 - иначе
    free(str_file);
    num_str++;  // номер строки в файле
    // printf("%s:%d:%d\n", file_name,  num_str, count);
  }
  if (GREP_C & flags) {  // если флаг С, то выводим только количество
    if ((flags & FILES) &&
        !(GREP_H & flags))  // вывод имени файла перед количеством
      printf("%s:", file_name);
    if (GREP_L & flags)  // если флаг L то нужно указать только количество
      if (count) count = 1;
    printf("%d\n", count);
  }
  if ((GREP_L & flags) &&
      count) {  // если флаг L то дополнительно выводим имя файла
    printf("%s\n", file_name);
  }
}
int file_line(int flags, char *str_file, char *file_name, int num_str,
              char **substring, int num_substrings) {
  int res = 0;
  if ((flags & GREP_E) || (flags & GREP_F)) {
    res |= file_line_pattern(flags, str_file, file_name, num_str, substring,
                             num_substrings);
    // printf("%d\n", res);
  } else {
    res = file_line_str(flags, str_file, file_name, num_str, *substring);
  }
  if (GREP_V & flags) res = !res;
  if (!(GREP_C & flags) && !(GREP_L & flags) && !(GREP_O & flags)) {
    if ((flags & FILES) && !(GREP_H & flags) && res) printf("%s:", file_name);

    if ((GREP_N & flags) && res) printf("%d:", num_str);

    if (res && !(GREP_O & flags)) printf("%s\n", str_file);
  }
  return res;
}

int file_line_pattern(int flags, char *str_file, char *file_name, int num_str,
                      char **substring, int num_substrings) {
  regex_t *preg = malloc(sizeof(regex_t));
  regmatch_t pmatch;
  int cflags = 0, i;
  int q = 0, res = 0;
  char *copy_str_file = malloc(sizeof(char) * (strlen(str_file) + 1));
  strcpy(copy_str_file, str_file);
  char *str = copy_str_file;
  if (flags & GREP_I) fall(str);
  // printf("err\n");

  for (i = 0; i < num_substrings; ++i) {  // цикл по всем шаблонам
    q = 0;
    char *sub = malloc(sizeof(char) * (strlen(substring[i]) + 1));
    strcpy(sub, substring[i]);
    if (flags & GREP_I) fall(sub);
    regcomp(preg, sub, cflags);  // подготовка шаблона к поиску
    q |= (regexec(preg, str, 1, &pmatch, 0) == 0) ||
         (*sub == '\0');  // проверка найден ли шаблон
    // printf("TUT%d\n", q);
    if ((GREP_O & flags) && q) {  // обработка флага О
      if ((flags & FILES) && !res && !((GREP_H | GREP_C | GREP_L) & flags))
        printf("%s:", file_name);

      if ((flags & GREP_N) && !res && !((GREP_L | GREP_C) & flags))
        printf("%d:", num_str);

      while (regexec(preg, str, 1, &pmatch, 0) ==
             0) {  // поиск всех шаблонов в строке
        int m;
        if (!((GREP_C | GREP_L) & flags)) {
          for (m = pmatch.rm_so; m < pmatch.rm_eo;
               ++m)  // вывод шаблонов (флаг О)
            printf("%c", str[m]);
          printf("\n");
        }
        str = str + pmatch.rm_so + 1;
      }
    }
    regfree(preg);
    free(sub);
    res = res || q;
  }
  free(preg);
  free(copy_str_file);
  return res;
}

int file_line_str(int flags, char *str_file, char *file_name, int num_str,
                  char *copy_sub) {
  char *copy_str_file = malloc(sizeof(char) * (strlen(str_file) + 1));
  strcpy(copy_str_file, str_file);
  char *str = copy_str_file;
  char *sub = malloc(sizeof(char) * (strlen(copy_sub) + 1));
  strcpy(sub, copy_sub);
  if (flags & GREP_I) {
    fall(str);
    fall(sub);
  }
  int res = (strstr(str, sub) != NULL);
  if ((GREP_O & flags) && res && !(GREP_C & flags)) {
    // printf("%d\n", res);
    char *f = str;
    if ((flags & FILES) && !(GREP_H & flags) && !(GREP_C & flags) &&
        !(GREP_L & flags))
      printf("%s:", file_name);
    if ((GREP_N & flags) && res && !(GREP_C & flags) && !(GREP_L & flags))
      printf("%d:", num_str);
    while (strstr(f, sub) != NULL) {
      if (!(GREP_C & flags) && !(GREP_L & flags)) printf("%s\n", copy_sub);
      f = strstr(f, sub);
      f = (f != NULL ? f + 1 : NULL);
    }
  }
  free(sub);
  free(copy_str_file);
  return res;
}
