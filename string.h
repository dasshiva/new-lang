#ifndef _STRING_H_
#define _STRING_H_

#include <sys/types.h>
typedef struct _str {
	char* buf;
	size_t len, max_sz;
} string;

typedef char* iterator;
typedef size_t index_t;

string* New (const char* cont);
string* AppendChar (string* cont, char a);
string* AppendStr (string* cont, const char* target);
size_t Len (string* cont);
void Destroy (string* str);
iterator GetIterator (string* str);
char CharAt (string* str, size_t index);

#endif
