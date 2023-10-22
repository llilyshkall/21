#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;

  void setRows(int rows);
  void setCols(int cols);
  int getRows() const noexcept;
  int getCols() const noexcept;

  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  S21Matrix operator*(const S21Matrix& other) const;
  bool operator==(const S21Matrix& other) const noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  double operator()(int row, int col) const;
  double& operator()(int row, int col);

 private:
  int rows_, cols_;
  double** matrix_;
  void clearMatrix_() noexcept;
  void initMatrix_(int rows, int cols);
  void findMinor_(S21Matrix& tmp, int n, int m) const;
  int find_(int index) const noexcept;
  void swapLine_(int i, int j) noexcept;
  void rowAdd_(int j, int i, double num);
};

S21Matrix operator*(const double num, const S21Matrix& other);

#endif  // CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H_
