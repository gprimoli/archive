#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

//=================================================//

struct lista{
  int size;
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
    printf("La list risulta NULL (bisogna usare la funzione newlist() !!!)\n");
    exit(1);
  }
}

static list deletelist(list l){
  checkstruct(l);
  struct node *temp = l->first;
  struct node *x;
  while(temp != NULL){
    x = temp;
    destroyitem(&(x->value));
    temp = temp->next;
    free(x);
  }
  l->first = NULL;
  l->size = 0;
  return l;
}

//=================================================//
static int checkdoppione(list l, item e){
    struct node *temp = l->first;
    while(temp != NULL){
      if(eq(e,temp->value))
        return 0;
      temp = temp->next;
    }
    return 1;
}

list newlist(){
  list l=malloc(sizeof(struct lista));
  if(l!=NULL){
    l->size = 0;
    l->first = NULL;
  }else{printf("[ERROR] Memoria insufficiente per creare la lista.\n"); exit(0);}
  return l;
}

list inputlist(int n){
  if(n==0){
    return newlist();
  }
  list l=newlist();
  item e;
  int i=0;
  printf("Inserimento del %d elemento\n", i);
  l->first = makenode(input_item(), NULL);
  struct node *temp = l->first;
  for(i=1;i<n;i++){
    printf("Inserimento del %d elemento\n", i);
    e=input_item();
    if(checkdoppione(l,e)){
      temp->next = makenode(e, NULL);
      temp = temp->next;
    }else{
      printf("Impossibile inserire l'elemento:");
      output_item(e);
      printf("è già presente all'interno della lista\nRiprova\n");
      i--;
    }
  }
  l->size = n;
  return l;
}

void outputlist(list l){
  checkstruct(l);
  if(sizeoflist(l)){
    struct node *temp = l->first;
    int i;
    for(i=0; temp != NULL; i++){
      printf("Il valore dell'elemento %d è:\n", i);
      output_item(temp->value);
      temp = temp->next;
    }
  }else{printf("La lista è vuota!\n");}
}

list clonelist(list l){
  checkstruct(l);
  if(l->size == 0){return NULL;}
  list l1=newlist();
  struct node *temp = l->first;
  l1->first = makenode(temp->value, NULL);
  struct node *new = l1->first;
  while(temp->next != NULL){
    new->next = makenode((temp->next)->value, NULL);
    new = new->next;
    temp = temp->next;
  }
  l1->size = l->size;
  return l1;
}

list reverselist(list l){
  checkstruct(l);
  struct node *precedente = NULL;
  struct node *attuale = l->first;
  struct node *successivo = NULL;
  while(attuale != NULL){
    successivo = attuale->next;
    attuale->next = precedente;
    precedente = attuale;
    attuale = successivo;
  }
  l->first =precedente;
  return l;
}

void destroylist(list *l){
  *l=deletelist(*l);
  free(*l);
  *l=NULL;
}

//=================================================//

int sizeoflist(list l){
  checkstruct(l);
  return (l->size);
}

item getitem(list l, int i){
  checkstruct(l);
  item e;
  struct node *temp = l->first;
  if(i<0 || i>sizeoflist(l)){return NULLITEM;}
  while(i){
      e = temp->value;
      temp=temp->next;
    i--;
  }
  return e;
}

int searchitem(list l, item x){
  checkstruct(l);
  struct node *temp = l->first;
  item e;
  while(temp != NULL){
    e = temp->value;
    if(eq(x,e)){
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int positem(list l, item x){
  checkstruct(l);
  struct node *temp = l->first;
  item e;
  int i=1;
  while(temp != NULL){
    e = temp->value;
    if(eq(x,e)){
      return i;
    }
    temp = temp->next;
    i++;
  }
  printf("[ERROR] Elemento non presente all'interno della lista!\n");
  return -1;
}

int insertitem(list l, item e, int posizione){
  checkstruct(l);
  if(posizione<0 || posizione > sizeoflist(l)){
    printf("Impossibile inserire l'elemento in posizione: %d\n", posizione);
    return 0;
  }else{
    struct node *newnode;
    if(!posizione){
      newnode = makenode(e, l->first);
      l->first = newnode;
    }else{
      int i;
      struct node *precedente = l->first;
      for(i=0; i<posizione-1 ;i++)
        precedente = precedente->next;
      newnode = makenode(e,precedente->next);
      precedente->next = newnode;
    }
  l->size++;
  return 1;
  }
}

int removeitem(list l, int posizione){
  checkstruct(l);
  if(posizione<0 || posizione > sizeoflist(l)){
    printf("Impossibile rimuovere l'elemento in posizione: %d\n", posizione);
    return 0;
  }else{
    struct node *x;
      if(!posizione){
        x = l->first;
        l->first = x->next;
        destroyitem(&(x->value));
        free(x);
      }else{
        int i;
        struct node *precedente = l->first;
        for(i=0;i<posizione-1;i++)
          precedente = precedente->next;
        x = precedente->next;
        precedente->next = x->next;
        destroyitem(&(x->value));
        free(x);
      }
    l->size--;
    return 1;
  }
}
