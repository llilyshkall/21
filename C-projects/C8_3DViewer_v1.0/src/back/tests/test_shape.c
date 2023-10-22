#include "test_me.h"

START_TEST(test_shape_1) {
  int ret = 0;
  ck_assert_int_eq(initShape(NULL, NULL), ret);
}
END_TEST

START_TEST(test_shape_2) {
  int ret = 0;
  Shape shape;
  ck_assert_int_eq(initShape(&shape, NULL), ret);
}
END_TEST

START_TEST(test_shape_3) {
  int ret = 0;
  ck_assert_int_eq(initShape(NULL, "back/shape.c"), ret);
}
END_TEST

START_TEST(test_shape_4) {
  int ret = 1;
  Shape shape;
  ck_assert_int_eq(initShape(&shape, "../data-samples/cube.obj"), ret);

  int countLines = 72, countVertexes = 24;
  unsigned lines[] = {1, 2, 2, 3, 3, 1, 3, 2, 2, 4, 4, 3, 3, 4, 4, 5, 5, 3,
                      5, 4, 4, 6, 6, 5, 5, 6, 6, 7, 7, 5, 7, 6, 6, 8, 8, 7,
                      7, 8, 8, 1, 1, 7, 1, 8, 8, 2, 2, 1, 2, 8, 8, 4, 4, 2,
                      4, 8, 8, 6, 6, 4, 7, 1, 1, 5, 5, 7, 5, 1, 1, 3, 3, 5};
  for (int i = 0; i < countLines; ++i) lines[i]--;
  double vertexes[] = {-0.800000, -0.800000, -1.200000, 0.800000,  -0.800000,
                       -1.200000, -0.800000, 0.800000,  -1.200000, 0.800000,
                       0.800000,  -1.200000, -0.800000, 0.800000,  -2.800000,
                       0.800000,  0.800000,  -2.800000, -0.800000, -0.800000,
                       -2.800000, 0.800000,  -0.800000, -2.800000};
  double scale = 1;
  double dAngles[3] = {0, 0, 0};
  rotation(&shape, dAngles);

  ck_assert_int_eq(countLines, shape.countLines);
  ck_assert_int_eq(countVertexes, shape.countVertexes);
  ck_assert_int_eq(scale, shape.scale);
  for (int i = 0; i < countLines; ++i)
    ck_assert_uint_eq(shape.lines[i], lines[i]);
  for (int i = 0; i < countVertexes; ++i)
    ck_assert_double_eq_tol(shape.vertexes[i], vertexes[i], 1e-6);
  clearShape(&shape);
}
END_TEST

START_TEST(test_shape_5) {
  int ret = 1;
  Shape shape;
  ck_assert_int_eq(initShape(&shape, "../data-samples/cube.obj"), ret);

  int countLines = 72, countVertexes = 24;
  unsigned lines[] = {1, 2, 2, 3, 3, 1, 3, 2, 2, 4, 4, 3, 3, 4, 4, 5, 5, 3,
                      5, 4, 4, 6, 6, 5, 5, 6, 6, 7, 7, 5, 7, 6, 6, 8, 8, 7,
                      7, 8, 8, 1, 1, 7, 1, 8, 8, 2, 2, 1, 2, 8, 8, 4, 4, 2,
                      4, 8, 8, 6, 6, 4, 7, 1, 1, 5, 5, 7, 5, 1, 1, 3, 3, 5};
  for (int i = 0; i < countLines; ++i) lines[i]--;
  double vertexes[] = {-1.600000, -1.600000, -0.400000, 1.600000,  -1.600000,
                       -0.400000, -1.600000, 1.600000,  -0.400000, 1.600000,
                       1.600000,  -0.400000, -1.600000, 1.600000,  -3.600000,
                       1.600000,  1.600000,  -3.600000, -1.600000, -1.600000,
                       -3.600000, 1.600000,  -1.600000, -3.600000};
  double scale = 1;

  ck_assert_int_eq(countLines, shape.countLines);
  ck_assert_int_eq(countVertexes, shape.countVertexes);
  ck_assert_int_eq(scale, shape.scale);
  setScale(&shape, 2);
  for (int i = 0; i < countLines; ++i)
    ck_assert_uint_eq(shape.lines[i], lines[i]);
  for (int i = 0; i < countVertexes; ++i)
    ck_assert_double_eq_tol(shape.vertexes[i], vertexes[i], 1e-6);
  clearShape(&shape);
}
END_TEST

START_TEST(test_shape_6) {
  int ret = 1;
  Shape shape;
  ck_assert_int_eq(initShape(&shape, "../data-samples/cube.obj"), ret);

  int countLines = 72, countVertexes = 24;
  unsigned lines[] = {1, 2, 2, 3, 3, 1, 3, 2, 2, 4, 4, 3, 3, 4, 4, 5, 5, 3,
                      5, 4, 4, 6, 6, 5, 5, 6, 6, 7, 7, 5, 7, 6, 6, 8, 8, 7,
                      7, 8, 8, 1, 1, 7, 1, 8, 8, 2, 2, 1, 2, 8, 8, 4, 4, 2,
                      4, 8, 8, 6, 6, 4, 7, 1, 1, 5, 5, 7, 5, 1, 1, 3, 3, 5};
  for (int i = 0; i < countLines; ++i) lines[i]--;
  double vertexes[] = {-0.755548, -0.843826, -1.201811, 0.843250,  -0.798781,
                       -1.244436, -0.799391, 0.754939,  -1.156767, 0.799407,
                       0.799983,  -1.199391, -0.843250, 0.798781,  -2.755564,
                       0.755548,  0.843826,  -2.798189, -0.799407, -0.799983,
                       -2.800609, 0.799391,  -0.754939, -2.843233};
  double scale = 1;

  ck_assert_int_eq(countLines, shape.countLines);
  ck_assert_int_eq(countVertexes, shape.countVertexes);
  ck_assert_int_eq(scale, shape.scale);
  double dAngles[3] = {M_PI / 2, M_PI / 2, M_PI / 2};
  rotation(&shape, dAngles);

  for (int i = 0; i < countLines; ++i)
    ck_assert_uint_eq(shape.lines[i], lines[i]);
  for (int i = 0; i < countVertexes; ++i)
    ck_assert_double_eq_tol(shape.vertexes[i], vertexes[i], 1e-6);
  clearShape(&shape);
}
END_TEST

START_TEST(test_shape_7) {
  int ret = 1;
  Shape shape;
  ck_assert_int_eq(initShape(&shape, "../data-samples/cube.obj"), ret);

  int countLines = 72, countVertexes = 24;
  unsigned lines[] = {1, 2, 2, 3, 3, 1, 3, 2, 2, 4, 4, 3, 3, 4, 4, 5, 5, 3,
                      5, 4, 4, 6, 6, 5, 5, 6, 6, 7, 7, 5, 7, 6, 6, 8, 8, 7,
                      7, 8, 8, 1, 1, 7, 1, 8, 8, 2, 2, 1, 2, 8, 8, 4, 4, 2,
                      4, 8, 8, 6, 6, 4, 7, 1, 1, 5, 5, 7, 5, 1, 1, 3, 3, 5};
  for (int i = 0; i < countLines; ++i) lines[i]--;
  double vertexes[] = {1.200000,  1.200000, 0.800000,  2.800000, 1.200000,
                       0.800000,  1.200000, 2.800000,  0.800000, 2.800000,
                       2.800000,  0.800000, 1.200000,  2.800000, -0.800000,
                       2.800000,  2.800000, -0.800000, 1.200000, 1.200000,
                       -0.800000, 2.800000, 1.200000,  -0.800000};
  double scale = 1;

  ck_assert_int_eq(countLines, shape.countLines);
  ck_assert_int_eq(countVertexes, shape.countVertexes);
  ck_assert_int_eq(scale, shape.scale);
  double dShifts[3] = {2, 2, 2};
  shifting(&shape, dShifts[0], AXIS_X);
  shifting(&shape, dShifts[0], AXIS_Y);
  shifting(&shape, dShifts[0], AXIS_Z);
  for (int i = 0; i < countLines; ++i)
    ck_assert_uint_eq(shape.lines[i], lines[i]);
  for (int i = 0; i < countVertexes; ++i)
    ck_assert_double_eq_tol(shape.vertexes[i], vertexes[i], 1e-6);
  clearShape(&shape);
}
END_TEST

Suite *test_shape(void) {
  Suite *s = suite_create("\033[36;1;47m-=TEST SHAPE=-\033[0m");
  TCase *tc = tcase_create("s21_test_calculation_tc");

  tcase_add_test(tc, test_shape_1);
  tcase_add_test(tc, test_shape_2);
  tcase_add_test(tc, test_shape_3);
  tcase_add_test(tc, test_shape_4);
  tcase_add_test(tc, test_shape_5);
  tcase_add_test(tc, test_shape_6);
  tcase_add_test(tc, test_shape_7);

  suite_add_tcase(s, tc);
  return s;
}
