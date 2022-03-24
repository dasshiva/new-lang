#include "tokens.h"
#include <stddef.h>

static string* target = NULL;
static index_t currentindex, length;
static iterator iter = NULL;

void SetTarget(const char* line) {
    target = AppendChar(New(line),' ');
    currentindex = 0;
    length = Len(target);
    iter = GetIterator(target);
}

Tokens* GetToken() {
    if(!target || (currentindex == length))
       return NULL;
    string* str = New("");
    for (; currentindex < Len(target); currentindex++, iter++) {
        if (*iter == ' ') {
		if (Len(str) == 0) // don't return if buffer is empty
			continue;
		currentindex++;
		iter++;
		return NewToken(str);
	}
	AppendChar(str, *iter);
    }
    return NewToken(str);
}
