/**
 * @file stack.h
 * @author chatayap
 * @brief Stack
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SRC_STACK_H
#define SRC_STACK_H

#include "lexema.h"

/**
 * @brief stack element structure
 *
 */
typedef struct ns {
  lexema data;     /**< Element information. The token is stored*/
  struct ns* next; /**< Pointer to the next element of the stack*/
} node_stack;

typedef node_stack* stack;

/**
 * @brief function to initialize the stack
 *
 * @return stack empty stack
 */
stack stack_init();
/**
 * @brief pushing a token onto the stack
 *
 * @param st source stack
 * @param data added token
 * @return stack modified stack
 */
stack stack_push(stack st, lexema data);
/**
 * @brief remove the top element of the stack
 *
 * @param st source stack
 * @return stack new stack
 */
stack stack_pop(stack st);
/**
 * @brief getting the top element of the stack
 *
 * @param st source stack
 * @return lexema top element of stack
 */
lexema stack_top(stack st);
/**
 * @brief stack empty check
 *
 * @param st checked stack
 * @return int 1 - the stack is empty, 0 - there is at least one element on the
 * stack
 */
int stack_is_empty(stack st);

#endif  // SRC_STACK_H
