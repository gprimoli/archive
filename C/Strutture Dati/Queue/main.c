#include <stdio.h>
#include "item.h"
#include "coda.h"

int main() {
  coda c=newcoda(4);
  for(int i=0;i<3;i++)
    enqueue(c,input_item());
  for(int i=0;i<2;i++)
    dequeue(c);
  for(int i=0;i<6;i++)
    enqueue(c,input_item());
  leggicoda(c);
  return 0;
}
