/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: key
  - Tipi usati: string, boolean, integer;
Semantica:
  - key è una stringa.

Specifica degli operatori
Sintattica:
hash(key, integer) -> integer
int eqkey(key, key) -> boolean
input_key() -> key

Semantica:
hash(k, m) -> n
Post: n è il risultato della codifica della key che è compresa tra 0≤k≤m
int eqkey(k1, k2) -> b
Post: se k1 = k2 allora flag = true altrimenti flag = false
input_key() -> k
Post: 
*/

typedef char *key;

int hash(key k, int m);
int eqkey(key x, key y);
char * input_key();
