#include "test_main.h"

TEST(sub, func_correct_0) {
  S21Matrix first(5, 4);
  first(0, 0) = -276;
  first(0, 1) = 352;
  first(0, 2) = 206;
  first(0, 3) = -219;
  first(1, 0) = -342;
  first(1, 1) = 179;
  first(1, 2) = 399;
  first(1, 3) = 412;
  first(2, 0) = 113;
  first(2, 1) = -449;
  first(2, 2) = -27;
  first(2, 3) = -241;
  first(3, 0) = -106;
  first(3, 1) = -274;
  first(3, 2) = 405;
  first(3, 3) = -354;
  first(4, 0) = 232;
  first(4, 1) = -323;
  first(4, 2) = 181;
  first(4, 3) = -413;
  S21Matrix second(5, 4);
  second(0, 0) = 238;
  second(0, 1) = 185;
  second(0, 2) = 437;
  second(0, 3) = -263;
  second(1, 0) = 385;
  second(1, 1) = -365;
  second(1, 2) = 304;
  second(1, 3) = 294;
  second(2, 0) = 32;
  second(2, 1) = -271;
  second(2, 2) = -251;
  second(2, 3) = 219;
  second(3, 0) = -381;
  second(3, 1) = 278;
  second(3, 2) = -63;
  second(3, 3) = 53;
  second(4, 0) = -320;
  second(4, 1) = -128;
  second(4, 2) = 21;
  second(4, 3) = -302;
  S21Matrix check(5, 4);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first.SubMatrix(second);
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, func_correct_1) {
  S21Matrix first(5, 3);
  first(0, 0) = 198;
  first(0, 1) = 229;
  first(0, 2) = -380;
  first(1, 0) = -138;
  first(1, 1) = 145;
  first(1, 2) = 62;
  first(2, 0) = -46;
  first(2, 1) = 498;
  first(2, 2) = 337;
  first(3, 0) = 18;
  first(3, 1) = 83;
  first(3, 2) = -309;
  first(4, 0) = 4;
  first(4, 1) = 148;
  first(4, 2) = 458;
  S21Matrix second(5, 3);
  second(0, 0) = -429;
  second(0, 1) = -378;
  second(0, 2) = -234;
  second(1, 0) = 416;
  second(1, 1) = -415;
  second(1, 2) = 215;
  second(2, 0) = -7;
  second(2, 1) = -435;
  second(2, 2) = -195;
  second(3, 0) = -446;
  second(3, 1) = -420;
  second(3, 2) = -116;
  second(4, 0) = -385;
  second(4, 1) = 429;
  second(4, 2) = 43;
  S21Matrix check(5, 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first.SubMatrix(second);
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, func_correct_2) {
  S21Matrix first(4, 2);
  first(0, 0) = 392;
  first(0, 1) = 60;
  first(1, 0) = -63;
  first(1, 1) = -188;
  first(2, 0) = -72;
  first(2, 1) = 98;
  first(3, 0) = 327;
  first(3, 1) = 191;
  S21Matrix second(4, 2);
  second(0, 0) = 62;
  second(0, 1) = -435;
  second(1, 0) = 245;
  second(1, 1) = 88;
  second(2, 0) = 146;
  second(2, 1) = -190;
  second(3, 0) = 418;
  second(3, 1) = 156;
  S21Matrix check(4, 2);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first.SubMatrix(second);
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, func_correct_3) {
  S21Matrix first(3, 5);
  first(0, 0) = -53;
  first(0, 1) = -34;
  first(0, 2) = -271;
  first(0, 3) = -463;
  first(0, 4) = -287;
  first(1, 0) = -69;
  first(1, 1) = -471;
  first(1, 2) = -39;
  first(1, 3) = -156;
  first(1, 4) = -151;
  first(2, 0) = -436;
  first(2, 1) = 366;
  first(2, 2) = 352;
  first(2, 3) = 164;
  first(2, 4) = 428;
  S21Matrix second(3, 5);
  second(0, 0) = -26;
  second(0, 1) = 255;
  second(0, 2) = -351;
  second(0, 3) = 87;
  second(0, 4) = 203;
  second(1, 0) = 221;
  second(1, 1) = 122;
  second(1, 2) = 87;
  second(1, 3) = -368;
  second(1, 4) = -354;
  second(2, 0) = 223;
  second(2, 1) = -36;
  second(2, 2) = 355;
  second(2, 3) = 0;
  second(2, 4) = 19;
  S21Matrix check(3, 5);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first.SubMatrix(second);
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, func_correct_4) {
  S21Matrix first(3, 4);
  first(0, 0) = 125;
  first(0, 1) = 229;
  first(0, 2) = 262;
  first(0, 3) = 463;
  first(1, 0) = -291;
  first(1, 1) = -454;
  first(1, 2) = -343;
  first(1, 3) = 146;
  first(2, 0) = -56;
  first(2, 1) = 18;
  first(2, 2) = 336;
  first(2, 3) = -351;
  S21Matrix second(3, 4);
  second(0, 0) = 272;
  second(0, 1) = 447;
  second(0, 2) = 201;
  second(0, 3) = -230;
  second(1, 0) = -306;
  second(1, 1) = 88;
  second(1, 2) = 91;
  second(1, 3) = -91;
  second(2, 0) = 84;
  second(2, 1) = 161;
  second(2, 2) = -499;
  second(2, 3) = -255;
  S21Matrix check(3, 4);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first.SubMatrix(second);
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, func_throw_0) {
  S21Matrix first(1, 2), second(3, 4);
  EXPECT_THROW(first.SubMatrix(second), std::out_of_range);
}

TEST(sub, func_throw_1) {
  S21Matrix first(1, 2), second(2, 2);
  EXPECT_THROW(first.SubMatrix(second), std::out_of_range);
}

TEST(sub, func_throw_2) {
  S21Matrix first(1, 1), second(1, 4);
  EXPECT_THROW(first.SubMatrix(second), std::out_of_range);
}

TEST(sub, operator_plus_equal_correct_0) {
  S21Matrix first(5, 4);
  first(0, 0) = -276;
  first(0, 1) = 352;
  first(0, 2) = 206;
  first(0, 3) = -219;
  first(1, 0) = -342;
  first(1, 1) = 179;
  first(1, 2) = 399;
  first(1, 3) = 412;
  first(2, 0) = 113;
  first(2, 1) = -449;
  first(2, 2) = -27;
  first(2, 3) = -241;
  first(3, 0) = -106;
  first(3, 1) = -274;
  first(3, 2) = 405;
  first(3, 3) = -354;
  first(4, 0) = 232;
  first(4, 1) = -323;
  first(4, 2) = 181;
  first(4, 3) = -413;
  S21Matrix second(5, 4);
  second(0, 0) = 238;
  second(0, 1) = 185;
  second(0, 2) = 437;
  second(0, 3) = -263;
  second(1, 0) = 385;
  second(1, 1) = -365;
  second(1, 2) = 304;
  second(1, 3) = 294;
  second(2, 0) = 32;
  second(2, 1) = -271;
  second(2, 2) = -251;
  second(2, 3) = 219;
  second(3, 0) = -381;
  second(3, 1) = 278;
  second(3, 2) = -63;
  second(3, 3) = 53;
  second(4, 0) = -320;
  second(4, 1) = -128;
  second(4, 2) = 21;
  second(4, 3) = -302;
  S21Matrix check(5, 4);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first -= second;
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, operator_plus_equal_correct_1) {
  S21Matrix first(5, 3);
  first(0, 0) = 198;
  first(0, 1) = 229;
  first(0, 2) = -380;
  first(1, 0) = -138;
  first(1, 1) = 145;
  first(1, 2) = 62;
  first(2, 0) = -46;
  first(2, 1) = 498;
  first(2, 2) = 337;
  first(3, 0) = 18;
  first(3, 1) = 83;
  first(3, 2) = -309;
  first(4, 0) = 4;
  first(4, 1) = 148;
  first(4, 2) = 458;
  S21Matrix second(5, 3);
  second(0, 0) = -429;
  second(0, 1) = -378;
  second(0, 2) = -234;
  second(1, 0) = 416;
  second(1, 1) = -415;
  second(1, 2) = 215;
  second(2, 0) = -7;
  second(2, 1) = -435;
  second(2, 2) = -195;
  second(3, 0) = -446;
  second(3, 1) = -420;
  second(3, 2) = -116;
  second(4, 0) = -385;
  second(4, 1) = 429;
  second(4, 2) = 43;
  S21Matrix check(5, 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first -= second;
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, operator_plus_equal_correct_2) {
  S21Matrix first(4, 2);
  first(0, 0) = 392;
  first(0, 1) = 60;
  first(1, 0) = -63;
  first(1, 1) = -188;
  first(2, 0) = -72;
  first(2, 1) = 98;
  first(3, 0) = 327;
  first(3, 1) = 191;
  S21Matrix second(4, 2);
  second(0, 0) = 62;
  second(0, 1) = -435;
  second(1, 0) = 245;
  second(1, 1) = 88;
  second(2, 0) = 146;
  second(2, 1) = -190;
  second(3, 0) = 418;
  second(3, 1) = 156;
  S21Matrix check(4, 2);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first -= second;
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, operator_plus_equal_correct_3) {
  S21Matrix first(3, 5);
  first(0, 0) = -53;
  first(0, 1) = -34;
  first(0, 2) = -271;
  first(0, 3) = -463;
  first(0, 4) = -287;
  first(1, 0) = -69;
  first(1, 1) = -471;
  first(1, 2) = -39;
  first(1, 3) = -156;
  first(1, 4) = -151;
  first(2, 0) = -436;
  first(2, 1) = 366;
  first(2, 2) = 352;
  first(2, 3) = 164;
  first(2, 4) = 428;
  S21Matrix second(3, 5);
  second(0, 0) = -26;
  second(0, 1) = 255;
  second(0, 2) = -351;
  second(0, 3) = 87;
  second(0, 4) = 203;
  second(1, 0) = 221;
  second(1, 1) = 122;
  second(1, 2) = 87;
  second(1, 3) = -368;
  second(1, 4) = -354;
  second(2, 0) = 223;
  second(2, 1) = -36;
  second(2, 2) = 355;
  second(2, 3) = 0;
  second(2, 4) = 19;
  S21Matrix check(3, 5);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first -= second;
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, operator_plus_equal_correct_4) {
  S21Matrix first(3, 4);
  first(0, 0) = 125;
  first(0, 1) = 229;
  first(0, 2) = 262;
  first(0, 3) = 463;
  first(1, 0) = -291;
  first(1, 1) = -454;
  first(1, 2) = -343;
  first(1, 3) = 146;
  first(2, 0) = -56;
  first(2, 1) = 18;
  first(2, 2) = 336;
  first(2, 3) = -351;
  S21Matrix second(3, 4);
  second(0, 0) = 272;
  second(0, 1) = 447;
  second(0, 2) = 201;
  second(0, 3) = -230;
  second(1, 0) = -306;
  second(1, 1) = 88;
  second(1, 2) = 91;
  second(1, 3) = -91;
  second(2, 0) = 84;
  second(2, 1) = 161;
  second(2, 2) = -499;
  second(2, 3) = -255;
  S21Matrix check(3, 4);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  first -= second;
  EXPECT_EQ(first.EqMatrix(check), true);
}

TEST(sub, operator_plus_equal_throw_0) {
  S21Matrix first(1, 2), second(3, 4);
  EXPECT_THROW(first -= second, std::out_of_range);
}

TEST(sub, operator_plus_equal_throw_1) {
  S21Matrix first(1, 2), second(2, 2);
  EXPECT_THROW(first -= second, std::out_of_range);
}

TEST(sub, operator_plus_equal_throw_2) {
  S21Matrix first(1, 1), second(1, 4);
  EXPECT_THROW(first -= second, std::out_of_range);
}

TEST(sub, operator_plus_correct_0) {
  S21Matrix first(5, 4);
  first(0, 0) = -276;
  first(0, 1) = 352;
  first(0, 2) = 206;
  first(0, 3) = -219;
  first(1, 0) = -342;
  first(1, 1) = 179;
  first(1, 2) = 399;
  first(1, 3) = 412;
  first(2, 0) = 113;
  first(2, 1) = -449;
  first(2, 2) = -27;
  first(2, 3) = -241;
  first(3, 0) = -106;
  first(3, 1) = -274;
  first(3, 2) = 405;
  first(3, 3) = -354;
  first(4, 0) = 232;
  first(4, 1) = -323;
  first(4, 2) = 181;
  first(4, 3) = -413;
  S21Matrix second(5, 4);
  second(0, 0) = 238;
  second(0, 1) = 185;
  second(0, 2) = 437;
  second(0, 3) = -263;
  second(1, 0) = 385;
  second(1, 1) = -365;
  second(1, 2) = 304;
  second(1, 3) = 294;
  second(2, 0) = 32;
  second(2, 1) = -271;
  second(2, 2) = -251;
  second(2, 3) = 219;
  second(3, 0) = -381;
  second(3, 1) = 278;
  second(3, 2) = -63;
  second(3, 3) = 53;
  second(4, 0) = -320;
  second(4, 1) = -128;
  second(4, 2) = 21;
  second(4, 3) = -302;
  S21Matrix check(5, 4);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  S21Matrix ans;
  ans = first - second;

  EXPECT_EQ(ans.EqMatrix(check), true);
}

TEST(sub, operator_plus_correct_1) {
  S21Matrix first(5, 3);
  first(0, 0) = 198;
  first(0, 1) = 229;
  first(0, 2) = -380;
  first(1, 0) = -138;
  first(1, 1) = 145;
  first(1, 2) = 62;
  first(2, 0) = -46;
  first(2, 1) = 498;
  first(2, 2) = 337;
  first(3, 0) = 18;
  first(3, 1) = 83;
  first(3, 2) = -309;
  first(4, 0) = 4;
  first(4, 1) = 148;
  first(4, 2) = 458;
  S21Matrix second(5, 3);
  second(0, 0) = -429;
  second(0, 1) = -378;
  second(0, 2) = -234;
  second(1, 0) = 416;
  second(1, 1) = -415;
  second(1, 2) = 215;
  second(2, 0) = -7;
  second(2, 1) = -435;
  second(2, 2) = -195;
  second(3, 0) = -446;
  second(3, 1) = -420;
  second(3, 2) = -116;
  second(4, 0) = -385;
  second(4, 1) = 429;
  second(4, 2) = 43;
  S21Matrix check(5, 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  S21Matrix ans;
  ans = first - second;
  EXPECT_EQ(ans.EqMatrix(check), true);
}

TEST(sub, operator_plus_correct_2) {
  S21Matrix first(4, 2);
  first(0, 0) = 392;
  first(0, 1) = 60;
  first(1, 0) = -63;
  first(1, 1) = -188;
  first(2, 0) = -72;
  first(2, 1) = 98;
  first(3, 0) = 327;
  first(3, 1) = 191;
  S21Matrix second(4, 2);
  second(0, 0) = 62;
  second(0, 1) = -435;
  second(1, 0) = 245;
  second(1, 1) = 88;
  second(2, 0) = 146;
  second(2, 1) = -190;
  second(3, 0) = 418;
  second(3, 1) = 156;
  S21Matrix check(4, 2);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  S21Matrix ans;
  ans = first - second;
  EXPECT_EQ(ans.EqMatrix(check), true);
}

TEST(sub, operator_plus_correct_3) {
  S21Matrix first(3, 5);
  first(0, 0) = -53;
  first(0, 1) = -34;
  first(0, 2) = -271;
  first(0, 3) = -463;
  first(0, 4) = -287;
  first(1, 0) = -69;
  first(1, 1) = -471;
  first(1, 2) = -39;
  first(1, 3) = -156;
  first(1, 4) = -151;
  first(2, 0) = -436;
  first(2, 1) = 366;
  first(2, 2) = 352;
  first(2, 3) = 164;
  first(2, 4) = 428;
  S21Matrix second(3, 5);
  second(0, 0) = -26;
  second(0, 1) = 255;
  second(0, 2) = -351;
  second(0, 3) = 87;
  second(0, 4) = 203;
  second(1, 0) = 221;
  second(1, 1) = 122;
  second(1, 2) = 87;
  second(1, 3) = -368;
  second(1, 4) = -354;
  second(2, 0) = 223;
  second(2, 1) = -36;
  second(2, 2) = 355;
  second(2, 3) = 0;
  second(2, 4) = 19;
  S21Matrix check(3, 5);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  S21Matrix ans;
  ans = first - second;
  EXPECT_EQ(ans.EqMatrix(check), true);
}

TEST(sub, operator_plus_correct_4) {
  S21Matrix first(3, 4);
  first(0, 0) = 125;
  first(0, 1) = 229;
  first(0, 2) = 262;
  first(0, 3) = 463;
  first(1, 0) = -291;
  first(1, 1) = -454;
  first(1, 2) = -343;
  first(1, 3) = 146;
  first(2, 0) = -56;
  first(2, 1) = 18;
  first(2, 2) = 336;
  first(2, 3) = -351;
  S21Matrix second(3, 4);
  second(0, 0) = 272;
  second(0, 1) = 447;
  second(0, 2) = 201;
  second(0, 3) = -230;
  second(1, 0) = -306;
  second(1, 1) = 88;
  second(1, 2) = 91;
  second(1, 3) = -91;
  second(2, 0) = 84;
  second(2, 1) = 161;
  second(2, 2) = -499;
  second(2, 3) = -255;
  S21Matrix check(3, 4);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      check(i, j) = first(i, j) - second(i, j);
  S21Matrix ans;
  ans = first - second;
  EXPECT_EQ(ans.EqMatrix(check), true);
}

TEST(sub, operator_plus_throw_0) {
  S21Matrix first(1, 2), second(3, 4), ans;
  EXPECT_THROW(ans = first - second, std::out_of_range);
}

TEST(sub, operator_plus_throw_1) {
  S21Matrix first(1, 2), second(2, 2), ans;
  EXPECT_THROW(ans = first - second, std::out_of_range);
}

TEST(sub, operator_plus_throw_2) {
  S21Matrix first(1, 1), second(1, 4), ans;
  EXPECT_THROW(ans = first - second, std::out_of_range);
}
