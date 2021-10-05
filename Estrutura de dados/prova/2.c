#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int low, int mid, int high) 
{
    int i, j, k;
    int *aux;

    i = low; 
    j = mid + 1;
    k = 0; 

    aux = (int *) malloc (sizeof(int) * ((high - low) + 1));
    while(i <= mid && j <= high)
    {
        if(vetor[i] < vetor[j]){
            aux[k] = vetor[i];
            i++;
        }
        else{
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        aux[k] = vetor[i];
        i++;
        k++;
    }

    while(j <= high){
        aux[k] = vetor[j];
        k++;
        j++;
    }

    for(k = 0, i = low; i <= high; i++, k++){
        vetor[i] = aux[k];
    }
}

void ordenar(int *array, int low, int high){
    int mid;
    mid= (low + high) / 2;

    if(low < high){
        ordenar(array, low, mid);
        ordenar(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int pesquisar(int *vetor, int key, int tam){
    int low=0, high= tam-1;
    int meio;

    high = tam - 1;
    low = 0;

    while(low <= high){

        meio = (low + high);
        meio= meio/2;

        if(key < vetor[meio]){
            high = meio - 1;
        }

        else if(key > vetor[meio]){    
            low = meio + 1;
        }
        
        else{
            return meio;
        }


    }
    return -1;
}

int main(){
    int i, p, vezes, qtdchaves, chave, cont, posic;
    int *vetor;

    scanf("%d", &vezes);
    vetor= (int *)(malloc(vezes* sizeof(int)));
    for(i=0; i<vezes; i++){
        scanf("%d", &vetor[i]);
    }
    
    ordenar(vetor, 0, vezes-1);

    /*for (i=0; i < vezes; i++){
        printf("%d ", vetor[i]); 
    }*/

    scanf("%d", &qtdchaves);  

    for(i=0; i<qtdchaves; i++){
        cont=0;
        scanf("%d", &chave);
        posic=pesquisar(vetor, chave, vezes);

        if(posic == -1){
            cont=0;
        }
        else{
            cont++;

            //esquerda
            p= posic -1;
            while((vetor[p] == chave) && (p >= 0)){
                cont++;
                p--;
            }

            //direita
            p= posic +1;
            while((vetor[p] == chave) && (p < vezes)){
                cont++;
                p++;
            }
        }
        printf("%d\n", cont);
    }

    free(vetor);
    return 0;
}