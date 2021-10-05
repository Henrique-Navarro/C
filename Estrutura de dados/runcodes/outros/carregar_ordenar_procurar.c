#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    int id;
    char descricao[50];
};

void merge(struct pessoa *array, int low, int meio, int high){
    int i, j, k;
    struct pessoa *auxiliar;
    i = low; 
    j = meio + 1;
    k = 0; 

    //ORDENAR POR STRING
    auxiliar = (struct pessoa *) malloc (sizeof(struct pessoa) * ((high - low) + 1));
    while((i <= meio) && (j <= high)){
        if(strcmp(array[i].descricao, array[j].descricao) < 0){
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


int pesquisar(struct pessoa *item, char *chave, int tam){
    int high, low, mid;
    low= 0;
    high= tam-1;
    
    //pesquisar string
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
    int vezes,i,posic;
    char chave[50];

    scanf("%d", &vezes);
    scanf("%s", chave);

    struct pessoa *vetor= (struct pessoa *)malloc(vezes * sizeof(struct pessoa));
    for(i=0; i<vezes; i++){
        scanf("%d", &vetor[i].id);
        scanf("%s", vetor[i].descricao);
    }

    ordenar(vetor, 0, vezes-1);
    pesquisar(vetor, chave, vezes);
    posic=pesquisar(vetor, chave, vezes);
    printf("%d\n", vetor[posic].id);
}