#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    int posic;
    char palavra[15];
};

void merge(struct dados *array, int inicio, int meio, int fim) 
{
    int i, j, k;
    char *auxiliar;
    i = inicio; 
    j = meio + 1;
    k = 0; 

    auxiliar = (char *) malloc (sizeof(char) * ((fim - inicio) + 1));
    while(i <= meio && j <= fim)
    {
        if(strcmp(array[i].palavra, array[j].palavra) < 0)
        {
            strcpy(auxiliar[k], array[i].palavra);
            i++;
        }
        else
        {
            strcpy(auxiliar[k], array[j].palavra);
            j++;
        }
        k++;
    }

    while(i <= meio)
    {
        strcpy(auxiliar[k], array[i].palavra);
        i++;
        k++;
    }

    while(j <= fim)
    {
        strcpy(auxiliar[k], array[j].palavra);
        j++;
        k++;
    }

    for(k = 0, i = inicio; i <= fim; i++, k++){
        strcpy(array[i].palavra, auxiliar[k]);
    }
}

void mergeSort(struct dados *array, int inicio, int fim) 
{
    int meio = (inicio + fim) / 2;

    if(inicio < fim) 
    {
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

int pesquisar(struct dados *vetor, char *chave , int vezes){
int BinarySearch(struct dados *key, string array[], int low, int high) 

   int mid, cmp;

   if (low > high) return NONE;
   mid = (low + high) / 2;
   cmp = strcmp( key, array[mid]);
   if (cmp == 0 ) 
      return mid;
   if (cmp < 0) 
      return BinarySearch( key, array, low, mid - 1); 
   else 
      return BinarySearch( key, array, mid + 1, high); 
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
    
    mergeSort(vetor, 0, vezes-1);

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