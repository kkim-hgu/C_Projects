main:	add.o remove.o file_operations.o main.o
	clang -o main add.o remove.o file_operations.o main.o

main.o: main.c file_operations.h add.h remove.h
	clang -c -Wall -pedantic-errors main.c

file_opterations.o: file_operations.c file_operations.h
	clang -c -Wall -pedantic-errors file_operations.c

add.o: add.c add.h file_operations.h
	clang -c -Wall -pedantic-errors add.c

remove.o: remove.c remove.h file_operations.h
	clang -c -Wall -pedantic-errors remove.c

all:	main

clean:
	rm -f main.o file_operations.o add.o remove.o main main.tar

tarball:	main
	tar -c -f main.tar main.c file_operations.c file_operations.h add.c add.h remove.c remove.h
