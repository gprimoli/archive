#include <stdio.h>
#include <stdlib.h>

void fcheck(FILE *f, char *nome){
	if(f){
//		printf("[SUCCESS]FIle %s aperto con successo\n", nome);
	}else{
		printf("[ERROR] Non è stato possibile aprire il file [%s]\n", nome);
		exit(0);
	}
}

int n_elementi(char *file_name){
	FILE *f=fopen(file_name,"r");
	fcheck(f,file_name);
	int temp, i;
	while(fscanf(f,"%d", &temp) != EOF)
		i++;
	fclose(f);
	return i;
}

int * ftoarray(char *file_name, int n){
	FILE *f=fopen(file_name,"r");
	fcheck(f, *file_name);
	int *a,i;
	a=calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		fscanf(f,"%d", &a[i]);
	fclose(f);
	return(a);
}
