main.exe:	item.o coda.o main.o
	gcc item.o coda.o main.o -o main.exe

item.o:	item.c
	gcc -c item.c

coda.o:	item.h coda.c
	gcc -c coda.c

main.o:	item.h coda.h main.c
	gcc -c main.c

del:
	rm -f coda.o item.o main.o main.exe
