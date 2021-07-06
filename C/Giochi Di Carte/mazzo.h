#define NUM_CARTE_IT 40
#define NUM_CARTE_FR 108

typedef struct c_mazzo *mazzo;
//TIPO 1 IT || 2 FR
void debug(mazzo x);
mazzo crea_mazzo(int tipo);
int inserisci_carta(mazzo x, carta y);
void inizialliza_mazzo(mazzo x);

int output_mazzo(mazzo x);

carta getcarta(mazzo x);
void reset_mazzo(mazzo x);
void del_mazzo(mazzo *x);
void mischia_mazzo(mazzo x, int tentativo);
