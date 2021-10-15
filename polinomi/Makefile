polinomi: parser.o lexer.o polinomi.o
	g++ $^ -o $@

parser.o: parser.tab.cpp
	g++ -c -o $@ $<

lexer.o: lex.yy.c
	g++ -c -o $@ $<

lex.yy.c: lexer.l
	flex $<

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d $<

polinomi.o: polinomi.cpp polinomi.hpp
	g++ -o $@ -c $<

.PHONY: clean

clean:
	rm -f *.o *.c *.tab.* polinomi ~*