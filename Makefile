all: start


start: main.o bintree.o
	gcc main.o bintree.o -o start


main.o: main.c
	gcc -c main.c


bintree.o:
	gcc -c bintree.c


clean:
	-rm -f *.o start
