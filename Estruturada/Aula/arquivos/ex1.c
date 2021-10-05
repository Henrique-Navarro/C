#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){ 
    int i,j=0,TAM;
    char nome[50],aux[50];
    TAM= strlen(nome)-1;
    
        gets(nome);
            for(i=TAM; i >= 0; i--){
                aux[j]=nome[i];
                j++;
                aux[j]='\0';
            }
            
    printf("%s", aux);
}