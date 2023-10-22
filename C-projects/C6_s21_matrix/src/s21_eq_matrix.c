#include <math.h>
#include <stddef.h>

#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (!A || !B || A->columns != B->columns || A->rows != B->rows ||
      A->columns <= 0 || A->rows <= 0 || A->matrix == NULL || B->matrix == NULL)
    ret = FAILURE;

  if (ret) {
    int i, j;
    for (i = 0; i < A->rows && ret; ++i)
      for (j = 0; j < A->columns && ret; ++j)
        ret = !(fabsl(A->matrix[i][j] - B->matrix[i][j]) > 1e-7);
  }
  return ret;
}
