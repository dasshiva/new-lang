#include <stdio.h>
#include "string.h"
#include "lexer.h"

int main () {
	size_t sz = 0;
	char* rd = NULL;
	getline(&rd, &sz, stdin);
	set_target(rd);

	while (1) {
		Tokens* tks = get_token();
		if (!tks)
			break;
		printf("%d", tks->tk);
	}
}
