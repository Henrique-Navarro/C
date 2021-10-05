#include <stdio.h>
#include <stdlib.h>

struct Cel{
    int dado;
    struct Cel *prox;
};

struct Lista{
    struct Cel *inicio;
    struct Cel *fim;
    int tam;
};

void inicializar(struct Lista *lista){
    lista->inicio= NULL;
    lista->fim= NULL;
    lista->tam=0;
}

int inserirInicio(struct Lista *lista, int dado){
    struct Cel *novo= malloc(sizeof(struct Cel));
    
    if(novo==NULL){
        return 0;
    }

    novo->dado= dado;

    if(lista->inicio == NULL){
        lista->inicio= novo;
        lista->fim= novo;
        lista->fim->prox= NULL;
    }
    else{
        novo->prox= lista->inicio;
        lista->inicio= novo;
    }
    lista->tam++;
    return 1;
}

int inserirFim(struct Lista *lista, int dado){
    struct Cel *novo= malloc(sizeof(struct Cel));

    novo->dado= dado;

    if(novo == NULL){
        return 0;
    }
    if(lista->inicio == NULL){
        lista->inicio= novo;
        lista->fim= novo;
        lista->fim->prox= NULL;
    }
    else{
        lista->fim->prox= novo;
        lista->fim= novo;
        lista->fim->prox= NULL;
    }
    lista->tam++;
    return 1;
}

int remover(struct Lista *lista, int dado){
    struct Cel *aux;
    struct Cel *ant;
    int qtdDel=0;

    aux=lista->inicio;
    ant=NULL;

    while(aux != NULL){
        if(aux->dado== dado){
            qtdDel++;
            lista->tam--;

            if(aux== lista->inicio){
                lista->inicio= aux->prox;
                free(aux);
                aux= lista->inicio;
            }
            else if(aux== lista->fim){
                ant->prox= NULL;
                lista->fim= ant;
                free(aux);
                aux= NULL;
            }
            else{
                ant->prox= aux->prox;
                free(aux);
                aux= ant->prox;
            }
        }
        else{
            ant= aux;
            aux= aux->prox;
        }
    }

    return qtdDel;  
}

int main(){
    struct Lista lista;
    int numero, apagado;

    inicializar(&lista);

    scanf("%d", &numero);
    inserirInicio(&lista, numero);

    scanf("%d", &numero);
    inserirFim(&lista, numero);

    scanf("%d", &numero);
    apagado=remover(&lista, numero);
    printf("%d", apagado);
}