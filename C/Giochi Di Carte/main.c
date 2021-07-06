#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "carta.h"
#include "mazzo.h"
#include "player.h"
#include "solitario.h"
#include "magic.h"

#define cls "\033[2J"

static void extract(char in[]);
int menu();
player menu_player();

int main(int argc, char *argv[]) {
  menu();
  printf("\n\t\t\t\tQuesto programma è stato realizzato da Gennaro Pio Rimoli :)\n");
  //sleep(3);
  return 0;
}

int menu(){
  int rispota;
  mazzo m = crea_mazzo(1);
  inizialliza_mazzo(m);
  printf(cls);
  player p = menu_player();
  printf(cls);
  while(1){
    extract("name.txt");
    output_player(p);
    printf("Menu:\n");
    printf("[1] Solitario Loop\n");
    printf("[2] Solitario\n");
    printf("[3] Magic\n");
    printf("\n\n\n...\n\n\n");
    printf("[97] Bancarotta\n"); //debug only
    printf("[98] Guadagna 1000\n"); //debug only
    printf("[99] Esci\n");
    scanf("%d", &rispota);
    switch (rispota) {
      case 1: solitario_loop(m, p); break;
      case 2: solitario_lento(m, p); break;
      case 3: magic(m); break;
      case 97: printf(cls); modifica_cash(p,0); break;
      case 98: printf(cls); modifica_cash(p,1000); break;
      case 99: reset_mazzo(m); del_mazzo(&m); salva_player(p); return 1;
      default: printf("Scelta non contemplata\n"); break;
    }
  }
}

player menu_player(){
  char nome[255];
  printf("Inserisic il tuo nome\n");
  scanf("%s", nome);
  return(crea_player(nome, 1));
}


static void extract(char in[]){
  FILE *input = fopen(in, "r");
  char testo[255];
  int res;
  for(res = fscanf(input, "%s", testo); res != EOF; res = fscanf(input, "%s", testo)){
    if(!strcmp(testo, "*"))
      printf(" ");
    else
      printf("%s\n", testo);
  }
}
