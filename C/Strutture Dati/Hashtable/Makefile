main.exe:	key.o hashtable.o item.o main.o
	gcc key.o hashtable.o item.o main.o -o main.exe

key.o:	key.c
	gcc -c key.c

hashtable.o:	key.h item.h hashtable.c
	gcc -c hashtable.c

item.o:	item.c
	gcc -c item.c

main.o:	key.h hashtable.h item.h main.c
	gcc -c main.c

del:
	rm -f *.o *.exe
