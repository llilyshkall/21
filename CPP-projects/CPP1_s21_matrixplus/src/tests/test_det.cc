#include "test_main.h"

TEST(det, incorrect_0) {
  S21Matrix check(1, 2);
  EXPECT_THROW(check.Determinant(), std::out_of_range);
}

TEST(det, incorrect_1) {
  S21Matrix check(3, 2);
  EXPECT_THROW(check.Determinant(), std::out_of_range);
}

TEST(det, incorrect_2) {
  S21Matrix check(35, 23);
  EXPECT_THROW(check.Determinant(), std::out_of_range);
}

TEST(det, correct_0) {
  S21Matrix check;
  EXPECT_EQ(check.Determinant(), 0);
}

TEST(det, correct_1) {
  S21Matrix check(2, 2);
  check(0, 0) = 3;
  check(0, 1) = 2;
  check(1, 0) = 8;
  check(1, 1) = 5;
  EXPECT_NEAR(check.Determinant(), -1.0, 1e-6);
}

TEST(det, correct_2) {
  S21Matrix check(4, 4);
  check(0, 0) = 0;
  check(0, 1) = 0;
  check(0, 2) = 8;
  check(0, 3) = 4;
  check(1, 0) = 0;
  check(1, 1) = 0;
  check(1, 2) = 6;
  check(1, 3) = 3;
  check(2, 0) = 8;
  check(2, 1) = 6;
  check(2, 2) = 4;
  check(2, 3) = 2;
  check(3, 0) = 4;
  check(3, 1) = 3;
  check(3, 2) = 2;
  check(3, 3) = 1;
  EXPECT_NEAR(check.Determinant(), 0, 1e-6);
}

TEST(det, correct_3) {
  S21Matrix check(4, 4);
  check(0, 0) = 13;
  check(0, 1) = 37;
  check(0, 2) = 23;
  check(0, 3) = 4;
  check(1, 0) = 0;
  check(1, 1) = 11;
  check(1, 2) = 9;
  check(1, 3) = 0;
  check(2, 0) = 11;
  check(2, 1) = 41;
  check(2, 2) = 73;
  check(2, 3) = 3;
  check(3, 0) = 0;
  check(3, 1) = 9;
  check(3, 2) = 11;
  check(3, 3) = 0;
  EXPECT_NEAR(check.Determinant(), 200, 1e-6);
}

TEST(det, correct_4) {
  S21Matrix check(6, 6);
  check(0, 0) = 1;
  check(0, 1) = 2;
  check(0, 2) = 0;
  check(0, 3) = 0;
  check(0, 4) = 0;
  check(0, 5) = 0;
  check(1, 0) = 3;
  check(1, 1) = 4;
  check(1, 2) = 0;
  check(1, 3) = 0;
  check(1, 4) = 0;
  check(1, 5) = 0;
  check(2, 0) = 7;
  check(2, 1) = 6;
  check(2, 2) = 5;
  check(2, 3) = 4;
  check(2, 4) = 0;
  check(2, 5) = 0;
  check(3, 0) = 2;
  check(3, 1) = 3;
  check(3, 2) = 4;
  check(3, 3) = 5;
  check(3, 4) = 0;
  check(3, 5) = 0;
  check(4, 0) = 5;
  check(4, 1) = 1;
  check(4, 2) = 2;
  check(4, 3) = 6;
  check(4, 4) = 7;
  check(4, 5) = 3;
  check(5, 0) = 2;
  check(5, 1) = 7;
  check(5, 2) = 5;
  check(5, 3) = 3;
  check(5, 4) = 4;
  check(5, 5) = 1;
  EXPECT_NEAR(check.Determinant(), 90, 1e-6);
}

TEST(det, correct_5) {
  S21Matrix check(4, 4);
  check(0, 0) = 1;
  check(0, 1) = 3;
  check(0, 2) = 5;
  check(0, 3) = 7;
  check(1, 0) = 2;
  check(1, 1) = 4;
  check(1, 2) = 6;
  check(1, 3) = 8;
  check(2, 0) = 3;
  check(2, 1) = 5;
  check(2, 2) = 7;
  check(2, 3) = 9;
  check(3, 0) = 65;
  check(3, 1) = 74;
  check(3, 2) = 83;
  check(3, 3) = 92;
  EXPECT_NEAR(check.Determinant(), 0, 1e-6);
}
