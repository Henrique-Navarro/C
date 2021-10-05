#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    int id;
    char descricao[50];
};

void ordenar(struct pessoa *dados, int tam){
    int j,k;
    struct pessoa aux;
    for(j=1; j<= tam; j++){
        for(k=0; k<tam-1; k++){
            if(strcmp(dados[k].descricao , dados[k+1].descricao) > 0){
                aux= dados[k];
                dados[k]= dados[k+1];
                dados[k+1]= aux;
            }
        }
    }
}

int pesquisar(struct pessoa *item, char *chave, int tam){
    int high, low, mid;
    low= 0;
    high= tam-1;
    
    while(low <= high){
        mid= (low + high)/2;
        if(strcmp(chave, item[mid].descricao) < 0){
            high= mid-1;
        }
        else if(strcmp(chave, item[mid].descricao) > 0){
            low= mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int vezes,i,posic=-1;
    char chave[50];
    scanf("%d", &vezes);
    scanf("%s", chave);
    struct pessoa *vetor= (struct pessoa *)malloc(vezes * sizeof(struct pessoa));
    for(i=0; i<vezes; i++){
        scanf("%d", &vetor[i].id);
        scanf("%s", vetor[i].descricao);
    }

    ordenar(vetor, vezes);
    /*for(i=0; i<vezes; i++){
        printf("%d \n", vetor[i].id);
        printf("%s \n", vetor[i].descricao);
    }
    */
    
    posic=pesquisar(vetor, chave, vezes);
    printf("%d", vetor[posic].id);
}