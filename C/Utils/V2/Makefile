maker.exe:	maker.o main.o
	gcc maker.o main.o -o maker.exe

maker.o:	maker.c
	gcc -c maker.c

main.o:	maker.h main.c
	gcc -c main.c

del:
	rm -f *.exe *.o
