#include <stdio.h>
#include "item.h"
#include "set.h"

int main() {
  set s=newSet();
  set s2=newSet();
  for(int i=0;i<4;i++){
    item e = input_item();
    insertSet(s,e);
  }
  printf("\n");
  for(int i=0;i<4;i++){
    item e = input_item();
    insertSet(s2,e);
  }
  intersectSet(s,s2);
  leggiset(s);

  return 0;
}
