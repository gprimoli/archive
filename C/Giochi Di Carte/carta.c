#include <stdio.h>
#include <stdlib.h>
#include "carta.h"

struct c_carta{
  int valore;
  int tipo;
};

static carta newcarta(){
  carta x=malloc(sizeof(struct c_carta));
  if(x == NULL){
    printf("[ERROR] Memoria insufficiente per creare una carta. Libera RAM!\n");
    exit(0);
  }
  return x;
}

carta crea_carta(int valore, int tipo){
  carta x = newcarta();
  x->valore = valore;
  x->tipo = tipo;
  return x;
}


int output_carta(carta x){
  if(x == NULL){
    printf("CARTA INESISTENTE\n");
    return 0;
  }
  printf("%d ", x->valore);
  switch (x->tipo) {
    case 1: printf("ORO\n"); break;
    case 2: printf("SPADE\n"); break;
    case 3: printf("BASTONI\n"); break;
    case 4: printf("COPPE\n"); break;
    default: printf("Tipo Inesistente\n"); break;
  }
  return 1;
}

int getvalore(carta x){
  if(x == NULL){
    printf("CARTA INESISTENTE\n");
    return 0;
  }
  int c = x->valore;
  return c;
}

int gettipo(carta x){
  if(x == NULL){
    printf("CARTA INESISTENTE\n");
    return 0;
  }
  int c = x->tipo;
  return c;
}

void del_carta(carta *x){
  free(*x);
  *x=NULL;
}

int eq_carte(carta x, carta y){
  if(x == NULL || y == NULL){
    printf("CARTA INESISTENTE\n");
    return 0;
  }
  if(x->valore == y->valore && x->tipo == y->tipo)
    return 1;
  return 0;
}
