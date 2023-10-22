/**
 * @file operations.h
 * @author chatayap
 * @brief Operations
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SRC_OPERATIONS_H
#define SRC_OPERATIONS_H

#include "math.h"
#include "stack.h"
/**
 * @brief initializes an array of calculator functions
 *
 * @param operations source array
 */
void init_operations(stack (*operations[])(stack));
/**
 * @brief unary plus function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack posit(stack st);
/**
 * @brief unary minus function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack negat(stack st);
/**
 * @brief exponent function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack expon(stack st);
/**
 * @brief multiplication function of two numbers
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack multy(stack st);
/**
 * @brief division function of two numbers
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack divid(stack st);
/**
 * @brief the function of finding the remainder when dividing two numbers
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack moddi(stack st);
/**
 * @brief function to add two numbers
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack addit(stack st);
/**
 * @brief function to subtract two numbers
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack subst(stack st);
/**
 * @brief cosine function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack cosin(stack st);
/**
 * @brief sine function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack sinus(stack st);
/**
 * @brief tangent function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack tange(stack st);
/**
 * @brief arccosine function
 *
 * @param st исходный стек
 * @return stack стек после выполнения операции
 */
stack acosi(stack st);
/**
 * @brief arcsine function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack asinu(stack st);
/**
 * @brief arc tangent function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack atang(stack st);
/**
 * @brief square root function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack squar(stack st);
/**
 * @brief natural log function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack natul(stack st);
/**
 * @brief decimal logarithm function
 *
 * @param st source stack
 * @return stack stack after operation
 */
stack decil(stack st);

#endif  // SRC_OPERATIONS_H
