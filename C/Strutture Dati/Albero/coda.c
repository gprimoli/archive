#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "coda.h"

#define MAX 30

struct c_coda{
  item *arr;
  int size;
  int head, tail;
};

//=================================================//

static void checkstruct(void *x){
  if(x == NULL){
    printf("La coda risulta NULL (bisogna usare la funzione newcoda() !!!)\n");
    exit(1);
  }
}

//=================================================//

coda newcoda(int n){
  coda c=malloc(sizeof(struct c_coda));
  checkstruct(c);
  if(n>1){
    c->size = n;
  }else{
    printf("[WARNING]Hai provato a creare una coda con meno di 1 elemento\n Abbiamo allocato quindi un'array da %d\n", MAX);
    c->size = MAX;
  }
  c->head=0;
  c->tail=0;
  c->arr=malloc((c->size)*sizeof(item));
  if(c->arr == NULL){
    printf("Spazio insufficiente per creare l'array di elementi\n");
    free(c);
    exit(0);
  }
  return c;
}

int emptycoda(coda c){
  checkstruct(c);
  return !((c->head) == (c->tail));
}

int enqueue(coda c,item e){
  checkstruct(c);
  if(c->head == ((c->tail + 1) % c->size)){
    printf("[WARNING] Coda piena.\n");
    c->arr=realloc(c->arr, (c->size * 2)*sizeof(item));
    if(c->arr!=NULL){
      int oldsize = c->size;
      c->size = c->size*2;
      if((c->head)>(c->tail)){
          for(int y=c->head; y<oldsize; y++)
            c->arr[oldsize+y]=c->arr[y];
          c->head=c->head+oldsize;
      }
      printf("Riallocazione delo spazio: [ESEGUITO]\n");
      enqueue(c,e);
      return 1;
    }
    return 0;
  }
  c->arr[c->tail] = e;
  c->tail = (c->tail + 1) % c->size;
  return 1;
}

item dequeue(coda c){
  checkstruct(c);
  if(c->head != c->tail){
    item e = c->arr[(c->head)];
    c->head = (c->head + 1) % c->size;
    return e;
  }
  return NULLITEM;
}


void destroycoda(coda *c){
  checkstruct(c);
  free((*c)->arr);
  free(*c);
  *c=NULL;
}


void leggicoda(coda c){
  checkstruct(c);
  int i = (c->head);
  if(c->head != c->tail){
  do {
    output_item(c->arr[i]);
    i= (i+1) % (c->size);
  } while(i != c->tail);
}else
  printf("La coda è vuota\n");
}
