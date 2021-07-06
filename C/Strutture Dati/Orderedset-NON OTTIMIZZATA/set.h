/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: set
  - Tipi usati: item, boolean, integer;
Semantica:
  - I valori di tipo set sono sottoinsiemi di elementi di tipo item
  - nil ϵ set (set vuoto)

Specifica degli operatori
Sintattica:
newSet() -> set
sizeofset(set) -> integer
searchitemSet(set, item) -> boolean
insertSet(set, item) -> set
removeSet(set, item) -> set
unionSet(set, set) -> set
intersectSet(set, set) -> set
leggiset(set) -> void

Semantica:
newSet() -> s
Post: s = ∅
sizeofset(s) -> n
Post: n è il numero di elementi contenuti in s (n = |s|)
searchitemSet(s, e) -> b
Post: se e ∈ s allora b = true altrimenti b = false
insertSet(s, e) -> s'
Pre: e ∉ s
Post: s’ = s ∪ {e}
removeSet(s, e) -> s'
Pre: e ∈ s
Post: s = s’ ∪ {e} AND e ∉ s’
unionSet(s1, s2) -> s'
Post: s’ = s1 ∪ s2 (s’ contiene tutti gli elementi di s1 ed s2)
intersectSet(s1, s2) -> s'
Post:s’ = s1 ∩ s2 (s’ contiene tutti gli elementi comuni ad s1 ed s2)
leggiset(s) -> void
Post: stampa a video gli elementi del set.

*/

typedef struct set_c *set;

set newSet(void);
int sizeofset(set s);
int searchitemSet(set s, item e);

int insertSet(set s, item e); // inseriamo e in s
int removeSet(set s, item e); // rimuoviamo e da s
int unionSet(set s1, set s2); // aggiunge elementi di s2 ad s1
int intersectSet(set s1, set s2); // rimuove da s1 gli elementi che non sono in s2
int leggiset(set s);
