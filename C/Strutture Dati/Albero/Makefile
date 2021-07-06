main.exe:	item.o coda.o albero.o main.o
	gcc item.o coda.o albero.o main.o -o main.exe

item.o:	item.c
	gcc -c item.c

coda.o:	item.h coda.c
	gcc -c coda.c

albero.o:	item.h albero.c
	gcc -c albero.c

main.o:	item.h coda.h albero.h main.c
	gcc -c main.c

del:
	rm -f *.o *.exe
