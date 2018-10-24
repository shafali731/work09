all: main.o
	gcc main.o

file.o: main.c
	gcc -c main.c

run:
	./a.out

clear:
	rm *.o
