#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Crea il file .c e il suo associato .h con il file Makefile e un main.c
int main(int argc, char *argv[]) {
  if(argc != 2){
    printf("[ERROR] Hai inserito un numero di argomenti diverso da quello rischiesto\n");
  }
  char c[30], h[30];
  char command[]="touch ";
  strcpy(c, argv[1]);
  strcat(c, ".c ");
  strcpy(h, argv[1]);
  strcat(h, ".h ");
  strcat(command, c);
  strcat(command, h);
  strcat(command, "main.c");
  strcat(command, "Makefile");
  system(command);
  printf("\nComando eseguito! :) File creati\n\n");
  return 0;
}
