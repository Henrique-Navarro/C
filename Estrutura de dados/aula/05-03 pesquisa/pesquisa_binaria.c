#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binario(char **item, char *key, int count);

int main(){
    char key[30];
    int tam=4, posic=-1, i;
    int linha=4, coluna=30;

    char **v=(char **)malloc(linha * sizeof(char *)); //aloca linha
    for(i=0; i<tam; i++){
        v[i]= (char * ) malloc(coluna * sizeof(char)); //aloca coluna
    }

    //veja que o vetor ja está sendo atribuido valores já ordenados
    //em caso normal é necessário ordena-lo

    strcpy(v[0], "A");
    strcpy(v[1], "B");
    strcpy(v[2], "C");
    strcpy(v[3], "D");

    strcpy(key,"C");
    posic= binario(*v, key, tam);
}

int binario(char **item, char *key, int tam){
    int low, high, mid;
    low=0;
    high=tam-1;

    while(low <= high){
        mid= (low+high)/2;
        if (strcmp(key, item[mid]) < 0){
            high= mid-1;
        }
        else if(strcmp(key, item[mid]) > 0){
            low=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}