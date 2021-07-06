#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BStree.h"

int main() {
  bstree t=newbstree();
  inputbstree(t);
  outputbstree(t);
  removeitem(t,input_item());

  outputbstree(t);


/*
removeitem(t,input_item());

outputbstree(t);
*/
  return 0;
}
