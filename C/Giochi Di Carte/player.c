#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "carta.h"
#include "mazzo.h"
#include "player.h"
#define DIM 255

char path[DIM] = "data/";

struct c_player {
  char nome[DIM];
  mazzo mano;
  mazzo prese;
  int punteggio;
  int cash;
};

player newplayer(){
  player x=malloc(sizeof(struct c_player));
  if(x == NULL){
    printf("[ERROR] Memoria insufficiente per creare un player. Libera RAM!\n");
    exit(0);
  }
  return x;
}

player crea_player(char *nome, int tipo){
  player x = newplayer();
  strcat(path, nome);
  strcat(path, ".dat");
  FILE *in = fopen(path, "r");
  if(in == NULL){
    printf("Benvenuto %s\n", nome);
    sleep(1);
    in = fopen(path, "w");
    fprintf(in, "1000");
    x->cash = 1000;
  }else{
    printf("Bentornato %s\n", nome);
    fscanf(in, "%d", &(x->cash));
    sleep(1);
  }
  switch (tipo) {
    case 1: x->mano = crea_mazzo(1); x->prese = crea_mazzo(1); break;
    case 2: x->mano = crea_mazzo(2); x->prese = crea_mazzo(2); break;
    default: printf("Tipo non valido\n"); return NULL;
  }
  strcpy(x->nome, nome);
  x->punteggio = 0;
  fclose(in);
  return x;
}

void salva_player(player x){
  FILE *in =fopen(path, "w");
  fprintf(in, "%d", x->cash);
  fclose(in);
  reset_mazzo(x->mano);
  reset_mazzo(x->prese);
  del_mazzo(&(x->mano));
  del_mazzo(&(x->prese));
}

void reset_player(player x){
  x->punteggio = 0;
  reset_mazzo(x->mano);
  reset_mazzo(x->prese);
}

char *getnome(player x){
  char *nome = malloc(DIM * sizeof(char));
  strcpy(nome, x->nome);
  return nome;
}

int output_player(player x){
  printf("\nNome profilo: %s\n", x->nome);
  printf("Saldo: %d\n\n", x->cash);
}

mazzo getmano(player x){
  return x->mano;
}

mazzo getprese(player x){
  return x->prese;
}

int getpunteggio(player x){
  return x->punteggio;
}

void modifica_punteggio(player x, int new){
  x->punteggio = new;
}

int getcash(player x){
  return x->cash;
}

void printcash(player x){
  printf("Il tuo saldo è %d\n\n", x->cash);
}

void modifica_cash(player x, int new){
  x->cash = new;
}
