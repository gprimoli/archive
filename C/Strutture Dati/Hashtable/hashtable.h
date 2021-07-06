/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: hashtable
  - Tipi usati: item, boolean, integer;
Semantica:
  - hashtable è l’insieme di elementi H={a1,a2,…,an} di tipo item
  - nil ϵ H (hashtable vuoto)
  - Un item contiene un campo chiave di tipo key e dei dati associati

Specifica degli operatori
Sintattica:
newHashtable(int) -> hashtable
put(hashtable, key, item) -> hashtable
get(hashtable, key) -> item
delete(hashtable, key) -> hashtable
destroy(hashtable) -> hashtable
output(hashtable) -> void

Semantica:
newHashtable(n) -> h'
Post: h = {}
put(h, k, e) -> h'
Pre: ai con 1 ≤ i ≤ n deve avere ai->key != k;
Post: h = {a1, a2, … an}, h’ = {a1, a2, …, e,..., an}
get(h, k) -> e
Pre: h = {a1, a2, …, an} n>0
Post: e = ai con 1 ≤ i ≤ n se ai->key=k
delete(h, k) -> h'
Pre: h = {a1, a2, …, an} n>0, ai->key=k con 1 ≤ i ≤ n
Post: l’ = <a1, a2, …, ai-1, ai+1, ..., an>
destroy(h) -> h'
Post: h = {a1, a2, … an}, h' = {}
output(h) -> void
Post: stampa a video gli elementi dell'hashtable


*/

typedef struct hash *hashtable;

hashtable newHashtable(int size);
int put(hashtable h, key k, item e);
item get(hashtable h, key k);
int delete(hashtable h, key k);
void destroy(hashtable h);
void output(hashtable h);
