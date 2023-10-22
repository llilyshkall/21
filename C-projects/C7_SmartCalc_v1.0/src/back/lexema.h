/**
 * @file lexema.h
 * @author chatayap
 * @brief Lexeme
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef SRC_LEXEMA_H
#define SRC_LEXEMA_H
/**
 * @brief Constants for operations
 * the lower three bits store the priority of the operation, the rest
 * for the sequence number of the operation
 *
 */
typedef enum {
  PLUS = 1 << 3 | 4,   // unary plus
  MINUS = 2 << 3 | 4,  // unary minus

  EXP = 1 << 3 | 3,  // exponentiation

  MUL = 1 << 3 | 2,  // multiplication
  DIV = 2 << 3 | 2,  // division
  MOD = 3 << 3 | 2,  // remainder of the division

  ADD = 1 << 3 | 1,  // addition
  SUB = 2 << 3 | 1,  // subtraction

  COS = 1 << 3 | 0,          // cosine
  SIN = 2 << 3 | 0,          // sinus
  TAN = 3 << 3 | 0,          // tangent
  ACOS = 4 << 3 | 0,         // arccosine
  ASIN = 5 << 3 | 0,         // arcsine
  ATAN = 6 << 3 | 0,         // arc tangent
  SQRT = 7 << 3 | 0,         // Square root
  LN = 8 << 3 | 0,           // natural logarithm
  LOG = 9 << 3 | 0,          // decimal logarithm
  OPEN_SCOPE = 10 << 3 | 0,  // open bracket

  CLOSE_SCOPE = -1,  // closing bracket

  NONE = 0  // uninitialized operation
} operators;

/**
 * @brief Union in which can be stored as and
 * number so and operation
 */
typedef union {
  long double num; /**< Number*/
  operators oper;  /**< operator*/
} data_lexema;

#define LEXEMA_OPERATOR 0
#define LEXEMA_NUMBER 1

/**
 * @brief Lexeme structure
 */
typedef struct {
  int type;         /**< Lexeme type: 0 - operator, 1 - number*/
  data_lexema data; /**< number or operation*/
} lexema;

/**
 * @brief getting a token from a string
 *
 * @param str line with expression
 * @param ans received token
 * @param value constant x
 * @return int 1 - successful reading, 0 - error in the expression
 */
int next_lexema(char** str, lexema* ans, long double value);
/**
 * @brief stack calculation for short statements
 *
 * @param str line
 * @param ans result
 * @return int 1 - successful calculation, 0 - not a short statement
 */
int short_operator(char** str, lexema* ans);
/**
 * @brief stack calculation for long statements
 *
 * @param str line
 * @param ans result
 * @return 1 - successful calculation, 0 - not a long statement
 */
int long_operator(char** str, lexema* ans);
/**
 * @brief change the case of all elements of a string
 * top to bottom
 *
 * @param str mutable string
 */
void strlow(char* str);
/**
 * @brief operator precedence calculation
 *
 * @param value source token
 * @return int operator precedence
 */
int prior(lexema value);

#endif  // SRC_LEXEMA_H
