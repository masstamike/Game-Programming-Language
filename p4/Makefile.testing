test: test.cpp symbol.o symbol_table.o
	g++ -o test -Wall -g test.cpp symbol.o symbol_table.o

symbol.o: symbol.cpp symbol.h
	g++ -c -Wall -g symbol.cpp

symbol_table.o: symbol_table.cpp symbol_table.h
	g++ -c -Wall -g symbol_table.cpp

clean:
	rm *.o
