main.exe:	carta.o mazzo.o player.o magic.o solitario.o main.o
	gcc carta.o mazzo.o player.o magic.o solitario.o main.o -o main.exe

carta.o:	carta.c
	gcc -c carta.c

mazzo.o:	carta.h mazzo.c
	gcc -c mazzo.c

magic.o:	carta.h mazzo.h magic.c
	gcc -c magic.c

solitario.o:	carta.h mazzo.h player.h solitario.c
	gcc -c solitario.c

player.o:	player.c
	gcc -c player.c

main.o:	carta.h mazzo.h magic.h solitario.h main.c
	gcc -c main.c

del:
	rm -f *.o *.exe *.dat
