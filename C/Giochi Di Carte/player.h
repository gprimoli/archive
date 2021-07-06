typedef struct c_player *player;

player newplayer();
player crea_player(char *nome, int tipo);
void salva_player(player x);
void reset_player(player x);


int output_player(player x);

char *getnome(player x);
mazzo getmano(player x);
mazzo getprese(player x);
int getpunteggio(player x);

int getcash(player x);
void printcash(player x);

void modifica_punteggio(player x, int new);
void modifica_cash(player x, int new);
