#include "test_me.h"

START_TEST(test_create_remove_1) {
  matrix_t A;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(3, A.columns);
  ck_assert_int_eq(3, A.rows);
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) ck_assert_ldouble_eq_tol(A.matrix[i][j], 0, 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_create_remove_2) {
  matrix_t A;
  ck_assert_int_eq(1, s21_create_matrix(-1, 3, &A));
  ck_assert_int_eq(1, s21_create_matrix(3, -2, &A));
  ck_assert_int_eq(1, s21_create_matrix(0, -2, &A));
  ck_assert_int_eq(1, s21_create_matrix(0, 2, &A));
  ck_assert_int_eq(1, s21_create_matrix(2, 0, &A));
}
END_TEST

Suite *test_create_remove(void) {
  Suite *s = suite_create("\033[45m-=S21_CREATE_REMOVE=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_create_remove_1);
  tcase_add_test(tc, test_create_remove_2);

  suite_add_tcase(s, tc);
  return s;
}
