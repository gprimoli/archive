#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BStree.h"

struct node{
  item value;
  struct node *sx;
  struct node *dx;
};

struct bstree_c{
  struct node *root;
  int size;
};


//=======================================================//

static void checkstruct(bstree t){
  if(t == NULL){
    printf("L'albero binario di ricerca risulta NULL (bisogna usare la funzione newbstree() !!!)\n");
    exit(1);
  }
}

static void static_outputbstree(struct node *x){
  if(x != NULL){
    output_item(x->value);
    printf("SX\n");
    static_outputbstree(x->sx);
    printf("DX\n");
    static_outputbstree(x->dx);
  }
}

static int static_searchitem(struct node *x, item e){
  if(x == NULL)
    return 0;
  if(!eq(x->value,e))
    return 1;
  if(eq(x->value,e) > 0)
    return static_searchitem(x->sx,e);
  else
    return static_searchitem(x->dx,e);
}

static struct node * makenode(item e){
  struct node *new;
  new=malloc(sizeof(struct node));
  if(new != NULL){
    new->value = e;
    new->sx=NULL;
    new->dx=NULL;
  }
  return new;
}

static int static_insertitem(struct node **x, item e){
  if(*x == NULL){
    *x = makenode(e);
    if(x != NULL)
      return 1;//inserimento effettuato
    return -1;//inserimento non riuscito
  }else{
    if(!eq((*x)->value,e))
      return 0; // elemento già presente
    if(eq((*x)->value,e) < 0)
      static_insertitem(&((*x)->dx),e);
    else
      static_insertitem(&((*x)->sx),e);
  }
}

static item delmax(struct node **x){
  if((*x)->dx != NULL)
    delmax(&((*x)->dx));
  item e = (*x)->value;
  struct node *temp = *x;
  *x = (*x)->sx;
  free(temp);
  return e;
}

static int static_removeitem(struct node **x, item e){
  if(*x == NULL)
    return 0; //elemento non presente
  else{
    if(!eq((*x)->value,e)){
      struct node *temp;
      if((*x)->sx == NULL && (*x)->dx == NULL){
        temp = *x;
        *x = NULL;
        free(temp);
      }else{
        if((*x)->sx == NULL){
          temp = *x;
          *x= (*x)->dx;
          free(temp);
        }
        if((*x)->dx == NULL){
          temp = *x;
          *x= (*x)->sx;
          free(temp);
        }
        if((*x)->sx != NULL && (*x)->sx != NULL)
          (*x)->value = delmax(&(*x)->sx);
      }
      return 1; //eliminzaione effettuata
    }
    if(eq((*x)->value,e) > 0)
      static_removeitem(&((*x)->sx),e);
    else
      static_removeitem(&((*x)->dx),e);
  }
}

static item static_massimobstree(struct node *x){
  if(x->dx == NULL)
    return x->value;
  static_massimobstree(x->dx);
}

static item static_minimobstree(struct node *x){
  if(x->sx == NULL)
    return x->value;
  static_minimobstree(x->sx);
}

static void static_outputbstree_decrescente(struct node *x){
  if(x != NULL){
    static_outputbstree_decrescente(x->dx);
    output_item(x->value);
    static_outputbstree_decrescente(x->sx);
  }
}

static int static_n_nodi_piu_piccoli(struct node *x, int n){
    if(x->sx != NULL)
      n=static_n_nodi_piu_piccoli(x->sx,n);
    if(n){
      output_item(x->value);
      n--;
    }
    if(x->dx != NULL)
      n=static_n_nodi_piu_piccoli(x->dx,n);
    return n;

}

static int static_n_nodi_piu_grandi(struct node *x, int n){
    if(x->dx != NULL)
      n=static_n_nodi_piu_grandi(x->dx,n);
    if(n){
      output_item(x->value);
      n--;
    }
    if(x->sx != NULL)
      n=static_n_nodi_piu_grandi(x->sx,n);
    return n;

}
//=======================================================//



bstree newbstree(void){
  bstree t=malloc(sizeof(struct bstree_c));
  if(t != NULL){
    t->size=0;
    t->root=NULL;
    return t;
  }
  printf("Impossibile creare un Albero binario di ricerca\n");
  exit(0);
}

void inputbstree(bstree t){
  checkstruct(t);
  int n;
  printf("Quanti elementi vuoi inserire?\n");
  scanf("%d", &n);
  while(n){
    item e = input_item();
    insertitem(t,e);
    n--;
  }
  printf("Elementi inseriti\n");
}

void outputbstree(bstree t){
  checkstruct(t);
  if(sizeofbstree(t))
    static_outputbstree(t->root);
  else
    printf("L'albero è vuoto\n");
}

int sizeofbstree(bstree t){
  checkstruct(t);
  return t->size;
}

int searchitem(bstree t, item e){
  checkstruct(t);
    return static_searchitem(t->root,e);
}

int insertitem(bstree t, item e){
  checkstruct(t);
  int risultato = static_insertitem(&(t->root),e);
  if(risultato)
    t->size++;
  return risultato;
}

int removeitem(bstree t, item e){
  checkstruct(t);
  int risultato = static_removeitem(&(t->root), e);
  if(risultato)
    t->size--;
  return risultato;
}

item massimobstree(bstree t){
  checkstruct(t);
  return static_massimobstree(t->root);
}

item minimobstree(bstree t){
  checkstruct(t);
  return static_minimobstree(t->root);
}

void outputbstree_decrescente(bstree t){
  checkstruct(t);
  static_outputbstree_decrescente(t->root);
}

void n_nodi_piu_piccoli(bstree t){
  int n;
  printf("Quanti nodi vuoi stampare (dai più piccoli ai più grandi)\n");
  scanf("%d", &n );
  if (n>sizeofbstree(t))
    static_n_nodi_piu_piccoli(t->root, sizeofbstree(t));
  else
    static_n_nodi_piu_piccoli(t->root, n);
  printf("\n");
}

void n_nodi_piu_grandi(bstree t){
  int n;
  printf("Quanti nodi vuoi stampare (dai più grandi ai più piccoli)\n");
  scanf("%d", &n );
  if (n>sizeofbstree(t))
    static_n_nodi_piu_grandi(t->root, sizeofbstree(t));
  else
    static_n_nodi_piu_grandi(t->root, n);
  printf("\n");
}
