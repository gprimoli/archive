typedef struct c_carta *carta;

carta crea_carta(int valore, int tipo);

int output_carta(carta x);
int getvalore(carta x);
int gettipo(carta x);

void del_carta(carta *x);
int eq_carte(carta x, carta y);
