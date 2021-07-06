#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "carta.h"
#include "mazzo.h"
#include "magic.h"
#define cls "\033[2J"

static int gruppi(mazzo a, mazzo b, mazzo c, mazzo d);
static void unisci_mazzo(mazzo a, mazzo b);

void magic(mazzo x){
  mischia_mazzo(x,0);
  printf(cls);
  mazzo a = crea_mazzo(1);
  mazzo b = crea_mazzo(1);
  mazzo c = crea_mazzo(1);
  mazzo d = crea_mazzo(1);
  int i;
  carta cart;
  printf("Ecco un semplice gioco di magia :)\n");
  sleep(2);
  printf("Inanzitutto ecco il mazzo\n");
  output_mazzo(x);
  printf("Adesso prendiamo le prime 21 carte di questo mazzo\n\n\n");
  sleep(3);
  for(i=0; i<21; i++)
    inserisci_carta(d, getcarta(x));
  output_mazzo(d);
  printf("\n\nTra queste 21 carte scegliene 1 e ricordatela\n");
  sleep(5);
  printf("Adesso iniziamo.\nDividerò per 3 volte queste carte in 3 gruppi da 7.\n");
  printf("Per 3 volte dovrai dirmi in che gruppo di carte si trova la tua carta\n");
  sleep(8);
  gruppi(a, b, c, d);
  gruppi(a, b, c, d);
  gruppi(a, b, c, d);
  for(i=0; i<11; i++)
    cart = getcarta(d);
  printf("La tua carta è:\n");
  output_carta(cart);
  sleep(4);
}

int gruppi(mazzo a, mazzo b, mazzo c, mazzo d){
  int i, risp;
  carta cart;
  printf(cls);
  for(i=0; i<7; i++){
    inserisci_carta(a,getcarta(d));
    inserisci_carta(b,getcarta(d));
    inserisci_carta(c,getcarta(d));
  }
  printf("Mazzo 1:\n");
  output_mazzo(a);
  printf("\nMazzo 2:\n");
  output_mazzo(b);
  printf("\nMazzo 3:\n");
  output_mazzo(c);
  while(1){
    printf("In quale dei 3 mazzi si trova la tua carta?\n");
    scanf("%d", &risp);
    switch (risp) {
      case 1: unisci_mazzo(d,b); unisci_mazzo(d,a); unisci_mazzo(d,c); return 1;
      case 2: unisci_mazzo(d,c); unisci_mazzo(d,b); unisci_mazzo(d,a); return 1;
      case 3: unisci_mazzo(d,a); unisci_mazzo(d,c); unisci_mazzo(d,b); return 1;
      default: printf("Risposta non valida\n"); break;
    }
  }

}

static void unisci_mazzo(mazzo a, mazzo b){
  int i;
  for(i=0; i<7; i++)
    inserisci_carta(a,getcarta(b));
}
