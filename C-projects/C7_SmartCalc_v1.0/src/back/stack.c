/**
 * @file stack.c
 * @author chatayap
 * @brief Stack
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "stack.h"

#include <stdlib.h>

/**
 * creating an empty stack
 */
stack stack_init() { return NULL; }

/**
 * adding an element to the stack. A new memory area is created,
 * initialized with a token, and a pointer is set to the first
 * element of the stack. Returns a pointer to the created element
 */
stack stack_push(stack st, lexema data) {
  stack tmp = malloc(sizeof(node_stack));
  tmp->data.data = data.data;
  tmp->data.type = data.type;
  tmp->next = st;
  return tmp;
}

/**
 * the top element of the stack is cleared. Return pointer
 * following the removed element
 */
stack stack_pop(stack st) {
  stack tmp = st->next;
  free(st);
  return tmp;
}

/**
 * returns the token at the top of the stack
 */
lexema stack_top(stack st) { return st->data; }

/**
 * check pointer for null
 */
int stack_is_empty(const stack st) { return st == NULL; }
