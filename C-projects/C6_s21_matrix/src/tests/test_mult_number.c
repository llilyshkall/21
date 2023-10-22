#include "test_me.h"

START_TEST(test_mult_number_1) {
  matrix_t A, B;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) A.matrix[i][j] = i + j;
  ck_assert_int_eq(s21_mult_number(&A, 0.2, &B), 0);
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j)
      ck_assert_ldouble_eq_tol(A.matrix[i][j] * 0.2, B.matrix[i][j], 1e-6);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_number_2) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.columns = 0;
  ck_assert_int_eq(s21_mult_number(&A, 0.2, &B), 1);
  A.columns = 3;
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_number_3) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.rows = 0;
  ck_assert_int_eq(s21_mult_number(&A, 0.2, &B), 1);
  A.rows = 3;
  s21_remove_matrix(&A);
  ck_assert_int_eq(s21_mult_number(&A, 0.2, &B), 1);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[45m-=S21_MULT_NUMBER=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_mult_number_1);
  tcase_add_test(tc, test_mult_number_2);
  tcase_add_test(tc, test_mult_number_3);

  suite_add_tcase(s, tc);
  return s;
}
