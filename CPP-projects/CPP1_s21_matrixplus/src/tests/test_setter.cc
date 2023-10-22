#include "test_main.h"

TEST(setter, column_0) {
  S21Matrix check;
  EXPECT_THROW(check.setCols(0), std::out_of_range);
}

TEST(setter, column_1) {
  S21Matrix check;
  EXPECT_THROW(check.setCols(-15), std::out_of_range);
}

TEST(setter, column_2) {
  S21Matrix check;
  EXPECT_THROW(check.setCols(-34), std::out_of_range);
}

TEST(setter, column_3) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setCols(4));
  EXPECT_EQ(check.getCols(), 4);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_4) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setCols(23));
  EXPECT_EQ(check.getCols(), 23);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_5) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setCols(1));
  EXPECT_EQ(check.getCols(), 1);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_6) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setCols(3));
  EXPECT_EQ(check.getCols(), 3);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_7) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setCols(30));
  EXPECT_EQ(check.getCols(), 30);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_8) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setCols(24));
  EXPECT_EQ(check.getCols(), 24);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_9) {
  S21Matrix check;
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) check(i, j) = i + j;
  EXPECT_NO_THROW(check.setCols(24));
  EXPECT_EQ(check.getCols(), 24);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      if (i < 3 && j < 3)
        EXPECT_EQ(check(i, j), i + j);
      else
        EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_10) {
  S21Matrix check;
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) check(i, j) = 9;
  EXPECT_NO_THROW(check.setCols(24));
  EXPECT_EQ(check.getCols(), 24);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      if (i < 3 && j < 3)
        EXPECT_EQ(check(i, j), 9);
      else
        EXPECT_EQ(check(i, j), 0);
}

TEST(setter, column_11) {
  S21Matrix check;
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) check(i, j) = 9;
  EXPECT_NO_THROW(check.setCols(2));
  EXPECT_EQ(check.getCols(), 2);
  EXPECT_EQ(check.getRows(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      if (i < 3 && j < 3)
        EXPECT_EQ(check(i, j), 9);
      else
        EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_0) {
  S21Matrix check;
  EXPECT_THROW(check.setRows(0), std::out_of_range);
}

TEST(setter, row_1) {
  S21Matrix check;
  EXPECT_THROW(check.setRows(-15), std::out_of_range);
}

TEST(setter, row_2) {
  S21Matrix check;
  EXPECT_THROW(check.setRows(-34), std::out_of_range);
}

TEST(setter, row_3) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setRows(4));
  EXPECT_EQ(check.getRows(), 4);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_4) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setRows(23));
  EXPECT_EQ(check.getRows(), 23);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_5) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setRows(1));
  EXPECT_EQ(check.getRows(), 1);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_6) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setRows(3));
  EXPECT_EQ(check.getRows(), 3);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_7) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setRows(30));
  EXPECT_EQ(check.getRows(), 30);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_8) {
  S21Matrix check;
  EXPECT_NO_THROW(check.setRows(24));
  EXPECT_EQ(check.getRows(), 24);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_9) {
  S21Matrix check;
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) check(i, j) = i + j;
  EXPECT_NO_THROW(check.setRows(24));
  EXPECT_EQ(check.getRows(), 24);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      if (i < 3 && j < 3)
        EXPECT_EQ(check(i, j), i + j);
      else
        EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_10) {
  S21Matrix check;
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) check(i, j) = 9;
  EXPECT_NO_THROW(check.setRows(24));
  EXPECT_EQ(check.getRows(), 24);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      if (i < 3 && j < 3)
        EXPECT_EQ(check(i, j), 9);
      else
        EXPECT_EQ(check(i, j), 0);
}

TEST(setter, row_11) {
  S21Matrix check;
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j) check(i, j) = 9;
  EXPECT_NO_THROW(check.setRows(2));
  EXPECT_EQ(check.getRows(), 2);
  EXPECT_EQ(check.getCols(), 3);
  for (int i = 0; i < check.getRows(); ++i)
    for (int j = 0; j < check.getCols(); ++j)
      if (i < 3 && j < 3)
        EXPECT_EQ(check(i, j), 9);
      else
        EXPECT_EQ(check(i, j), 0);
}
