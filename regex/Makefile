basic: parser.tab.o lex.yy.o basic.o
	g++ $^ -o $@

lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -c $< -o $@

lex.yy.c: lexer.l
	flex $<

parser.tab.o: parser.tab.cpp
	g++ -c $<

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<

basic.o: regex.cpp regex.hpp
	g++ -c $< -o $@


.PHONY: clean
clean:
	-rm -f *~ *.o *tab* *.c *.output basic | clear