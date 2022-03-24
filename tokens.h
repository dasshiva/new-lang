#ifndef _TOKENS_H_
#define _TOKENS_H_

#include "string.h"
typedef enum _tokens {
    K_VAR,
    O_ASSIGN,
    L_STRING,
    L_INTEGER,
    L_DOUBLE
} Token;

typedef struct __tokens {
    Token tk;
    string* str;
    long ival;
    double dval;
} Tokens;

Tokens* NewToken (string* str);
#endif
