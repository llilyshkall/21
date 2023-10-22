#include "s21_matrix.h"

int check_matrix(matrix_t *A) {
  return !A || A->columns <= 0 || A->rows <= 0 || A->matrix == NULL;
}
