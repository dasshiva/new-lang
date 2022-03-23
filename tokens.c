#include "tokens.h"
#include "string.h"

#include <stdlib.h>
#include <string.h>

Tokens* new_token (string* str) {
	Tokens* tks = (Tokens*) malloc(sizeof(Tokens));
	char* onfail;
	iterator iter = get_iterator(str);
	if (getlen(str) == 1) {
		switch (charat(str, 0)) {
			case '=' : tks->tk = O_ASSIGN; return tks;
		}
	}

	if (strcmp("var", iter) == 0) {
		tks->tk = K_VAR;
		return tks;
	}

	else {
		long ival = strtol(iter, &onfail, 10);
		if (iter != onfail) {
			tks->tk = L_INTEGER;
			tks->ival = ival;
			return tks;
		}

		double dval = strtod(iter, &onfail);
		if (iter!= onfail) {
			tks->tk = L_DOUBLE;
			tks->dval = dval;
			return tks;
		}

		tks->tk = L_STRING;
		tks->str = str;
		return tks;
	}
}
