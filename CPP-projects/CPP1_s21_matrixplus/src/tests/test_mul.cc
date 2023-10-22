#include "test_main.h"

TEST(mul_matrix, incorrect_0) {
  S21Matrix first(1, 1), second(2, 2);
  EXPECT_THROW(first.MulMatrix(second), std::out_of_range);
}

TEST(mul_matrix, incorrect_1) {
  S21Matrix first(5, 1), second(2, 1);
  EXPECT_THROW(first.MulMatrix(second), std::out_of_range);
}

TEST(mul_matrix, incorrect_2) {
  S21Matrix first(2, 4), second(3, 2);
  EXPECT_THROW(first.MulMatrix(second), std::out_of_range);
}

TEST(mul_matrix, func_correct_0) {
  S21Matrix first(2, 4), second(4, 2), ans(2, 2);
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_1) {
  S21Matrix first(2, 5);
  first(0, 0) = 141;
  first(0, 1) = 120;
  first(0, 2) = 278;
  first(0, 3) = -111;
  first(0, 4) = 250;
  first(1, 0) = -205;
  first(1, 1) = 227;
  first(1, 2) = 306;
  first(1, 3) = -421;
  first(1, 4) = 281;
  S21Matrix second(5, 4);
  second(0, 0) = -17;
  second(0, 1) = -338;
  second(0, 2) = -500;
  second(0, 3) = -359;
  second(1, 0) = 53;
  second(1, 1) = 472;
  second(1, 2) = 191;
  second(1, 3) = -220;
  second(2, 0) = 292;
  second(2, 1) = 262;
  second(2, 2) = -496;
  second(2, 3) = 18;
  second(3, 0) = -306;
  second(3, 1) = -401;
  second(3, 2) = 64;
  second(3, 3) = -395;
  second(4, 0) = 476;
  second(4, 1) = 430;
  second(4, 2) = 53;
  second(4, 3) = -279;
  S21Matrix ans(2, 4);
  ans(0, 0) = 238105;
  ans(0, 1) = 233829;
  ans(0, 2) = -179322;
  ans(0, 3) = -97920;
  ans(1, 0) = 367450;
  ans(1, 1) = 546257;
  ans(1, 2) = -17970;
  ans(1, 3) = 117059;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_2) {
  S21Matrix first(1, 3);
  first(0, 0) = -407;
  first(0, 1) = 280;
  first(0, 2) = 72;
  S21Matrix second(3, 2);
  second(0, 0) = -51;
  second(0, 1) = -7;
  second(1, 0) = -33;
  second(1, 1) = 308;
  second(2, 0) = -157;
  second(2, 1) = 456;
  S21Matrix ans(1, 2);
  ans(0, 0) = 213;
  ans(0, 1) = 121921;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_3) {
  S21Matrix first(1, 5);
  first(0, 0) = 112;
  first(0, 1) = -173;
  first(0, 2) = -24;
  first(0, 3) = 95;
  first(0, 4) = -52;
  S21Matrix second(5, 4);
  second(0, 0) = -450;
  second(0, 1) = -357;
  second(0, 2) = -131;
  second(0, 3) = 453;
  second(1, 0) = 431;
  second(1, 1) = 42;
  second(1, 2) = 267;
  second(1, 3) = -190;
  second(2, 0) = 317;
  second(2, 1) = 162;
  second(2, 2) = -158;
  second(2, 3) = -400;
  second(3, 0) = -408;
  second(3, 1) = 91;
  second(3, 2) = 292;
  second(3, 3) = 409;
  second(4, 0) = 141;
  second(4, 1) = -17;
  second(4, 2) = -205;
  second(4, 3) = -326;
  S21Matrix ans(1, 4);
  ans(0, 0) = -178663;
  ans(0, 1) = -41609;
  ans(0, 2) = -18671;
  ans(0, 3) = 149013;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_4) {
  S21Matrix first(4, 2);
  first(0, 0) = 245;
  first(0, 1) = 351;
  first(1, 0) = 245;
  first(1, 1) = -151;
  first(2, 0) = -148;
  first(2, 1) = -401;
  first(3, 0) = -61;
  first(3, 1) = -87;
  S21Matrix second(2, 1);
  second(0, 0) = -283;
  second(1, 0) = -313;
  S21Matrix ans(4, 1);
  ans(0, 0) = -179198;
  ans(1, 0) = -22072;
  ans(2, 0) = 167397;
  ans(3, 0) = 44494;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_5) {
  S21Matrix first(2, 3);
  first(0, 0) = -184;
  first(0, 1) = -385;
  first(0, 2) = -84;
  first(1, 0) = 60;
  first(1, 1) = -428;
  first(1, 2) = -385;
  S21Matrix second(3, 1);
  second(0, 0) = -459;
  second(1, 0) = 474;
  second(2, 0) = 103;
  S21Matrix ans(2, 1);
  ans(0, 0) = -106686;
  ans(1, 0) = -270067;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_6) {
  S21Matrix first(5, 4);
  first(0, 0) = 316;
  first(0, 1) = 292;
  first(0, 2) = -29;
  first(0, 3) = 35;
  first(1, 0) = -289;
  first(1, 1) = 318;
  first(1, 2) = -88;
  first(1, 3) = 166;
  first(2, 0) = -444;
  first(2, 1) = -348;
  first(2, 2) = 121;
  first(2, 3) = -113;
  first(3, 0) = 261;
  first(3, 1) = 14;
  first(3, 2) = 274;
  first(3, 3) = 75;
  first(4, 0) = 348;
  first(4, 1) = 35;
  first(4, 2) = 11;
  first(4, 3) = -230;
  S21Matrix second(4, 4);
  second(0, 0) = -44;
  second(0, 1) = 32;
  second(0, 2) = -184;
  second(0, 3) = -14;
  second(1, 0) = 484;
  second(1, 1) = 444;
  second(1, 2) = 143;
  second(1, 3) = 371;
  second(2, 0) = 205;
  second(2, 1) = 165;
  second(2, 2) = 16;
  second(2, 3) = -346;
  second(3, 0) = 88;
  second(3, 1) = -44;
  second(3, 2) = -355;
  second(3, 3) = -407;
  S21Matrix ans(5, 4);
  ans(0, 0) = 124559;
  ans(0, 1) = 133435;
  ans(0, 2) = -29277;
  ans(0, 3) = 99697;
  ans(1, 0) = 163196;
  ans(1, 1) = 110120;
  ans(1, 2) = 38312;
  ans(1, 3) = 84910;
  ans(2, 0) = -134035;
  ans(2, 1) = -143783;
  ans(2, 2) = 73983;
  ans(2, 3) = -118767;
  ans(3, 0) = 58062;
  ans(3, 1) = 56478;
  ans(3, 2) = -68263;
  ans(3, 3) = -123789;
  ans(4, 0) = -16357;
  ans(4, 1) = 38611;
  ans(4, 2) = 22799;
  ans(4, 3) = 97917;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_7) {
  S21Matrix first(5, 2);
  first(0, 0) = 367;
  first(0, 1) = 196;
  first(1, 0) = -418;
  first(1, 1) = -387;
  first(2, 0) = 29;
  first(2, 1) = 319;
  first(3, 0) = 193;
  first(3, 1) = -336;
  first(4, 0) = -324;
  first(4, 1) = 63;
  S21Matrix second(2, 3);
  second(0, 0) = 248;
  second(0, 1) = -177;
  second(0, 2) = 464;
  second(1, 0) = -359;
  second(1, 1) = -139;
  second(1, 2) = 65;
  S21Matrix ans(5, 3);
  ans(0, 0) = 20652;
  ans(0, 1) = -92203;
  ans(0, 2) = 183028;
  ans(1, 0) = 35269;
  ans(1, 1) = 127779;
  ans(1, 2) = -219107;
  ans(2, 0) = -107329;
  ans(2, 1) = -49474;
  ans(2, 2) = 34191;
  ans(3, 0) = 168488;
  ans(3, 1) = 12543;
  ans(3, 2) = 67712;
  ans(4, 0) = -102969;
  ans(4, 1) = 48591;
  ans(4, 2) = -146241;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_8) {
  S21Matrix first(5, 1);
  first(0, 0) = -87;
  first(1, 0) = -475;
  first(2, 0) = 373;
  first(3, 0) = -209;
  first(4, 0) = -323;
  S21Matrix second(1, 5);
  second(0, 0) = 35;
  second(0, 1) = -5;
  second(0, 2) = 67;
  second(0, 3) = -495;
  second(0, 4) = 159;
  S21Matrix ans(5, 5);
  ans(0, 0) = -3045;
  ans(0, 1) = 435;
  ans(0, 2) = -5829;
  ans(0, 3) = 43065;
  ans(0, 4) = -13833;
  ans(1, 0) = -16625;
  ans(1, 1) = 2375;
  ans(1, 2) = -31825;
  ans(1, 3) = 235125;
  ans(1, 4) = -75525;
  ans(2, 0) = 13055;
  ans(2, 1) = -1865;
  ans(2, 2) = 24991;
  ans(2, 3) = -184635;
  ans(2, 4) = 59307;
  ans(3, 0) = -7315;
  ans(3, 1) = 1045;
  ans(3, 2) = -14003;
  ans(3, 3) = 103455;
  ans(3, 4) = -33231;
  ans(4, 0) = -11305;
  ans(4, 1) = 1615;
  ans(4, 2) = -21641;
  ans(4, 3) = 159885;
  ans(4, 4) = -51357;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_9) {
  S21Matrix first(5, 1);
  first(0, 0) = -492;
  first(1, 0) = -111;
  first(2, 0) = -399;
  first(3, 0) = 339;
  first(4, 0) = -209;
  S21Matrix second(1, 2);
  second(0, 0) = -331;
  second(0, 1) = -246;
  S21Matrix ans(5, 2);
  ans(0, 0) = 162852;
  ans(0, 1) = 121032;
  ans(1, 0) = 36741;
  ans(1, 1) = 27306;
  ans(2, 0) = 132069;
  ans(2, 1) = 98154;
  ans(3, 0) = -112209;
  ans(3, 1) = -83394;
  ans(4, 0) = 69179;
  ans(4, 1) = 51414;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, func_correct_10) {
  S21Matrix first(1, 2);
  first(0, 0) = 372;
  first(0, 1) = -279;
  S21Matrix second(2, 2);
  second(0, 0) = 401;
  second(0, 1) = 286;
  second(1, 0) = 1;
  second(1, 1) = -265;
  S21Matrix ans(1, 2);
  ans(0, 0) = 148893;
  ans(0, 1) = 180327;
  first.MulMatrix(second);
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_incorrect_0) {
  S21Matrix first(1, 1), second(2, 2);
  EXPECT_THROW(first * second, std::out_of_range);
}

TEST(mul_matrix, operator_incorrect_1) {
  S21Matrix first(5, 1), second(2, 1);
  EXPECT_THROW(first * second, std::out_of_range);
}

TEST(mul_matrix, operator_incorrect_2) {
  S21Matrix first(2, 4), second(3, 2);
  EXPECT_THROW(first * second, std::out_of_range);
}

TEST(mul_matrix, operator_correct_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -86;
  first(1, 0) = 473;
  S21Matrix second(1, 4);
  second(0, 0) = 37;
  second(0, 1) = -129;
  second(0, 2) = -38;
  second(0, 3) = 332;
  S21Matrix ans(2, 4);
  ans(0, 0) = -3182;
  ans(0, 1) = 11094;
  ans(0, 2) = 3268;
  ans(0, 3) = -28552;
  ans(1, 0) = 17501;
  ans(1, 1) = -61017;
  ans(1, 2) = -17974;
  ans(1, 3) = 157036;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_2) {
  S21Matrix first(4, 2);
  first(0, 0) = -191;
  first(0, 1) = 483;
  first(1, 0) = -395;
  first(1, 1) = 158;
  first(2, 0) = -388;
  first(2, 1) = -476;
  first(3, 0) = 349;
  first(3, 1) = 318;
  S21Matrix second(2, 4);
  second(0, 0) = 142;
  second(0, 1) = -355;
  second(0, 2) = 278;
  second(0, 3) = -206;
  second(1, 0) = 44;
  second(1, 1) = -451;
  second(1, 2) = 345;
  second(1, 3) = -48;
  S21Matrix ans(4, 4);
  ans(0, 0) = -5870;
  ans(0, 1) = -150028;
  ans(0, 2) = 113537;
  ans(0, 3) = 16162;
  ans(1, 0) = -49138;
  ans(1, 1) = 68967;
  ans(1, 2) = -55300;
  ans(1, 3) = 73786;
  ans(2, 0) = -76040;
  ans(2, 1) = 352416;
  ans(2, 2) = -272084;
  ans(2, 3) = 102776;
  ans(3, 0) = 63550;
  ans(3, 1) = -267313;
  ans(3, 2) = 206732;
  ans(3, 3) = -87158;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_3) {
  S21Matrix first(5, 4);
  first(0, 0) = 64;
  first(0, 1) = -237;
  first(0, 2) = 389;
  first(0, 3) = -398;
  first(1, 0) = 410;
  first(1, 1) = 148;
  first(1, 2) = -360;
  first(1, 3) = -367;
  first(2, 0) = -354;
  first(2, 1) = 298;
  first(2, 2) = 327;
  first(2, 3) = 31;
  first(3, 0) = 498;
  first(3, 1) = 339;
  first(3, 2) = -35;
  first(3, 3) = -466;
  first(4, 0) = 424;
  first(4, 1) = -64;
  first(4, 2) = -303;
  first(4, 3) = 215;
  S21Matrix second(4, 3);
  second(0, 0) = -292;
  second(0, 1) = 379;
  second(0, 2) = 124;
  second(1, 0) = 29;
  second(1, 1) = 110;
  second(1, 2) = -140;
  second(2, 0) = -341;
  second(2, 1) = -481;
  second(2, 2) = -377;
  second(3, 0) = 301;
  second(3, 1) = -41;
  second(3, 2) = -129;
  S21Matrix ans(5, 3);
  ans(0, 0) = -278008;
  ans(0, 1) = -172605;
  ans(0, 2) = -54195;
  ans(1, 0) = -103135;
  ans(1, 1) = 359877;
  ans(1, 2) = 213183;
  ans(2, 0) = 9834;
  ans(2, 1) = -259944;
  ans(2, 2) = -212894;
  ans(3, 0) = -263916;
  ans(3, 1) = 261973;
  ans(3, 2) = 87601;
  ans(4, 0) = 42374;
  ans(4, 1) = 290584;
  ans(4, 2) = 148032;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_4) {
  S21Matrix first(1, 4);
  first(0, 0) = 364;
  first(0, 1) = -250;
  first(0, 2) = -301;
  first(0, 3) = 459;
  S21Matrix second(4, 1);
  second(0, 0) = 392;
  second(1, 0) = -143;
  second(2, 0) = -464;
  second(3, 0) = 216;
  S21Matrix ans(1, 1);
  ans(0, 0) = 417246;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_5) {
  S21Matrix first(5, 2);
  first(0, 0) = 53;
  first(0, 1) = -29;
  first(1, 0) = 174;
  first(1, 1) = -65;
  first(2, 0) = 97;
  first(2, 1) = -31;
  first(3, 0) = 239;
  first(3, 1) = -394;
  first(4, 0) = -198;
  first(4, 1) = 66;
  S21Matrix second(2, 5);
  second(0, 0) = -457;
  second(0, 1) = 227;
  second(0, 2) = 55;
  second(0, 3) = -154;
  second(0, 4) = -318;
  second(1, 0) = 285;
  second(1, 1) = 480;
  second(1, 2) = -408;
  second(1, 3) = -76;
  second(1, 4) = 188;
  S21Matrix ans(5, 5);
  ans(0, 0) = -32486;
  ans(0, 1) = -1889;
  ans(0, 2) = 14747;
  ans(0, 3) = -5958;
  ans(0, 4) = -22306;
  ans(1, 0) = -98043;
  ans(1, 1) = 8298;
  ans(1, 2) = 36090;
  ans(1, 3) = -21856;
  ans(1, 4) = -67552;
  ans(2, 0) = -53164;
  ans(2, 1) = 7139;
  ans(2, 2) = 17983;
  ans(2, 3) = -12582;
  ans(2, 4) = -36674;
  ans(3, 0) = -221513;
  ans(3, 1) = -134867;
  ans(3, 2) = 173897;
  ans(3, 3) = -6862;
  ans(3, 4) = -150074;
  ans(4, 0) = 109296;
  ans(4, 1) = -13266;
  ans(4, 2) = -37818;
  ans(4, 3) = 25476;
  ans(4, 4) = 75372;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_6) {
  S21Matrix first(4, 1);
  first(0, 0) = -338;
  first(1, 0) = -90;
  first(2, 0) = 473;
  first(3, 0) = -46;
  S21Matrix second(1, 1);
  second(0, 0) = -388;
  S21Matrix ans(4, 1);
  ans(0, 0) = 131144;
  ans(1, 0) = 34920;
  ans(2, 0) = -183524;
  ans(3, 0) = 17848;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_7) {
  S21Matrix first(1, 1);
  first(0, 0) = -388;
  S21Matrix second(1, 3);
  second(0, 0) = 322;
  second(0, 1) = 233;
  second(0, 2) = 498;
  S21Matrix ans(1, 3);
  ans(0, 0) = -124936;
  ans(0, 1) = -90404;
  ans(0, 2) = -193224;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_8) {
  S21Matrix first(2, 1);
  first(0, 0) = -76;
  first(1, 0) = -217;
  S21Matrix second(1, 4);
  second(0, 0) = -404;
  second(0, 1) = -73;
  second(0, 2) = 492;
  second(0, 3) = 48;
  S21Matrix ans(2, 4);
  ans(0, 0) = 30704;
  ans(0, 1) = 5548;
  ans(0, 2) = -37392;
  ans(0, 3) = -3648;
  ans(1, 0) = 87668;
  ans(1, 1) = 15841;
  ans(1, 2) = -106764;
  ans(1, 3) = -10416;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_9) {
  S21Matrix first(4, 1);
  first(0, 0) = 32;
  first(1, 0) = 23;
  first(2, 0) = -100;
  first(3, 0) = 197;
  S21Matrix second(1, 1);
  second(0, 0) = 437;
  S21Matrix ans(4, 1);
  ans(0, 0) = 13984;
  ans(1, 0) = 10051;
  ans(2, 0) = -43700;
  ans(3, 0) = 86089;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_correct_10) {
  S21Matrix first(1, 5);
  first(0, 0) = 203;
  first(0, 1) = 390;
  first(0, 2) = 381;
  first(0, 3) = 460;
  first(0, 4) = -206;
  S21Matrix second(5, 5);
  second(0, 0) = 75;
  second(0, 1) = 265;
  second(0, 2) = 155;
  second(0, 3) = -179;
  second(0, 4) = 47;
  second(1, 0) = 39;
  second(1, 1) = -316;
  second(1, 2) = 429;
  second(1, 3) = -230;
  second(1, 4) = 66;
  second(2, 0) = 12;
  second(2, 1) = -433;
  second(2, 2) = -160;
  second(2, 3) = -136;
  second(2, 4) = 475;
  second(3, 0) = 247;
  second(3, 1) = -323;
  second(3, 2) = 374;
  second(3, 3) = 160;
  second(3, 4) = 70;
  second(4, 0) = 5;
  second(4, 1) = -310;
  second(4, 2) = -340;
  second(4, 3) = 290;
  second(4, 4) = 238;
  S21Matrix ans(1, 5);
  ans(0, 0) = 147597;
  ans(0, 1) = -319138;
  ans(0, 2) = 379895;
  ans(0, 3) = -163993;
  ans(0, 4) = 199428;
  S21Matrix check = first * second;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_incorrect_0) {
  S21Matrix first(1, 1), second(2, 2);
  EXPECT_THROW(first *= second, std::out_of_range);
}

TEST(mul_matrix, operator_pe_incorrect_1) {
  S21Matrix first(5, 1), second(2, 1);
  EXPECT_THROW(first *= second, std::out_of_range);
}

TEST(mul_matrix, operator_pe_incorrect_2) {
  S21Matrix first(2, 4), second(3, 2);
  EXPECT_THROW(first *= second, std::out_of_range);
}

TEST(mul_matrix, operator_pe_correct_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -86;
  first(1, 0) = 473;
  S21Matrix second(1, 4);
  second(0, 0) = 37;
  second(0, 1) = -129;
  second(0, 2) = -38;
  second(0, 3) = 332;
  S21Matrix ans(2, 4);
  ans(0, 0) = -3182;
  ans(0, 1) = 11094;
  ans(0, 2) = 3268;
  ans(0, 3) = -28552;
  ans(1, 0) = 17501;
  ans(1, 1) = -61017;
  ans(1, 2) = -17974;
  ans(1, 3) = 157036;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_2) {
  S21Matrix first(4, 2);
  first(0, 0) = -191;
  first(0, 1) = 483;
  first(1, 0) = -395;
  first(1, 1) = 158;
  first(2, 0) = -388;
  first(2, 1) = -476;
  first(3, 0) = 349;
  first(3, 1) = 318;
  S21Matrix second(2, 4);
  second(0, 0) = 142;
  second(0, 1) = -355;
  second(0, 2) = 278;
  second(0, 3) = -206;
  second(1, 0) = 44;
  second(1, 1) = -451;
  second(1, 2) = 345;
  second(1, 3) = -48;
  S21Matrix ans(4, 4);
  ans(0, 0) = -5870;
  ans(0, 1) = -150028;
  ans(0, 2) = 113537;
  ans(0, 3) = 16162;
  ans(1, 0) = -49138;
  ans(1, 1) = 68967;
  ans(1, 2) = -55300;
  ans(1, 3) = 73786;
  ans(2, 0) = -76040;
  ans(2, 1) = 352416;
  ans(2, 2) = -272084;
  ans(2, 3) = 102776;
  ans(3, 0) = 63550;
  ans(3, 1) = -267313;
  ans(3, 2) = 206732;
  ans(3, 3) = -87158;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_3) {
  S21Matrix first(5, 4);
  first(0, 0) = 64;
  first(0, 1) = -237;
  first(0, 2) = 389;
  first(0, 3) = -398;
  first(1, 0) = 410;
  first(1, 1) = 148;
  first(1, 2) = -360;
  first(1, 3) = -367;
  first(2, 0) = -354;
  first(2, 1) = 298;
  first(2, 2) = 327;
  first(2, 3) = 31;
  first(3, 0) = 498;
  first(3, 1) = 339;
  first(3, 2) = -35;
  first(3, 3) = -466;
  first(4, 0) = 424;
  first(4, 1) = -64;
  first(4, 2) = -303;
  first(4, 3) = 215;
  S21Matrix second(4, 3);
  second(0, 0) = -292;
  second(0, 1) = 379;
  second(0, 2) = 124;
  second(1, 0) = 29;
  second(1, 1) = 110;
  second(1, 2) = -140;
  second(2, 0) = -341;
  second(2, 1) = -481;
  second(2, 2) = -377;
  second(3, 0) = 301;
  second(3, 1) = -41;
  second(3, 2) = -129;
  S21Matrix ans(5, 3);
  ans(0, 0) = -278008;
  ans(0, 1) = -172605;
  ans(0, 2) = -54195;
  ans(1, 0) = -103135;
  ans(1, 1) = 359877;
  ans(1, 2) = 213183;
  ans(2, 0) = 9834;
  ans(2, 1) = -259944;
  ans(2, 2) = -212894;
  ans(3, 0) = -263916;
  ans(3, 1) = 261973;
  ans(3, 2) = 87601;
  ans(4, 0) = 42374;
  ans(4, 1) = 290584;
  ans(4, 2) = 148032;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_4) {
  S21Matrix first(1, 4);
  first(0, 0) = 364;
  first(0, 1) = -250;
  first(0, 2) = -301;
  first(0, 3) = 459;
  S21Matrix second(4, 1);
  second(0, 0) = 392;
  second(1, 0) = -143;
  second(2, 0) = -464;
  second(3, 0) = 216;
  S21Matrix ans(1, 1);
  ans(0, 0) = 417246;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_5) {
  S21Matrix first(5, 2);
  first(0, 0) = 53;
  first(0, 1) = -29;
  first(1, 0) = 174;
  first(1, 1) = -65;
  first(2, 0) = 97;
  first(2, 1) = -31;
  first(3, 0) = 239;
  first(3, 1) = -394;
  first(4, 0) = -198;
  first(4, 1) = 66;
  S21Matrix second(2, 5);
  second(0, 0) = -457;
  second(0, 1) = 227;
  second(0, 2) = 55;
  second(0, 3) = -154;
  second(0, 4) = -318;
  second(1, 0) = 285;
  second(1, 1) = 480;
  second(1, 2) = -408;
  second(1, 3) = -76;
  second(1, 4) = 188;
  S21Matrix ans(5, 5);
  ans(0, 0) = -32486;
  ans(0, 1) = -1889;
  ans(0, 2) = 14747;
  ans(0, 3) = -5958;
  ans(0, 4) = -22306;
  ans(1, 0) = -98043;
  ans(1, 1) = 8298;
  ans(1, 2) = 36090;
  ans(1, 3) = -21856;
  ans(1, 4) = -67552;
  ans(2, 0) = -53164;
  ans(2, 1) = 7139;
  ans(2, 2) = 17983;
  ans(2, 3) = -12582;
  ans(2, 4) = -36674;
  ans(3, 0) = -221513;
  ans(3, 1) = -134867;
  ans(3, 2) = 173897;
  ans(3, 3) = -6862;
  ans(3, 4) = -150074;
  ans(4, 0) = 109296;
  ans(4, 1) = -13266;
  ans(4, 2) = -37818;
  ans(4, 3) = 25476;
  ans(4, 4) = 75372;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_6) {
  S21Matrix first(4, 1);
  first(0, 0) = -338;
  first(1, 0) = -90;
  first(2, 0) = 473;
  first(3, 0) = -46;
  S21Matrix second(1, 1);
  second(0, 0) = -388;
  S21Matrix ans(4, 1);
  ans(0, 0) = 131144;
  ans(1, 0) = 34920;
  ans(2, 0) = -183524;
  ans(3, 0) = 17848;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_7) {
  S21Matrix first(1, 1);
  first(0, 0) = -388;
  S21Matrix second(1, 3);
  second(0, 0) = 322;
  second(0, 1) = 233;
  second(0, 2) = 498;
  S21Matrix ans(1, 3);
  ans(0, 0) = -124936;
  ans(0, 1) = -90404;
  ans(0, 2) = -193224;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_8) {
  S21Matrix first(2, 1);
  first(0, 0) = -76;
  first(1, 0) = -217;
  S21Matrix second(1, 4);
  second(0, 0) = -404;
  second(0, 1) = -73;
  second(0, 2) = 492;
  second(0, 3) = 48;
  S21Matrix ans(2, 4);
  ans(0, 0) = 30704;
  ans(0, 1) = 5548;
  ans(0, 2) = -37392;
  ans(0, 3) = -3648;
  ans(1, 0) = 87668;
  ans(1, 1) = 15841;
  ans(1, 2) = -106764;
  ans(1, 3) = -10416;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_9) {
  S21Matrix first(4, 1);
  first(0, 0) = 32;
  first(1, 0) = 23;
  first(2, 0) = -100;
  first(3, 0) = 197;
  S21Matrix second(1, 1);
  second(0, 0) = 437;
  S21Matrix ans(4, 1);
  ans(0, 0) = 13984;
  ans(1, 0) = 10051;
  ans(2, 0) = -43700;
  ans(3, 0) = 86089;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_matrix, operator_pe_correct_10) {
  S21Matrix first(1, 5);
  first(0, 0) = 203;
  first(0, 1) = 390;
  first(0, 2) = 381;
  first(0, 3) = 460;
  first(0, 4) = -206;
  S21Matrix second(5, 5);
  second(0, 0) = 75;
  second(0, 1) = 265;
  second(0, 2) = 155;
  second(0, 3) = -179;
  second(0, 4) = 47;
  second(1, 0) = 39;
  second(1, 1) = -316;
  second(1, 2) = 429;
  second(1, 3) = -230;
  second(1, 4) = 66;
  second(2, 0) = 12;
  second(2, 1) = -433;
  second(2, 2) = -160;
  second(2, 3) = -136;
  second(2, 4) = 475;
  second(3, 0) = 247;
  second(3, 1) = -323;
  second(3, 2) = 374;
  second(3, 3) = 160;
  second(3, 4) = 70;
  second(4, 0) = 5;
  second(4, 1) = -310;
  second(4, 2) = -340;
  second(4, 3) = 290;
  second(4, 4) = 238;
  S21Matrix ans(1, 5);
  ans(0, 0) = 147597;
  ans(0, 1) = -319138;
  ans(0, 2) = 379895;
  ans(0, 3) = -163993;
  ans(0, 4) = 199428;
  first *= second;
  EXPECT_EQ(first.EqMatrix(ans), true);
}

TEST(mul_number, func_0) {
  S21Matrix check(1, 4);
  check(0, 0) = 5.3;
  check(0, 1) = -13.7;
  check(0, 2) = 6.4;
  check(0, 3) = 36.5;
  double num = -43;
  S21Matrix ans(1, 4);
  ans(0, 0) = -227.9;
  ans(0, 1) = 589.1;
  ans(0, 2) = -275.2;
  ans(0, 3) = -1569.5;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_1) {
  S21Matrix check(1, 2);
  check(0, 0) = -9.6;
  check(0, 1) = -7.6;
  double num = -33.5;
  S21Matrix ans(1, 2);
  ans(0, 0) = 321.6;
  ans(0, 1) = 254.6;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_2) {
  S21Matrix check(3, 5);
  check(0, 0) = 43.5;
  check(0, 1) = -38.8;
  check(0, 2) = -8.1;
  check(0, 3) = 0.6;
  check(0, 4) = -25.2;
  check(1, 0) = -22.9;
  check(1, 1) = 28.5;
  check(1, 2) = -20.5;
  check(1, 3) = 11.1;
  check(1, 4) = 27.9;
  check(2, 0) = -28.9;
  check(2, 1) = 29.3;
  check(2, 2) = 12;
  check(2, 3) = -10.5;
  check(2, 4) = -5.6;
  double num = 29.7;
  S21Matrix ans(3, 5);
  ans(0, 0) = 1291.95;
  ans(0, 1) = -1152.36;
  ans(0, 2) = -240.57;
  ans(0, 3) = 17.82;
  ans(0, 4) = -748.44;
  ans(1, 0) = -680.13;
  ans(1, 1) = 846.45;
  ans(1, 2) = -608.85;
  ans(1, 3) = 329.67;
  ans(1, 4) = 828.63;
  ans(2, 0) = -858.33;
  ans(2, 1) = 870.21;
  ans(2, 2) = 356.4;
  ans(2, 3) = -311.85;
  ans(2, 4) = -166.32;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_3) {
  S21Matrix check(3, 1);
  check(0, 0) = -24.5;
  check(1, 0) = -6.8;
  check(2, 0) = -17.9;
  double num = -22.4;
  S21Matrix ans(3, 1);
  ans(0, 0) = 548.8;
  ans(1, 0) = 152.32;
  ans(2, 0) = 400.96;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_4) {
  S21Matrix check(5, 4);
  check(0, 0) = 10.9;
  check(0, 1) = 41;
  check(0, 2) = -45.4;
  check(0, 3) = 45.6;
  check(1, 0) = 47;
  check(1, 1) = 48.3;
  check(1, 2) = 31.4;
  check(1, 3) = -4;
  check(2, 0) = 1.2;
  check(2, 1) = 33.6;
  check(2, 2) = 8.3;
  check(2, 3) = -46.1;
  check(3, 0) = 15.6;
  check(3, 1) = -22.8;
  check(3, 2) = -8.1;
  check(3, 3) = -3.8;
  check(4, 0) = 1.2;
  check(4, 1) = 37;
  check(4, 2) = 28.7;
  check(4, 3) = -35;
  double num = -20.2;
  S21Matrix ans(5, 4);
  ans(0, 0) = -220.18;
  ans(0, 1) = -828.2;
  ans(0, 2) = 917.08;
  ans(0, 3) = -921.12;
  ans(1, 0) = -949.4;
  ans(1, 1) = -975.66;
  ans(1, 2) = -634.28;
  ans(1, 3) = 80.8;
  ans(2, 0) = -24.24;
  ans(2, 1) = -678.72;
  ans(2, 2) = -167.66;
  ans(2, 3) = 931.22;
  ans(3, 0) = -315.12;
  ans(3, 1) = 460.56;
  ans(3, 2) = 163.62;
  ans(3, 3) = 76.76;
  ans(4, 0) = -24.24;
  ans(4, 1) = -747.4;
  ans(4, 2) = -579.74;
  ans(4, 3) = 707;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_5) {
  S21Matrix check(3, 1);
  check(0, 0) = -8.1;
  check(1, 0) = 23.4;
  check(2, 0) = -19.1;
  double num = -22.1;
  S21Matrix ans(3, 1);
  ans(0, 0) = 179.01;
  ans(1, 0) = -517.14;
  ans(2, 0) = 422.11;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_6) {
  S21Matrix check(1, 4);
  check(0, 0) = 27.2;
  check(0, 1) = -41.9;
  check(0, 2) = 38.2;
  check(0, 3) = -34.4;
  double num = 1.3;
  S21Matrix ans(1, 4);
  ans(0, 0) = 35.36;
  ans(0, 1) = -54.47;
  ans(0, 2) = 49.66;
  ans(0, 3) = -44.72;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_7) {
  S21Matrix check(1, 5);
  check(0, 0) = 21;
  check(0, 1) = 27.2;
  check(0, 2) = 31.8;
  check(0, 3) = 35.6;
  check(0, 4) = -13.4;
  double num = -33.1;
  S21Matrix ans(1, 5);
  ans(0, 0) = -695.1;
  ans(0, 1) = -900.32;
  ans(0, 2) = -1052.58;
  ans(0, 3) = -1178.36;
  ans(0, 4) = 443.54;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_8) {
  S21Matrix check(1, 4);
  check(0, 0) = -45.8;
  check(0, 1) = -20.4;
  check(0, 2) = -24.4;
  check(0, 3) = 6.7;
  double num = -33.3;
  S21Matrix ans(1, 4);
  ans(0, 0) = 1525.14;
  ans(0, 1) = 679.32;
  ans(0, 2) = 812.52;
  ans(0, 3) = -223.11;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, func_9) {
  S21Matrix check(3, 1);
  check(0, 0) = -33.3;
  check(1, 0) = -25.8;
  check(2, 0) = -1.4;
  double num = -15.6;
  S21Matrix ans(3, 1);
  ans(0, 0) = 519.48;
  ans(1, 0) = 402.48;
  ans(2, 0) = 21.84;
  check.MulNumber(num);
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_0) {
  S21Matrix check(3, 3);
  check(0, 0) = -20.2;
  check(0, 1) = -34;
  check(0, 2) = 17.7;
  check(1, 0) = -6.2;
  check(1, 1) = 20.9;
  check(1, 2) = -38.3;
  check(2, 0) = -40.3;
  check(2, 1) = -21.4;
  check(2, 2) = -37.6;
  double num = -6.3;
  S21Matrix ans(3, 3);
  ans(0, 0) = 127.26;
  ans(0, 1) = 214.2;
  ans(0, 2) = -111.51;
  ans(1, 0) = 39.06;
  ans(1, 1) = -131.67;
  ans(1, 2) = 241.29;
  ans(2, 0) = 253.89;
  ans(2, 1) = 134.82;
  ans(2, 2) = 236.88;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_1) {
  S21Matrix check(5, 2);
  check(0, 0) = -12;
  check(0, 1) = 41;
  check(1, 0) = 15.2;
  check(1, 1) = 0.5;
  check(2, 0) = -43.4;
  check(2, 1) = 4.4;
  check(3, 0) = 18.2;
  check(3, 1) = 4.1;
  check(4, 0) = -38.5;
  check(4, 1) = 33.8;
  double num = -41;
  S21Matrix ans(5, 2);
  ans(0, 0) = 492;
  ans(0, 1) = -1681;
  ans(1, 0) = -623.2;
  ans(1, 1) = -20.5;
  ans(2, 0) = 1779.4;
  ans(2, 1) = -180.4;
  ans(3, 0) = -746.2;
  ans(3, 1) = -168.1;
  ans(4, 0) = 1578.5;
  ans(4, 1) = -1385.8;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_2) {
  S21Matrix check(3, 2);
  check(0, 0) = 22.6;
  check(0, 1) = 42.4;
  check(1, 0) = -6.7;
  check(1, 1) = -45.2;
  check(2, 0) = 0.1;
  check(2, 1) = 39.8;
  double num = -48.1;
  S21Matrix ans(3, 2);
  ans(0, 0) = -1087.06;
  ans(0, 1) = -2039.44;
  ans(1, 0) = 322.27;
  ans(1, 1) = 2174.12;
  ans(2, 0) = -4.81;
  ans(2, 1) = -1914.38;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_3) {
  S21Matrix check(3, 3);
  check(0, 0) = -18.9;
  check(0, 1) = 26.8;
  check(0, 2) = -26.4;
  check(1, 0) = 34.6;
  check(1, 1) = 0.5;
  check(1, 2) = -30.2;
  check(2, 0) = -14.4;
  check(2, 1) = -23.6;
  check(2, 2) = 18;
  double num = -26.7;
  S21Matrix ans(3, 3);
  ans(0, 0) = 504.63;
  ans(0, 1) = -715.56;
  ans(0, 2) = 704.88;
  ans(1, 0) = -923.82;
  ans(1, 1) = -13.35;
  ans(1, 2) = 806.34;
  ans(2, 0) = 384.48;
  ans(2, 1) = 630.12;
  ans(2, 2) = -480.6;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_4) {
  S21Matrix check(2, 1);
  check(0, 0) = -47;
  check(1, 0) = 6.9;
  double num = 22.5;
  S21Matrix ans(2, 1);
  ans(0, 0) = -1057.5;
  ans(1, 0) = 155.25;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_5) {
  S21Matrix check(3, 3);
  check(0, 0) = 34.3;
  check(0, 1) = 47.3;
  check(0, 2) = -29.1;
  check(1, 0) = -40.6;
  check(1, 1) = 36.1;
  check(1, 2) = -1.3;
  check(2, 0) = 11;
  check(2, 1) = 39.7;
  check(2, 2) = -12.1;
  double num = -6.7;
  S21Matrix ans(3, 3);
  ans(0, 0) = -229.81;
  ans(0, 1) = -316.91;
  ans(0, 2) = 194.97;
  ans(1, 0) = 272.02;
  ans(1, 1) = -241.87;
  ans(1, 2) = 8.71;
  ans(2, 0) = -73.7;
  ans(2, 1) = -265.99;
  ans(2, 2) = 81.07;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_6) {
  S21Matrix check(5, 1);
  check(0, 0) = -23.6;
  check(1, 0) = -46;
  check(2, 0) = -24.9;
  check(3, 0) = -25.2;
  check(4, 0) = 31;
  double num = 14.1;
  S21Matrix ans(5, 1);
  ans(0, 0) = -332.76;
  ans(1, 0) = -648.6;
  ans(2, 0) = -351.09;
  ans(3, 0) = -355.32;
  ans(4, 0) = 437.1;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_7) {
  S21Matrix check(1, 3);
  check(0, 0) = 8.6;
  check(0, 1) = -20.9;
  check(0, 2) = 22;
  double num = 38.6;
  S21Matrix ans(1, 3);
  ans(0, 0) = 331.96;
  ans(0, 1) = -806.74;
  ans(0, 2) = 849.2;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_8) {
  S21Matrix check(4, 1);
  check(0, 0) = -0.1;
  check(1, 0) = -38.3;
  check(2, 0) = 29.3;
  check(3, 0) = -11.5;
  double num = 7.7;
  S21Matrix ans(4, 1);
  ans(0, 0) = -0.77;
  ans(1, 0) = -294.91;
  ans(2, 0) = 225.61;
  ans(3, 0) = -88.55;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_9) {
  S21Matrix check(3, 2);
  check(0, 0) = 34.4;
  check(0, 1) = 8.2;
  check(1, 0) = -37.4;
  check(1, 1) = -27.2;
  check(2, 0) = -7.7;
  check(2, 1) = 16.9;
  double num = -35;
  S21Matrix ans(3, 2);
  ans(0, 0) = -1204;
  ans(0, 1) = -287;
  ans(1, 0) = 1309;
  ans(1, 1) = 952;
  ans(2, 0) = 269.5;
  ans(2, 1) = -591.5;
  S21Matrix tmp = check * num;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_0) {
  S21Matrix check(2, 1);
  check(0, 0) = 49.4;
  check(1, 0) = 48.6;
  double num = 13.1;
  S21Matrix ans(2, 1);
  ans(0, 0) = 647.14;
  ans(1, 0) = 636.66;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_1) {
  S21Matrix check(3, 3);
  check(0, 0) = 14.2;
  check(0, 1) = 26.7;
  check(0, 2) = 32;
  check(1, 0) = -4.4;
  check(1, 1) = -7.9;
  check(1, 2) = 6.1;
  check(2, 0) = 26.1;
  check(2, 1) = 49.8;
  check(2, 2) = 2.8;
  double num = 8;
  S21Matrix ans(3, 3);
  ans(0, 0) = 113.6;
  ans(0, 1) = 213.6;
  ans(0, 2) = 256;
  ans(1, 0) = -35.2;
  ans(1, 1) = -63.2;
  ans(1, 2) = 48.8;
  ans(2, 0) = 208.8;
  ans(2, 1) = 398.4;
  ans(2, 2) = 22.4;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_2) {
  S21Matrix check(4, 4);
  check(0, 0) = 43.2;
  check(0, 1) = 40.2;
  check(0, 2) = -15.7;
  check(0, 3) = 29;
  check(1, 0) = 16;
  check(1, 1) = -16.1;
  check(1, 2) = 1.9;
  check(1, 3) = -18.6;
  check(2, 0) = -28.6;
  check(2, 1) = 41.2;
  check(2, 2) = -32.7;
  check(2, 3) = 46.8;
  check(3, 0) = -3.6;
  check(3, 1) = -7.4;
  check(3, 2) = 16.8;
  check(3, 3) = -8.4;
  double num = -48.9;
  S21Matrix ans(4, 4);
  ans(0, 0) = -2112.48;
  ans(0, 1) = -1965.78;
  ans(0, 2) = 767.73;
  ans(0, 3) = -1418.1;
  ans(1, 0) = -782.4;
  ans(1, 1) = 787.29;
  ans(1, 2) = -92.91;
  ans(1, 3) = 909.54;
  ans(2, 0) = 1398.54;
  ans(2, 1) = -2014.68;
  ans(2, 2) = 1599.03;
  ans(2, 3) = -2288.52;
  ans(3, 0) = 176.04;
  ans(3, 1) = 361.86;
  ans(3, 2) = -821.52;
  ans(3, 3) = 410.76;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_3) {
  S21Matrix check(3, 1);
  check(0, 0) = -16.8;
  check(1, 0) = -24.6;
  check(2, 0) = 25.9;
  double num = 4.7;
  S21Matrix ans(3, 1);
  ans(0, 0) = -78.96;
  ans(1, 0) = -115.62;
  ans(2, 0) = 121.73;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_4) {
  S21Matrix check(4, 3);
  check(0, 0) = 8.1;
  check(0, 1) = 15.9;
  check(0, 2) = -44.4;
  check(1, 0) = 27.6;
  check(1, 1) = 41.4;
  check(1, 2) = 42;
  check(2, 0) = 27.6;
  check(2, 1) = 23.5;
  check(2, 2) = 32.3;
  check(3, 0) = -2;
  check(3, 1) = -2.5;
  check(3, 2) = 21.1;
  double num = 9.4;
  S21Matrix ans(4, 3);
  ans(0, 0) = 76.14;
  ans(0, 1) = 149.46;
  ans(0, 2) = -417.36;
  ans(1, 0) = 259.44;
  ans(1, 1) = 389.16;
  ans(1, 2) = 394.8;
  ans(2, 0) = 259.44;
  ans(2, 1) = 220.9;
  ans(2, 2) = 303.62;
  ans(3, 0) = -18.8;
  ans(3, 1) = -23.5;
  ans(3, 2) = 198.34;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_5) {
  S21Matrix check(4, 2);
  check(0, 0) = 34.9;
  check(0, 1) = 31.4;
  check(1, 0) = 7.4;
  check(1, 1) = -37.1;
  check(2, 0) = 27.4;
  check(2, 1) = -27.1;
  check(3, 0) = 47.6;
  check(3, 1) = -33;
  double num = -14.7;
  S21Matrix ans(4, 2);
  ans(0, 0) = -513.03;
  ans(0, 1) = -461.58;
  ans(1, 0) = -108.78;
  ans(1, 1) = 545.37;
  ans(2, 0) = -402.78;
  ans(2, 1) = 398.37;
  ans(3, 0) = -699.72;
  ans(3, 1) = 485.1;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_6) {
  S21Matrix check(1, 4);
  check(0, 0) = 35.9;
  check(0, 1) = 33.1;
  check(0, 2) = 41.6;
  check(0, 3) = -43.1;
  double num = 15.2;
  S21Matrix ans(1, 4);
  ans(0, 0) = 545.68;
  ans(0, 1) = 503.12;
  ans(0, 2) = 632.32;
  ans(0, 3) = -655.12;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_7) {
  S21Matrix check(5, 5);
  check(0, 0) = -13.6;
  check(0, 1) = -24.7;
  check(0, 2) = -25.9;
  check(0, 3) = -23.3;
  check(0, 4) = 19.4;
  check(1, 0) = -28.1;
  check(1, 1) = -36;
  check(1, 2) = 22.9;
  check(1, 3) = -28.3;
  check(1, 4) = 11;
  check(2, 0) = -46.7;
  check(2, 1) = -23;
  check(2, 2) = -40.9;
  check(2, 3) = -9.5;
  check(2, 4) = -22.3;
  check(3, 0) = -26.9;
  check(3, 1) = -45;
  check(3, 2) = 46.8;
  check(3, 3) = -19;
  check(3, 4) = -43.7;
  check(4, 0) = 31.2;
  check(4, 1) = 13.1;
  check(4, 2) = -25.6;
  check(4, 3) = -17.6;
  check(4, 4) = 5.7;
  double num = 33.4;
  S21Matrix ans(5, 5);
  ans(0, 0) = -454.24;
  ans(0, 1) = -824.98;
  ans(0, 2) = -865.06;
  ans(0, 3) = -778.22;
  ans(0, 4) = 647.96;
  ans(1, 0) = -938.54;
  ans(1, 1) = -1202.4;
  ans(1, 2) = 764.86;
  ans(1, 3) = -945.22;
  ans(1, 4) = 367.4;
  ans(2, 0) = -1559.78;
  ans(2, 1) = -768.2;
  ans(2, 2) = -1366.06;
  ans(2, 3) = -317.3;
  ans(2, 4) = -744.82;
  ans(3, 0) = -898.46;
  ans(3, 1) = -1503;
  ans(3, 2) = 1563.12;
  ans(3, 3) = -634.6;
  ans(3, 4) = -1459.58;
  ans(4, 0) = 1042.08;
  ans(4, 1) = 437.54;
  ans(4, 2) = -855.04;
  ans(4, 3) = -587.84;
  ans(4, 4) = 190.38;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_8) {
  S21Matrix check(3, 3);
  check(0, 0) = -18.6;
  check(0, 1) = 23.5;
  check(0, 2) = 8.6;
  check(1, 0) = -19.5;
  check(1, 1) = 26.4;
  check(1, 2) = 30.1;
  check(2, 0) = -25.5;
  check(2, 1) = -22;
  check(2, 2) = -37;
  double num = 16.4;
  S21Matrix ans(3, 3);
  ans(0, 0) = -305.04;
  ans(0, 1) = 385.4;
  ans(0, 2) = 141.04;
  ans(1, 0) = -319.8;
  ans(1, 1) = 432.96;
  ans(1, 2) = 493.64;
  ans(2, 0) = -418.2;
  ans(2, 1) = -360.8;
  ans(2, 2) = -606.8;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_eq_9) {
  S21Matrix check(5, 4);
  check(0, 0) = 12.3;
  check(0, 1) = 38.2;
  check(0, 2) = 22.2;
  check(0, 3) = -3.6;
  check(1, 0) = -22.8;
  check(1, 1) = 11.1;
  check(1, 2) = -34.8;
  check(1, 3) = 16.9;
  check(2, 0) = -40.3;
  check(2, 1) = -48;
  check(2, 2) = 26.8;
  check(2, 3) = 23;
  check(3, 0) = 13.6;
  check(3, 1) = 11.6;
  check(3, 2) = 11.8;
  check(3, 3) = -45.4;
  check(4, 0) = 30.5;
  check(4, 1) = 21.3;
  check(4, 2) = 22.4;
  check(4, 3) = 0.9;
  double num = -0.4;
  S21Matrix ans(5, 4);
  ans(0, 0) = -4.92;
  ans(0, 1) = -15.28;
  ans(0, 2) = -8.88;
  ans(0, 3) = 1.44;
  ans(1, 0) = 9.12;
  ans(1, 1) = -4.44;
  ans(1, 2) = 13.92;
  ans(1, 3) = -6.76;
  ans(2, 0) = 16.12;
  ans(2, 1) = 19.2;
  ans(2, 2) = -10.72;
  ans(2, 3) = -9.2;
  ans(3, 0) = -5.44;
  ans(3, 1) = -4.64;
  ans(3, 2) = -4.72;
  ans(3, 3) = 18.16;
  ans(4, 0) = -12.2;
  ans(4, 1) = -8.52;
  ans(4, 2) = -8.96;
  ans(4, 3) = -0.36;
  check *= num;
  EXPECT_EQ(check.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__0) {
  S21Matrix check(3, 3);
  check(0, 0) = -20.2;
  check(0, 1) = -34;
  check(0, 2) = 17.7;
  check(1, 0) = -6.2;
  check(1, 1) = 20.9;
  check(1, 2) = -38.3;
  check(2, 0) = -40.3;
  check(2, 1) = -21.4;
  check(2, 2) = -37.6;
  double num = -6.3;
  S21Matrix ans(3, 3);
  ans(0, 0) = 127.26;
  ans(0, 1) = 214.2;
  ans(0, 2) = -111.51;
  ans(1, 0) = 39.06;
  ans(1, 1) = -131.67;
  ans(1, 2) = 241.29;
  ans(2, 0) = 253.89;
  ans(2, 1) = 134.82;
  ans(2, 2) = 236.88;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__1) {
  S21Matrix check(5, 2);
  check(0, 0) = -12;
  check(0, 1) = 41;
  check(1, 0) = 15.2;
  check(1, 1) = 0.5;
  check(2, 0) = -43.4;
  check(2, 1) = 4.4;
  check(3, 0) = 18.2;
  check(3, 1) = 4.1;
  check(4, 0) = -38.5;
  check(4, 1) = 33.8;
  double num = -41;
  S21Matrix ans(5, 2);
  ans(0, 0) = 492;
  ans(0, 1) = -1681;
  ans(1, 0) = -623.2;
  ans(1, 1) = -20.5;
  ans(2, 0) = 1779.4;
  ans(2, 1) = -180.4;
  ans(3, 0) = -746.2;
  ans(3, 1) = -168.1;
  ans(4, 0) = 1578.5;
  ans(4, 1) = -1385.8;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__2) {
  S21Matrix check(3, 2);
  check(0, 0) = 22.6;
  check(0, 1) = 42.4;
  check(1, 0) = -6.7;
  check(1, 1) = -45.2;
  check(2, 0) = 0.1;
  check(2, 1) = 39.8;
  double num = -48.1;
  S21Matrix ans(3, 2);
  ans(0, 0) = -1087.06;
  ans(0, 1) = -2039.44;
  ans(1, 0) = 322.27;
  ans(1, 1) = 2174.12;
  ans(2, 0) = -4.81;
  ans(2, 1) = -1914.38;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__3) {
  S21Matrix check(3, 3);
  check(0, 0) = -18.9;
  check(0, 1) = 26.8;
  check(0, 2) = -26.4;
  check(1, 0) = 34.6;
  check(1, 1) = 0.5;
  check(1, 2) = -30.2;
  check(2, 0) = -14.4;
  check(2, 1) = -23.6;
  check(2, 2) = 18;
  double num = -26.7;
  S21Matrix ans(3, 3);
  ans(0, 0) = 504.63;
  ans(0, 1) = -715.56;
  ans(0, 2) = 704.88;
  ans(1, 0) = -923.82;
  ans(1, 1) = -13.35;
  ans(1, 2) = 806.34;
  ans(2, 0) = 384.48;
  ans(2, 1) = 630.12;
  ans(2, 2) = -480.6;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__4) {
  S21Matrix check(2, 1);
  check(0, 0) = -47;
  check(1, 0) = 6.9;
  double num = 22.5;
  S21Matrix ans(2, 1);
  ans(0, 0) = -1057.5;
  ans(1, 0) = 155.25;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__5) {
  S21Matrix check(3, 3);
  check(0, 0) = 34.3;
  check(0, 1) = 47.3;
  check(0, 2) = -29.1;
  check(1, 0) = -40.6;
  check(1, 1) = 36.1;
  check(1, 2) = -1.3;
  check(2, 0) = 11;
  check(2, 1) = 39.7;
  check(2, 2) = -12.1;
  double num = -6.7;
  S21Matrix ans(3, 3);
  ans(0, 0) = -229.81;
  ans(0, 1) = -316.91;
  ans(0, 2) = 194.97;
  ans(1, 0) = 272.02;
  ans(1, 1) = -241.87;
  ans(1, 2) = 8.71;
  ans(2, 0) = -73.7;
  ans(2, 1) = -265.99;
  ans(2, 2) = 81.07;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__6) {
  S21Matrix check(5, 1);
  check(0, 0) = -23.6;
  check(1, 0) = -46;
  check(2, 0) = -24.9;
  check(3, 0) = -25.2;
  check(4, 0) = 31;
  double num = 14.1;
  S21Matrix ans(5, 1);
  ans(0, 0) = -332.76;
  ans(1, 0) = -648.6;
  ans(2, 0) = -351.09;
  ans(3, 0) = -355.32;
  ans(4, 0) = 437.1;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__7) {
  S21Matrix check(1, 3);
  check(0, 0) = 8.6;
  check(0, 1) = -20.9;
  check(0, 2) = 22;
  double num = 38.6;
  S21Matrix ans(1, 3);
  ans(0, 0) = 331.96;
  ans(0, 1) = -806.74;
  ans(0, 2) = 849.2;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__8) {
  S21Matrix check(4, 1);
  check(0, 0) = -0.1;
  check(1, 0) = -38.3;
  check(2, 0) = 29.3;
  check(3, 0) = -11.5;
  double num = 7.7;
  S21Matrix ans(4, 1);
  ans(0, 0) = -0.77;
  ans(1, 0) = -294.91;
  ans(2, 0) = 225.61;
  ans(3, 0) = -88.55;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}

TEST(mul_number, operator_mul_rev__9) {
  S21Matrix check(3, 2);
  check(0, 0) = 34.4;
  check(0, 1) = 8.2;
  check(1, 0) = -37.4;
  check(1, 1) = -27.2;
  check(2, 0) = -7.7;
  check(2, 1) = 16.9;
  double num = -35;
  S21Matrix ans(3, 2);
  ans(0, 0) = -1204;
  ans(0, 1) = -287;
  ans(1, 0) = 1309;
  ans(1, 1) = 952;
  ans(2, 0) = 269.5;
  ans(2, 1) = -591.5;
  S21Matrix tmp = num * check;
  EXPECT_EQ(tmp.EqMatrix(ans), true);
}
