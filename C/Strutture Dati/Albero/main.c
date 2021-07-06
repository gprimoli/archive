#include <stdio.h>
#include "item.h"
#include "coda.h"
#include "albero.h"
#define MAX 20

int main() {
  btree z= inputalbero();
  coda c=newcoda(5);
  in_order(z, c);
  leggicoda(c);
  printf("\n");
  printf("%d\n",sbtree(z) );
  return 0;
}
