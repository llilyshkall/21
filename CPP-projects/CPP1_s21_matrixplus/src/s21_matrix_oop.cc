#include "s21_matrix_oop.h"

void S21Matrix::clearMatrix_() noexcept {
  for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
  delete[] matrix_;
}

void S21Matrix::initMatrix_(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = 0.0;
  }
}

S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::out_of_range("The value is <= 0");
  } else {
    initMatrix_(rows, cols);
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.initMatrix_(1, 1);
}

S21Matrix::~S21Matrix() noexcept { clearMatrix_(); }

void S21Matrix::setRows(int rows) {
  if (rows <= 0) throw std::out_of_range("The value is <= 0");
  if (rows != rows_) {
    S21Matrix copy(rows, cols_);
    int res_rows = rows_ < rows ? rows_ : rows;
    for (int i = 0; i < res_rows; ++i) {
      for (int j = 0; j < cols_; ++j) {
        copy.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(copy);
  }
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0) throw std::out_of_range("The value is <= 0");
  if (cols != cols_) {
    S21Matrix copy(rows_, cols);
    int res_cols = cols_ < cols ? cols_ : cols;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < res_cols; ++j) {
        copy.matrix_[i][j] = matrix_[i][j];
      }
    }

    *this = std::move(copy);
  }
}

int S21Matrix::getRows() const noexcept { return rows_; }

int S21Matrix::getCols() const noexcept { return cols_; }

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool ret = rows_ == other.rows_ && cols_ == other.cols_;
  for (int i = 0; i < rows_ && ret; ++i) {
    for (int j = 0; j < cols_ && ret; ++j) {
      ret = std::abs(matrix_[i][j] - other.matrix_[i][j]) < 1e-6;
    }
  }
  return ret;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::out_of_range("Different matrix dimensions");

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::out_of_range("Different matrix dimensions");

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::out_of_range("The number of columns is not equal");

  S21Matrix tmp(rows_, other.cols_);

  for (int i = 0; i < tmp.rows_; ++i) {
    for (int j = 0; j < tmp.cols_; ++j) {
      for (int k = 0; k < other.rows_; ++k) {
        tmp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(tmp);
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix ret(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      ret.matrix_[j][i] = matrix_[i][j];
    }
  }
  return ret;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (cols_ != rows_) throw std::out_of_range("The matrix is not square");
  if (cols_ == 1) throw std::out_of_range("The matrix is 1 - 1");

  S21Matrix tmp(rows_ - 1, cols_ - 1), result(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      findMinor_(tmp, i, j);
      double res = tmp.Determinant();
      result.matrix_[i][j] = res * ((i + j) % 2 == 0 ? 1 : -1);
    }
  }

  return result;
}

void S21Matrix::findMinor_(S21Matrix& tmp, int n, int m) const {
  for (int i = 0; i < rows_ - 1; ++i)
    for (int j = 0; j < cols_ - 1; ++j)
      tmp.matrix_[i][j] = matrix_[i < n ? i : i + 1][j < m ? j : j + 1];
}

double S21Matrix::Determinant() const {
  if (cols_ != rows_) throw std::out_of_range("The matrix is not square");
  S21Matrix tmp = *this;
  double res = 1;
  for (int i = 0; i < cols_; ++i) {
    int pivot = tmp.find_(i);
    if (pivot != cols_) {
      if (i != pivot) {
        tmp.swapLine_(i, pivot);
        res *= -1;
      }
      for (int j = i + 1; j < rows_; ++j) {
        tmp.rowAdd_(j, i, -tmp.matrix_[j][i] / tmp.matrix_[i][i]);
      }
    }
  }
  for (int i = 0; i < rows_; ++i) res *= tmp.matrix_[i][i];
  return res;
}

int S21Matrix::find_(int index) const noexcept {
  int ret = index;
  for (int i = index; i < rows_ && abs(this->matrix_[i][index]) < 1e-6; ++i)
    ret = i + 1;
  return ret;
}

void S21Matrix::swapLine_(int i, int j) noexcept {
  double* tmp = matrix_[i];
  matrix_[i] = matrix_[j];
  matrix_[j] = tmp;
}

void S21Matrix::rowAdd_(int j, int i, double num) {
  for (int p = 0; p < cols_; ++p) matrix_[j][p] += matrix_[i][p] * num;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double det = Determinant();
  if (std::abs(det) < 1e-6) throw std::out_of_range("matrix determinant is 0");

  S21Matrix inv(rows_, cols_);
  if (cols_ == 1)
    inv.matrix_[0][0] = 1.0;
  else
    inv = CalcComplements().Transpose();
  inv.MulNumber(1.0 / det);

  return inv;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix sum(*this);
  sum.SumMatrix(other);
  return sum;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix sub(*this);
  sub.SubMatrix(other);
  return sub;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix mul(*this);
  mul.MulNumber(num);
  return mul;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix mul(*this);
  mul.MulMatrix(other);
  return mul;
}

bool S21Matrix::operator==(const S21Matrix& other) const noexcept {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    clearMatrix_();
    initMatrix_(other.rows_, other.cols_);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    clearMatrix_();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;

    other.initMatrix_(1, 1);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0) throw std::out_of_range("The number of row is less than 0");
  if (col < 0) throw std::out_of_range("The number of col is less than 0");
  if (row >= rows_)
    throw std::out_of_range("The number of row is greater than rows_");
  if (col >= cols_)
    throw std::out_of_range("The number of col is greater than cols_");
  return matrix_[row][col];
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0) throw std::out_of_range("The number of row is less than 0");
  if (col < 0) throw std::out_of_range("The number of col is less than 0");
  if (row >= rows_)
    throw std::out_of_range("The number of row is greater than rows_");
  if (col >= cols_)
    throw std::out_of_range("The number of col is greater than cols_");
  return matrix_[row][col];
}

S21Matrix operator*(const double num, const S21Matrix& other) {
  return other * num;
}
