#include "test_main.h"

TEST(calc_compl, incorrect_0) {
  S21Matrix check(1, 4);
  EXPECT_THROW(check.CalcComplements(), std::out_of_range);
}

TEST(calc_compl, incorrect_1) {
  S21Matrix check(5, 4);
  EXPECT_THROW(check.CalcComplements(), std::out_of_range);
}

TEST(calc_compl, incorrect_2) {
  S21Matrix check(1, 1);
  EXPECT_THROW(check.CalcComplements(), std::out_of_range);
}

TEST(calc_compl, correct_0) {
  S21Matrix check(3, 3);
  check(0, 0) = 3;
  check(0, 1) = 6;
  check(0, 2) = 2;
  check(1, 0) = -2;
  check(1, 1) = 3;
  check(1, 2) = 1;
  check(2, 0) = 1;
  check(2, 1) = 2;
  check(2, 2) = 1;
  S21Matrix ansCalc(3, 3);
  ansCalc(0, 0) = 1;
  ansCalc(0, 1) = 3;
  ansCalc(0, 2) = -7;
  ansCalc(1, 0) = -2;
  ansCalc(1, 1) = 1;
  ansCalc(1, 2) = 0;
  ansCalc(2, 0) = 0;
  ansCalc(2, 1) = -7;
  ansCalc(2, 2) = 21;
  EXPECT_EQ(check.CalcComplements() == ansCalc, true);
  S21Matrix ansInv(3, 3);
  ansInv(0, 0) = 1. / 7;
  ansInv(0, 1) = -2. / 7;
  ansInv(0, 2) = 0;
  ansInv(1, 0) = 3. / 7;
  ansInv(1, 1) = 1. / 7;
  ansInv(1, 2) = -1;
  ansInv(2, 0) = -1;
  ansInv(2, 1) = 0;
  ansInv(2, 2) = 3;
  EXPECT_EQ(check.InverseMatrix() == ansInv, true);
}

TEST(calc_compl, correct_1) {
  S21Matrix check(1, 1);
  check(0, 0) = 6;
  S21Matrix ansInv(1, 1);
  ansInv(0, 0) = 1.0 / 6;
  EXPECT_EQ(check.InverseMatrix() == ansInv, true);
}

TEST(calc_compl, correct_2) {
  S21Matrix check(2, 2);
  check(0, 0) = 3;
  check(0, 1) = 4;
  check(1, 0) = 5;
  check(1, 1) = 7;
  S21Matrix ansCalc(2, 2);
  ansCalc(0, 0) = 7;
  ansCalc(0, 1) = -5;
  ansCalc(1, 0) = -4;
  ansCalc(1, 1) = 3;
  EXPECT_EQ(check.CalcComplements() == ansCalc, true);
  S21Matrix ansInv(2, 2);
  ansInv(0, 0) = 7;
  ansInv(0, 1) = -4;
  ansInv(1, 0) = -5;
  ansInv(1, 1) = 3;
  EXPECT_EQ(check.InverseMatrix() == ansInv, true);
}

TEST(calc_compl, correct_3) {
  S21Matrix check(3, 3);
  check(0, 0) = 2;
  check(0, 1) = 5;
  check(0, 2) = 7;
  check(1, 0) = 6;
  check(1, 1) = 3;
  check(1, 2) = 4;
  check(2, 0) = 5;
  check(2, 1) = -2;
  check(2, 2) = -3;
  S21Matrix ansCalc(3, 3);
  ansCalc(0, 0) = -1;
  ansCalc(0, 1) = 38;
  ansCalc(0, 2) = -27;
  ansCalc(1, 0) = 1;
  ansCalc(1, 1) = -41;
  ansCalc(1, 2) =29;
  ansCalc(2, 0) = -1;
  ansCalc(2, 1) = 34;
  ansCalc(2, 2) = -24;
  EXPECT_EQ(check.CalcComplements() == ansCalc, true);
  S21Matrix ansInv(3, 3);
  ansInv(0, 0) = 1;
  ansInv(0, 1) = -1;
  ansInv(0, 2) = 1;
  ansInv(1, 0) = -38;
  ansInv(1, 1) = 41;
  ansInv(1, 2) = -34;
  ansInv(2, 0) = 27;
  ansInv(2, 1) = -29;
  ansInv(2, 2) = 24;
  EXPECT_EQ(check.InverseMatrix() == ansInv, true);
}

TEST(calc_compl, correct_4) {
  S21Matrix check(4, 4);
  check(0, 0) = 2;
  check(0, 1) = 1;
  check(0, 2) = 0;
  check(0, 3) = 0;
  check(1, 0) = 3;
  check(1, 1) = 2;
  check(1, 2) = 0;
  check(1, 3) = 0;
  check(2, 0) = 1;
  check(2, 1) = 1;
  check(2, 2) = 3;
  check(2, 3) = 4;
  check(3, 0) = 2;
  check(3, 1) = -1;
  check(3, 2) = 2;
  check(3, 3) = 3;
  S21Matrix ansCalc(4, 4);
  ansCalc(0, 0) = 2;
  ansCalc(0, 1) = -3;
  ansCalc(0, 2) = 31;
  ansCalc(0, 3) = -23;
  ansCalc(1, 0) = -1;
  ansCalc(1, 1) = 2;
  ansCalc(1, 2) = -19;
  ansCalc(1, 3) = 14;
  ansCalc(2, 0) = 0;
  ansCalc(2, 1) = 0;
  ansCalc(2, 2) = 3;
  ansCalc(2, 3) = -2;
  ansCalc(3, 0) = 0;
  ansCalc(3, 1) = 0;
  ansCalc(3, 2) = -4;
  ansCalc(3, 3) = 3;
  EXPECT_EQ(check.CalcComplements() == ansCalc, true);
  S21Matrix ansInv(4, 4);
  ansInv(0, 0) = 2;
  ansInv(0, 1) = -1;
  ansInv(0, 2) = 0;
  ansInv(0, 3) = 0;
  ansInv(1, 0) = -3;
  ansInv(1, 1) = 2;
  ansInv(1, 2) = 0;
  ansInv(1, 3) = 0;
  ansInv(2, 0) = 31;
  ansInv(2, 1) = -19;
  ansInv(2, 2) = 3;
  ansInv(2, 3) = -4;
  ansInv(3, 0) = -23;
  ansInv(3, 1) = 14;
  ansInv(3, 2) = -2;
  ansInv(3, 3) = 3;
  EXPECT_EQ(check.InverseMatrix() == ansInv, true);
}
