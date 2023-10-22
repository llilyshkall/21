#include <stddef.h>

#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = check_matrix(A) || check_matrix(B);

  if (!ret && (A->columns != B->columns || A->rows != B->rows)) ret = 2;
  if (!ret && result) {
    int i, j;
    s21_create_matrix(A->rows, A->columns, result);
    for (i = 0; i < A->rows; ++i)
      for (j = 0; j < A->columns; ++j)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }
  return ret;
}
