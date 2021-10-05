#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int inicio, int meio, int fim) 
{
    int i, j, k, *auxiliar;

    i = inicio; 
    j = meio + 1;
    k = 0; 

    auxiliar = (int *) malloc (sizeof(int) * ((fim - inicio) + 1));
    while(i <= meio && j <= fim)
    {
        if(array[i] < array[j])
        {
            auxiliar[k] = array[i];
            i++;
        }
        else
        {
            auxiliar[k] = array[j];
            j++;
        }
        k++;
    }

    while(i <= meio)
    {
        auxiliar[k] = array[i];
        i++;
        k++;
    }

    while(j <= fim)
    {
        auxiliar[k] = array[j];
        j++;
        k++;
    }

    for(k = 0, i = inicio; i <= fim; i++, k++){
        array[i] = auxiliar[k];
    }
}

void mergeSort(int *array, int inicio, int fim) 
{
    int meio = (inicio + fim) / 2;

    if(inicio < fim) 
    {
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

int pesquisar(int *vetor, int chave , int vezes){
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

int main(){
    int i, vezes, qtdchaves, chave, cont;
    int *vetor;

    scanf("%d", &vezes);
    vetor= (int *)(malloc(vezes* sizeof(int)));
    for(i=0; i<vezes; i++){
        scanf("%d", &vetor[i]);
    }
    
    mergeSort(vetor, 0, vezes-1);

    /*for (i=0; i < vezes; i++){
        printf("%d ", vetor[i]); 
    }*/

    scanf("%d", &qtdchaves);  
    for(i=0; i<qtdchaves; i++){
        scanf("%d", &chave);
        cont=pesquisar(vetor, chave, vezes);
        printf("%d\n", cont);
    }
    free(vetor);
    return 0;
}