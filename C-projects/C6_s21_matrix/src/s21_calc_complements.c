#include "s21_matrix.h"

void add_minor(matrix_t *A, matrix_t *B, int n, int m);

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = check_matrix(A);
  if (!ret && (A->columns != A->rows || A->columns == 1)) ret = 2;

  if (!ret) {
    matrix_t tmp;
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        double res;
        add_minor(A, &tmp, i, j);
        s21_determinant(&tmp, &res);
        result->matrix[i][j] = res * ((i + j) % 2 == 0 ? 1 : -1);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return 0;
}

void add_minor(matrix_t *A, matrix_t *B, int n, int m) {
  for (int i = 0; i < A->rows - 1; ++i)
    for (int j = 0; j < A->columns - 1; ++j)
      B->matrix[i][j] = A->matrix[i < n ? i : i + 1][j < m ? j : j + 1];
}
