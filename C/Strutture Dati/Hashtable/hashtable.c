#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "key.h"
#include "hashtable.h"

struct elemento {
  key chiave;
  item value;
  struct elemento *next;
};

struct hash{
  int size;
  struct elemento **table;
};


hashtable newHashtable(int size){
  hashtable x=malloc(sizeof(struct hash));
  if(x != NULL){
    x->size = size;
    x->table=malloc(size*sizeof(struct elemento *));
    if(x->table != NULL){
      for(int i=0;i<size;i++)
        x->table[i]=NULL;
      return x;
    }else
      printf("[ERROR] Spazio insufficiente per creare la tabella di elementi\n");
  }else
    printf("[ERROR] Spazio insufficiente per creare la tabella hash\n");
}

int put(hashtable h, key k, item e){
  int id = hash(k,h->size);
  struct elemento *first , *temp;
  first = temp = h->table[id];
  while(temp){
    if(eqkey(temp->chiave,k))
      return -1;
    temp = temp->next;
  }
  struct elemento *new = malloc(sizeof(struct elemento));
  if(new != NULL){
    new->chiave = k;
    new->value = e;
    new->next = first;
    h->table[id] = new;
    return 1;
  }
  return 0;
}

item get(hashtable h, key k){
  int id = hash(k,h->size);
  struct elemento *temp;
  temp = h->table[id];
  while(temp){
    if(eqkey(temp->chiave,k))
      return temp->value;
    temp = temp->next;
  }
  return NULL;
}

int delete(hashtable h, key k){
  int id = hash(k,h->size);
  struct elemento *temp, *prec;
  prec = temp = h->table[id];
  while(temp){
    if(eqkey(temp->chiave,k)){
      if(prec = temp)
        h->table[id] = temp->next;
      else
        prec->next = temp->next;
      destroyitem(&(temp->value));
      return 1;
    }
    prec = temp;
    temp = temp->next;
  }
  return 0;
}

static void destroy_item_list(struct elemento *temp){
  struct elemento *x;
  while(temp){
    x=temp;
    destroyitem(&(x->value));
    temp = temp->next;
  }
}

void destroy(hashtable h){
  int i;
  for(i=0; i<h->size; i++)
    destroy_item_list(h->table[i]);
  free(h->table);
  h->table = NULL;
}

void output(hashtable h){
  int i;
  if(h->table == NULL){
    printf("La tabellaHash è NULL\n");
  }else{
    struct elemento *temp;
    for(i=0; i<h->size ;i++){
      temp = h->table[i];
      printf("Posizione: %3d\n", i);
      while(temp){
        output_item(temp->value);
        temp = temp->next;
      }
    }
  }
}
