main.exe:	item.o BStree.o main.o
	gcc item.o BStree.o main.o -o main.exe

item.o:	item.c
	gcc -c item.c

BStree.o:	item.h BStree.c
	gcc -c BStree.c

main.o:	item.h BStree.h main.c
	gcc -c main.c

del:
	rm -f *.o *.exe
