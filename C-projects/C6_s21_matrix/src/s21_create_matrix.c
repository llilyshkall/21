#include <stdlib.h>

#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ret = 0;
  if (rows <= 0 || columns <= 0) ret = 1;
  if (!ret) {
    int i, j;
    result->rows = rows;
    result->columns = columns;
    result->matrix = malloc(sizeof(double **) * rows);
    for (i = 0; i < rows; ++i) {
      result->matrix[i] = malloc(sizeof(double) * columns);
      for (j = 0; j < columns; ++j) result->matrix[i][j] = 0;
    }
  }
  return ret;
}
