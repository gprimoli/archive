#include <stdio.h>
#include "stack.h"

int main() {
  stack l=newstruct();
  push(l);
  printf("%d", emptystack(l));
  return 0;
}
