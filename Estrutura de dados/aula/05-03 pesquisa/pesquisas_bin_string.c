#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binario(char **item, char *key, int count);

int main(){
   
    char key[30];
    int tam = 4 , posicao = -1, i = 0;
    int linhas = 4, colunas = 30;
    
    char **v = (char **) malloc(linhas * sizeof(char *));  // aloca as linhas
    for (i=0; i<tam; i++) 
         v[i] = (char *) malloc(colunas * sizeof(char));   // aloca as colunas

    // Veja que já estou inserindo ordenado, se fosse um vetor desconhecido seria necessário ordena-lo primeiro.
    strcpy(v[0],"A");
    strcpy(v[1],"B");
    strcpy(v[2],"C");
    strcpy(v[3],"D");

    strcpy(key,"C");

    posicao = binario(v, key, tam);
    printf("Localizado na posicao: %d\n", posicao);

    strcpy(key,"F");
    posicao = binario(v, key, tam);
    printf("Localizado na posicao: %d\n", posicao);

    // libera a memória
    for(int i = 0; i < tam; i++)
       free(v[i]);
    free(v);
  
}

int binario(char **item, char *key, int tam){
    int low, high, mid;
    low=0;
    high = tam - 1;

    while(low <= high){
        mid = (low+high)/2;
        if(strcmp(key,item[mid]) < 0) {                 //if(strcmp(key,item[mid]) < 0)
            high = mid - 1;
        }else if(strcmp(key , item[mid]) > 0) {         //if(strcmp(key , item[mid]) > 0 )
            low = mid + 1;
        }else{
            return mid;
        }
    }

    return -1;
}