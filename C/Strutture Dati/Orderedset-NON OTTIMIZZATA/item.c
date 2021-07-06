#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct gg{
  int x;
};

//=================================================//

static void checkstruct(item x){
  if(x == NULL){
    printf("L'item risulta NULL (bisogna usare la funzione newitem() !!!)\n");
    exit(1);
  }
}

static item newitem(){
  item x=malloc(sizeof(struct gg));
  if(x==NULL){
    printf("[ERROR] Memoria insufficiente per creare un item\n");
    exit(0);
  }
  return x;
}

//=================================================//

int getx(item x){
  int c = x->x;
  return c;
}

int eq(item x, item y){
  checkstruct(x);
  checkstruct(y);
  return (x->x - y->x);
}

item input_item(){
  item x=newitem();
  checkstruct(x);
  printf("INSERISCI UN NUMERO:\n");
  scanf("%d", &x->x);
  return x;
}

item duplica(item x){
  item y=newitem();
  checkstruct(y);
  y->x=x->x;
  return y;

}

void output_item(item x){
  if(x == NULL){
    printf("Item vuoto\n");
  }
  printf("%d\n", x->x);
}

void destroyitem(item *x){
  free(*x);
  *x=NULL;
}
