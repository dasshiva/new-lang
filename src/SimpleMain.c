#include <SimpleParser.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main (int argc, char* argv[]) {
	if (argc < 2)  
		return ParseFile(stdin);
	FILE* src = fopen(argv[1], "r");
	if (!src) {
		printf("Could not open file %s : %s", argv[1], strerror(errno));
		return -1;
	}
	ParseFile(src);
	return 0;
}
