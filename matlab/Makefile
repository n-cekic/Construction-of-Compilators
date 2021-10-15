program: lex.yy.o parser.tab.o matrix.o
	g++ $^ -o $@
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -c -o $@ $<
parser.tab.o: parser.tab.cpp
	g++ -c -o $@ $<
lex.yy.c: lexerr.l
	flex $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
matrix.o: matrix.cpp matrix.hpp
	g++ -c -o $@ $<

.PHONY: clean
clean:
	-rm -f *~ program *.o *.c *.tab.* *.output | clear


# matrix: lex.yy.o parser.tab.o matrix.o
# 	g++ -o $@ $^
# lex.yy.o: lex.yy.c parser.tab.hpp
# 	g++ -c -o $@ $<
# parser.tab.o: parser.tab.cpp
# 	g++ -c -o $@ $<
# lex.yy.c: lexerr.l
# 	flex $<
# parser.tab.cpp parser.tab.hpp: parser.ypp
# 	bison -d -v $<
# matrix.o: matrix.cpp matrix.hpp
# 	g++ -c -o $@ $<

# .PHONY: clean

# clean: 
# 	rm -f *.o matrix lex.yy.c *.tab.* *~ *.output
