#ifndef _LEXER_H_
#define _LEXER_H_

#include "tokens.h"

void set_target(const char* line);
Tokens* get_token();

#endif
