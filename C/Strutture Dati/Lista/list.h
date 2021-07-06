/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: list
  - Tipi usati: item, boolean, integer;

Semantica:
  - list è l’insieme delle sequenze L=a1,a2,…,an di tipo item
  - L’insieme list contiene inoltre un elemento nil che rappresenta la lista vuota (priva di elementi)
*/

typedef struct lista *list;

/*Specifica degli operatori
Sintattica:
    newlist() -> list
    inputlist(integer) -> list
    outputlist(list) -> void
    clonelist(list) -> list
    reverselist(list) -> list
    destroylist(list) -> list
    sizeoflist(list) -> integer
    getitem(list, integer) -> item
    searchitem(list, item) -> integer
    positem(list, item) -> integer
    insertitem(list, item, integer) -> list
    removeitem(list, integer) -> list

Semantica:
    newlist() -> l
      - Post: l = nil
    inputlist(n) -> l
      - Post: se n=0 l=nil altrimenti l = <a1, a2, …, an>
    outputlist(l)
      - Post: stampa a video gli elementi della lista.
    cloneList(l) -> l’
      - Post: l = <a1, a2, …, an> AND l’ = <a1, a2, …, an>
    reverseList(l) -> l’
      - Post: l = <a1, a2, …, an> AND l’ = <an, ..., a2, a1>
    destroylist(l) -> l'
      - Post: l = <a1, a2, …, an> AND l’ = nil
    sizeoflist(l) -> n
      - Post: l = <a1, a2, …, an> AND n ≥ 0
    getitem(l, pos) -> e
      - Pre: pos >= 0 AND sizeList(l) > pos
      - Post: e è l’elemento che occupa in l la posizione pos
    searchitem(l, e) -> flag
      - Post: flag = TRUE se e è presente all'interno di l, altrimenti flag = FALSE
    positem(l, e) -> p
      - Post: se e è contenuto in l allora p è la posizione della prima occorrenza di e in l, altrimenti p = -1
    insertitem(l, pos, e) -> l’
      - Pre: sizeList(l) ≥ pos
      - Post: l’ si ottiene da l inserendo e in posizione pos
    removeitem(l, pos) -> l’
      - Pre: sizeList(l) > pos
      - Post: l’ si ottiene da l eliminando l’elemento in posizione pos

*/
/*NB: Esiste ma non serve perchè è incluso in inputlist(0)*/
list newlist();                                        //OK
//======================================================//

list inputlist(int n);                                 //OK
void outputlist(list l);                               //OK
list clonelist(list l);                                //OK
list reverselist(list l);                              //OK
void destroylist(list *l);                             //OK

int sizeoflist(list l);                                //OK
item getitem(list l, int i);                           //OK
int searchitem(list l, item x);                        //OK
int positem(list l, item x);                           //OK
int insertitem(list l, item e, int posizione);         //OK
int removeitem(list l, int posizione);                 //OK
