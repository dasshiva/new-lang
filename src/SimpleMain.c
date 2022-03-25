#include <stdio.h>
#include <SimpleString.h>
#include <SimpleLexer.h>

int main () {
	size_t sz = 0;
	char* rd = NULL;
	getline(&rd, &sz, stdin);
	SetTarget(rd);
	while (1) {
		Tokens* tks = GetToken();
		if (!tks)
			break;
		printf("%d", tks->tk);
	}

}
