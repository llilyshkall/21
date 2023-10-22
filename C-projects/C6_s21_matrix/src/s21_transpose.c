#include <stddef.h>

#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int ret = check_matrix(A);

  if (!ret && result) {
    int i, j;
    s21_create_matrix(A->columns, A->rows, result);
    for (i = 0; i < A->rows; ++i)
      for (j = 0; j < A->columns; ++j) result->matrix[j][i] = A->matrix[i][j];
  }
  return ret;
}
