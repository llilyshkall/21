/**
 * @file operations.c
 * @author chatayap
 * @brief Operations
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "operations.h"

/**
 * element-by-element initialization of each element of an array of pointers
 */
void init_operations(stack (*operations[])(stack)) {
  operations[PLUS] = posit;
  operations[MINUS] = negat;
  operations[EXP] = expon;
  operations[MUL] = multy;
  operations[DIV] = divid;
  operations[MOD] = moddi;
  operations[ADD] = addit;
  operations[SUB] = subst;
  operations[COS] = cosin;
  operations[SIN] = sinus;
  operations[TAN] = tange;
  operations[ACOS] = acosi;
  operations[ASIN] = asinu;
  operations[ATAN] = atang;
  operations[SQRT] = squar;
  operations[LN] = natul;
  operations[LOG] = decil;
}

/**
 * unary plus does nothing to the number, so return the original stack
 */
stack posit(stack st) { return st; }

/**
 * getting the top element of the list, changing its sign, and
 * pushing the resulting number onto the stack
 */
stack negat(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num *= -1;
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top two elements of the stack, raising one number to
 * the power of another number, and pushing the result onto the stack
 */
stack expon(stack st) {
  lexema tmp1, tmp2;
  tmp2 = stack_top(st);
  st = stack_pop(st);
  tmp1 = stack_top(st);
  st = stack_pop(st);
  tmp1.data.num = powl(tmp1.data.num, tmp2.data.num);
  st = stack_push(st, tmp1);
  return st;
}

/**
 * getting the top two elements of the stack, multiplying the two numbers,
 * and pushing the result onto the stack
 */
stack multy(stack st) {
  lexema tmp1, tmp2;
  tmp2 = stack_top(st);
  st = stack_pop(st);
  tmp1 = stack_top(st);
  st = stack_pop(st);
  tmp1.data.num = tmp1.data.num * tmp2.data.num;
  st = stack_push(st, tmp1);
  return st;
}

/**
 * getting the top two elements of the stack, dividing one number by another,
 * and pushing the result onto the stack
 */
stack divid(stack st) {
  lexema tmp1, tmp2;
  tmp2 = stack_top(st);
  st = stack_pop(st);
  tmp1 = stack_top(st);
  st = stack_pop(st);
  tmp1.data.num = tmp1.data.num / tmp2.data.num;
  st = stack_push(st, tmp1);
  return st;
}

/**
 * getting the top two elements of the stack,
 * getting the remainder from dividing one number by another
 * and pushing the result onto the stack
 */
stack moddi(stack st) {
  lexema tmp1, tmp2;
  tmp2 = stack_top(st);
  st = stack_pop(st);
  tmp1 = stack_top(st);
  st = stack_pop(st);
  tmp1.data.num = fmodl(tmp1.data.num, tmp2.data.num);
  st = stack_push(st, tmp1);
  return st;
}

/**
 * getting the top two elements of the stack,
 * addition of these numbers
 * and pushing the result onto the stack
 */
stack addit(stack st) {
  lexema tmp1, tmp2;
  tmp2 = stack_top(st);
  st = stack_pop(st);
  tmp1 = stack_top(st);
  st = stack_pop(st);
  tmp1.data.num = tmp1.data.num + tmp2.data.num;
  st = stack_push(st, tmp1);
  return st;
}

/**
 * getting the top two elements of the stack,
 * subtraction of two numbers
 * and pushing the result onto the stack
 */
stack subst(stack st) {
  lexema tmp1, tmp2;
  tmp2 = stack_top(st);
  st = stack_pop(st);
  tmp1 = stack_top(st);
  st = stack_pop(st);
  tmp1.data.num = tmp1.data.num - tmp2.data.num;
  st = stack_push(st, tmp1);
  return st;
}

/**
 * getting the top element of the stack,
 * get cosine
 * and pushing the result onto the stack
 */
stack cosin(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = cosl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * receiving sine
 * and pushing the result onto the stack
 */
stack sinus(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = sinl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * get tangent
 * and pushing the result onto the stack
 */
stack tange(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = tanl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * getting the arccosine
 * and pushing the result onto the stack
 */
stack acosi(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = acosl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * get the arcsine
 * and pushing the result onto the stack
 */
stack asinu(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = asinl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * getting the arc tangent
 * and pushing the result onto the stack
 */
stack atang(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = atanl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * obtaining a square root
 * and pushing the result onto the stack
 */
stack squar(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = sqrtl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * get the natural logarithm
 * and pushing the result onto the stack
 */
stack natul(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = logl(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}

/**
 * getting the top element of the stack,
 * getting the decimal logarithm
 * and pushing the result onto the stack
 */
stack decil(stack st) {
  lexema tmp = stack_top(st);
  st = stack_pop(st);
  tmp.data.num = log10l(tmp.data.num);
  st = stack_push(st, tmp);
  return st;
}
