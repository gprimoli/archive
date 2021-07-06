#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

//=================================================//

struct c_stack{
  struct node *first;
};

struct node{
  item value;
  struct node *next;
};

//=================================================//

static struct node * makenode(item e, struct node *nxt){
  struct node *new=malloc(sizeof(struct node));
  if(new == NULL){
    printf("[ERROR] Memoria insufficiente per creare un nodo\n");
    exit(0);
  }else{
    new->value = e;
    new->next = nxt;
  }
  return new;
}

static void checkstruct(void *x){
  if(x == NULL){
    printf("Lo stack risulta NULL (bisogna usare la funzione newstack() !!!)\n");
    exit(1);
  }
}


static stack deletestack(stack s){
  checkstruct(s);
  struct node *temp = s->first;
  struct node *x;
  while(temp != NULL){
    x = temp;
    destroyitem(&(x->value));
    temp = temp->next;
    free(x);
  }
  s->first = NULL;
  return s;
}

//=================================================//

stack newstack(){
  stack s=malloc(sizeof(struct c_stack));
  if(s!=NULL){
    s->first = NULL;
  }else{printf("[ERROR] Memoria insufficiente per creare lo stack.\n"); exit(0);}
  return s;
}

void push(stack s, item e){
  checkstruct(s);
  struct node *newnode;
  newnode = makenode(e, s->first);
  s->first = newnode;
}

void pop(stack s){
  checkstruct(s);
  if(s->first != NULL){
  struct node *x;
  x = s->first;
  s->first = x->next;
  destroyitem(&(x->value));
  free(x);
  }
}

item top(stack s){
  checkstruct(s);
  if(s->first != NULL){
  return duplica(s->first->value);
  }
}

int emptystack(stack s){
  checkstruct(s);
  if (s->first == NULL)
    return 0;
  return 1;
}

void destroystack(stack *s){
  deletestack(*s);
  free(*s);
  *s=NULL;
}
