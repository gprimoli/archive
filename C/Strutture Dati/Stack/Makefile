main.exe:	item.o stack.o main.o
	gcc item.o stack.o main.o -o main.exe

item.o:	item.c
	gcc -c item.c

stack.o:	item.h stack.c
	gcc -c stack.c

main.o:	item.h stack.h main.c
	gcc -c main.c

del:
	rm -f stack.o item.o main.o main.exe
