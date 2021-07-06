#define NULLITEM NULL

typedef struct gg *item;


int getx(item x);
int eq(item x, item y);
//0 se sono uguali 1 se x>y -1 se x<y
item input_item();
item duplica(item x);
void output_item(item x);
void destroyitem(item *x);
