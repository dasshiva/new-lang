#include "string.h"
#include "tokens.h"
#include <stddef.h>

static string* target = NULL;
static index_t currentindex, length;
static iterator iter = NULL;

void set_target(const char* line) {
    target = append_char(init(line),' ');
    currentindex = 0;
    length = getlen(target);
    iter = get_iterator(target);
}

Tokens* get_token() {
    if(!target || (currentindex == length))
       return NULL;
    
    for (; currentindex < getlen(target); currentindex++) {
        if (*iter == ' ') {}
    }
}