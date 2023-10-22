#include <stdio.h>

#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int ret = check_matrix(A);

  if (!ret && A->columns != A->rows) ret = 2;

  if (!ret) {
    double res;
    s21_determinant(A, &res);
    if (res < 1e-6 && res > -1e-6) {
      ret = 2;
    } else {
      if (result) {
        if (A->columns == 1) {
          s21_create_matrix(1, 1, result);
          result->matrix[0][0] = 1 / A->matrix[0][0];
        } else {
          matrix_t tmp;
          s21_calc_complements(A, &tmp);
          s21_transpose(&tmp, result);
          for (int i = 0; i < A->rows; ++i)
            for (int j = 0; j < A->columns; ++j)
              result->matrix[i][j] = result->matrix[i][j] / res;
          s21_remove_matrix(&tmp);
        }
      }
    }
  }

  return ret;
}
