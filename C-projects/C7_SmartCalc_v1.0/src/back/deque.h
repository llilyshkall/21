/**
 * @file deque.h
 * @author chatayap
 * @brief Deque
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SRC_DEQUE_H
#define SRC_DEQUE_H

#include "lexema.h"

/**
 * @brief deque element structure
 *
 */
typedef struct nd {
  lexema data;     /**< Data storage area (tokens)*/
  struct nd *next; /**< Pointer to next deque element*/
  struct nd *prev; /**< Pointer to previous deque element*/
} node_deque;

/**
 * @brief Structure for deque element
 *
 */
typedef struct {
  node_deque *begin; /**< Pointer to start deque*/
  node_deque *end;   /**< End deque pointer*/
} deque;

/**
 * @brief deck initialization function
 *
 * @return deque empty deque
 */
deque deque_init();
/**
 * @brief adding an element to the end of the deque
 *
 * @param st original deque
 * @param data added element
 * @return deque modified deque
 */
deque deque_push_end(deque st, lexema data);
/**
 * @brief getting the first element of the deque
 *
 * @param st original deque
 * @return deque modified deque
 */
deque deque_pop_begin(deque st);
/**
 * @brief deleting the last deque element
 *
 * @param st
 * @return deque modified deque
 */
deque deque_pop_end(deque st);
/**
 * @brief getting the first element of the deque
 *
 * @param st original deque
 * @return lexema the token that is stored in the first element of the deque
 */
lexema deque_top_begin(deque st);
/**
 * @brief deque cleansing
 *
 * @param st release deque
 */
void deque_clear(deque st);
/**
 * @brief checking the deck for emptiness
 *
 * @param st checked dec
 * @return int 1 - deque is empty, 0 - there is at least one element in deque
 */
int deque_is_empty(deque st);

#endif  // SRC_DEQUE_H
