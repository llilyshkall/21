#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {test_is_equal(),
                              test_is_not_equal(),
                              test_is_greater(),
                              test_is_greater_or_equal(),
                              test_is_less(),
                              test_is_less_or_equal(),

                              test_mod(),
                              test_add(),
                              test_sub(),
                              test_mul(),
                              test_div(),

                              test_truncate(),
                              test_round(),
                              test_floor(),
                              test_negate(),

                              test_from_int_to_decimal(),
                              test_from_decimal_to_int(),
                              test_from_decimal_to_float(),
                              test_from_float_to_decimal(),

                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("Failed: %d\n", failed);

  return failed == 0 ? 0 : 1;
}
