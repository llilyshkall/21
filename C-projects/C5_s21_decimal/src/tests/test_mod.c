#include "test_me.h"

START_TEST(s21_mod_00) {
  int true_res = 0;
  s21_decimal val1 = {{0x9E929C64, 0x205127BD, 0xB8BE77ED, 0x80120000}};
  s21_decimal val2 = {{0x828A0CC8, 0x21C72D9D, 0x8D8E8A48, 0x801C0000}};
  int s21_res = s21_mod(val1, val2, NULL);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_0) {
  int true_res = 0;
  s21_decimal val1 = {{0x9E929C64, 0x205127BD, 0xB8BE77ED, 0x00120000}};
  s21_decimal val2 = {{0x828A0CC8, 0x21C72D9D, 0x8D8E8A48, 0x801C0000}};
  int s21_res = s21_mod(val1, val2, NULL);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_1) {
  int true_res = 0;
  s21_decimal val1 = {{0x5BA74305, 0x694A24FC, 0x4D730632, 0x800E0000}};
  s21_decimal val2 = {{0x8FFB8C54, 0x90A8C718, 0xACA96403, 0x800C0000}};
  s21_decimal result = {{0x5BA74305, 0x694A24FC, 0x4D730632, 0x800E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_2) {
  int true_res = 0;
  s21_decimal val1 = {{0x02906F6F, 0x32153896, 0x90502ECF, 0x80020000}};
  s21_decimal val2 = {{0x9141279D, 0xEB3A9CC0, 0x406AE5A2, 0x80160000}};
  s21_decimal result = {{0x62E94FE9, 0x5ED2CE64, 0x0951BAF7, 0x80160000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_3) {
  int true_res = 0;
  s21_decimal val1 = {{0x648A40C1, 0xBF67F821, 0x5E5511D6, 0x80170000}};
  s21_decimal val2 = {{0xF3184261, 0x8F74CED2, 0x86DEAAD1, 0x80040000}};
  s21_decimal result = {{0x648A40C1, 0xBF67F821, 0x5E5511D6, 0x80170000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_4) {
  int true_res = 0;
  s21_decimal val1 = {{0xA39B42E0, 0x954237AE, 0xB621A26B, 0x00000000}};
  s21_decimal val2 = {{0xF86C1C5B, 0xF2F4F910, 0xEB7788DE, 0x00020000}};
  s21_decimal result = {{0x30219821, 0x3A2ED61D, 0x522F46F7, 0x00020000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_5) {
  int true_res = 0;
  s21_decimal val1 = {{0x2A254D7B, 0x964EE7DE, 0x11EC8B80, 0x800F0000}};
  s21_decimal val2 = {{0x05096D12, 0x265F14F3, 0x7CFF9925, 0x000C0000}};
  s21_decimal result = {{0x2A254D7B, 0x964EE7DE, 0x11EC8B80, 0x800F0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_6) {
  int true_res = 0;
  s21_decimal val1 = {{0x0C1CF13F, 0x011784DF, 0x67F1E778, 0x000A0000}};
  s21_decimal val2 = {{0x3599EAD1, 0x0D690CFB, 0xEF7577AF, 0x00060000}};
  s21_decimal result = {{0x0C1CF13F, 0x011784DF, 0x67F1E778, 0x000A0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_7) {
  int true_res = 0;
  s21_decimal val1 = {{0xA04F9345, 0xCDE5F414, 0xDA1637F3, 0x001B0000}};
  s21_decimal val2 = {{0xC73E7ADA, 0x56A94B5F, 0x3AC32928, 0x80010000}};
  s21_decimal result = {{0xA04F9345, 0xCDE5F414, 0xDA1637F3, 0x001B0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_8) {
  int true_res = 0;
  s21_decimal val1 = {{0x2CA98589, 0x22D502FB, 0xB777A9F1, 0x00190000}};
  s21_decimal val2 = {{0x68DF4CE0, 0x2BD2B130, 0x19418D9F, 0x80030000}};
  s21_decimal result = {{0x2CA98589, 0x22D502FB, 0xB777A9F1, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_9) {
  int true_res = 0;
  s21_decimal val1 = {{0x5E6224E2, 0xB7513306, 0x08212CBB, 0x00060000}};
  s21_decimal val2 = {{0xB7894A0E, 0x4F5B344C, 0x2D27C78D, 0x000A0000}};
  s21_decimal result = {{0xADFCA1CB, 0x0A50247D, 0x00006A18, 0x00060000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_10) {
  int true_res = 0;
  s21_decimal val1 = {{0x7E01DB2C, 0xB2210C73, 0xDC86860D, 0x80170000}};
  s21_decimal val2 = {{0xE1D7DBEF, 0x744C252A, 0x7524D386, 0x00100000}};
  s21_decimal result = {{0x7E01DB2C, 0xB2210C73, 0xDC86860D, 0x80170000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_11) {
  int true_res = 0;
  s21_decimal val1 = {{0x346BB1FE, 0x053F933B, 0xE6B0E3DC, 0x000C0000}};
  s21_decimal val2 = {{0x6B53216B, 0x73829129, 0x326AF1CB, 0x80030000}};
  s21_decimal result = {{0x346BB1FE, 0x053F933B, 0xE6B0E3DC, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_12) {
  int true_res = 0;
  s21_decimal val1 = {{0xBA420BBC, 0x43B5933F, 0xE1A71D31, 0x800E0000}};
  s21_decimal val2 = {{0x58C497C5, 0x8E7A5B91, 0x0169631C, 0x80060000}};
  s21_decimal result = {{0xBA420BBC, 0x43B5933F, 0xE1A71D31, 0x800E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_13) {
  int true_res = 0;
  s21_decimal val1 = {{0x0077C1F4, 0xBE69FC7A, 0xC7F2A08C, 0x001C0000}};
  s21_decimal val2 = {{0xC0C042A1, 0xB20964FF, 0x458F590A, 0x00110000}};
  s21_decimal result = {{0x0077C1F4, 0xBE69FC7A, 0xC7F2A08C, 0x001C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_14) {
  int true_res = 0;
  s21_decimal val1 = {{0x9E654686, 0x8CED46FD, 0x037561ED, 0x801C0000}};
  s21_decimal val2 = {{0x17D4095A, 0xF6288FFE, 0xD366AED6, 0x00090000}};
  s21_decimal result = {{0x9E654686, 0x8CED46FD, 0x037561ED, 0x801C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_15) {
  int true_res = 0;
  s21_decimal val1 = {{0xB1AEFD71, 0x32D90B63, 0x6995DAC0, 0x00110000}};
  s21_decimal val2 = {{0x0353ED31, 0x7D7D398C, 0x614A9B94, 0x00170000}};
  s21_decimal result = {{0xD92BD300, 0x6AD627E0, 0x204888D4, 0x00170000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_16) {
  int true_res = 0;
  s21_decimal val1 = {{0x9CA94A77, 0x422A2CAE, 0x82A93620, 0x80070000}};
  s21_decimal val2 = {{0xBA15AF12, 0xD45856DC, 0x838F21B9, 0x80090000}};
  s21_decimal result = {{0x3BBE6286, 0xBA4FDCD9, 0x29BF19BC, 0x80090000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_17) {
  int true_res = 0;
  s21_decimal val1 = {{0x75A27509, 0x6327F229, 0x2CE790E3, 0x80050000}};
  s21_decimal val2 = {{0x14E49385, 0xCD960911, 0xB7F464EB, 0x000A0000}};
  s21_decimal result = {{0xE2791063, 0xFCC6FFA2, 0x0C3565E5, 0x80090000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_18) {
  int true_res = 0;
  s21_decimal val1 = {{0x302E76E8, 0xD13FD38B, 0xE78A2EEC, 0x80140000}};
  s21_decimal val2 = {{0xC63B4953, 0x7C705FA1, 0xC8A7BBEB, 0x80170000}};
  s21_decimal result = {{0x647B3B6D, 0xEB33A016, 0xB851ED75, 0x80170000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_19) {
  int true_res = 0;
  s21_decimal val1 = {{0x0EDAA08B, 0x60D798F7, 0xA1287C37, 0x80150000}};
  s21_decimal val2 = {{0x74602CE9, 0x03E5C385, 0x678099AC, 0x80180000}};
  s21_decimal result = {{0x3911F9DB, 0x95BF5A65, 0x04FE951E, 0x80180000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_20) {
  int true_res = 0;
  s21_decimal val1 = {{0xED85353B, 0x07D4D117, 0x61BDFE82, 0x00010000}};
  s21_decimal val2 = {{0x8D395287, 0x6C2FD36F, 0x59280D0B, 0x80120000}};
  s21_decimal result = {{0x9ADE4CD2, 0x8D0334C6, 0x07CF2C31, 0x00110000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_21) {
  int true_res = 0;
  s21_decimal val1 = {{0x9F67B4AF, 0xDD05FEE6, 0x1A7D8D0B, 0x80070000}};
  s21_decimal val2 = {{0x210829E5, 0xAA642B10, 0x68DA7F96, 0x00080000}};
  s21_decimal result = {{0xF7FCBB0C, 0x4D739EE1, 0x37328349, 0x80080000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_22) {
  int true_res = 0;
  s21_decimal val1 = {{0x54C12957, 0xDEBE5A74, 0x73E25F74, 0x00050000}};
  s21_decimal val2 = {{0x46EF9A6A, 0x7DC48859, 0xA125F171, 0x800B0000}};
  s21_decimal result = {{0x007B6CC8, 0xAE6792B6, 0x08FF6D78, 0x000B0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_23) {
  int true_res = 0;
  s21_decimal val1 = {{0x0807811F, 0xA6DE9477, 0xA402549B, 0x800C0000}};
  s21_decimal val2 = {{0x8E799D20, 0x45626353, 0x7F919EE5, 0x00020000}};
  s21_decimal result = {{0x0807811F, 0xA6DE9477, 0xA402549B, 0x800C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_24) {
  int true_res = 0;
  s21_decimal val1 = {{0xA177D670, 0x60537FA5, 0xB5403FD0, 0x000F0000}};
  s21_decimal val2 = {{0x8EA7D14D, 0x8A9377FB, 0x270AB29A, 0x00010000}};
  s21_decimal result = {{0xA177D670, 0x60537FA5, 0xB5403FD0, 0x000F0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_25) {
  int true_res = 0;
  s21_decimal val1 = {{0xAC462501, 0xAEBDB4DB, 0xEBEE908C, 0x000E0000}};
  s21_decimal val2 = {{0x396CDA8C, 0x695962E8, 0xE12E47BD, 0x00130000}};
  s21_decimal result = {{0xEB493858, 0x9AA1A27F, 0x620B6F07, 0x00130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_26) {
  int true_res = 0;
  s21_decimal val1 = {{0xE7EDB4B1, 0x39210E50, 0xA6B441F9, 0x000C0000}};
  s21_decimal val2 = {{0x756D5D07, 0xEB98DA6F, 0xB6FB342F, 0x80040000}};
  s21_decimal result = {{0xE7EDB4B1, 0x39210E50, 0xA6B441F9, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_27) {
  int true_res = 0;
  s21_decimal val1 = {{0x63495E78, 0xBB48E3C0, 0x59FECD43, 0x00030000}};
  s21_decimal val2 = {{0x65CC3C67, 0xD20B5BED, 0xF79114DF, 0x80030000}};
  s21_decimal result = {{0x63495E78, 0xBB48E3C0, 0x59FECD43, 0x00030000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_28) {
  int true_res = 0;
  s21_decimal val1 = {{0x72CDF0A0, 0xCA9A7150, 0x3EA12BB1, 0x000B0000}};
  s21_decimal val2 = {{0x9EE14596, 0x78B4C203, 0xDF3E3AD8, 0x000D0000}};
  s21_decimal result = {{0x77CE6218, 0xF08F0B07, 0x0C26A1C5, 0x000D0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_29) {
  int true_res = 0;
  s21_decimal val1 = {{0x745D187F, 0x2B9CE1ED, 0x5BC0301D, 0x80090000}};
  s21_decimal val2 = {{0x64DABDE0, 0x245CD76C, 0x90653E58, 0x001C0000}};
  s21_decimal result = {{0x6A2720C0, 0x31A333FA, 0x661F6CA6, 0x801C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_30) {
  int true_res = 0;
  s21_decimal val1 = {{0xF65EC8FA, 0x39133BAA, 0xA72064B1, 0x80150000}};
  s21_decimal val2 = {{0xB815D4C0, 0x16ADC0E4, 0x2930D149, 0x80190000}};
  s21_decimal result = {{0xCE0697B8, 0xD264DD3F, 0x005A8519, 0x80170000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_31) {
  int true_res = 0;
  s21_decimal val1 = {{0x00E9B97A, 0xAADAC723, 0x4AC7E131, 0x00010000}};
  s21_decimal val2 = {{0x382C14A8, 0x4ED799E4, 0xC32CD556, 0x80030000}};
  s21_decimal result = {{0x9A1356AC, 0x1A8BB1C7, 0x06246E0F, 0x00020000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_32) {
  int true_res = 0;
  s21_decimal val1 = {{0x2814B70E, 0x97883CB8, 0xBC3C3941, 0x80110000}};
  s21_decimal val2 = {{0x6A8BC85D, 0xFDB677F0, 0xA9167051, 0x00020000}};
  s21_decimal result = {{0x2814B70E, 0x97883CB8, 0xBC3C3941, 0x80110000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_33) {
  int true_res = 0;
  s21_decimal val1 = {{0x4B1DC6D8, 0x38A98606, 0x610EAC0E, 0x80030000}};
  s21_decimal val2 = {{0x481B8FAE, 0x626EBFD6, 0x2F215604, 0x00130000}};
  s21_decimal result = {{0x990798B0, 0xFD0FAE74, 0x0D9F1423, 0x80130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_34) {
  int true_res = 0;
  s21_decimal val1 = {{0xE8030CA2, 0x3A496AAF, 0xF90E5A8A, 0x80150000}};
  s21_decimal val2 = {{0xF9C7B78B, 0x4A634CB7, 0xA425FD3E, 0x00150000}};
  s21_decimal result = {{0xEE3B5517, 0xEFE61DF7, 0x54E85D4B, 0x80150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_35) {
  int true_res = 0;
  s21_decimal val1 = {{0x67BAFFD1, 0xA10317B1, 0xF10F60C5, 0x80020000}};
  s21_decimal val2 = {{0xD56B6F64, 0x33288E29, 0x6F2DB4A7, 0x00060000}};
  s21_decimal result = {{0x53689088, 0xA7F4EEC6, 0x1BA5AED6, 0x80060000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_36) {
  int true_res = 0;
  s21_decimal val1 = {{0xE74A53D9, 0xF249CA75, 0x578CBE99, 0x00190000}};
  s21_decimal val2 = {{0xEF9F81B5, 0x9C442F69, 0xC03992A9, 0x80180000}};
  s21_decimal result = {{0xE74A53D9, 0xF249CA75, 0x578CBE99, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_37) {
  int true_res = 0;
  s21_decimal val1 = {{0x6C162D27, 0xCAD314F3, 0x4AF24131, 0x00100000}};
  s21_decimal val2 = {{0x41CCC829, 0xCA1939C9, 0x68F5DA4D, 0x80100000}};
  s21_decimal result = {{0x6C162D27, 0xCAD314F3, 0x4AF24131, 0x00100000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_38) {
  int true_res = 0;
  s21_decimal val1 = {{0xBD33CBF9, 0xB3A05D1F, 0x4F47EBC3, 0x00190000}};
  s21_decimal val2 = {{0xAF5DA735, 0x2FAD43B0, 0x77203604, 0x80080000}};
  s21_decimal result = {{0xBD33CBF9, 0xB3A05D1F, 0x4F47EBC3, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_39) {
  int true_res = 0;
  s21_decimal val1 = {{0xC2A99260, 0xCA1C8FD9, 0x3330761F, 0x80090000}};
  s21_decimal val2 = {{0xE20BFCCD, 0xD393B9A8, 0xA3396D23, 0x00040000}};
  s21_decimal result = {{0xC2A99260, 0xCA1C8FD9, 0x3330761F, 0x80090000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_40) {
  int true_res = 0;
  s21_decimal val1 = {{0x193CB0B4, 0x0F644187, 0x45B5AA9E, 0x00090000}};
  s21_decimal val2 = {{0x7D4FA7B1, 0x05303B86, 0x8998D347, 0x00140000}};
  s21_decimal result = {{0xFE70C8B3, 0x9E61B13E, 0x063BD431, 0x00130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_41) {
  int true_res = 0;
  s21_decimal val1 = {{0xCF934DFC, 0xE35EDF3D, 0xC3F14160, 0x800A0000}};
  s21_decimal val2 = {{0xA828AEF3, 0x52C07675, 0x10FF139F, 0x80170000}};
  s21_decimal result = {{0xD5705B4B, 0xFFFD8A9C, 0x0105CC4A, 0x80160000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_42) {
  int true_res = 0;
  s21_decimal val1 = {{0xABFA353C, 0xEE766F07, 0x65ECD74C, 0x00070000}};
  s21_decimal val2 = {{0x755CC702, 0x25C5387E, 0x2D84B44F, 0x000F0000}};
  s21_decimal result = {{0x45AAD24B, 0x9C49FC2E, 0x00BCDA16, 0x000E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_43) {
  int true_res = 0;
  s21_decimal val1 = {{0xC02CB211, 0x7B27DD9B, 0x51CE7B36, 0x00130000}};
  s21_decimal val2 = {{0xC7EC4C96, 0x4C440678, 0x08CF6CD5, 0x80110000}};
  s21_decimal result = {{0xC02CB211, 0x7B27DD9B, 0x51CE7B36, 0x00130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_44) {
  int true_res = 0;
  s21_decimal val1 = {{0x993BD04E, 0xACF452A5, 0xB723FE6B, 0x000A0000}};
  s21_decimal val2 = {{0x67A41519, 0xC6FA5E97, 0x174577A6, 0x000C0000}};
  s21_decimal result = {{0xA59497B6, 0xA2B9DBD3, 0x16C60400, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_45) {
  int true_res = 0;
  s21_decimal val1 = {{0xD130B6A3, 0x61701670, 0x98E62392, 0x800A0000}};
  s21_decimal val2 = {{0x207B2419, 0x2EB3E67D, 0x1C8D8920, 0x80030000}};
  s21_decimal result = {{0xD130B6A3, 0x61701670, 0x98E62392, 0x800A0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_46) {
  int true_res = 0;
  s21_decimal val1 = {{0xFC14E3B8, 0xC989E9C2, 0x2DC153C2, 0x800B0000}};
  s21_decimal val2 = {{0x9089324C, 0x4D9185E7, 0x52B7FFE3, 0x00100000}};
  s21_decimal result = {{0xF97A96FA, 0xADA18B22, 0x0022CB0D, 0x800E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_47) {
  int true_res = 0;
  s21_decimal val1 = {{0x27EB3D8F, 0xEEE8D3BD, 0x24350EBF, 0x00160000}};
  s21_decimal val2 = {{0x729E1D38, 0xAB021BF8, 0x482A579D, 0x00160000}};
  s21_decimal result = {{0x27EB3D8F, 0xEEE8D3BD, 0x24350EBF, 0x00160000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_48) {
  int true_res = 0;
  s21_decimal val1 = {{0x1DFAEDE7, 0x75432DAF, 0xAC441286, 0x800A0000}};
  s21_decimal val2 = {{0x8101562B, 0x895DD6FF, 0x4467CAD8, 0x80120000}};
  s21_decimal result = {{0x75A75E41, 0x1A480051, 0x225033A9, 0x80120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_49) {
  int true_res = 0;
  s21_decimal val1 = {{0x4D57E590, 0xC91C3458, 0xD75D5EEB, 0x80050000}};
  s21_decimal val2 = {{0xFC280F08, 0x2FE6A851, 0x3DEC0D8F, 0x80150000}};
  s21_decimal result = {{0x8BD7B8E0, 0x6EDFE65D, 0x0E8F123A, 0x80150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_50) {
  int true_res = 0;
  s21_decimal val1 = {{0xBA31E9F3, 0xC78E5D26, 0xB7053004, 0x00000000}};
  s21_decimal val2 = {{0xDF1F4924, 0x617F2F8E, 0xC33F6BF6, 0x00120000}};
  s21_decimal result = {{0xDBD4A268, 0x1F5ABDDB, 0x0F8CD638, 0x00120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_51) {
  int true_res = 0;
  s21_decimal val1 = {{0xFB1CA504, 0x6787AA61, 0xBC6B31C6, 0x00150000}};
  s21_decimal val2 = {{0x2BC029B1, 0x5E99D6A3, 0x9A8EB9F8, 0x80160000}};
  s21_decimal result = {{0xC21C7DDC, 0x9C16982D, 0x1D7F3A1B, 0x00160000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_52) {
  int true_res = 0;
  s21_decimal val1 = {{0x06FD861F, 0xEA4E1A67, 0x8B4A2957, 0x80160000}};
  s21_decimal val2 = {{0x36BB586A, 0xBE9D420E, 0x0A4A8CF6, 0x80070000}};
  s21_decimal result = {{0x06FD861F, 0xEA4E1A67, 0x8B4A2957, 0x80160000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_53) {
  int true_res = 0;
  s21_decimal val1 = {{0x0F6CB57D, 0x07F832DA, 0x78E6569B, 0x801B0000}};
  s21_decimal val2 = {{0xD2331FEF, 0x5FB5196D, 0x1B90CC97, 0x800A0000}};
  s21_decimal result = {{0x0F6CB57D, 0x07F832DA, 0x78E6569B, 0x801B0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_54) {
  int true_res = 0;
  s21_decimal val1 = {{0x2C4FC716, 0x0515E626, 0x418D642F, 0x00150000}};
  s21_decimal val2 = {{0x79A1BF32, 0x44D96901, 0x0DDA6801, 0x00130000}};
  s21_decimal result = {{0x2C4FC716, 0x0515E626, 0x418D642F, 0x00150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_55) {
  int true_res = 0;
  s21_decimal val1 = {{0xC9935820, 0xEA8FF2D5, 0xA4A4AA0E, 0x00100000}};
  s21_decimal val2 = {{0x1FC5706B, 0xC6010772, 0x54657A52, 0x00050000}};
  s21_decimal result = {{0xC9935820, 0xEA8FF2D5, 0xA4A4AA0E, 0x00100000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_56) {
  int true_res = 0;
  s21_decimal val1 = {{0xA8BF37C5, 0xC4675132, 0x9A5940A5, 0x00150000}};
  s21_decimal val2 = {{0x4BA5A434, 0x0D7AF8C9, 0x40B5F1EB, 0x800D0000}};
  s21_decimal result = {{0xA8BF37C5, 0xC4675132, 0x9A5940A5, 0x00150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_57) {
  int true_res = 0;
  s21_decimal val1 = {{0x8D768759, 0x37A64AF7, 0xD14DA29D, 0x80190000}};
  s21_decimal val2 = {{0x993EDBCC, 0x351DF0B8, 0x44A585E2, 0x800F0000}};
  s21_decimal result = {{0x8D768759, 0x37A64AF7, 0xD14DA29D, 0x80190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_58) {
  int true_res = 0;
  s21_decimal val1 = {{0xDCBDF24E, 0x9805A0ED, 0x14E21A0A, 0x001A0000}};
  s21_decimal val2 = {{0x2F8E19EE, 0x5EC8042D, 0x35BECEC6, 0x001A0000}};
  s21_decimal result = {{0x2FAC983B, 0x4266F67E, 0x02169C34, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_59) {
  int true_res = 0;
  s21_decimal val1 = {{0x1CB402A2, 0xD876763A, 0x144DA851, 0x00050000}};
  s21_decimal val2 = {{0x0E3D13A8, 0xB01FD6C9, 0x6236E2EF, 0x80120000}};
  s21_decimal result = {{0x10C48B90, 0x72F0B909, 0x09FB4BB0, 0x00120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_60) {
  int true_res = 0;
  s21_decimal val1 = {{0xDE598AA5, 0xF7CDFC41, 0x65CC20C5, 0x00110000}};
  s21_decimal val2 = {{0xE16C5449, 0x5DB56C77, 0xB9B174BD, 0x00190000}};
  s21_decimal result = {{0xC5A276A1, 0x3DA61CC2, 0x0D4EB973, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_61) {
  int true_res = 0;
  s21_decimal val1 = {{0x62EF81AE, 0x38458708, 0x7617F994, 0x00120000}};
  s21_decimal val2 = {{0x206B85B0, 0x73827E85, 0x9E681B0A, 0x80020000}};
  s21_decimal result = {{0x62EF81AE, 0x38458708, 0x7617F994, 0x00120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_62) {
  int true_res = 0;
  s21_decimal val1 = {{0x55A92866, 0x1554FDD3, 0x5B5313C1, 0x00140000}};
  s21_decimal val2 = {{0xE90FB817, 0x9F950F81, 0xECA382DF, 0x80120000}};
  s21_decimal result = {{0x55A92866, 0x1554FDD3, 0x5B5313C1, 0x00140000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_63) {
  int true_res = 0;
  s21_decimal val1 = {{0x47FA20EB, 0xA3C20403, 0xF1801B8E, 0x00190000}};
  s21_decimal val2 = {{0xC66D0948, 0x564EC630, 0xEA9DC72E, 0x000F0000}};
  s21_decimal result = {{0x47FA20EB, 0xA3C20403, 0xF1801B8E, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_64) {
  int true_res = 0;
  s21_decimal val1 = {{0x656024F6, 0x75DAAF89, 0x84DA3BE0, 0x00120000}};
  s21_decimal val2 = {{0x8702B40C, 0x9E7E7B0A, 0xC20623A5, 0x80180000}};
  s21_decimal result = {{0xB676D534, 0x6A53369C, 0xB58F2748, 0x00180000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_65) {
  int true_res = 0;
  s21_decimal val1 = {{0x212B97F6, 0xF196A772, 0x4784388A, 0x00120000}};
  s21_decimal val2 = {{0xDAB194F7, 0x8F84989D, 0x53AF2735, 0x00010000}};
  s21_decimal result = {{0x212B97F6, 0xF196A772, 0x4784388A, 0x00120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_66) {
  int true_res = 0;
  s21_decimal val1 = {{0xE901663A, 0x9985BCDC, 0x483198E0, 0x00190000}};
  s21_decimal val2 = {{0xAF3752F8, 0xA809ECE3, 0x7A13F41A, 0x801A0000}};
  s21_decimal result = {{0x1165BCBE, 0x4580C66B, 0x0B279ED3, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_67) {
  int true_res = 0;
  s21_decimal val1 = {{0xBFA77933, 0x3CE0A6BB, 0xB8E02AD6, 0x80120000}};
  s21_decimal val2 = {{0x43A49956, 0x8D4F0FFD, 0xCDE0F63D, 0x80150000}};
  s21_decimal result = {{0xA27428E2, 0xAB8446FA, 0xCA688731, 0x80150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_68) {
  int true_res = 0;
  s21_decimal val1 = {{0x85BBD459, 0xF38EB2A5, 0x80F484E8, 0x00080000}};
  s21_decimal val2 = {{0x2041067C, 0x752EBD11, 0xC8F113B4, 0x80010000}};
  s21_decimal result = {{0x85BBD459, 0xF38EB2A5, 0x80F484E8, 0x00080000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_69) {
  int true_res = 0;
  s21_decimal val1 = {{0x0DDE727C, 0x3642A142, 0xF13AA885, 0x00160000}};
  s21_decimal val2 = {{0xCACD1894, 0x5111F469, 0xF144952A, 0x000F0000}};
  s21_decimal result = {{0x34963EA6, 0x856D1020, 0x181F7740, 0x00150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_70) {
  int true_res = 0;
  s21_decimal val1 = {{0xA58E02A7, 0xF2127D1B, 0xA6E06F4B, 0x80050000}};
  s21_decimal val2 = {{0xE9C1E484, 0xAAE81C22, 0x16F1AD5F, 0x80030000}};
  s21_decimal result = {{0xA58E02A7, 0xF2127D1B, 0xA6E06F4B, 0x80050000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_71) {
  int true_res = 0;
  s21_decimal val1 = {{0x75C13120, 0xDE65230E, 0xAE9DFC4E, 0x80030000}};
  s21_decimal val2 = {{0xCA2CDA44, 0x6DCA134B, 0xBFF8FDED, 0x00090000}};
  s21_decimal result = {{0xE02B735C, 0x6BA0A0EB, 0xAF9D6409, 0x80090000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_72) {
  int true_res = 0;
  s21_decimal val1 = {{0xDA4E798E, 0xA725C628, 0x9A678D39, 0x00130000}};
  s21_decimal val2 = {{0xB8938E7F, 0x75FDB9C5, 0x6DE4B6FF, 0x80100000}};
  s21_decimal result = {{0xDA4E798E, 0xA725C628, 0x9A678D39, 0x00130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_73) {
  int true_res = 0;
  s21_decimal val1 = {{0x89AC87D6, 0x99AC7178, 0x448AE579, 0x00060000}};
  s21_decimal val2 = {{0x0775CBD3, 0x5001849A, 0x0456F4AC, 0x80040000}};
  s21_decimal result = {{0x89AC87D6, 0x99AC7178, 0x448AE579, 0x00060000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_74) {
  int true_res = 0;
  s21_decimal val1 = {{0xF8F55649, 0xD78F9BE6, 0xCAC85038, 0x801B0000}};
  s21_decimal val2 = {{0xC3AA993B, 0x21BB96A2, 0x6F851502, 0x80020000}};
  s21_decimal result = {{0xF8F55649, 0xD78F9BE6, 0xCAC85038, 0x801B0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_75) {
  int true_res = 0;
  s21_decimal val1 = {{0x60BE6873, 0x42276493, 0x61139054, 0x80010000}};
  s21_decimal val2 = {{0x7F1F4E90, 0x7258BFC8, 0x58D2E1AE, 0x80170000}};
  s21_decimal result = {{0xE5DF1C94, 0x8FFD0ED7, 0x0095831C, 0x80150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_76) {
  int true_res = 0;
  s21_decimal val1 = {{0x99029176, 0x6DFC9E4E, 0x0C4B099C, 0x00100000}};
  s21_decimal val2 = {{0x8D24639E, 0xC08D5EF9, 0x10A8E00E, 0x80110000}};
  s21_decimal result = {{0x1E1AF54A, 0x0800963F, 0x06503FB5, 0x00110000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_77) {
  int true_res = 0;
  s21_decimal val1 = {{0x661931AA, 0x9F744FFB, 0xFD02F19C, 0x00080000}};
  s21_decimal val2 = {{0xB4D105B6, 0xFCFA5724, 0x3F4CC544, 0x800F0000}};
  s21_decimal result = {{0x44DA3795, 0x66D7DA89, 0x03CC64CB, 0x000E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_78) {
  int true_res = 0;
  s21_decimal val1 = {{0xAB4142B3, 0x8DF55072, 0x82BE295E, 0x000D0000}};
  s21_decimal val2 = {{0x66D45F1C, 0xA8ED34E7, 0x4C8E0676, 0x801A0000}};
  s21_decimal result = {{0xCA6B2C30, 0xDA68D8B7, 0x0A28B6DB, 0x001A0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_79) {
  int true_res = 0;
  s21_decimal val1 = {{0xA694736C, 0xBF2ADFAB, 0xF9BAFB50, 0x000C0000}};
  s21_decimal val2 = {{0x090D84A9, 0x2B7C931A, 0xCCDB518E, 0x800E0000}};
  s21_decimal result = {{0xCA99624F, 0x1EDDD7BE, 0xB9609F58, 0x000E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_80) {
  int true_res = 0;
  s21_decimal val1 = {{0x58A5BD75, 0x66A1EA3B, 0x86CB86BE, 0x80120000}};
  s21_decimal val2 = {{0x7FA824B3, 0x88978478, 0x2FA4BB81, 0x000E0000}};
  s21_decimal result = {{0x58A5BD75, 0x66A1EA3B, 0x86CB86BE, 0x80120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_81) {
  int true_res = 0;
  s21_decimal val1 = {{0xD8647638, 0x2D194A83, 0x385410C6, 0x80110000}};
  s21_decimal val2 = {{0x3BEC17A1, 0xDF7BB94B, 0x03401E4D, 0x00080000}};
  s21_decimal result = {{0xD8647638, 0x2D194A83, 0x385410C6, 0x80110000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_82) {
  int true_res = 0;
  s21_decimal val1 = {{0xC1662445, 0x3BAE2C3E, 0x6041014E, 0x80180000}};
  s21_decimal val2 = {{0xC1662445, 0x3BAE2C3E, 0x6041014E, 0x80180000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_83) {
  int true_res = 0;
  s21_decimal val1 = {{0xF2D6C310, 0xD440FA5B, 0xAD4FA987, 0x00110000}};
  s21_decimal val2 = {{0x3551BE6D, 0x3C6A6A18, 0x9881279B, 0x80090000}};
  s21_decimal result = {{0x651579E8, 0x2ED34C3C, 0x1154C427, 0x00100000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_84) {
  int true_res = 0;
  s21_decimal val1 = {{0x2E7E220A, 0xC17C6B8D, 0xCDEC3C71, 0x00060000}};
  s21_decimal val2 = {{0x9F08EF22, 0xEC0E28C8, 0x057AEA32, 0x800F0000}};
  s21_decimal result = {{0x67CCCCBD, 0x3D9D0FD9, 0x0016A405, 0x000E0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_85) {
  int true_res = 0;
  s21_decimal val1 = {{0x2CB8C9DA, 0x0DC4B8D9, 0x5920C034, 0x001C0000}};
  s21_decimal val2 = {{0xC5F65F56, 0x712A36FF, 0xC28036FD, 0x801C0000}};
  s21_decimal result = {{0x2CB8C9DA, 0x0DC4B8D9, 0x5920C034, 0x001C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_86) {
  int true_res = 0;
  s21_decimal val1 = {{0x43B1FD74, 0xD2B1490A, 0x38074B51, 0x00120000}};
  s21_decimal val2 = {{0xAFE16010, 0xAB3682A6, 0xE8FD0B1A, 0x00080000}};
  s21_decimal result = {{0x43B1FD74, 0xD2B1490A, 0x38074B51, 0x00120000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_87) {
  int true_res = 0;
  s21_decimal val1 = {{0x5F779724, 0xAC8E0D7D, 0x859CA602, 0x80170000}};
  s21_decimal val2 = {{0xED1057DB, 0x56669A6F, 0x57A5BDF8, 0x801A0000}};
  s21_decimal result = {{0xA5DB60E4, 0xB0154F6D, 0x2539900F, 0x801A0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_88) {
  int true_res = 0;
  s21_decimal val1 = {{0x486B4D15, 0x7CD3B3EA, 0x8CDF9E7E, 0x00010000}};
  s21_decimal val2 = {{0x8E81BDC9, 0x35D0454F, 0xE49779C0, 0x80010000}};
  s21_decimal result = {{0x486B4D15, 0x7CD3B3EA, 0x8CDF9E7E, 0x00010000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_89) {
  int true_res = 0;
  s21_decimal val1 = {{0x99CA4A2D, 0xBD6E305E, 0x8DBE0BCB, 0x00000000}};
  s21_decimal val2 = {{0x540F5910, 0x46269C88, 0x2E085156, 0x80180000}};
  s21_decimal result = {{0xD63D039A, 0xECD368FD, 0x000A5D19, 0x00150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_90) {
  int true_res = 0;
  s21_decimal val1 = {{0xF3CD8712, 0x6662A473, 0x1FF7FD1C, 0x00150000}};
  s21_decimal val2 = {{0xEFA0F3E5, 0x49F6CC80, 0x189A7745, 0x800A0000}};
  s21_decimal result = {{0xF3CD8712, 0x6662A473, 0x1FF7FD1C, 0x00150000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_91) {
  int true_res = 0;
  s21_decimal val1 = {{0xC1C395E3, 0xDC232C26, 0xC35920FB, 0x80130000}};
  s21_decimal val2 = {{0xA92BCAD0, 0x74368E22, 0x8A8611B9, 0x001A0000}};
  s21_decimal result = {{0x5F0795E0, 0xB41D5943, 0x2969D8EC, 0x801A0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_92) {
  int true_res = 0;
  s21_decimal val1 = {{0x215CDA9E, 0x6A8C13EA, 0xE9EB2B8E, 0x800D0000}};
  s21_decimal val2 = {{0x328827B4, 0xE8DD39C0, 0x93A7141E, 0x80030000}};
  s21_decimal result = {{0x215CDA9E, 0x6A8C13EA, 0xE9EB2B8E, 0x800D0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_93) {
  int true_res = 0;
  s21_decimal val1 = {{0x99E87783, 0x91223A43, 0x0F763D0E, 0x80170000}};
  s21_decimal val2 = {{0x5F7AE2BF, 0xB802997F, 0x81B80699, 0x800B0000}};
  s21_decimal result = {{0x99E87783, 0x91223A43, 0x0F763D0E, 0x80170000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_94) {
  int true_res = 0;
  s21_decimal val1 = {{0x8A02A2AA, 0x7081E0A3, 0x103FFB07, 0x00000000}};
  s21_decimal val2 = {{0xF4093AEC, 0x89B43629, 0x459E36BE, 0x00150000}};
  s21_decimal result = {{0x73F6CF76, 0x37147679, 0x0259D977, 0x00140000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_95) {
  int true_res = 0;
  s21_decimal val1 = {{0xCADFA972, 0xAEF60393, 0x16590B06, 0x00180000}};
  s21_decimal val2 = {{0xBAF548DE, 0x5EA2EA34, 0xEA2CE779, 0x00110000}};
  s21_decimal result = {{0xCADFA972, 0xAEF60393, 0x16590B06, 0x00180000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_96) {
  int true_res = 0;
  s21_decimal val1 = {{0x2A5E7054, 0x0F7739B7, 0xCC424014, 0x00010000}};
  s21_decimal val2 = {{0xD68CB864, 0x1CC32A4A, 0x7C707C1A, 0x80130000}};
  s21_decimal result = {{0xD83E496C, 0xD5812EDF, 0x5AC1DB2C, 0x00130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_97) {
  int true_res = 0;
  s21_decimal val1 = {{0x146EDFA5, 0xBD8BE09F, 0x610CB9BA, 0x800C0000}};
  s21_decimal val2 = {{0x039C6065, 0x56EEF7CE, 0xBD57F4BA, 0x00050000}};
  s21_decimal result = {{0x146EDFA5, 0xBD8BE09F, 0x610CB9BA, 0x800C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_98) {
  int true_res = 0;
  s21_decimal val1 = {{0x3623C7DB, 0x7A57692A, 0x4E0DB3F3, 0x00080000}};
  s21_decimal val2 = {{0x01EFF4EB, 0x1A9544A5, 0x4CB1FD3C, 0x00130000}};
  s21_decimal result = {{0x74326E71, 0xA0BFD4DC, 0x2F2FA1BE, 0x00130000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_99) {
  int true_res = 0;
  s21_decimal val1 = {{0x35861D82, 0xC9E713EC, 0xE33B4681, 0x80160000}};
  s21_decimal val2 = {{0x7EEAE78E, 0xE8FC3BCC, 0x63D9911D, 0x00140000}};
  s21_decimal result = {{0x35861D82, 0xC9E713EC, 0xE33B4681, 0x80160000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_100) {
  int true_res = 0;
  s21_decimal val1 = {{0x2C26F7E5, 0x910AFE7E, 0x5CB3AB11, 0x00190000}};
  s21_decimal val2 = {{0x9B758561, 0xD4D4CDAA, 0x088D9579, 0x00130000}};
  s21_decimal result = {{0x2C26F7E5, 0x910AFE7E, 0x5CB3AB11, 0x00190000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_101) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{1, 0, 0, 0x001C0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_102) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{997, 0, 0, 0x001B0000}};
  s21_decimal result = {{0x00000245, 0, 0, 0x001B0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_103) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal val2 = {{1, 0, 0, 0x001C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_104) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal val2 = {{1, 0, 0, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_105) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal val2 = {{1, 0, 0, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_106) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal val2 = {{0, 1, 0, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_107) {
  int true_res = 0;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal val2 = {{0, 0, 1, 0x000C0000}};
  s21_decimal output;
  int s21_res = s21_mod(val1, val2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mod_108) {
  int true_res = 3;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal val2 = {{0, 0, 0, 0x000C0000}};
  s21_decimal output;

  int s21_res = s21_mod(val1, val2, &output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_mod(void) {
  Suite *s = suite_create("\033[45m-=S21_MOD=-\033[0m");
  TCase *tc = tcase_create("s21_mod_tc");

  tcase_add_test(tc, s21_mod_00);
  tcase_add_test(tc, s21_mod_0);
  tcase_add_test(tc, s21_mod_1);
  tcase_add_test(tc, s21_mod_2);
  tcase_add_test(tc, s21_mod_3);
  tcase_add_test(tc, s21_mod_4);
  tcase_add_test(tc, s21_mod_5);
  tcase_add_test(tc, s21_mod_6);
  tcase_add_test(tc, s21_mod_7);
  tcase_add_test(tc, s21_mod_8);
  tcase_add_test(tc, s21_mod_9);
  tcase_add_test(tc, s21_mod_10);
  tcase_add_test(tc, s21_mod_11);
  tcase_add_test(tc, s21_mod_12);
  tcase_add_test(tc, s21_mod_13);
  tcase_add_test(tc, s21_mod_14);
  tcase_add_test(tc, s21_mod_15);
  tcase_add_test(tc, s21_mod_16);
  tcase_add_test(tc, s21_mod_17);
  tcase_add_test(tc, s21_mod_18);
  tcase_add_test(tc, s21_mod_19);
  tcase_add_test(tc, s21_mod_20);
  tcase_add_test(tc, s21_mod_21);
  tcase_add_test(tc, s21_mod_22);
  tcase_add_test(tc, s21_mod_23);
  tcase_add_test(tc, s21_mod_24);
  tcase_add_test(tc, s21_mod_25);
  tcase_add_test(tc, s21_mod_26);
  tcase_add_test(tc, s21_mod_27);
  tcase_add_test(tc, s21_mod_28);
  tcase_add_test(tc, s21_mod_29);
  tcase_add_test(tc, s21_mod_30);
  tcase_add_test(tc, s21_mod_31);
  tcase_add_test(tc, s21_mod_32);
  tcase_add_test(tc, s21_mod_33);
  tcase_add_test(tc, s21_mod_34);
  tcase_add_test(tc, s21_mod_35);
  tcase_add_test(tc, s21_mod_36);
  tcase_add_test(tc, s21_mod_37);
  tcase_add_test(tc, s21_mod_38);
  tcase_add_test(tc, s21_mod_39);
  tcase_add_test(tc, s21_mod_40);
  tcase_add_test(tc, s21_mod_41);
  tcase_add_test(tc, s21_mod_42);
  tcase_add_test(tc, s21_mod_43);
  tcase_add_test(tc, s21_mod_44);
  tcase_add_test(tc, s21_mod_45);
  tcase_add_test(tc, s21_mod_46);
  tcase_add_test(tc, s21_mod_47);
  tcase_add_test(tc, s21_mod_48);
  tcase_add_test(tc, s21_mod_49);
  tcase_add_test(tc, s21_mod_50);
  tcase_add_test(tc, s21_mod_51);
  tcase_add_test(tc, s21_mod_52);
  tcase_add_test(tc, s21_mod_53);
  tcase_add_test(tc, s21_mod_54);
  tcase_add_test(tc, s21_mod_55);
  tcase_add_test(tc, s21_mod_56);
  tcase_add_test(tc, s21_mod_57);
  tcase_add_test(tc, s21_mod_58);
  tcase_add_test(tc, s21_mod_59);
  tcase_add_test(tc, s21_mod_60);
  tcase_add_test(tc, s21_mod_61);
  tcase_add_test(tc, s21_mod_62);
  tcase_add_test(tc, s21_mod_63);
  tcase_add_test(tc, s21_mod_64);
  tcase_add_test(tc, s21_mod_65);
  tcase_add_test(tc, s21_mod_66);
  tcase_add_test(tc, s21_mod_67);
  tcase_add_test(tc, s21_mod_68);
  tcase_add_test(tc, s21_mod_69);
  tcase_add_test(tc, s21_mod_70);
  tcase_add_test(tc, s21_mod_71);
  tcase_add_test(tc, s21_mod_72);
  tcase_add_test(tc, s21_mod_73);
  tcase_add_test(tc, s21_mod_74);
  tcase_add_test(tc, s21_mod_75);
  tcase_add_test(tc, s21_mod_76);
  tcase_add_test(tc, s21_mod_77);
  tcase_add_test(tc, s21_mod_78);
  tcase_add_test(tc, s21_mod_79);
  tcase_add_test(tc, s21_mod_80);
  tcase_add_test(tc, s21_mod_81);
  tcase_add_test(tc, s21_mod_82);
  tcase_add_test(tc, s21_mod_83);
  tcase_add_test(tc, s21_mod_84);
  tcase_add_test(tc, s21_mod_85);
  tcase_add_test(tc, s21_mod_86);
  tcase_add_test(tc, s21_mod_87);
  tcase_add_test(tc, s21_mod_88);
  tcase_add_test(tc, s21_mod_89);
  tcase_add_test(tc, s21_mod_90);
  tcase_add_test(tc, s21_mod_91);
  tcase_add_test(tc, s21_mod_92);
  tcase_add_test(tc, s21_mod_93);
  tcase_add_test(tc, s21_mod_94);
  tcase_add_test(tc, s21_mod_95);
  tcase_add_test(tc, s21_mod_96);
  tcase_add_test(tc, s21_mod_97);
  tcase_add_test(tc, s21_mod_98);
  tcase_add_test(tc, s21_mod_99);
  tcase_add_test(tc, s21_mod_100);
  tcase_add_test(tc, s21_mod_101);
  tcase_add_test(tc, s21_mod_102);
  tcase_add_test(tc, s21_mod_103);
  tcase_add_test(tc, s21_mod_104);
  tcase_add_test(tc, s21_mod_105);
  tcase_add_test(tc, s21_mod_106);
  tcase_add_test(tc, s21_mod_107);
  tcase_add_test(tc, s21_mod_108);

  suite_add_tcase(s, tc);
  return s;
}
