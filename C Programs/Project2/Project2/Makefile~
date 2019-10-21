main:	file_operations.o main.o
	clang -o main file_operations.o main.o

main.o: main.c file_operations.h
	clang -c -Wall -pedantic-errors main.c

file_opterations.o: file_operations.c file_operations.h
	clang -c -Wall -pedantic-errors file_operations.c

all:	main

clean:
	rm -f main.o file_operations.o main main.tar

tarball:	main
	tar -c -f main.tar main.c file_operations.c file_operations.h 
