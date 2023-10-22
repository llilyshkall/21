/**
 * @file calculation.c
 * @author chatayap
 * @brief Calculation
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "calculation.h"

/**
 * creating an empty deck, filling it with the appropriate tokens from the
 * string
 */
int calculation(char* str, long double value, long double* ans) {
  deque polish = deque_init();
  int ret = to_polish(str, &polish, value);
  if (ret) *ans = calculus(&polish);
  deque_clear(polish);
  return ret;
}

/**
 * getting tokens from strings, translating into Polish notation as a deca
 */
int to_polish(char* str, deque* polish, long double value) {
  lexema dur;
  stack operators = stack_init();
  int ret = 1, check = 0, flag = 1, scope = 0;
  strlow(str);
  while ((ret = ret && next_lexema(&str, &dur, value) &&
                (check == 1 || check == 0) && scope >= 0)) {
    if (dur.type == LEXEMA_NUMBER) {
      *polish = deque_push_end(*polish, dur);
      check++;
      flag = 0;
    } else {
      if (!prior(dur)) {
        flag = 1;
        scope++;
        operators = stack_push(operators, dur);
      }
      if (dur.data.oper == CLOSE_SCOPE) {
        scope--;
        while (!stack_is_empty(operators) && prior(stack_top(operators))) {
          *polish = deque_push_end(*polish, stack_top(operators));
          operators = stack_pop(operators);
        }
        ret = !stack_is_empty(operators);
        if (ret && stack_top(operators).data.oper != OPEN_SCOPE)
          *polish = deque_push_end(*polish, stack_top(operators));
        if (ret) operators = stack_pop(operators);
      }
      if (prior(dur) && dur.data.oper != CLOSE_SCOPE) {
        if (flag && prior(dur) == 1) dur.data.oper += 3;
        if (prior(dur) > 0 && prior(dur) < 4) check--;
        while (!stack_is_empty(operators) &&
               prior(stack_top(operators)) >= prior(dur)) {
          *polish = deque_push_end(*polish, stack_top(operators));
          operators = stack_pop(operators);
        }
        operators = stack_push(operators, dur);
        flag = 0;
      }
    }
  }
  while (!stack_is_empty(operators)) {
    *polish = deque_push_end(*polish, stack_top(operators));
    operators = stack_pop(operators);
  }
  ret = !*str && (check == 1) && scope == 0;
  return ret;
}

/**
 * deque iteration and expression evaluation
 */
long double calculus(deque* polish) {
  lexema dur;
  stack numbers = stack_init();
  stack (*operations[100])(stack);
  init_operations(operations);

  while (!deque_is_empty(*polish)) {
    dur = deque_top_begin(*polish);
    *polish = deque_pop_begin(*polish);

    if (dur.type == LEXEMA_NUMBER) {
      numbers = stack_push(numbers, dur);
    } else {
      numbers = operations[dur.data.oper](numbers);
    }
  }
  dur = stack_top(numbers);
  numbers = stack_pop(numbers);
  return dur.data.num;
}
