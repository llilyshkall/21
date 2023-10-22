#include <stddef.h>

#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = check_matrix(A) || check_matrix(B);
  if (!ret && (A->columns != B->rows)) ret = 2;
  if (!ret && result) {
    int i, j, k;
    s21_create_matrix(A->rows, B->columns, result);
    for (i = 0; i < A->rows; ++i)
      for (j = 0; j < B->columns; ++j)
        for (k = 0; k < A->columns; ++k)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }
  return ret;
}
