#include "stdio.h"
#include <stdlib.h>
#include "scacchi.h"
#define NUM 8

int scacchiera[NUM][NUM];

int main(int argc, char *argv[]) {
  if(argc != 2){
    printf("Hai dimenticato di includere il file con le posizioni delle regine\n");
    exit(0);
  }
  FILE *file = fopen(argv[1] , "r");
  inizializza(scacchiera, file, NUM);
  leggi(scacchiera, NUM);
  check(scacchiera, file, NUM);
  return 0;
}
