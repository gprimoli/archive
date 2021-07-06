/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: coda
  - Tipi usati: item, boolean;

Semantica:
  - coda è l’insieme delle sequenze c=a1,a2,…,an di tipo item
  - L’insieme coda contiene inoltre un elemento nil che rappresenta la coda vuota (priva di elementi)
*/

typedef struct c_coda *coda;


/*Specifica degli operatori
Sintattica:
    newcoda() -> coda
    emptycoda(coda) -> boolean
    enqueue(coda) -> coda
    dequeue(coda) -> item,coda
    destroycoda(coda) -> coda
Semantica:
    newcoda() = c
      - Post: c=nil
    emptycoda(c) = b
      - Post: se c=nil allora b = false altrimenti b = true
    enqueue(c) = c'
      - Post: c=<a1,a2,...,an> AND c=<a1,a2,...,an,e>
    dequeue(c) = c'
      - Pre: c=<a1,a2,...,an> n>0
      - Post: c=<a1,a2,...,an> AND c=<a2,...,an>
    destroycoda(c) = c'
      - Post: c=<a1,a2,...,an> AND c'=nil
*/
//NOTA: posso usare n-1 posizioni!
coda newcoda(int n);
int emptycoda(coda c); //1 se piena

int enqueue(coda c, item e);
item dequeue(coda c);

void destroycoda(coda *c);

void leggicoda(coda c);
