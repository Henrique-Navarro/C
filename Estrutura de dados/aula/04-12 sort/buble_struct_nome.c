#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

struct pessoa{
    char nome[30];
    int idade;
};
void buble_sort(struct pessoa *vetor_pessoa, int n);

int main(){
    int i,j=0;
    struct pessoa *vetor = (struct pessoa * )malloc(TAM * sizeof(struct pessoa));

    if (vetor == NULL){
        printf("Não foi possivel");
        return 0;
    }

    strcpy(vetor[0].nome,"Paulo");
    vetor[0].idade = 30;

    strcpy(vetor[1].nome,"Henrique");
    vetor[1].idade = 50;

    strcpy(vetor[2].nome,"Julia");
    vetor[2].idade = 25;

    for(i=0; i<3; i++){
        printf("%s %d\n", vetor[i].nome, vetor[i].idade);
    }
    buble_sort(vetor, TAM);
    printf("\nOrdenado por ordem alfabetica\n");
    for(i=0; i<3; i++){
        printf("%s %d\n", vetor[i].nome, vetor[i].idade);
    }
    free(vetor);
}

void buble_sort(struct pessoa *vetor_pessoa, int n){
    int k,j;
    struct pessoa aux;
    for(k=1; k<=n; k++){
        for(j=0; j<n-1; j++){
            if (strcmp(vetor_pessoa[j].nome, vetor_pessoa[j+1].nome) > 0){
                aux= vetor_pessoa[j];
                vetor_pessoa[j]= vetor_pessoa[j+1];
                vetor_pessoa[j+1]=aux;
            }

            /*              em ordem decrescente basta inverter o comparativo [<]
            if (strcmp(vetor_pessoa[j].nome, vetor_pessoa[j+1].nome) < 0){
                aux= vetor_pessoa[j];
                vetor_pessoa[j]= vetor_pessoa[j+1];
                vetor_pessoa[j+1]=aux;
            }
            */
        }
    }
}