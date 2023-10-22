#include "test_me.h"

START_TEST(test_determinant_1) {
  matrix_t A;
  double res;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  for (i = 0; i < 3; ++i)
    for (j = 0; j < 3; ++j) A.matrix[i][j] = i * 3 + j;
  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_ldouble_eq_tol(res, 0, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_2) {
  matrix_t A;
  double res;
  int i, j;
  ck_assert_int_eq(0, s21_create_matrix(2, 2, &A));
  for (i = 0; i < 2; ++i)
    for (j = 0; j < 2; ++j) A.matrix[i][j] = i * 2 + j + 1;
  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_ldouble_eq_tol(res, -2, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_3) {
  matrix_t A;
  double res;
  ck_assert_int_eq(0, s21_create_matrix(5, 5, &A));
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[0][3] = 5;
  A.matrix[0][4] = 11;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 0;
  A.matrix[1][4] = 13;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = -1;
  A.matrix[2][4] = 5;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 3;
  A.matrix[3][3] = 0;
  A.matrix[3][4] = 7;
  A.matrix[4][0] = 4;
  A.matrix[4][1] = 1;
  A.matrix[4][2] = 2;
  A.matrix[4][3] = 3;
  A.matrix[4][4] = 8;

  ck_assert_int_eq(s21_determinant(&A, &res), 0);
  ck_assert_ldouble_eq_tol(res, 264, 1e-6);
  s21_remove_matrix(&A);
}
END_TEST

// START_TEST(test_determinant_4) {
//   matrix_t A, B;
//   ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
//   A.columns = 0;
//   ck_assert_int_eq(s21_determinant(&A, &B), 1);
//   A.columns = 3;
//   s21_remove_matrix(&A);
// }
// END_TEST

// START_TEST(test_determinant_3) {
//   matrix_t A, B;
//   ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
//   A.rows = 0;
//   ck_assert_int_eq(s21_determinant(&A, &B), 1);
//   A.rows = 3;
//   s21_remove_matrix(&A);
//   ck_assert_int_eq(s21_determinant(&A, &B), 1);
// }
// END_TEST

START_TEST(test_determinant_4) {
  matrix_t A;
  double res;
  ck_assert_int_eq(0, s21_create_matrix(5, 4, &A));

  ck_assert_int_eq(s21_determinant(&A, &res), 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[45m-=S21_DETERMINANT=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_determinant_1);
  tcase_add_test(tc, test_determinant_2);
  tcase_add_test(tc, test_determinant_3);
  tcase_add_test(tc, test_determinant_4);

  suite_add_tcase(s, tc);
  return s;
}
