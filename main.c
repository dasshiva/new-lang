#include <stdio.h>
#include "string.h"

int main () {
	string* str = init("hello world");
	printf("%s",getchars(append_str(str," guys")));
	destroy(str);
}
