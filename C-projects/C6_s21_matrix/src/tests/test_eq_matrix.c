#include "test_me.h"

START_TEST(test_eq_matrix_1) {
  matrix_t A, B;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_2) {
  matrix_t A, B;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 5, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 5, &B));
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 5; ++j) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_3) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 5, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 4, &B));
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_4) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(2, 5, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 5, &B));
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_5) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  A.columns = 0;
  B.columns = 0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  A.columns = 3;
  B.columns = 3;
  s21_remove_matrix(&B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
}
END_TEST

START_TEST(test_eq_matrix_6) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  A.rows = 0;
  B.rows = 0;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  A.rows = 3;
  B.rows = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_EQ_MATRIX=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_eq_matrix_1);
  tcase_add_test(tc, test_eq_matrix_2);
  tcase_add_test(tc, test_eq_matrix_3);
  tcase_add_test(tc, test_eq_matrix_4);
  tcase_add_test(tc, test_eq_matrix_5);
  tcase_add_test(tc, test_eq_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
