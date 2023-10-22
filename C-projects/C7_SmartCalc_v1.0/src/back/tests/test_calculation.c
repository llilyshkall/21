#include "test_me.h"

START_TEST(test_calculation_1) {
  int ret = 0;

  long double ans;
  char expression[300] = "(-58 + * 10)";
  ck_assert_int_eq(calculation(expression, 0, &ans), ret);
  // ck_assert_ldouble_eq(ans, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_2) {
  int ret = 0;

  long double ans;
  char expression[300] = "()";
  ck_assert_int_eq(calculation(expression, 0, &ans), ret);
  // ck_assert_ldouble_eq(ans, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_3) {
  int ret = 1;

  long double check_ans = 1;
  long double ans = 1;
  long double x = 1;
  char expression[300] = "(x)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_4) {
  int ret = 0;

  // long double check_ans = 1;
  long double ans = 1;
  long double x = 1;
  char expression[300] = "(123+345-43*)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  // ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_5) {
  int ret = 1;

  long double check_ans = 0;
  long double ans = 0;
  long double x = 0;
  char expression[300] = "(sin(asin(cos(acos(x)))))";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_6) {
  int ret = 1;

  long double check_ans = 0;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "(tan(atan(ln(log(X)))))";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_7) {
  int ret = 1;

  long double check_ans = 10;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "sQRt( (-X)^2)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_8) {
  int ret = 1;

  long double check_ans = -34701.5;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "345-786*45+567-(+234)-\n\t76/8mod100";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_9) {
  int ret = 0;

  // long double check_ans = -34701.5;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "(12 24)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  // ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_10) {
  int ret = 0;

  // long double check_ans = -34701.5;
  long double ans = 0;
  long double x = 10;
  char expression[300] = ")";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  // ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_11) {
  int ret = 0;

  long double ans;
  char expression[300] = "(-58 + * 10)";
  ck_assert_int_eq(calculation(expression, 0, &ans), ret);
  // ck_assert_ldouble_eq(ans, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_12) {
  int ret = 0;

  long double ans;
  char expression[300] = "()";
  ck_assert_int_eq(calculation(expression, 0, &ans), ret);
  // ck_assert_ldouble_eq(ans, CALCULATION_ERROR);
}
END_TEST

START_TEST(test_calculation_13) {
  int ret = 1;

  long double check_ans = 1;
  long double ans = 1;
  long double x = 1;
  char expression[300] = "(x)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_14) {
  int ret = 0;

  // long double check_ans = 1;
  long double ans = 1;
  long double x = 1;
  char expression[300] = "(123+345-43*)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  // ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_15) {
  int ret = 1;

  long double check_ans = 0;
  long double ans = 0;
  long double x = 0;
  char expression[300] = "(sin(asin(cos(acos(x)))))";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_16) {
  int ret = 1;

  long double check_ans = 0;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "(tan(atan(ln(log(X)))))";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_17) {
  int ret = 1;

  long double check_ans = 10;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "sQRt( (-X)^2)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_18) {
  int ret = 1;

  long double check_ans = -34701.5;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "345-786*45+567-(+234)-\n\t76/8mod100";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_19) {
  int ret = 0;

  // long double check_ans = -34701.5;
  long double ans = 0;
  long double x = 10;
  char expression[300] = "(12 24)";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  // ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

START_TEST(test_calculation_20) {
  int ret = 0;

  // long double check_ans = -34701.5;
  long double ans = 0;
  long double x = 10;
  char expression[300] = ")";
  ck_assert_int_eq(calculation(expression, x, &ans), ret);
  // ck_assert_ldouble_eq_tol(ans, check_ans, 1e-6);
}
END_TEST

Suite *test_calculation(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST CALCULATION=-\033[0m");
  TCase *tc = tcase_create("s21_test_calculation_tc");

  tcase_add_test(tc, test_calculation_1);
  tcase_add_test(tc, test_calculation_2);
  tcase_add_test(tc, test_calculation_3);
  tcase_add_test(tc, test_calculation_4);
  tcase_add_test(tc, test_calculation_5);
  tcase_add_test(tc, test_calculation_6);
  tcase_add_test(tc, test_calculation_7);
  tcase_add_test(tc, test_calculation_8);
  tcase_add_test(tc, test_calculation_9);
  tcase_add_test(tc, test_calculation_10);
  tcase_add_test(tc, test_calculation_11);
  tcase_add_test(tc, test_calculation_12);
  tcase_add_test(tc, test_calculation_13);
  tcase_add_test(tc, test_calculation_14);
  tcase_add_test(tc, test_calculation_15);
  tcase_add_test(tc, test_calculation_16);
  tcase_add_test(tc, test_calculation_17);
  tcase_add_test(tc, test_calculation_18);
  tcase_add_test(tc, test_calculation_19);
  tcase_add_test(tc, test_calculation_20);

  suite_add_tcase(s, tc);
  return s;
}
