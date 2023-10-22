#include "test_main.h"

TEST(assigment, assigment_matrix_0) {
  S21Matrix first(3, 2);
  first(0, 0) = 403;
  first(0, 1) = 471;
  first(1, 0) = 367;
  first(1, 1) = -14;
  first(2, 0) = -425;
  first(2, 1) = 61;
  S21Matrix second;
  second = first;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(assigment, assigment_matrix_1) {
  S21Matrix first(2, 1);
  first(0, 0) = -238;
  first(1, 0) = 355;
  S21Matrix second(2, 1);
  second = first;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(assigment, assigment_matrix_2) {
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
  S21Matrix second(4, 3);
  second = first;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(assigment, assigment_matrix_3) {
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
  S21Matrix second(50, 20);
  second = first;
  EXPECT_EQ(first.EqMatrix(second), true);
}

TEST(assigment, assigment_matrix_4) {
  S21Matrix first(2, 3);
  first(0, 0) = 49;
  first(0, 1) = -274;
  first(0, 2) = -498;
  first(1, 0) = -391;
  first(1, 1) = -401;
  first(1, 2) = -257;
  S21Matrix second(1, 1);
  second = first;
  EXPECT_EQ(first.EqMatrix(second), true);
}
