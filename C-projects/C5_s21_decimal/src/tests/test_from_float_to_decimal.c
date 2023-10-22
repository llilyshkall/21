#include "test_me.h"

START_TEST(s21_float_000) {
  float inp = 1. / 0.;
  s21_decimal out;
  int error = s21_from_float_to_decimal(inp, &out);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(s21_float_00) {
  float inp = 2;
  s21_decimal *out = NULL;
  int error = s21_from_float_to_decimal(inp, out);
  ck_assert_ptr_eq(out, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(s21_float_0) {
  float inp = 2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_1) {
  float inp = -321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 0x80010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_2) {
  float inp = 321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_3) {
  float inp = 321213143.8323;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x13255310, 0, 0, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_4) {
  float inp = 9732131234575756436473.323123474;
  s21_decimal out = {{3211, 123145, 231, 312441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xC7238000, 0x9472ED75, 0x0000020F, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_5) {
  float inp = 73.329959999;
  s21_decimal out = {{3211, 123145, 231, 312441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x006FE484, 0, 0, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_6) {
  float inp = 0.003;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000003, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_7) {
  float inp = 0.00312345;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0004C419, 0, 0, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_8) {
  float inp = 0.00000003123959595945;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0004C44C, 0, 0, 0x000D0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_9) {
  float inp = 0.0000000000000000093929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x008F532B, 0, 0, 0x00180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_10) {
  float inp = 0.00000000000000000000000000013929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000001, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_10_5) {
  float inp = 0.00000000000000000000000000016929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_11) {
  float inp = .00000000000000000000000000000000193929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_float_12) {
  float inp = 2183182381923912939123.365656f;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8ADB0000, 0x59BC8E01, 0x00000076, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_13) {
  float inp = 79215000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xCF000000, 0xAC05AE5D, 0xFFF51CBA, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_14) {
  float inp = 7015000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xC7000000, 0xFFD18396, 0x16AAAC07, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_15) {
  float inp = 0.00000000000000000000000005646473736464;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000235, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_16) {
  float inp = 0.00000000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_17) {
  float inp = 0.00000000000000000000000858598287381972;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000218A, 0, 0, 0x001B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_18) {
  float inp = 0.000000000000000000000099999999999;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000001, 0, 0, 0x00160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_19) {
  float inp = 0.00000000000000000000073766666662636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00708F1B, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_20) {
  float inp = 0.0000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00708344, 0, 0, 0x001B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST
START_TEST(s21_float_21) {
  float inp = 0.00000000000000000000000073736361612636;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00001CCE, 0, 0, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_22) {
  float inp = -1.307818E+07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00C78EA4, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_23) {
  float inp = -30914.76;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002F2C14, 0x00000000, 0x00000000, 0x80020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_24) {
  float inp = 1.965111E-26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000000C5, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_25) {
  float inp = -750.9904;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00729790, 0x00000000, 0x00000000, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_26) {
  float inp = 72932.2;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000B20EA, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_27) {
  float inp = 7.526432E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0072D820, 0x00000000, 0x00000000, 0x000C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_29) {
  float inp = -1.391184E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x9DB88000, 0x01EE3F72, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_30) {
  float inp = 3.693497E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00385BB9, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_31) {
  float inp = 351871.4;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0035B0FA, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_32) {
  float inp = 0.1175977;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0011F1A9, 0x00000000, 0x00000000, 0x00070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_33) {
  float inp = -2.013319E-14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001EB887, 0x00000000, 0x00000000, 0x80140000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_34) {
  float inp = -280.7036;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002AD4FC, 0x00000000, 0x00000000, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_35) {
  float inp = -3.196059E+18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x2030B000, 0x2C5AAEBA, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_36) {
  float inp = -1.38892E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x50527800, 0x00007E52, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_37) {
  float inp = 6.068951E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x69BCD7D8, 0x00000001, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_38) {
  float inp = -1.190043E+24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF98C0000, 0x5C3C75F5, 0x0000FC00, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_39) {
  float inp = 4.511203E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000002D, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_40) {
  float inp = -7.442655E+23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x1B360000, 0xB6AE8261, 0x00009D9A, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_41) {
  float inp = 8.763741E+26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8CD00000, 0x28107A63, 0x02D4EB6F, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_42) {
  float inp = -5.447201E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_43) {
  float inp = 1.333345E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x6F8D0680, 0x00000C20, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_44) {
  float inp = -3.85058E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0005E022, 0x00000000, 0x00000000, 0x800B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_45) {
  float inp = 1.325723E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00143A9B, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_46) {
  float inp = -5.831514E+23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x30840000, 0xB3639777, 0x00007B7C, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_47) {
  float inp = -1.337444E-22;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00146864, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_48) {
  float inp = 1.230342E+28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xAD800000, 0xA66BA8BD, 0x27C12686, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_49) {
  float inp = -8.335803E-07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x007F31BB, 0x00000000, 0x00000000, 0x800D0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_50) {
  float inp = 9.196544E-25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000023ED, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_51) {
  float inp = 2.922531E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x9AB80000, 0x3ACC2F60, 0x00182CB3, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_52) {
  float inp = 1.581408E+19;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x319C0000, 0xDB76E5F9, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_53) {
  float inp = -3.22218E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000020, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_54) {
  float inp = 1.290434E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0013B0C2, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_55) {
  float inp = -1.162378E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0011BC8A, 0x00000000, 0x00000000, 0x801A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_56) {
  float inp = -1.609435E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x78FAEAE0, 0x00000025, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_57) {
  float inp = -2.747507E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0029EC73, 0x00000000, 0x00000000, 0x800C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_58) {
  float inp = -2.233666E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_59) {
  float inp = -9.564972E-05;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0091F32C, 0x00000000, 0x00000000, 0x800B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_60) {
  float inp = 6.76729E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000A5379, 0x00000000, 0x00000000, 0x00100000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_61) {
  float inp = -1.56421E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0952CB88, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_62) {
  float inp = 1.248784E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00130E10, 0x00000000, 0x00000000, 0x00110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_63) {
  float inp = 3.830389E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000004, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_64) {
  float inp = -7.518575E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8BEBC180, 0x00004461, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_65) {
  float inp = 1.759471E+20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0821C000, 0x89C1AB3E, 0x00000009, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_66) {
  float inp = -1.730171E+16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x468E8C00, 0x003D77D0, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_67) {
  float inp = -0.005833615;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0059038F, 0x00000000, 0x00000000, 0x80090000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_68) {
  float inp = -1.083782E+27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x27C00000, 0xF1EDC3B6, 0x03807BC3, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_69) {
  float inp = -2.543952E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x3B22B200, 0x0000003B, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_70) {
  float inp = 8.122079E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE41D1718, 0x00000001, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_71) {
  float inp = -1.381688E-13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00151538, 0x00000000, 0x00000000, 0x80130000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_72) {
  float inp = 5.3419E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8890E000, 0x0769D2F9, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_73) {
  float inp = -1.899235E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xD8B80000, 0x5B459112, 0x000FB5C9, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_74) {
  float inp = 0.01434358;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0015E2F6, 0x00000000, 0x00000000, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_75) {
  float inp = -8.395913E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x320B2584, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_76) {
  float inp = 2.963941E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002D39E5, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_77) {
  float inp = -4.554593E-25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000011CB, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_78) {
  float inp = 1.511913E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001711E9, 0x00000000, 0x00000000, 0x001A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_79) {
  float inp = 12.18852;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00129924, 0x00000000, 0x00000000, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_80) {
  float inp = 8.216155E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x007D5E5B, 0x00000000, 0x00000000, 0x00110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_81) {
  float inp = -0.7325138;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x006FC5D2, 0x00000000, 0x00000000, 0x80070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_82) {
  float inp = 49394.41;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x004B5EB1, 0x00000000, 0x00000000, 0x00020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_83) {
  float inp = 0.0002621874;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002801B2, 0x00000000, 0x00000000, 0x000A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_84) {
  float inp = 5.880856E+15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x7CDAF000, 0x0014E49B, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_85) {
  float inp = -7.048725E-24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00011357, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_86) {
  float inp = 1.661392E-16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001959D0, 0x00000000, 0x00000000, 0x00160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_87) {
  float inp = -3.749618E-17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003936F2, 0x00000000, 0x00000000, 0x80170000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_88) {
  float inp = -1.078071E+10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x82949470, 0x00000002, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_89) {
  float inp = -942.165;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000E6055, 0x00000000, 0x00000000, 0x80030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_90) {
  float inp = 8.128622E+24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0CF80000, 0x7B4932DD, 0x0006B94D, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_91) {
  float inp = 3.478075E-10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0035123B, 0x00000000, 0x00000000, 0x00100000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_92) {
  float inp = -0.2220105;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0021E049, 0x00000000, 0x00000000, 0x80070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_93) {
  float inp = -4.057507E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003DE9A3, 0x00000000, 0x00000000, 0x80110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_94) {
  float inp = -7.703651E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x75D03380, 0x00004610, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_95) {
  float inp = 4.329224E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00420F08, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_96) {
  float inp = -3.238849E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00316BC1, 0x00000000, 0x00000000, 0x800C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_97) {
  float inp = -5.937755E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x005A9A5B, 0x00000000, 0x00000000, 0x80180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_98) {
  float inp = 9.214601E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x008C9A89, 0x00000000, 0x00000000, 0x000F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_99) {
  float inp = -2.788572E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x80595C00, 0x0000FD9E, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_100) {
  float inp = -0.2386963;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00246C13, 0x00000000, 0x00000000, 0x80070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_101) {
  float inp = -4.803305E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00494AE9, 0x00000000, 0x00000000, 0x801A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_102) {
  float inp = -6.715998E+27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xFEC00000, 0x19B4CE7F, 0x15B357E5, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_103) {
  float inp = 1.001074E+27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE3400000, 0x47EB885C, 0x033C11AA, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_104) {
  float inp = 1.061498E+12;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x26361280, 0x000000F7, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_105) {
  float inp = -5.398762E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF8E99100, 0x00003119, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_106) {
  float inp = 2.011937E-05;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001EB321, 0x00000000, 0x00000000, 0x000B0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_107) {
  float inp = 1.208047E+28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE9C00000, 0xEEAB1663, 0x2708BB06, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_108) {
  float inp = -3.577309;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003695DD, 0x00000000, 0x00000000, 0x80060000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_109) {
  float inp = -0.01349936;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00149930, 0x00000000, 0x00000000, 0x80080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_110) {
  float inp = 2.636795E+21;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x4E1F8000, 0xF0E1AA29, 0x0000008E, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_111) {
  float inp = 1.886762E+28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xBE800000, 0xAE79E847, 0x3CF6EDF1, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_112) {
  float inp = 1.137225E+20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xED5C4000, 0x2A377B38, 0x00000006, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_113) {
  float inp = 2.033605E-23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00031A61, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_114) {
  float inp = -3.082871E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xAF159700, 0x00011862, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_115) {
  float inp = -4.087111E-10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003E5D47, 0x00000000, 0x00000000, 0x80100000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_116) {
  float inp = -1.082272E+23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x14400000, 0x021DDBB8, 0x000016EB, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_117) {
  float inp = -9.243464E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x008D0B48, 0x00000000, 0x00000000, 0x801A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_118) {
  float inp = -1.351883E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0014A0CB, 0x00000000, 0x00000000, 0x80110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_119) {
  float inp = 1.067036E+22;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x811C0000, 0x70FDEE02, 0x00000242, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_120) {
  float inp = -1.655359E-07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0019423F, 0x00000000, 0x00000000, 0x800D0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_121) {
  float inp = -2.818527E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002B01DF, 0x00000000, 0x00000000, 0x800F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_122) {
  float inp = 2.024663E-23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000316E2, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_123) {
  float inp = 2.310628E-10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002341E4, 0x00000000, 0x00000000, 0x00100000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_124) {
  float inp = 2968.287;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002D4ADF, 0x00000000, 0x00000000, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_125) {
  float inp = 1.229755E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0012C3BB, 0x00000000, 0x00000000, 0x00180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_126) {
  float inp = 1.059234E-14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001029A2, 0x00000000, 0x00000000, 0x00140000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_127) {
  float inp = -64208.49;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0061F971, 0x00000000, 0x00000000, 0x80020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_128) {
  float inp = 2.186795E+15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE32BEE00, 0x0007C4E0, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_129) {
  float inp = -2.191804E+07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x014E7158, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_130) {
  float inp = 6.5419E-24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000FF8B, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_131) {
  float inp = -1.152604E+26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF9C00000, 0xCDD8046A, 0x005F5756, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_132) {
  float inp = 6.767653E+21;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0AB08000, 0xE00D62F0, 0x0000016E, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_133) {
  float inp = -4.926002E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x6BEFF200, 0x0001C004, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_134) {
  float inp = 1.194919E+26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x4F700000, 0xE0F3DC90, 0x0062D764, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_135) {
  float inp = 0.2616035;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0027EAE3, 0x00000000, 0x00000000, 0x00070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_136) {
  float inp = -2.989957E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x893FB080, 0x00001B31, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_137) {
  float inp = -4.61851E-24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000B469, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_138) {
  float inp = -0.003898347;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003B7BEB, 0x00000000, 0x00000000, 0x80090000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_139) {
  float inp = 11.08692;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0010EAD4, 0x00000000, 0x00000000, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_140) {
  float inp = -0.003970314;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003C950A, 0x00000000, 0x00000000, 0x80090000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_141) {
  float inp = 1.054338E-15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00101682, 0x00000000, 0x00000000, 0x00150000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_142) {
  float inp = -32.53767;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0031A607, 0x00000000, 0x00000000, 0x80050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_143) {
  float inp = 0.06596097;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0064A601, 0x00000000, 0x00000000, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_144) {
  float inp = 8.861377E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE7E80000, 0x18E914DA, 0x00494CB2, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_145) {
  float inp = 2.324943E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000002, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_146) {
  float inp = 3191.227;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0030B1BB, 0x00000000, 0x00000000, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_147) {
  float inp = 0.938446;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000E51CE, 0x00000000, 0x00000000, 0x00060000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_148) {
  float inp = -3.894784E-17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003B6E00, 0x00000000, 0x00000000, 0x80170000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_149) {
  float inp = 7.679175E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xB9CDE700, 0x0002BA6A, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_150) {
  float inp = 9.389545E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x37F74F04, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_151) {
  float inp = -8.570058E+07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x051BAFE4, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_152) {
  float inp = 1.069406E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0010515E, 0x00000000, 0x00000000, 0x001A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_153) {
  float inp = 1963320;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001DF538, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_154) {
  float inp = 1631.409;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0018E4B1, 0x00000000, 0x00000000, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_155) {
  float inp = -9.583782E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00923CA6, 0x00000000, 0x00000000, 0x800F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_156) {
  float inp = 4.934571E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xEF284B00, 0x0001C0CB, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_157) {
  float inp = 10.23795;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000F9F33, 0x00000000, 0x00000000, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_158) {
  float inp = -703088.8;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x006B4868, 0x00000000, 0x00000000, 0x80010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_159) {
  float inp = -1.061253E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE82E8800, 0x01790865, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_160) {
  float inp = 0.0001655871;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0019443F, 0x00000000, 0x00000000, 0x000A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_161) {
  float inp = -158.45;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00003DE5, 0x00000000, 0x00000000, 0x80020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_162) {
  float inp = 2.961945E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF69165A0, 0x00000044, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_163) {
  float inp = -1.617612E-26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000000A2, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_164) {
  float inp = -212.0078;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0020598E, 0x00000000, 0x00000000, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_165) {
  float inp = 1.683534E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0019B04E, 0x00000000, 0x00000000, 0x001A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_166) {
  float inp = 1.360221E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x01480000, 0x4818EABE, 0x000B4061, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_167) {
  float inp = 4.304772E-15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0041AF84, 0x00000000, 0x00000000, 0x00150000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_168) {
  float inp = 2.341019E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x18973B00, 0x0000D4EA, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_169) {
  float inp = 2.241625E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00223459, 0x00000000, 0x00000000, 0x000C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_170) {
  float inp = -1.303562E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000000D, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_171) {
  float inp = 3.300137E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000003, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_172) {
  float inp = -6.89053E+23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xD4540000, 0xA35284BD, 0x000091E9, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_173) {
  float inp = -1.335107E-17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00145F43, 0x00000000, 0x00000000, 0x80170000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_174) {
  float inp = 4.299471E+28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xA1C00000, 0x5E84AF70, 0x8AEC63FB, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_175) {
  float inp = 5.439797E-13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00530135, 0x00000000, 0x00000000, 0x00130000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_176) {
  float inp = 9283997;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x008DA99D, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_177) {
  float inp = -5.917783E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x005A4C57, 0x00000000, 0x00000000, 0x801A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_178) {
  float inp = -4.605351E-08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x004645A7, 0x00000000, 0x00000000, 0x800E0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_179) {
  float inp = 3.67147E-07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00059A2B, 0x00000000, 0x00000000, 0x000C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_180) {
  float inp = 7.805752E-14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00771B38, 0x00000000, 0x00000000, 0x00140000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_181) {
  float inp = -4.665166E-28;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000005, 0x00000000, 0x00000000, 0x801C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_182) {
  float inp = 1.029686E+16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8A9A1800, 0x002494F0, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_183) {
  float inp = -1.623241E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xCB4533A0, 0x00000025, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_184) {
  float inp = 0.01401084;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001560FC, 0x00000000, 0x00000000, 0x00080000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_185) {
  float inp = 16.07887;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001888CF, 0x00000000, 0x00000000, 0x00050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_186) {
  float inp = -2.094895E+21;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x45F18000, 0x90821F45, 0x00000071, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_187) {
  float inp = -4.274481E-16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00413931, 0x00000000, 0x00000000, 0x80160000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_188) {
  float inp = 7.869093E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x994C0500, 0x0002CBB0, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_189) {
  float inp = -1.272028E-09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001368DC, 0x00000000, 0x00000000, 0x800F0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_190) {
  float inp = -5.217951E-12;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x004F9E9F, 0x00000000, 0x00000000, 0x80120000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_191) {
  float inp = -386648.3;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x003AFF73, 0x00000000, 0x00000000, 0x80010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_192) {
  float inp = 3.61813E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xD7A84850, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_193) {
  float inp = -109.3412;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0010AF24, 0x00000000, 0x00000000, 0x80040000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_194) {
  float inp = 4.581238E+18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x45856000, 0x3F93D3B0, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_195) {
  float inp = -6.603116E-17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0064C16C, 0x00000000, 0x00000000, 0x80170000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_196) {
  float inp = -1.320119E+10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x12DA2C70, 0x00000003, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_197) {
  float inp = 2.82232E-12;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00044E78, 0x00000000, 0x00000000, 0x00110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_198) {
  float inp = -1.841507E+09;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x6DC32AB8, 0x00000000, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_199) {
  float inp = -2.262675E-19;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00228693, 0x00000000, 0x00000000, 0x80190000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_200) {
  float inp = 2.464824E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00259C38, 0x00000000, 0x00000000, 0x001A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_201) {
  float inp = 1.511738E-07;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0017113A, 0x00000000, 0x00000000, 0x000D0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_202) {
  float inp = 1.720869E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001A4225, 0x00000000, 0x00000000, 0x000C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_203) {
  float inp = 8.188374E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000052, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_204) {
  float inp = -10.51995;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00100D5B, 0x00000000, 0x00000000, 0x80050000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_205) {
  float inp = 1.603923E+24;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x896C0000, 0xD70DD7BD, 0x000153A4, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_206) {
  float inp = 119471.1;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00123AD7, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_207) {
  float inp = 6.965003E+25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x44F80000, 0xB125DD81, 0x00399CF7, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_208) {
  float inp = 1.296483E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x233BB800, 0x01CC9A71, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_209) {
  float inp = -5.872053E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF054E880, 0x00003567, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_210) {
  float inp = -1.481293E+23;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x26820000, 0x1AFE5755, 0x00001F5E, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_211) {
  float inp = -2.851002E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002B80BA, 0x00000000, 0x00000000, 0x80180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_212) {
  float inp = 112195.3;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00111EA1, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_213) {
  float inp = 1.039634E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x06325B08, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_214) {
  float inp = 3.40683E+13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x24EB6B00, 0x00001EFC, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_215) {
  float inp = 6.772869E+11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xB171F120, 0x0000009D, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_216) {
  float inp = -1.268637E+15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x91BBE200, 0x000481D1, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_217) {
  float inp = -0.001798262;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001B7076, 0x00000000, 0x00000000, 0x80090000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_218) {
  float inp = -3.38201E-15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00052919, 0x00000000, 0x00000000, 0x80140000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_219) {
  float inp = -3.263142E-13;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0031CAA6, 0x00000000, 0x00000000, 0x80130000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_220) {
  float inp = 1.231812E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0000000C, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_221) {
  float inp = 3.812988E+22;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xCF7C0000, 0x06623F3C, 0x00000813, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_222) {
  float inp = 3.308621E+16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x92039400, 0x00758BBB, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_223) {
  float inp = -1.322553E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00142E39, 0x00000000, 0x00000000, 0x801A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_224) {
  float inp = 1.148738E+08;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x06D8D5C8, 0x00000000, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_225) {
  float inp = -1.991151E+10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xA2D187F0, 0x00000004, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_226) {
  float inp = 884496.5;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0086F6A5, 0x00000000, 0x00000000, 0x00010000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_227) {
  float inp = 4.103006E-27;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000029, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_228) {
  float inp = 4.647867E-26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000001D1, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_229) {
  float inp = 9.713084E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF55A6000, 0x0D7AC7D7, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_230) {
  float inp = -2.557154E+19;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x6BB14000, 0x62E05C25, 0x00000001, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_231) {
  float inp = -0.6512141;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00635E0D, 0x00000000, 0x00000000, 0x80070000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_232) {
  float inp = 3.490169E+16;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xF282C400, 0x007BFEE6, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_233) {
  float inp = 5.061718E-20;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x004D3C56, 0x00000000, 0x00000000, 0x001A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_234) {
  float inp = 6.59684E+22;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xEEE80000, 0x27750C6F, 0x00000DF8, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_235) {
  float inp = -1.918654E-19;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x001D46BE, 0x00000000, 0x00000000, 0x80190000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_236) {
  float inp = -1.215304E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00128B48, 0x00000000, 0x00000000, 0x80180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_237) {
  float inp = -3.20701E-15;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x0004E4BD, 0x00000000, 0x00000000, 0x80140000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_238) {
  float inp = -2.55141E+17;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x40A35000, 0x038A7163, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_239) {
  float inp = -1.751754E+22;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x684A0000, 0xA0B3FA18, 0x000003B5, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_240) {
  float inp = -1.188452E+26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xD2400000, 0x3393C802, 0x00624E73, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_241) {
  float inp = 3.866995E-25;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000F1B, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_242) {
  float inp = 44301.02;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00439916, 0x00000000, 0x00000000, 0x00020000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_243) {
  float inp = 2.47909E-26;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x000000F8, 0x00000000, 0x00000000, 0x001C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_244) {
  float inp = -3.094722E-11;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x002F38C2, 0x00000000, 0x00000000, 0x80110000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_245) {
  float inp = -0.0001411886;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00158B2E, 0x00000000, 0x00000000, 0x800A0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_246) {
  float inp = 4.721357E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00480ACD, 0x00000000, 0x00000000, 0x00180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_247) {
  float inp = -6.247398E+10;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x8BBD4860, 0x0000000E, 0x00000000, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_248) {
  float inp = -1.663049E-18;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00196049, 0x00000000, 0x00000000, 0x80180000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_249) {
  float inp = 4.894282E+14;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0xE2010A00, 0x0001BD21, 0x00000000, 0x00000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_250) {
  float inp = 7.748195E-06;
  s21_decimal out = {{0x00009D40, 0x0000EB82, 0x00008442, 0x00001472}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00763A63, 0x00000000, 0x00000000, 0x000C0000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[45m-=S21_FROM_FLOAT_TO_DECIMAL=-\033[0m");
  TCase *tc = tcase_create("s21_from_float_to_decimal_tc");

  tcase_add_test(tc, s21_float_000);
  tcase_add_test(tc, s21_float_00);
  tcase_add_test(tc, s21_float_0);
  tcase_add_test(tc, s21_float_1);
  tcase_add_test(tc, s21_float_2);
  tcase_add_test(tc, s21_float_3);
  tcase_add_test(tc, s21_float_4);
  tcase_add_test(tc, s21_float_5);
  tcase_add_test(tc, s21_float_6);
  tcase_add_test(tc, s21_float_7);
  tcase_add_test(tc, s21_float_8);
  tcase_add_test(tc, s21_float_9);
  tcase_add_test(tc, s21_float_10);
  tcase_add_test(tc, s21_float_10_5);
  tcase_add_test(tc, s21_float_11);
  tcase_add_test(tc, s21_float_12);
  tcase_add_test(tc, s21_float_13);
  tcase_add_test(tc, s21_float_14);
  tcase_add_test(tc, s21_float_15);
  tcase_add_test(tc, s21_float_16);
  tcase_add_test(tc, s21_float_17);
  tcase_add_test(tc, s21_float_18);
  tcase_add_test(tc, s21_float_19);
  tcase_add_test(tc, s21_float_20);
  tcase_add_test(tc, s21_float_21);
  tcase_add_test(tc, s21_float_22);
  tcase_add_test(tc, s21_float_23);
  tcase_add_test(tc, s21_float_24);
  tcase_add_test(tc, s21_float_25);
  tcase_add_test(tc, s21_float_26);
  tcase_add_test(tc, s21_float_27);
  tcase_add_test(tc, s21_float_29);
  tcase_add_test(tc, s21_float_30);
  tcase_add_test(tc, s21_float_31);
  tcase_add_test(tc, s21_float_32);
  tcase_add_test(tc, s21_float_33);
  tcase_add_test(tc, s21_float_34);
  tcase_add_test(tc, s21_float_35);
  tcase_add_test(tc, s21_float_36);
  tcase_add_test(tc, s21_float_37);
  tcase_add_test(tc, s21_float_38);
  tcase_add_test(tc, s21_float_39);
  tcase_add_test(tc, s21_float_40);
  tcase_add_test(tc, s21_float_41);
  tcase_add_test(tc, s21_float_42);
  tcase_add_test(tc, s21_float_43);
  tcase_add_test(tc, s21_float_44);
  tcase_add_test(tc, s21_float_45);
  tcase_add_test(tc, s21_float_46);
  tcase_add_test(tc, s21_float_47);
  tcase_add_test(tc, s21_float_48);
  tcase_add_test(tc, s21_float_49);
  tcase_add_test(tc, s21_float_50);
  tcase_add_test(tc, s21_float_51);
  tcase_add_test(tc, s21_float_52);
  tcase_add_test(tc, s21_float_53);
  tcase_add_test(tc, s21_float_54);
  tcase_add_test(tc, s21_float_55);
  tcase_add_test(tc, s21_float_56);
  tcase_add_test(tc, s21_float_57);
  tcase_add_test(tc, s21_float_58);
  tcase_add_test(tc, s21_float_59);
  tcase_add_test(tc, s21_float_60);
  tcase_add_test(tc, s21_float_61);
  tcase_add_test(tc, s21_float_62);
  tcase_add_test(tc, s21_float_63);
  tcase_add_test(tc, s21_float_64);
  tcase_add_test(tc, s21_float_65);
  tcase_add_test(tc, s21_float_66);
  tcase_add_test(tc, s21_float_67);
  tcase_add_test(tc, s21_float_68);
  tcase_add_test(tc, s21_float_69);
  tcase_add_test(tc, s21_float_70);
  tcase_add_test(tc, s21_float_71);
  tcase_add_test(tc, s21_float_72);
  tcase_add_test(tc, s21_float_73);
  tcase_add_test(tc, s21_float_74);
  tcase_add_test(tc, s21_float_75);
  tcase_add_test(tc, s21_float_76);
  tcase_add_test(tc, s21_float_77);
  tcase_add_test(tc, s21_float_78);
  tcase_add_test(tc, s21_float_79);
  tcase_add_test(tc, s21_float_80);
  tcase_add_test(tc, s21_float_81);
  tcase_add_test(tc, s21_float_82);
  tcase_add_test(tc, s21_float_83);
  tcase_add_test(tc, s21_float_84);
  tcase_add_test(tc, s21_float_85);
  tcase_add_test(tc, s21_float_86);
  tcase_add_test(tc, s21_float_87);
  tcase_add_test(tc, s21_float_88);
  tcase_add_test(tc, s21_float_89);
  tcase_add_test(tc, s21_float_90);
  tcase_add_test(tc, s21_float_91);
  tcase_add_test(tc, s21_float_92);
  tcase_add_test(tc, s21_float_93);
  tcase_add_test(tc, s21_float_94);
  tcase_add_test(tc, s21_float_95);
  tcase_add_test(tc, s21_float_96);
  tcase_add_test(tc, s21_float_97);
  tcase_add_test(tc, s21_float_98);
  tcase_add_test(tc, s21_float_99);
  tcase_add_test(tc, s21_float_100);
  tcase_add_test(tc, s21_float_101);
  tcase_add_test(tc, s21_float_102);
  tcase_add_test(tc, s21_float_103);
  tcase_add_test(tc, s21_float_104);
  tcase_add_test(tc, s21_float_105);
  tcase_add_test(tc, s21_float_106);
  tcase_add_test(tc, s21_float_107);
  tcase_add_test(tc, s21_float_108);
  tcase_add_test(tc, s21_float_109);
  tcase_add_test(tc, s21_float_110);
  tcase_add_test(tc, s21_float_111);
  tcase_add_test(tc, s21_float_112);
  tcase_add_test(tc, s21_float_113);
  tcase_add_test(tc, s21_float_114);
  tcase_add_test(tc, s21_float_115);
  tcase_add_test(tc, s21_float_116);
  tcase_add_test(tc, s21_float_117);
  tcase_add_test(tc, s21_float_118);
  tcase_add_test(tc, s21_float_119);
  tcase_add_test(tc, s21_float_120);
  tcase_add_test(tc, s21_float_121);
  tcase_add_test(tc, s21_float_122);
  tcase_add_test(tc, s21_float_123);
  tcase_add_test(tc, s21_float_124);
  tcase_add_test(tc, s21_float_125);
  tcase_add_test(tc, s21_float_126);
  tcase_add_test(tc, s21_float_127);
  tcase_add_test(tc, s21_float_128);
  tcase_add_test(tc, s21_float_129);
  tcase_add_test(tc, s21_float_130);
  tcase_add_test(tc, s21_float_131);
  tcase_add_test(tc, s21_float_132);
  tcase_add_test(tc, s21_float_133);
  tcase_add_test(tc, s21_float_134);
  tcase_add_test(tc, s21_float_135);
  tcase_add_test(tc, s21_float_136);
  tcase_add_test(tc, s21_float_137);
  tcase_add_test(tc, s21_float_138);
  tcase_add_test(tc, s21_float_139);
  tcase_add_test(tc, s21_float_140);
  tcase_add_test(tc, s21_float_141);
  tcase_add_test(tc, s21_float_142);
  tcase_add_test(tc, s21_float_143);
  tcase_add_test(tc, s21_float_144);
  tcase_add_test(tc, s21_float_145);
  tcase_add_test(tc, s21_float_146);
  tcase_add_test(tc, s21_float_147);
  tcase_add_test(tc, s21_float_148);
  tcase_add_test(tc, s21_float_149);
  tcase_add_test(tc, s21_float_150);
  tcase_add_test(tc, s21_float_151);
  tcase_add_test(tc, s21_float_152);
  tcase_add_test(tc, s21_float_153);
  tcase_add_test(tc, s21_float_154);
  tcase_add_test(tc, s21_float_155);
  tcase_add_test(tc, s21_float_156);
  tcase_add_test(tc, s21_float_157);
  tcase_add_test(tc, s21_float_158);
  tcase_add_test(tc, s21_float_159);
  tcase_add_test(tc, s21_float_160);
  tcase_add_test(tc, s21_float_161);
  tcase_add_test(tc, s21_float_162);
  tcase_add_test(tc, s21_float_163);
  tcase_add_test(tc, s21_float_164);
  tcase_add_test(tc, s21_float_165);
  tcase_add_test(tc, s21_float_166);
  tcase_add_test(tc, s21_float_167);
  tcase_add_test(tc, s21_float_168);
  tcase_add_test(tc, s21_float_169);
  tcase_add_test(tc, s21_float_170);
  tcase_add_test(tc, s21_float_171);
  tcase_add_test(tc, s21_float_172);
  tcase_add_test(tc, s21_float_173);
  tcase_add_test(tc, s21_float_174);
  tcase_add_test(tc, s21_float_175);
  tcase_add_test(tc, s21_float_176);
  tcase_add_test(tc, s21_float_177);
  tcase_add_test(tc, s21_float_178);
  tcase_add_test(tc, s21_float_179);
  tcase_add_test(tc, s21_float_180);
  tcase_add_test(tc, s21_float_181);
  tcase_add_test(tc, s21_float_182);
  tcase_add_test(tc, s21_float_183);
  tcase_add_test(tc, s21_float_184);
  tcase_add_test(tc, s21_float_185);
  tcase_add_test(tc, s21_float_186);
  tcase_add_test(tc, s21_float_187);
  tcase_add_test(tc, s21_float_188);
  tcase_add_test(tc, s21_float_189);
  tcase_add_test(tc, s21_float_190);
  tcase_add_test(tc, s21_float_191);
  tcase_add_test(tc, s21_float_192);
  tcase_add_test(tc, s21_float_193);
  tcase_add_test(tc, s21_float_194);
  tcase_add_test(tc, s21_float_195);
  tcase_add_test(tc, s21_float_196);
  tcase_add_test(tc, s21_float_197);
  tcase_add_test(tc, s21_float_198);
  tcase_add_test(tc, s21_float_199);
  tcase_add_test(tc, s21_float_200);
  tcase_add_test(tc, s21_float_201);
  tcase_add_test(tc, s21_float_202);
  tcase_add_test(tc, s21_float_203);
  tcase_add_test(tc, s21_float_204);
  tcase_add_test(tc, s21_float_205);
  tcase_add_test(tc, s21_float_206);
  tcase_add_test(tc, s21_float_207);
  tcase_add_test(tc, s21_float_208);
  tcase_add_test(tc, s21_float_209);
  tcase_add_test(tc, s21_float_210);
  tcase_add_test(tc, s21_float_211);
  tcase_add_test(tc, s21_float_212);
  tcase_add_test(tc, s21_float_213);
  tcase_add_test(tc, s21_float_214);
  tcase_add_test(tc, s21_float_215);
  tcase_add_test(tc, s21_float_216);
  tcase_add_test(tc, s21_float_217);
  tcase_add_test(tc, s21_float_218);
  tcase_add_test(tc, s21_float_219);
  tcase_add_test(tc, s21_float_220);
  tcase_add_test(tc, s21_float_221);
  tcase_add_test(tc, s21_float_222);
  tcase_add_test(tc, s21_float_223);
  tcase_add_test(tc, s21_float_224);
  tcase_add_test(tc, s21_float_225);
  tcase_add_test(tc, s21_float_226);
  tcase_add_test(tc, s21_float_227);
  tcase_add_test(tc, s21_float_228);
  tcase_add_test(tc, s21_float_229);
  tcase_add_test(tc, s21_float_230);
  tcase_add_test(tc, s21_float_231);
  tcase_add_test(tc, s21_float_232);
  tcase_add_test(tc, s21_float_233);
  tcase_add_test(tc, s21_float_234);
  tcase_add_test(tc, s21_float_235);
  tcase_add_test(tc, s21_float_236);
  tcase_add_test(tc, s21_float_237);
  tcase_add_test(tc, s21_float_238);
  tcase_add_test(tc, s21_float_239);
  tcase_add_test(tc, s21_float_240);
  tcase_add_test(tc, s21_float_241);
  tcase_add_test(tc, s21_float_242);
  tcase_add_test(tc, s21_float_243);
  tcase_add_test(tc, s21_float_244);
  tcase_add_test(tc, s21_float_245);
  tcase_add_test(tc, s21_float_246);
  tcase_add_test(tc, s21_float_247);
  tcase_add_test(tc, s21_float_248);
  tcase_add_test(tc, s21_float_249);
  tcase_add_test(tc, s21_float_250);

  suite_add_tcase(s, tc);
  return s;
}
