#include "test_me.h"

START_TEST(test_calc_complements_1) {
  matrix_t A, B, C;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 4;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  B.matrix[0][0] = -8;
  B.matrix[0][1] = -2;
  B.matrix[0][2] = 6;
  B.matrix[1][0] = 8;
  B.matrix[1][1] = -4;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = -2;
  B.matrix[2][1] = 7;
  B.matrix[2][2] = -3;

  ck_assert_int_eq(0, s21_calc_complements(&A, &C));

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      ck_assert_ldouble_eq_tol(C.matrix[i][j], B.matrix[i][j], 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t A, B, C;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = 4;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &B));
  B.matrix[0][0] = -8 / 12.0;
  B.matrix[0][1] = 8 / 12.0;
  B.matrix[0][2] = -2 / 12.0;
  B.matrix[1][0] = -2 / 12.0;
  B.matrix[1][1] = -4 / 12.0;
  B.matrix[1][2] = 7 / 12.0;
  B.matrix[2][0] = 6 / 12.0;
  B.matrix[2][1] = 0 / 12.0;
  B.matrix[2][2] = -3 / 12.0;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &C));

  // for (int i = 0; i < 3; ++i)
  //   for (int j = 0; j < 3; ++j)
  //     printf("%f ", B.matrix[i][j]);
  // printf("\n");
  // for (int i = 0; i < 3; ++i)
  //   for (int j = 0; j < 3; ++j)
  //     printf("%f ", C.matrix[i][j]);

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      ck_assert_ldouble_eq_tol(C.matrix[i][j], B.matrix[i][j], 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 3, &A));
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(2, s21_inverse_matrix(&A, &B));

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t A, B;
  ck_assert_int_eq(0, s21_create_matrix(3, 4, &A));

  ck_assert_int_eq(2, s21_inverse_matrix(&A, &B));

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_5) {
  ck_assert_int_eq(1, s21_inverse_matrix(NULL, NULL));
}
END_TEST

START_TEST(test_calc_complements_6) {
  matrix_t A, B, C;
  ck_assert_int_eq(0, s21_create_matrix(1, 1, &A));
  A.matrix[0][0] = 1;
  ck_assert_int_eq(0, s21_create_matrix(1, 1, &B));
  B.matrix[0][0] = 1;

  ck_assert_int_eq(0, s21_inverse_matrix(&A, &C));

  // for (int i = 0; i < 3; ++i)
  //   for (int j = 0; j < 3; ++j)
  //     printf("%f ", B.matrix[i][j]);
  // printf("\n");
  // for (int i = 0; i < 3; ++i)
  //   for (int j = 0; j < 3; ++j)
  //     printf("%f ", C.matrix[i][j]);

  ck_assert_ldouble_eq_tol(C.matrix[0][0], B.matrix[0][0], 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_calc_complements_1);
  tcase_add_test(tc, test_calc_complements_2);
  tcase_add_test(tc, test_calc_complements_3);
  tcase_add_test(tc, test_calc_complements_4);
  tcase_add_test(tc, test_calc_complements_5);
  tcase_add_test(tc, test_calc_complements_6);

  suite_add_tcase(s, tc);
  return s;
}
