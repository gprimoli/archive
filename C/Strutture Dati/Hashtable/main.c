#include <stdio.h>
#include "key.h"
#include "item.h"
#include "hashtable.h"

int main() {
  hashtable h=newHashtable(5);
  put(h, input_key(), input_item());
  put(h, input_key(), input_item());
  destroy(h);
  output(h);
  return 0;
}
