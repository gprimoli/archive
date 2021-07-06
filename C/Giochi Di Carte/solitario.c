#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "carta.h"
#include "mazzo.h"
#include "player.h"
#include "solitario.h"
#define cls "\033[2J"

static int solitario(mazzo m, int tentativo, player p){
  printf(cls);
  mischia_mazzo(m,tentativo);
  carta c;
  int i, flag;
  for(i=1, flag=0, c = getcarta(m); c != NULL && !flag; i++, c = getcarta(m)){
    if(i == 1){
      printf("Uno: ");
      output_carta(c);
      if(getvalore(c) == 1)
        flag++;
      }
      if(i == 2){
        printf("Due: ");
        output_carta(c);
        if(getvalore(c) == 2)
        flag++;
      }
      if(i == 3){
        i = 0;
        printf("Tre: ");
        output_carta(c);
        if(getvalore(c) == 3)
        flag++;
      }
    }
  if(!flag){
    printf("Hai vinto!\n");
    modifica_cash(p, getcash(p) + 100);
    return 1;
  }else{
    printf("Hai perso, ritenta sarai più fortunato.\n\n\n");
    modifica_cash(p, getcash(p) - 1);
    return 0;
  }
}

int solitario_lento(mazzo m, player p){
  printf(cls);
  if(getcash(p) <= 0){
    printf("Non hai abbastanza credito per giocare\n\n");
    sleep(2);
    return 0;
  }
  mischia_mazzo(m,0);
  carta c;
  int i, flag;
  for(i=1, flag=0, c = getcarta(m); c != NULL && !flag; i++, c = getcarta(m)){
    sleep(1);
    if(i == 1){
      printf("Uno: ");
      output_carta(c);
      if(getvalore(c) == 1)
        flag++;
      }
      if(i == 2){
        printf("Due: ");
        output_carta(c);
        if(getvalore(c) == 2)
        flag++;
      }
      if(i == 3){
        i = 0;
        printf("Tre: ");
        output_carta(c);
        if(getvalore(c) == 3)
        flag++;
      }
    }
  if(!flag){
    printf("Hai vinto!\n");
    modifica_cash(p, getcash(p) + 100);
    return 1;
  }else{
    printf("Hai perso, ritenta sarai più fortunato.\n\n\n");
    modifica_cash(p, getcash(p) - 1);
    return 0;
  }
}

int solitario_loop(mazzo m, player p){
  int i, flag;
  printf(cls);
  if(getcash(p) <= 0){
    printf("Non hai abbastanza credito per giocare\n\n");
    sleep(2);
    return 0;
  }
  for(i=0, flag=0; !flag; i++)
    if(solitario(m,i,p))
      flag++;
  printf("Hai vinto dopo %d tentativi\n\n\n\n", i);
  return 1;
}
