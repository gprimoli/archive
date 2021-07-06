main.exe:	item.o set.o main.o
	gcc item.o set.o main.o -o main.exe

item.o:	item.c
	gcc -c item.c

set.o:	item.h set.c
	gcc -c set.c

main.o:	item.h set.h main.c
	gcc -c main.c

del:
	rm -f *.o *.exe
