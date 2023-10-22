#include <stdlib.h>

#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  int i;
  for (i = 0; i < A->rows; ++i) free(A->matrix[i]);
  free(A->matrix);
  A->matrix = NULL;
}
