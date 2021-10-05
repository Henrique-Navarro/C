#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
    char numero[9], nome1[30], nome2[30];
    int status;
};

int pesquisar(struct dados *vetor, char *chave, int tam){
    int high, low, mid;
    low=0;
    high= tam-1;

    while(low <= high){
        mid= (low + high)/2;
        if(strcmp(chave, vetor[mid].numero) < 0){
            high= mid-1;
        }
        else if(strcmp(chave, vetor[mid].numero) > 0){
            low= mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void merge(struct dados *vetor, int low, int mid, int high){
    int i,j,k;
    struct dados *auxiliar;
    i= low;
    j= mid+1;
    k= 0;

    auxiliar= (struct dados *)malloc(sizeof(struct dados) * ((high - low) +1));
    while((i <= mid) && (j <= high)){
        if(strcmp(vetor[i].numero, vetor[j].numero) < 0){
            auxiliar[k]= vetor[i];
            i++;
        }
        else{
            auxiliar[k]= vetor[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        auxiliar[k]= vetor[i];
        i++;
        k++;
    }
    while(j <= high){
        auxiliar[k]= vetor[j];
        j++;
        k++;
    }
    k=0;
    for(i=low; i<= high; i++){
        vetor[i]= auxiliar[k];
        k++;
    }
}

void ordenar(struct dados *vetor, int low, int high){
    int mid= (low + high)/2;

    if(low < high){
        ordenar(vetor, low, mid); 
        ordenar(vetor, mid+1, high);
        merge(vetor, low, mid, high);
    }
}

int main(){
    int n, i, vezes, posic;
    char opcao[2], chave[30];
    scanf("%d", &n);
    struct dados *vetor= (struct dados*)malloc(sizeof(struct dados) * n);
    
    //ler vetor
    for(i=0; i<n; i++){
        scanf("%d %s %s %s", &vetor[i].status,
                            vetor[i].numero, 
                            vetor[i].nome1, 
                            vetor[i].nome2);
    }
    
    ordenar(vetor, 0, n-1);

    //printar vetor
    /*(for(i=0; i<n; i++){
        printf("%d\n", vetor[i].status);
        printf("%s\n", vetor[i].numero);
        printf("%s\n", vetor[i].nome1);
        printf("%s\n\n", vetor[i].nome2);
    }*/

    scanf("%d", &vezes);
    for(i=0; i<vezes; i++){
        scanf("%s", opcao);
        scanf("%s", chave);

        posic=pesquisar(vetor, chave, n);

        if(posic == -1){
            printf("INVALIDO\n");
        }
        else{
            if((strcmp(opcao, "E") == 0)){
                if(vetor[posic].status == 0){
                    printf("APAGADO\n");
                }
                else if(vetor[posic].status == 1){
                    vetor[posic].status=0;
                    printf("%d %s\n", vetor[posic].status, vetor[posic].numero);
                }
            } 

            else if((strcmp(opcao, "P") == 0)){
                if(vetor[posic].status == 0){
                    printf("APAGADO\n");
                }
                else if(vetor[posic].status == 1){
                    printf("%s %s %s\n", vetor[posic].numero, vetor[posic].nome1, vetor[posic].nome2);
                }
            }

            else{
                printf("INVALIDO\n");
            }
        }
        //printf("\n%s", vetor[posic].numero);
    }
}