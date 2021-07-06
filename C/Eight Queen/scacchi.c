#include <stdio.h>
#include <stdlib.h>

static void azzera(int arr[][8], int dim){
  int i, y;
  for(i=0; i<dim; i++)
    for(y=0; y<dim; y++)
      arr[i][y] = 0;
}

void inizializza(int arr[][8], FILE *file, int dim){
  int n1, n2, i=0;
  azzera(arr, dim);
  while(fscanf(file, "%d", &n1) != EOF){
    fscanf(file, "%d", &n2);
    arr[n1][n2] = 1;
    i++;
  }
  if(i != 8){
    printf("Hai inserito più regine del dovuto\n");
    exit(1);
  }
  rewind(file);
}

void leggi(int arr[][8], int dim){
  int i, y;
  printf("Questa è la scacchiera\n");
  for(i=0; i<dim; i++){
    for(y=0; y<dim; y++)
      printf("%5d", arr[i][y]);
    printf("\n\n");
  }
}

static int orizzontale(int arr[][8], int n1, int n2, int dim){
  int i, flag=1;
  for(i=0; i<dim; i++)
    if(arr[n1][i] == 0)
      flag++;
  if(flag == 8)
    return 0;
  return 1;
}

static int verticale(int arr[][8], int n1, int n2, int dim){
  int i, flag=1;
  for(i=0; i<dim; i++)
    if(arr[i][n2] == 0)
      flag++;
  if(flag == 8)
    return 0;
  return 1;
}

static int diagonale(int arr[][8], int n1, int n2, int dim){
  int i, y, flag=0;
  //destra basso
  for(i=n1, y=n2; i<dim, y<dim; i++, y++)
    if(arr[i][y] == 1)
      flag++;
  if(flag > 1)     return 1;
  flag=0;

  //sinistra alto
  for(i=n1, y=n2; i>=0, y>=0; i--, y--)
    if(arr[i][y] == 1)
      flag++;
  if(flag > 1)     return 1;
  flag=0;

  //destra alto
  for(i=n1, y=n2; i>=0, y<dim; i--, y++)
    if(arr[i][y] == 1)
      flag++;
  if(flag > 1)     return 1;
  flag=0;

  //sinistra basso
  for(i=n1, y=n2; i<dim, y>=0; i++, y--)
    if(arr[i][y] == 1)
      flag++;
  if(flag > 1)     return 1;
  flag=0;

  return 0;
}

void check(int arr[][8], FILE *file, int dim){
  int n1, n2, flag = 1;
  int i=0, j, y;
  while(i < 8 && flag){
    fscanf(file, "%d", &n1);
    fscanf(file, "%d", &n2);
    if(orizzontale(arr, n1, n2, dim) || verticale(arr, n1, n2, dim) || diagonale(arr, n1, n2, dim))
      flag--;
/*
printf("%d\t%d\t%d\n", orizzontale(arr, n1, n2, dim) , verticale(arr, n1, n2, dim), diagonale(arr, n1, n2, dim));
*/
  i++;
  }
  if(flag)
    printf("Le regine non si mangiano\n");
  else
    printf("La regine %d %d mangia un'altra regina\n", n1, n2);
}
