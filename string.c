#include "string.h"

#include <stdlib.h>
#include <string.h>

struct _str {
	char* buf;
	size_t len, max_sz;
};


string* init (const char* cont) {
	string* str = (struct _str*) malloc (sizeof(struct _str));
	str->len = strlen(cont);

	/* We always allocate 20 bytes more than the actual length
	 * of the string as this helps us to prevent too many
	 * reallocations while appending to it */
	str->max_sz = str->len + 20;
	str->buf = (char*) malloc(sizeof (char) * str->max_sz);
	str->buf[str->len-1] = '\0';
	strcpy(str->buf,cont);
	return str;
}

static void extend(string* cont, size_t sz ) {
	cont->max_sz += sz;
        cont->buf = (char*) realloc(cont->buf,cont->max_sz);
}

string* append_char (string* cont, char a) {
	cont->len++;
	if (cont->max_sz == cont->len) 
		extend(cont, 20);
	cont->buf[cont->len-1] = a;
	cont->buf[cont->len] = '\0';
	return cont;
}

string* append_str(string* cont, const char* target) {
	cont->len += strlen (target);
	if (cont->max_sz <= cont->len) 
		extend(cont, (cont->len - cont->max_sz) + 20);
	strcat(cont->buf, target);
	return cont;
}

char* getchars (string* str) {
	return str->buf;
}

size_t getlen(string* str) {
	return str->len;
}

void destroy (string* str) {
	free(str->buf);
	free(str);
}


