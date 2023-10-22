#ifndef SRC_TESTS_ME_H
#define SRC_TESTS_ME_H

#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *test_create_remove(void);
Suite *test_eq_matrix(void);
Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);
Suite *test_transpose(void);
Suite *test_determinant(void);
Suite *test_calc_complements(void);

#endif  // SRC_TESTS_ME_H
