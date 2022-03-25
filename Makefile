CFLAGS = -Iinclude/ -Wall -Wextra

all: main tokens string lexer parser
	$(CC) $(LDFLAGS) objs/main.o objs/tokens.o objs/string.o objs/lexer.o objs/parser.o -o bin/Simple

main: src/SimpleMain.c
	mkdir -p objs bin
	$(CC) $(CFLAGS) -c src/SimpleMain.c -o objs/main.o

tokens: src/SimpleTokens.c
	$(CC) $(CFLAGS) -c src/SimpleTokens.c -o objs/tokens.o

string: src/SimpleString.c
	$(CC) $(CFLAGS) -c src/SimpleString.c -o objs/string.o

lexer: src/SimpleLexer.c
	$(CC) $(CFLAGS) -c src/SimpleLexer.c -o objs/lexer.o

parser: src/SimpleParser.c
	$(CC) $(CFLAGS) -c src/SimpleParser.c -o objs/parser.o
