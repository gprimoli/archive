#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"
#include "albero.h"

struct nodo{
  item value;
  struct nodo *sx;
  struct nodo *dx;
};

btree inputalbero(){
  item x = input_item();
  if(getx(x) == -1)
    return NULL;
  btree sx = inputalbero();
  btree dx = inputalbero();
  return consbtree(x,sx,dx);
}

void pre_order(btree t, coda c){
  if(emptybtree(t)){
    enqueue(c, duplica(t->value));
    pre_order(t->sx,c);
    pre_order(t->dx,c);
  }
}

void post_order(btree t, coda c){
  if(emptybtree(t)){
    post_order(t->sx,c);
    post_order(t->dx,c);
    enqueue(c, duplica(t->value));
  }
}

void in_order(btree t, coda c){
  if(emptybtree(t)){
    in_order(t->sx,c);
    enqueue(c, duplica(t->value));
    in_order(t->dx,c);
  }
}

int altezzaalbero(btree t){
  if(t->sx == NULL && t->dx == NULL)
    return 0;
  int hsx=0, hdx=0;
  if(t->sx != NULL)
    hsx = 1 + altezzaalbero(t->sx);
  if(t->dx != NULL)
    hdx = 1 + altezzaalbero(t->dx);
  if(hsx>hdx)
    return hsx;
  else
    return hdx;
}

int numeronodi(btree t){
  if(t->sx == NULL && t->dx == NULL)
    return 1;
  int hsx=0, hdx=0;
  if(t->sx != NULL)
    hsx = 1 + altezzaalbero(t->sx);
  if(t->dx != NULL)
    hdx = 1 + altezzaalbero(t->dx);
  return 1+hdx+hsx;
}

static int static_bstree(btree t, int min, int max){
  if(t==NULL)
    return 1;
  else{
    if(min != -1 && getx(t->value) < min)
      return 0;
    if(max != -1 && getx(t->value) > max)
      return 0;
  }
  return (static_bstree(t->sx,min,getx(t->value)) && static_bstree(t->dx,getx(t->value),max));
}

int bstree(btree t){
  return static_bstree(t,-1,-1);
}

int emptybtree(btree t){
  if(t != NULL)
    return 1;
  return 0;
}

btree consbtree(item val, btree sx, btree dx){
  btree t = malloc(sizeof(struct nodo));
  if(t != NULL){
    t->value= val;
    t->sx = sx;
    t->dx = dx;
    return t;
  }
  return NULL;
}

/*
bree ricostruisci(coda qpre, coda qin){
  item e = dequeue(qpre);
  item e1 = dequeue(qin);
  if(!emptycoda(qin)){
    coda qsx,qdx;
    while()
      enqueue(qsx, dequeue(qin));
    while()//rimuovi root
      enqueue(qdx, dequeue(qin));
    consbtree(e,ricostruisci(qpre,qsx),ricostruisci(qpre,qdx));
  }else
    return consbtree(e1,NULL,NULL);

}
*/
/*
btree newbtree(void){
  return NULL;
}
*/
