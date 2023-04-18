#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* arquivo = fopen("a.txt", "r");
    char linha[1000];

    fgets(linha, 1000, arquivo);
    
    char *string[1000];   
    char delimit[]=",";
    int i = 0;                                  
    string[i]=strtok(linha, delimit);
    while(string[i]!=NULL) {
      printf("%s\n",string[i]);
      string[i]=strtok(NULL,delimit);
    }
    
    //printf("%s", linha);
}