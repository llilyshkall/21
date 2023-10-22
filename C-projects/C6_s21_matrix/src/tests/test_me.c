#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_matrix_test[] = {test_create_remove(),    test_eq_matrix(),
                              test_sum_matrix(),       test_sub_matrix(),
                              test_mult_number(),      test_mult_matrix(),
                              test_transpose(),        test_determinant(),
                              test_calc_complements(), NULL};

  for (int i = 0; s21_matrix_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_matrix_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
