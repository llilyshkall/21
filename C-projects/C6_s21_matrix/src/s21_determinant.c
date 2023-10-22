#include <stddef.h>
#include <stdio.h>

#include "s21_matrix.h"

void print(matrix_t *A);
void s21_copy_matrix(matrix_t *A, matrix_t *B);

int s21_determinant(matrix_t *A, double *result) {
  int ret = check_matrix(A);
  if (!ret && A->columns != A->rows) ret = 2;

  if (!ret && result) {
    int i, j, sign = 1;
    matrix_t tmp;
    s21_create_matrix(A->rows, A->columns, &tmp);
    s21_copy_matrix(A, &tmp);

    for (i = 0; i < A->columns - 1; ++i) {
      int pivot = find(&tmp, i);
      if (pivot != A->columns) {
        if (swap_line(&tmp, i, pivot)) sign *= -1;
        for (j = i + 1; j < A->rows; ++j) {
          row_addition(&tmp, j, i, -tmp.matrix[j][i] / tmp.matrix[i][i]);
        }
      }
    }

    *result = sign;
    for (i = 0; i < A->rows; ++i) *result *= tmp.matrix[i][i];
    s21_remove_matrix(&tmp);
  }
  return ret;
}

// search for non-null element in column n below main diagonal
int find(matrix_t *A, int n) {
  int ret = n, i;
  for (i = n;
       i < A->rows && (A->matrix[i][n] < 1e-7 && A->matrix[i][n] > -1e-7); ++i)
    ret = i + 1;
  return ret;
}

void row_addition(matrix_t *A, int j, int i, double k) {
  for (int p = 0; p < A->columns; ++p) A->matrix[j][p] += A->matrix[i][p] * k;
  return;
}

int swap_line(matrix_t *A, int i, int j) {
  if (i != j) {
    double *tmp = A->matrix[i];
    A->matrix[i] = A->matrix[j];
    A->matrix[j] = tmp;
  }
  return i != j;
}

void s21_copy_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j <= A->columns - 1; ++j) B->matrix[i][j] = A->matrix[i][j];
}
