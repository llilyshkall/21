/**
 * @file deque.c
 * @author chatayap
 * @brief Deque
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "deque.h"

#include <stdlib.h>

/**
 * initialization of a pointer to the first and last element of the deque
 */
deque deque_init() {
  deque ret;
  ret.begin = NULL;
  ret.end = NULL;
  return ret;
}

/**
 * allocating memory for a new deque element, adding an element
 * by changing the pointer to the next deque element after the last
 */
deque deque_push_end(deque dq, lexema data) {
  node_deque* tmp = malloc(sizeof(node_deque));
  tmp->data.data = data.data;
  tmp->data.type = data.type;
  tmp->next = NULL;
  tmp->prev = dq.end;
  if (dq.end)
    dq.end->next = tmp;
  else
    dq.begin = tmp;
  dq.end = tmp;
  return dq;
}

/**
 * getting the first element of the deque, freeing memory for that element, and
 * changing the pointer of the new first element
 */
deque deque_pop_begin(deque dq) {
  node_deque* tmp = dq.begin;
  dq.begin = dq.begin->next;
  free(tmp);
  if (dq.begin)
    dq.begin->prev = NULL;
  else
    dq.end = NULL;
  return dq;
}

/**
 * getting the last element of the deque, freeing memory for that element, and
 * changing the pointer of the new last element
 */
deque deque_pop_end(deque dq) {
  node_deque* tmp = dq.end;
  dq.end = dq.end->prev;
  free(tmp);
  if (dq.end)
    dq.end->next = NULL;
  else
    dq.begin = NULL;
  return dq;
}

/**
 * getting the token stored in the first element of the deque
 */
lexema deque_top_begin(deque dq) { return dq.begin->data; }

/**
 * deleting deque elements until it is empty
 */
void deque_clear(deque dq) {
  while (!deque_is_empty(dq)) dq = deque_pop_end(dq);
}

/**
 * check pointer for null
 */
int deque_is_empty(deque dq) { return dq.begin == NULL; }
