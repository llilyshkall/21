#include "test_me.h"

START_TEST(s21_negate_1) {
  int true_res = 1;
  s21_decimal val1 = {{0xAE56BAB1, 0xDD8C865E, 0xB2952F05, 0x80110000}};
  s21_decimal *output = NULL;
  int s21_res = s21_negate(val1, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_2) {
  int true_res = 0;
  s21_decimal val1 = {{0x2D49DA8F, 0xDF69976D, 0x66F5B9AE, 0x800C0000}};
  s21_decimal result = {{0x2D49DA8F, 0xDF69976D, 0x66F5B9AE, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_3) {
  int true_res = 0;
  s21_decimal val1 = {{0x0D002B08, 0x2E8F72FC, 0x36DBE597, 0x800F0000}};
  s21_decimal result = {{0x0D002B08, 0x2E8F72FC, 0x36DBE597, 0x000F0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_4) {
  int true_res = 0;
  s21_decimal val1 = {{0x4016945A, 0xC024AC55, 0x7AD7D5C0, 0x00050000}};
  s21_decimal result = {{0x4016945A, 0xC024AC55, 0x7AD7D5C0, 0x80050000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_5) {
  int true_res = 0;
  s21_decimal val1 = {{0x83172C7A, 0x6255A473, 0x5B278B48, 0x80070000}};
  s21_decimal result = {{0x83172C7A, 0x6255A473, 0x5B278B48, 0x00070000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_6) {
  int true_res = 0;
  s21_decimal val1 = {{0x7CA3F841, 0x8C2C4E67, 0x8223D4E6, 0x80090000}};
  s21_decimal result = {{0x7CA3F841, 0x8C2C4E67, 0x8223D4E6, 0x00090000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_7) {
  int true_res = 0;
  s21_decimal val1 = {{0x37D05B51, 0x9469AD15, 0xEADDE653, 0x00010000}};
  s21_decimal result = {{0x37D05B51, 0x9469AD15, 0xEADDE653, 0x80010000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_8) {
  int true_res = 0;
  s21_decimal val1 = {{0xB98C3618, 0x9B1922B8, 0x56AC8182, 0x000A0000}};
  s21_decimal result = {{0xB98C3618, 0x9B1922B8, 0x56AC8182, 0x800A0000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_9) {
  int true_res = 0;
  s21_decimal val1 = {{0x9E50DC4C, 0x72FF977E, 0x060B3C70, 0x00040000}};
  s21_decimal result = {{0x9E50DC4C, 0x72FF977E, 0x060B3C70, 0x80040000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_10) {
  int true_res = 0;
  s21_decimal val1 = {{0x7711CCD1, 0x66FE9CD4, 0xE70E4954, 0x00130000}};
  s21_decimal result = {{0x7711CCD1, 0x66FE9CD4, 0xE70E4954, 0x80130000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("\033[45m-=S21_NEGATE=-\033[0m");
  TCase *tc = tcase_create("s21_negate_tc");

  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);
  tcase_add_test(tc, s21_negate_6);
  tcase_add_test(tc, s21_negate_7);
  tcase_add_test(tc, s21_negate_8);
  tcase_add_test(tc, s21_negate_9);
  tcase_add_test(tc, s21_negate_10);

  suite_add_tcase(s, tc);
  return s;
}
