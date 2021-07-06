/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: btree
  - Tipi usati: item, boolean, integer, coda;
Semantica:
  - btree è l’insieme degli alberi binari, dove: se r ϵ item, t1 ϵ btree e t2 ϵ btree allora <r, t1, r2> ϵ btree
  - nil ϵ btree (albero vuoto)


Specifica degli operatori
Sintattica:
inputalbero(integer) -> btree
consbtree(item, btree, btree) → btree
emptybtree(btree) → boolean
post_order(btree) -> coda
pre_order(btree) -> coda
in_order(btree) -> coda
altezzaalbero(btree) -> integer
numeronodi(btree) ->  integer
bstree(btree) -> boolean

Semantica:
inputalbero(n) -> t
Pre: t = nil
Post: t = <a1,a2,…,an> AND ∀  1≤i<j≤n  ai,aj ∈ t (ai) ≠ (aj)
consbtree(e, t, t) → t
Post: b = <r, tsx, tdx>
emptybtree(t) → flag
Post: se t != nil allora flag = true altrimenti flag = false

post_order(t) -> c
Post: vengono caricati nella coda c' i nodi nell'ordine secondo il metodo di visita in postorder
pre_order(t) -> c
Post: vengono caricati nella coda c' i nodi nell'ordine secondo il metodo di visita in preorder
in_order(t) -> c
Post: vengono caricati nella coda c' i nodi nell'ordine secondo il metodo di visita in inorder

altezzaalbero(t) -> h
Post: t=<e,tsx,tdx> se altezza(tsx)>altezza(tdx) allora h=altezza(tsx), altrimenti h=altezza(tdx)
numeronodi(t) ->  n
Post: t=<e,tsx,tdx>  n=1+numeronodi(tsx)+numeronodi(tdx)
bstree(t) -> t
Post:
*/


typedef struct nodo *btree;

btree inputalbero(void);

void post_order(btree t, coda c);
void pre_order(btree t, coda c);
void in_order(btree t, coda c);

int altezzaalbero(btree t);
int numeronodi(btree t);
int bstree(btree t); //check if tree is bstree

int emptybtree(btree t);
btree consbtree(item val, btree sx, btree dx);
