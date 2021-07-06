/*Specifica della struttura struttura
Sintattica:
  - Tipi di riferimento: albero binario di ricerca
  - Tipi usati: item, boolean, integer;
Semantica:
  - bstree è l'insieme degli alberi binari di ricerca, dove se r è un item, tsx e tdx
    sono alberi binari di ricerca e r1 ϵ tsx e r2 ϵ tdx, se r1 < r < r2 allora <r,tsx.tdx>
    è un albero binario di ricerca
  - bstree contiene un elemento nil che identifica l'albero vuoto, privo di elementi

Specifica degli operatori
Sintattica:
newbstree(void) -> bstree
inputbstree(bstree) -> bstree'
outputbstree(bstree) -> void

sizeofbstree(bstree) -> integer
searchitem(bstree, item) -> boolean
insertitem(bstree, item) -> bstree'
removeitem(bstree, item) -> bstree'

massimobstree(bstree) -> item
minimobstree(bstree) -> item
outputbstree_decrescente(bstree) -> void
n_nodi_piu_piccoli(bstree, integer) -> void
n_nodi_piu_grandi(bstree, integer) -> void

Semantica:
newbstree(void) = b
post: b=nil
inputbstree(b) = b'
pre: b=nil
post: b=<a1,a2,…,an> AND per ogni  1 <= i<j <=n  ai,aj ∈ t (ai) != (aj)
outputbstree(b) = void
post: vengono stampati a video tutti gli elementi di b in ordine crescente


sizeofbstree(b) = n
post: b=<a1,a2,...,an> AND n>=0
searchitem(b, e) = flag
post: se e ϵ b allora flag=tre, altrimenti flag=false
insertitem(b, e) = b'
pre: e non appartiene a b
post: b'=b U {e}
removeitem(b, e) = b'
pre: e ϵ b
post: b'=b - {e}

massimobstree(b) = e
post: b=<r,tsx,tdx> e = massimobstree(tdx)
minimobstree(b) = e
post: b=<r,tsx,tdx> e = minimobstree(tsx)

outputbstree_decrescente(b) = void
post: vengono stampati a video tutti gli elementi di b in ordine decrescente
n_nodi_piu_piccoli(b,n) = void
post: vengono stampati a video gli n elementi di b più piccoli di n
n_nodi_piu_grandi(b,n) = void
post: vengono stampati a video gli n elementi di b più grandi di n

*/

typedef struct bstree_c *bstree;

bstree newbstree(void);//ok
void inputbstree(bstree t);//ok
void outputbstree(bstree t);//ok

int sizeofbstree(bstree t); //ok
int searchitem(bstree t, item e);//ok
int insertitem(bstree t, item e);//ok
int removeitem(bstree t, item e);//ok

item massimobstree(bstree t);//ok
item minimobstree(bstree t);//ok
void outputbstree_decrescente(bstree t);//ok
void n_nodi_piu_piccoli(bstree t);//ok
void n_nodi_piu_grandi(bstree t);//ok
