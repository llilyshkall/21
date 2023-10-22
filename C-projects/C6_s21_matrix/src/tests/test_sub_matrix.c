#include "test_me.h"

START_TEST(test_sub_matrix_1) {
  matrix_t A, B, result;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      A.matrix[i][j] = i;
      B.matrix[i][j] = j;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      ck_assert_ldouble_eq_tol(result.matrix[i][j], i - j, 1e-6);
      B.matrix[i][j] = j;
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sub_matrix_2) {
  matrix_t A, B, result;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 4, &B));
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      A.matrix[i][j] = i;
      B.matrix[i][j] = j;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  s21_remove_matrix(&A);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
}
END_TEST

START_TEST(test_sub_matrix_3) {
  matrix_t A, B, result;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(4, 3, &B));
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 3; ++j) {
      A.matrix[i][j] = i;
      B.matrix[i][j] = j;
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_sub_matrix_4) {
  matrix_t A, B, result;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.rows = 0;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  A.rows = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_5) {
  matrix_t A, B, result;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.columns = 0;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  A.columns = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_6) {
  matrix_t A, B, result;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  B.columns = 0;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  B.columns = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_7) {
  matrix_t A, B, result;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  B.rows = 0;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
  B.rows = 3;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("\033[45m-=S21_SUM_MATRIX=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_sub_matrix_1);
  tcase_add_test(tc, test_sub_matrix_2);
  tcase_add_test(tc, test_sub_matrix_3);
  tcase_add_test(tc, test_sub_matrix_4);
  tcase_add_test(tc, test_sub_matrix_5);
  tcase_add_test(tc, test_sub_matrix_6);
  tcase_add_test(tc, test_sub_matrix_7);

  suite_add_tcase(s, tc);
  return s;
}
