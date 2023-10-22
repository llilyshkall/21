#include <stddef.h>

#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = check_matrix(A);

  if (!ret && result) {
    int i, j;
    s21_create_matrix(A->rows, A->columns, result);
    for (i = 0; i < A->rows; ++i)
      for (j = 0; j < A->columns; ++j)
        result->matrix[i][j] = A->matrix[i][j] * number;
  }
  return ret;
}
