#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "key.h"

#define MAX 50


int hash(key k, int m){
  int lenght= strlen(k);
  int v = (k[0] + k[lenght-1] + lenght);
  return (v % m);
}

int eqkey(key x, key y){
  if(!(strcmp(x,y)))
    return 1;
  return 0;
}

char * input_key(){
  key x=malloc(MAX*sizeof(char));
  printf("Inserisci la key\n");
  scanf("%s", x);
  return x;
}
