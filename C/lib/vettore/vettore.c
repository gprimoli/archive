#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

static void scambia(int *a, int *b);

void inserisci(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("Inserisci il %d valore", i+1);
		scanf("%d", &a[i]);
	}
}

void leggi(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}

void elimina(int a[], int n){
	int i, aggiunta, pos=0;
	leggi(a,n);
	printf("\n");
	printf("\nChe valore vuoi eliminare?\n");
	scanf("%d", &i);
	while(i!=a[pos])
		pos++;
	for(i=pos;i<n;i++)
		a[i]=a[i+1];
	a[n-1]=0;
	printf("\n");
	leggi(a,n);
}

void min(int a[], int n){
	int min=a[0], i=1;
	while(i<n){
		if(min>a[i])
			min=a[i];
	i++;}
	printf("\nIl valore minimo di questo array:\n");
	leggi(a,n);
	printf("\nè %d\n",min);
}

void max(int a[], int n){
	int max=a[0], i=1;
	while(i<n){
		if(max<a[i])
			max=a[i];
	i++;
	}
	printf("\nIl valore massimo di questo array:\n");
	leggi(a,n);
	printf("\nè %d\n",max);
}

void ordina(int a[], int n){
	int i, j;
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(a[j]>a[j+1])
				scambia(&a[j],&a[j+1]);                  
}

int confronta(int a[], int b[], int n){
	int i, flag;
	for(i=0, flag=0;i<n && !flag;i++){
		if(a[i]!=b[i])
			flag=1;
	}
	if(flag){
		return 0;
	}else{
		return 1;
	}
}


static void scambia(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int somma_elementi(int a[], int n){
	int i, somma=0;
	for(i=0;i<n;i++){
		somma+=a[i];
	}
	return(somma);
}

int * somma_array(int a[], int b[], int n){
	int *c, i;
	c=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		c[i]=a[i]+b[i];
	return(c);
}

int * prodotto_scalare(int a[], int b[], int n, int m){
	int *c , i, j;
	c=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			c[i]+=a[i]*b[j];
		}
	return(c);
}
