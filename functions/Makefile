PROGRAM = function
CC = g++
CFLAGS = -Wall -pedantic -ansi
LEX = flex	
YACC = bison
YFLAGS = -d -v

$(PROGRAM): function.tab.o lex.yy.o function.o
	$(CC) $(CFLAGS) -o $@ $^
function.tab.o: function.tab.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c -o $@ $<
function.tab.cpp function.tab.hpp : function.ypp
	$(YACC) $(YFLAGS) $<
lex.yy.c: function.l function.tab.hpp
	$(LEX) $<
function.o: function.cpp function.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	-rm -f *~ $(PROGRAM) *.c *.tab.hpp *.o *.tab.cpp function.output
