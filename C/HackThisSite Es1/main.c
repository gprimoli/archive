#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int check(char in[], char word[], int dim);

int main(int argc, char const *argv[]) {
  if(argc<3){
    printf("Non ci sono abbastanza argomenti\n");
    exit(0);
  }
  else{
    FILE *input = fopen(argv[1],"r");
    FILE *wordlist = fopen(argv[2],"r");
    FILE *output = fopen("output.txt","w");
    char in[MAX], word[MAX];
    int lenin, lenword;
    while(fscanf(input, "%s", in) != EOF){
      lenin = strlen(in);
      while(fscanf(wordlist, "%s", word) != EOF){
        lenword = strlen(word);
        if(lenin == lenword){
          if(check(in, word, lenin)){
            fprintf(output, "%s,", word);
          }
        }
      }
    rewind(wordlist);
    }
  }
  return 0;
}


int check(char in[], char word[], int dim){
  int i, y, flag, count=0;
  for(i=0; i<dim; i++){
    flag = 1;
    for(y=0; y<dim && flag; y++){
      if(in[i] == word[y]){
        count++;
        flag = 0;
      }
    }
  }
  if(count == dim)
    return 1;
  return 0;
}
