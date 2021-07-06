main.exe:	main.o scacchi.o
	gcc scacchi.o main.o -o main.exe

main.o:	scacchi.o main.c
	gcc -c main.c

scacchi.o:	scacchi.c
	gcc -c scacchi.c

del:
	rm -f *.o *.exe
