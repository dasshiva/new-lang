#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Creates a new string from the given character buffer 
 * @param cont the buffer from which the string is to be constructed
 * @return - a new string*
 */
string* New (const char* cont) {
	string* str = (struct _str*) malloc (sizeof(struct _str));
	str->len = strlen(cont);

	/* We always allocate 20 bytes more than the actual length
	 * of the string as this helps us to prevent too many
	 * reallocations while appending to it */
	str->max_sz = str->len + 20;
	str->buf = (char*) malloc(sizeof (char) * str->max_sz);
	str->buf[str->len] = '\0';
	strcpy(str->buf, cont);

	/* Since we get some of the input from getline() which 
	 * preserves the new-line character at the end, we remove 
	 * it here */

	if (str->buf[str->len - 1] == '\n') 
		str->buf[str->len - 1] = '\0';
	return str;
}

/* Increases the size of the internal buffer of cont by sz. Please keep in mind that 
 * this fucntion should not be called externally and is automatically called by the
 * append_*() fucntions as and when needed
 * @param cont the string whose buffer needs to be resized
 * @param sz the magnitude by which the buffer's has to be increased
 */
static void extend(string* cont, size_t sz ) {
	cont->max_sz += sz;
        cont->buf = (char*) realloc(cont->buf,cont->max_sz);
}

/* Appends a char to the end of the given string 
 * @param cont the string to be modified
 * @param a the char to be appended to the string
 * @return the modified string
 */
string* AppendChar (string* cont, char a) {
	cont->len++;
	if (cont->max_sz == cont->len) 
		extend(cont, 20);
	cont->buf[cont->len-1] = a;
	cont->buf[cont->len] = '\0';
	return cont;
}

/* Appends the contents of a character buffer to the end of the given string
 * @param cont the string which is to be modified
 * @param target the character buffer whose contents will be appended (undefined behaviour if NULL)
 * @return the modified string
 */
string* AppendStr(string* cont, const char* target) {
	cont->len += strlen (target);
	if (cont->max_sz <= cont->len) 
		extend(cont, (cont->len - cont->max_sz) + 20);
	strcat(cont->buf, target);
	return cont;
}

/* Returns the length of the string
 * @param str the string whose length needs to be printed
 * @return the length of the string
 */
size_t Len (string* str) {
	return str->len;
}

/* Frees all resources that were occupied by the string and sets str to NULL
 * @param str the string whose resources have to be freed
 */
void Destroy (string* str) {
	free(str->buf);
	free(str);
	str = NULL;
}

/* Returns an iterator (i.e a pointer) to the beginning of the iternal buffer 
 * @param str the string from which the iterator will be created from
 * @return the iterator to the beginning of the iternal buffer
*/
iterator GetIterator (string* str){
	return str->buf;
}

/* Returns a character from the internal buffer as specified by the index
 * @param str the string from which the character has to be returned
 * @param index the index of the character that is to be returned
 * @return if index is more than or equal to the string's length then 0 is returned,
 * otherwise the character specified by the index is returned
 */
char CharAt (string* str,index_t index) {
	if (index >= str->len) 
	    return 0;
	return str->buf[index];
}
