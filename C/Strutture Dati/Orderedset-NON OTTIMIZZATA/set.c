#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "set.h"

struct set_c{
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
  }else{
    new->value = e;
    new->next = nxt;
  }
  return new;
}
//=================================================//

set newSet(void){
  set s=malloc(sizeof(struct set_c));
  if(s != NULL){
    s->size = 0;
    s->first = NULL;
  }else{printf("[ERROR] Memoria insufficiente per creare set\n"); exit(0);}
  return s;
}

int sizeofset(set s){
  if(s != NULL)
    return s->size;
  return -1;
}

int searchitemSet(set s, item e){
  if(s == NULL)
    return -1;//Set NULL
  struct node *temp = s->first;
  while(temp != NULL){
    int res=eq(e, temp->value);
    if(!res)
      return 1;//Trovato
    if(res > 0)
      return 0;//Non trovato
    temp = temp->next;
  }
  return 0;//Non trovato
}

//=================================================//

int insertSet(set s, item e){
  if(s == NULL)
    return -1;//Set NULL

  struct node *temp = s->first;
  struct node *newnode;
  int great = 0;

  if(temp == NULL){
    s->first = makenode(e,NULL);
    if(s->first == NULL){
      s->size++;
      return 1;
    }else
      return 0;
  }

  if(eq(temp->value,e) > 0){
    newnode = makenode(e,s->first);
    if(newnode == NULL)
      return 0;
    s->first = newnode;
    s->size++;
    return 1;
  }

  while(temp->next != NULL && !great) {
    int ris = eq(temp->next->value,e);
    if(!ris){
      printf("Elemento già presente\n");
      return 0;
    }
    if(ris>0)
      great = 1;
    else
      temp = temp->next;
  }
  newnode = makenode(e,temp->next);
  if(newnode == NULL)
    return 0;
  temp->next = newnode;
  s->size++;
  return 1;
}

int removeSet(set s, item e){
  if(s == NULL)
    return -1;//Set NULL
  int res = eq(s->first->value , e);
  int great = 0;
  struct node *temp = s->first;
  if(!res){
    s->first = s->first->next;
    destroyitem(&(temp->value));
    free(temp);
    s->size--;
    return 1;
  }
  if(res > 0)
    return 0;
  while (temp->next != NULL && !great) {
    res = eq(temp->next->value , e);
    if(!res){
      struct node *temp1 = temp->next;
      temp->next = temp1->next;
      destroyitem(&(temp1->value));
      free(temp1);
      s->size--;
      return 1;
    }else{
      if(res > 0)
        return 0;
      else
        temp = temp->next;
    }
  }
}

int unionSet(set s1, set s2){
  if(s1->first == NULL || s2->first == NULL)
    return -1;

  struct node *temps2 = s2->first;
  while (temps2 != NULL) {
    if(!searchitemSet(s1, temps2->value))
      insertSet(s1, temps2->value);
    temps2 = temps2->next;
  }
}

int intersectSet(set s1, set s2){
  if(s1->first == NULL || s2->first == NULL)
    return -1;

  struct node *temps2 = s2->first;
  while (temps2 != NULL) {
    if(!searchitemSet(s1, temps2->value))
      removeSet(s1, temps2->value);
    temps2 = temps2->next;
  }
}


int leggiset(set s){
  if(s == NULL){
    printf("Set vuoto\n");
    return 0;
  }
  struct node *temp = s->first;
  while(temp != NULL){
    output_item(temp->value);
    temp = temp->next;
  }
  return 1;
}
