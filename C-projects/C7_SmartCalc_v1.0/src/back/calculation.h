/**
 * @file calculation.h
 * @author chatayap
 * @brief Calculation
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SRC_CALCULATION_H
#define SRC_CALCULATION_H

#include "deque.h"
#include "lexema.h"
#include "operations.h"
#include "stack.h"

/**
 * @brief change all case letters from upper to lower
 *
 * @param str mutable string
 */
void strlow(char* str);

/**
 * @brief Polish notation calculation function
 *
 * @param str expression to evaluate
 * @param value constant to substitute into a variable
 * @param ans variable to get response
 * @return int 1 - successful eviction, 0 - error in expression
 */
int calculation(char* str, long double value, long double* ans);
/**
 * @brief translation of a string into a deque from tokens and checking the
 * string for correctness
 *
 * @param str the string where the expression is stored
 * @param polish deque composed of tokens
 * @param value variable x
 * @return int 1 - successful translation, 0 - incorrect expression
 */
int to_polish(char* str, deque* polish, long double value);
/**
 * @brief evaluating an expression using Polish notation
 *
 * @param polish deque polish notation
 * @return long double expression result
 */
long double calculus(deque* polish);
/**
 * @brief performing operation dur
 *
 * @param numbers stack of numbers
 * @param dur operation
 * @return stack modified stack
 */
stack operation(stack numbers, lexema dur);

#include <stdio.h>
#define PRINT_OPERATOR(x) printf("%d\n", x)
#define PRINT_NUMBER(x) printf("%.6Lf\n", x)
#define PRINT_VARIABLE printf("x ")

#endif  // SRC_CALCULATION_H
