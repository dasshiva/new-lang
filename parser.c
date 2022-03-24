#include "parser.h"
#include "lexer.h"
#include "tokens.h"

static unsigned int line = 1;

static void ParseVar();

void ParseFile (FILE* src){
	char* buf = NULL;
	size_t st = 0;
	while (!feof(src)) {
		getline(&buf, &st, src);
		SetTarget(buf);
		Tokens* tks = GetToken();
		if (tks) {
			switch (tks->tk) {
				case K_VAR: ParseVar(); break;
			}
		}
		line++;
	}
}

static void ParseVar() { // TODO: Implement parsing of var statements
	 
}
