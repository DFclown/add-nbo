
#Makefile

all: add-nbo

add-nbo: FileRead.o main.o
	g++ -o add-nbo FileRead.o main.o

main.o: main.c FileRead.h
	gcc -c -o main.o main.c

FileRead.o: FileRead.h FileRead.c
	gcc -c -o FileRead.o FileRead.c

clean:
	rm -f add-nbo
	rm -f *.o



