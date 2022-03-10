#ifndef _STRING_H_
#define _STRING_H_

#include <sys/types.h>
typedef struct _str string;

string* init (const char* cont);
string* append_char (string* cont, char a);
string* append_str (string* cont, const char* target);
char* getchars (string* cont);
size_t getlen (string* cont);
void destroy(string* str);

#endif
