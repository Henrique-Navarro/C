#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    int posic;
    char palavra[15];
};

int pesquisar(struct dados *vetor, char *chave , int vezes){
    int low, high, mid;
    low=0;
    high=vezes-1;

    while(low <= high){
        mid= (low+high)/2;
        if (strcmp(chave, vetor[mid].palavra) < 0){
            high = mid-1;
        }
        else if(strcmp(chave, vetor[mid].palavra) > 0){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void ordenar(struct dados *vetor, int vezes){
    int j,k;
    struct dados aux;

    for(j=1; j<vezes; j++){
        for(k=0; k<vezes-1; k++){
            if(strcmp(vetor[k].palavra, vetor[k+1].palavra) > 0){
                aux = vetor[k];
                vetor[k] = vetor[k+1];
                vetor[k+1] = aux;
            }
        }
    }
}

int main(){
    int vezes, qtdchaves, i, posicao;
    char palavra[15], chave[15];

    //ler as palavras
    scanf("%d", &vezes);
    struct dados *vetor;
    vetor= (struct dados *)(malloc(vezes * sizeof(struct dados)));
    for(i=0; i<vezes; i++){
        scanf("%s", palavra);
        strcpy(vetor[i].palavra, palavra);
        vetor[i].posic=i;
    }
    
    ordenar(vetor, vezes);

    //ler as chaves 
    scanf("%d", &qtdchaves);
    for(i=0; i<qtdchaves; i++){
        scanf("%s", chave);
        posicao=pesquisar(vetor, chave, vezes);
        if(posicao <0){
            printf("-1");
        }
        else{ 
            printf("%d\n", vetor[posicao].posic);
        }
    }
    
    free(vetor);
}