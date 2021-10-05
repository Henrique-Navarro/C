//lista pode ter varios formatos
//fila é uma lista que só vai pra frente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fila
struct Info{
    char placa[9];
    int qtdRetirados;
};
typedef struct Info info;

struct Cel{
    struct Info *informacao;
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
int insere(lista *LISTA, info *INFO){
    cel *novo=(cel *)malloc(sizeof(cel));
    novo->informacao= INFO;

    if(novo == NULL){
        return 0;
    }

    if(LISTA->inicio == NULL){
        LISTA->inicio= novo;
        LISTA->fim= novo;
        LISTA->fim->prox= NULL; 
    }

    else{
        LISTA->fim->prox= novo;
        LISTA->fim= novo;
        LISTA->fim->prox= NULL;
    }
    return 1;
}

//inicio
info *retira(lista *LISTA){
    info *res;
    /*lista *LISTAUX;
    LISTAUX->inicio->informacao= LISTA->inicio->informacao;
    cel *pointer= LISTA->inicio;
    LISTA->inicio= LISTA->inicio->prox;
    free(pointer);
    LISTA->tam--;

    return LISTAUX;
    */

    res= LISTA->inicio->informacao;
    cel *pointer= LISTA->inicio;
    LISTA->inicio= LISTA->inicio->prox;
    free(pointer);
    LISTA->tam--;

    return res;
}

void printa(lista *LISTA){
    cel *aux;
    aux= LISTA->inicio;

    while(aux != NULL){
        printf("[%s]", aux->informacao->placa);
        printf("[%d]\n", aux->informacao->qtdRetirados);
        aux= aux->prox;
    }
    printf("\n\n");
}

int main(void){
    char tipo;

    FILE *arq;
    arq= fopen("fila.in", "r");

    lista *LISTA= (lista *)malloc(sizeof(lista));
    lista *LISTA1= (lista *)malloc(sizeof(lista));

    /*info *retirado, *Placa;
    cel *aux;*/

    info *retirado= (info *)malloc(sizeof(info));
    info *Placa= (info *)malloc(sizeof(info));
    cel *aux= (cel *)malloc(sizeof(cel));

    while(fscanf(arq, "%c %s", &tipo, Placa->placa) != EOF){
        switch(tipo){
            case 'E':
                insere(LISTA, Placa);
                break;
                
            case 'S':
                aux= LISTA->inicio;
                while(aux != NULL){
                    retirado=retira(LISTA);

                    if(strcmp(retirado->placa, Placa->placa) != 0){
                        insere(LISTA1, retirado);
                    }
                    aux= aux->prox;
                }
                aux= LISTA->inicio;
                while(aux != NULL){
                    insere(LISTA, LISTA1->inicio->informacao);
                }
                break;

            case 'P':
                printa(LISTA);
                break;
        }   

    }
    
    free(LISTA);
    free(LISTA1);
    fclose(arq);
}
