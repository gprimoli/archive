/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: stack
  - Tipi usati: item, boolean;

Semantica:
  - stack è l’insieme delle sequenze S=a1,a2,…,an di tipo item
  - L’insieme stack contiene inoltre un elemento nil che rappresenta lo stack vuoto (privo di elementi)
*/

typedef struct c_stack *stack;

/*Specifica degli operatori
Sintattica:
    newstruct() -> stack
    push(stack) -> stack
    pop(stack) -> stack
    top(stack) -> item
    emptystack(stack) -> boolean
    destroystack(stack) -> stack

Semantica:
    newstruct() -> s
      - Post: s = nil
    push(s) -> s'
      - Post: s=<a1,a2,...,an> AND s'=<a1,a2,...,an,e>
    pop(s) -> s'
      - Pre: s=<a1,a2,...,an,an+1> n>0
      - Post: s'=<a1,a2,...,an>
    top(s) -> e
      - Pre: s=<a1,a2,...,an> n>0
      - Post: e = an
    emptystack(s) -> b
      - Post: se s=nil allora b = false altrimenti b = true
    destroystack(s) -> s'
      - Post: s=<a1,a2,...,an> AND s'=nil
*/

stack newstack();
void push(stack s, item e);
void pop(stack s);
item top(stack s);

int emptystack(stack s);
void destroystack(stack *s);
