main.exe:	item.o list.o main.o
	gcc item.o list.o main.o -o main.exe

item.o:	item.c
	gcc -c item.c

list.o:	item.h list.c
	gcc -c list.c

main.o:	item.h list.h main.c
	gcc -c main.c

del:
	rm -f list.o item.o main.o main.exe
