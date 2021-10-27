all: main.o
	gcc -o filereader main.o
	
main.o: main.c
	gcc -c main.c

run:
	./filereader
