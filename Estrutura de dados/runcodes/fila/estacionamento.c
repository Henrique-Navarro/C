//lista pode ter varios formatos
//fila é uma lista que só vai pra frente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fila
struct Cel{
    char placa[9];
    int qtdRetirados;
    struct Cel *prox;
};
typedef struct Cel cel;

struct Lista{
    struct Cel *inicio;
    struct Cel *fim;
    int tam;
};
typedef struct Lista lista;

void inicia(lista *LISTA){    
    LISTA->inicio = NULL;
    LISTA->fim = NULL;
    LISTA->tam=0;
}

//final
int insere(lista *LISTA, cel *novo){

    novo->prox= NULL;
    LISTA->tam++;
    
    if(LISTA->inicio == NULL){
        LISTA->inicio= novo;
        LISTA->fim= novo;
    }

    else{
        LISTA->fim->prox= novo;
        LISTA->fim= novo;
    }

    return 1;
}

//inicio
cel *retira(lista *LISTA){

    if(LISTA->tam == 0) return NULL;
    if(LISTA->tam == 1) LISTA->fim = NULL;
    cel *res = LISTA->inicio;
    LISTA->inicio= LISTA->inicio->prox;
    LISTA->tam--;

    return res;
    
}


void printa(lista *LISTA){
    cel *aux;
    aux= LISTA->inicio;

    while(aux != NULL){
        printf("[%s]", aux->placa);
        printf("[%d]\n", aux->qtdRetirados);
        aux= aux->prox;
    }
    printf("\n");
}

int main(void){
    char tipo;
    int booleanogg;

    FILE *arq;
    arq= fopen("fila.txt", "r");
    if(arq == NULL){
        printf("\nERRO\n");
    }
    lista *LISTA= (lista *)malloc(sizeof(lista));
    lista *LISTA1= (lista *)malloc(sizeof(lista));
    
    inicia(LISTA);
    inicia(LISTA1);

    cel *retirado= NULL;
    cel *Placa= (cel *)malloc(sizeof(cel));
    
    while(fscanf(arq, "%c %s\n", &tipo, Placa->placa) != EOF){
        switch(tipo){
            case 'E':
                Placa->qtdRetirados = 0;
                insere(LISTA, Placa);
                break;
                
            case 'S':
                booleanogg = 1;
                retirado=retira(LISTA);
                while(retirado != NULL){
                    if(strcmp(retirado->placa, Placa->placa) != 0){
                        insere(LISTA1, retirado);
                        if(booleanogg)retirado->qtdRetirados++;
                    }else{
                        booleanogg=0;
                        free(retirado);
                    }
                    retirado=retira(LISTA);
                    
                }
                retirado= retira(LISTA1);
                while(retirado != NULL){
                    insere(LISTA, retirado);
                    retirado=retira(LISTA1);
                }
                break;

            case 'P':
                printa(LISTA);
                break;
        }
        Placa = (cel *)malloc(sizeof(cel));

    }
    printf("\n");
    free(LISTA);
    free(LISTA1);
    fclose(arq);
}