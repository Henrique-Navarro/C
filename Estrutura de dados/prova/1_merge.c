#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    int posic;
    char palavra[15];
};

void merge(struct dados *array, int low, int meio, int high){
    int i, j, k;
    struct dados *auxiliar;
    i = low; 
    j = meio + 1;
    k = 0; 

    auxiliar = (struct dados *) malloc (sizeof(struct dados) * ((high - low) + 1));
    while((i <= meio) && (j <= high)){
        if(strcmp(array[i].palavra, array[j].palavra) < 0){
            //strcpy(auxiliar[k].palavra, array[i].palavra);
            auxiliar[k]=array[i];
            i++;
        }

        else{
            //strcpy(auxiliar[k].palavra, array[j].palavra);
            auxiliar[k]=array[j];
            j++;
        }
        k++;
    }

    while(i <= meio){ 
        //strcpy(auxiliar[k].palavra, array[i].palavra);
        auxiliar[k]=array[i];
        i++;
        k++;
    }

    while(j <= high){
        //strcpy(auxiliar[k].palavra, array[j].palavra);
        auxiliar[k]=array[j];
        j++;
        k++;
    }
    k=0;
    for(i = low; i <= high; i++){
        //strcpy(array[i].palavra, auxiliar[k].palavra);
        array[i]=auxiliar[k];
        k++;
    }
}

void ordenar(struct dados *array, int low, int high){ 
    int meio = (low + high) / 2;

    if(low < high){ 
        ordenar(array, low, meio);
        ordenar(array, meio + 1, high);
        merge(array, low, meio, high);
    }
}

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
    
    ordenar(vetor, 0, vezes-1);

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
    return 0;
}