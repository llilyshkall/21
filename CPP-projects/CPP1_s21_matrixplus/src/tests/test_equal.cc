#include "test_main.h"

TEST(equal, equal_matrix_0) {
  S21Matrix first(3, 2);
  first(0, 0) = 403;
  first(0, 1) = 471;
  first(1, 0) = 367;
  first(1, 1) = -14;
  first(2, 0) = -425;
  first(2, 1) = 61;
  S21Matrix second(first);
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(equal, equal_matrix_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -238;
  first(1, 0) = 355;
  S21Matrix second(2, 1);
  second(0, 0) = -238;
  second(1, 0) = 355;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(equal, equal_matrix_2) {
  S21Matrix first(3, 4);
  first(0, 0) = -192;
  first(0, 1) = 166;
  first(0, 2) = 205;
  first(0, 3) = -221;
  first(1, 0) = 434;
  first(1, 1) = 428;
  first(1, 2) = -145;
  first(1, 3) = -482;
  first(2, 0) = -485;
  first(2, 1) = 245;
  first(2, 2) = -389;
  first(2, 3) = 174;
  S21Matrix second(3, 4);
  second(0, 0) = -192;
  second(0, 1) = 166;
  second(0, 2) = 205;
  second(0, 3) = -221;
  second(1, 0) = 434;
  second(1, 1) = 428;
  second(1, 2) = -145;
  second(1, 3) = -482;
  second(2, 0) = -485;
  second(2, 1) = 245;
  second(2, 2) = -389;
  second(2, 3) = 174;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(equal, equal_matrix_3) {
  S21Matrix first(5, 2);
  first(0, 0) = -41;
  first(0, 1) = 262;
  first(1, 0) = 180;
  first(1, 1) = 48;
  first(2, 0) = -142;
  first(2, 1) = 149;
  first(3, 0) = 418;
  first(3, 1) = 78;
  first(4, 0) = -127;
  first(4, 1) = 242;
  S21Matrix second(5, 2);
  second(0, 0) = -41;
  second(0, 1) = 262;
  second(1, 0) = 180;
  second(1, 1) = 48;
  second(2, 0) = -142;
  second(2, 1) = 149;
  second(3, 0) = 418;
  second(3, 1) = 78;
  second(4, 0) = -127;
  second(4, 1) = 242;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(equal, equal_matrix_4) {
  S21Matrix first(2, 3);
  first(0, 0) = 49;
  first(0, 1) = -274;
  first(0, 2) = -498;
  first(1, 0) = -391;
  first(1, 1) = -401;
  first(1, 2) = -257;
  S21Matrix second(2, 3);
  second(0, 0) = 49;
  second(0, 1) = -274;
  second(0, 2) = -498;
  second(1, 0) = -391;
  second(1, 1) = -401;
  second(1, 2) = -257;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(equal, not_equal_matrix_0) {
  S21Matrix first(3, 2);
  first(0, 0) = 403;
  first(0, 1) = 471;
  first(1, 0) = 367;
  first(1, 1) = -14;
  first(2, 0) = -425;
  first(2, 1) = 61;
  S21Matrix second(3, 2);
  second(0, 0) = 403;
  second(0, 1) = 47;
  second(1, 0) = 367;
  second(1, 1) = -14;
  second(2, 0) = -425;
  second(2, 1) = 61;
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_matrix_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -238;
  first(1, 0) = 355;
  S21Matrix second(2, 1);
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_matrix_2) {
  S21Matrix first(3, 4);
  first(0, 0) = -192;
  first(0, 1) = 166;
  first(0, 2) = 205;
  first(0, 3) = -221;
  first(1, 0) = 434;
  first(1, 1) = 428;
  first(1, 2) = -145;
  first(1, 3) = -482;
  first(2, 0) = -485;
  first(2, 1) = 245;
  first(2, 2) = -389;
  first(2, 3) = 174;
  S21Matrix second(3, 4);
  second(0, 0) = -192;
  second(0, 1) = 166;
  second(0, 2) = 0;
  second(0, 3) = -221;
  second(1, 0) = 434;
  second(1, 1) = 428;
  second(1, 2) = -145;
  second(1, 3) = -482;
  second(2, 0) = -485;
  second(2, 1) = 245;
  second(2, 2) = -389;
  second(2, 3) = 174;
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_matrix_3) {
  S21Matrix first(5, 2);
  first(0, 0) = -41;
  first(0, 1) = 262;
  first(1, 0) = 180;
  first(1, 1) = 48;
  first(2, 0) = -142;
  first(2, 1) = 149;
  first(3, 0) = 418;
  first(3, 1) = 78;
  first(4, 0) = -127;
  first(4, 1) = 242;
  S21Matrix second(5, 2);
  second(0, 0) = -41;
  second(0, 1) = 262;
  second(1, 0) = 180;
  second(1, 1) = 48;
  second(2, 0) = -142;
  second(2, 1) = 149;
  second(3, 0) = 418;
  second(3, 1) = 0;
  second(4, 0) = -127;
  second(4, 1) = 242;
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_matrix_4) {
  S21Matrix first(2, 3);
  first(0, 0) = 49;
  first(0, 1) = -274;
  first(0, 2) = -498;
  first(1, 0) = -391;
  first(1, 1) = -401;
  first(1, 2) = -257;
  S21Matrix second(2, 3);
  second(0, 0) = 32;
  second(0, 1) = 184;
  second(0, 2) = 247;
  second(1, 0) = 2753;
  second(1, 1) = -42;
  second(1, 2) = 239;
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_5) {
  S21Matrix first(2, 3);
  S21Matrix second(3, 2);
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_6) {
  S21Matrix first(2, 3);
  S21Matrix second;
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, not_equal_7) {
  S21Matrix first(2, 3);
  S21Matrix second(30, 2);
  EXPECT_EQ(first.EqMatrix(second), false);
}

TEST(equal, operator_equal_matrix_0) {
  S21Matrix first(3, 2);
  first(0, 0) = 403;
  first(0, 1) = 471;
  first(1, 0) = 367;
  first(1, 1) = -14;
  first(2, 0) = -425;
  first(2, 1) = 61;
  S21Matrix second(first);
  EXPECT_EQ(first == second, true);
}

TEST(equal, operator_equal_matrix_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -238;
  first(1, 0) = 355;
  S21Matrix second(2, 1);
  second(0, 0) = -238;
  second(1, 0) = 355;
  EXPECT_EQ(first == second, true);
}

TEST(equal, operator_equal_matrix_2) {
  S21Matrix first(3, 4);
  first(0, 0) = -192;
  first(0, 1) = 166;
  first(0, 2) = 205;
  first(0, 3) = -221;
  first(1, 0) = 434;
  first(1, 1) = 428;
  first(1, 2) = -145;
  first(1, 3) = -482;
  first(2, 0) = -485;
  first(2, 1) = 245;
  first(2, 2) = -389;
  first(2, 3) = 174;
  S21Matrix second(3, 4);
  second(0, 0) = -192;
  second(0, 1) = 166;
  second(0, 2) = 205;
  second(0, 3) = -221;
  second(1, 0) = 434;
  second(1, 1) = 428;
  second(1, 2) = -145;
  second(1, 3) = -482;
  second(2, 0) = -485;
  second(2, 1) = 245;
  second(2, 2) = -389;
  second(2, 3) = 174;
  EXPECT_EQ(first == second, true);
}

TEST(equal, operator_equal_matrix_3) {
  S21Matrix first(5, 2);
  first(0, 0) = -41;
  first(0, 1) = 262;
  first(1, 0) = 180;
  first(1, 1) = 48;
  first(2, 0) = -142;
  first(2, 1) = 149;
  first(3, 0) = 418;
  first(3, 1) = 78;
  first(4, 0) = -127;
  first(4, 1) = 242;
  S21Matrix second(5, 2);
  second(0, 0) = -41;
  second(0, 1) = 262;
  second(1, 0) = 180;
  second(1, 1) = 48;
  second(2, 0) = -142;
  second(2, 1) = 149;
  second(3, 0) = 418;
  second(3, 1) = 78;
  second(4, 0) = -127;
  second(4, 1) = 242;
  EXPECT_EQ(first == second, true);
}

TEST(equal, operator_equal_matrix_4) {
  S21Matrix first(2, 3);
  first(0, 0) = 49;
  first(0, 1) = -274;
  first(0, 2) = -498;
  first(1, 0) = -391;
  first(1, 1) = -401;
  first(1, 2) = -257;
  S21Matrix second(2, 3);
  second(0, 0) = 49;
  second(0, 1) = -274;
  second(0, 2) = -498;
  second(1, 0) = -391;
  second(1, 1) = -401;
  second(1, 2) = -257;
  EXPECT_EQ(first == second, true);
}

TEST(equal, not_operator_equal_matrix_0) {
  S21Matrix first(3, 2);
  first(0, 0) = 403;
  first(0, 1) = 471;
  first(1, 0) = 367;
  first(1, 1) = -14;
  first(2, 0) = -425;
  first(2, 1) = 61;
  S21Matrix second(3, 2);
  second(0, 0) = 403;
  second(0, 1) = 47;
  second(1, 0) = 367;
  second(1, 1) = -14;
  second(2, 0) = -425;
  second(2, 1) = 61;
  EXPECT_EQ(first == second, false);
}

TEST(equal, not_operator_equal_matrix_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -238;
  first(1, 0) = 355;
  S21Matrix second(2, 1);
  EXPECT_EQ(first == second, false);
}

TEST(equal, not_operator_equal_matrix_2) {
  S21Matrix first(3, 4);
  first(0, 0) = -192;
  first(0, 1) = 166;
  first(0, 2) = 205;
  first(0, 3) = -221;
  first(1, 0) = 434;
  first(1, 1) = 428;
  first(1, 2) = -145;
  first(1, 3) = -482;
  first(2, 0) = -485;
  first(2, 1) = 245;
  first(2, 2) = -389;
  first(2, 3) = 174;
  S21Matrix second(3, 4);
  second(0, 0) = -192;
  second(0, 1) = 166;
  second(0, 2) = 0;
  second(0, 3) = -221;
  second(1, 0) = 434;
  second(1, 1) = 428;
  second(1, 2) = -145;
  second(1, 3) = -482;
  second(2, 0) = -485;
  second(2, 1) = 245;
  second(2, 2) = -389;
  second(2, 3) = 174;
  EXPECT_EQ(first == second, false);
}

TEST(equal, not_operator_equal_matrix_3) {
  S21Matrix first(5, 2);
  first(0, 0) = -41;
  first(0, 1) = 262;
  first(1, 0) = 180;
  first(1, 1) = 48;
  first(2, 0) = -142;
  first(2, 1) = 149;
  first(3, 0) = 418;
  first(3, 1) = 78;
  first(4, 0) = -127;
  first(4, 1) = 242;
  S21Matrix second(5, 2);
  second(0, 0) = -41;
  second(0, 1) = 262;
  second(1, 0) = 180;
  second(1, 1) = 48;
  second(2, 0) = -142;
  second(2, 1) = 149;
  second(3, 0) = 418;
  second(3, 1) = 0;
  second(4, 0) = -127;
  second(4, 1) = 242;
  EXPECT_EQ(first == second, false);
}

TEST(equal, not_operator_equal_matrix_4) {
  S21Matrix first(2, 3);
  first(0, 0) = 49;
  first(0, 1) = -274;
  first(0, 2) = -498;
  first(1, 0) = -391;
  first(1, 1) = -401;
  first(1, 2) = -257;
  S21Matrix second(2, 3);
  second(0, 0) = 32;
  second(0, 1) = 184;
  second(0, 2) = 247;
  second(1, 0) = 2753;
  second(1, 1) = -42;
  second(1, 2) = 239;
  EXPECT_EQ(first == second, false);
}
