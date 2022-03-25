#include <SimpleParser.h>
#include <SimpleLexer.h>
#include <SimpleTokens.h>

#include <stdbool.h>
#include <stdarg.h>

typedef unsigned char flags_t; // a type for storing flags

/* indicates if a parser error has ocurred yet */
static flags_t err_state = false; 

/* stores the line number of the file */
static unsigned int line;

static void ReportError(const char* msg, ...) {
	err_state = true;
	va_list args;
	va_start(args, msg);
	vprintf(msg, args);
	va_end(args);
}

static void ParseVar();

int ParseFile (FILE* src) {
	line = 1;
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
		if (err_state) return 1;
		line++;
	}
	fclose(src);
	return 0;
}

static void ParseVar() { // TODO: Implement parsing of var statements
	flags_t exp_eol = false, exp_id = true, exp_eq = false, exp_val = false;
	Tokens* tks = NULL;
	while ((tks = GetToken()) != NULL) {
		if (exp_id) {
			if (tks->tk != L_STRING) 
				ReportError("%d : Expected a valid identifier ", line);
			exp_id = false;
			exp_eq = true;
			continue;
		}
		if (exp_eq) {
			if (tks->tk != O_ASSIGN) 
				ReportError("%d : Expected '=' here", line);
			exp_eq = false;
			exp_val = true;
			continue;
		}
		if (exp_val) {
			switch (tks->tk) {
				case L_INTEGER: break;
				case L_DOUBLE: break;
				case L_STRING: break;
				default: ReportError("%d : Expecting a value ", line);
			}
			exp_val = false;
			exp_eol = true;
			break;
		}
	}
	if (!exp_eol) 
		ReportError("%d : Unexpected end of line ", line);
}
