#include <stdio.h>
#include <stdlib.h>

int pesquisar(int *vetor, int chave, int vezes){
    int t, cont;
    cont=0;

    for(t=0; t<vezes; t++){
        if(vetor[t] == chave){
            cont++;
            while(vetor[t]==vetor[t+1]){
                cont++;
                t++;
            }
            return cont;
        }
    }
    return cont;
}

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int particao(int *vetor, int low, int high){
    int pivot=vetor[high];
    int i=(low-1),aux;

    for(int j=low; j <= high-1; j++){
        if(vetor[j] <= pivot){
            i++;
            swap(&vetor[i], &vetor[j]);
            /*aux=vetor[i];
            vetor[i]=vetor[j];
            vetor[j]=aux;*/
        }
    }
    swap(&vetor[i+1], &vetor[high]);
    /*aux=vetor[i+1];
    vetor[i+1]=vetor[high];
    vetor[high]=aux;*/
    return (i+1);
}

void ordenar(int *vetor, int low, int high){
    if (low < high){
        int pi= particao(vetor, low, high);
        ordenar(vetor, low, pi-1);
        ordenar(vetor, pi+1, high);
    }
}

int main(){
    int i, vezes, qtdchaves, chave, cont;
    int *vetor;

    scanf("%d", &vezes);
    vetor= (int *)(malloc(vezes* sizeof(int)));
    for(i=0; i<vezes; i++){
        scanf("%d", &vetor[i]);
    }
    
    int n= sizeof(vetor) / sizeof(vetor[0]);
    ordenar(vetor, 0, n-1);

    for (i=0; i < vezes; i++){
        printf("%d ", vetor[i]); 
    }

    scanf("%d", &qtdchaves);  
    for(i=0; i<qtdchaves; i++){
        scanf("%d", &chave);
        cont=pesquisar(vetor, chave, vezes);
        printf("resposta:%d\n", cont);
    }
    free(vetor);
    return 0;
}