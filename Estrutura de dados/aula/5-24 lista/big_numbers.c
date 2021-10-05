#include <stdio.h>
#include <stdlib.h>

struct Cel{
    int dado;
    struct Cel *prox;
};

typedef struct Cel cel;

struct Lista{
    struct Cel *inicio;
    struct Cel *fim;
    int tam;
};

typedef struct Lista lista;

void inicializar(lista *LISTA){
    LISTA->inicio= NULL;
    LISTA->fim= NULL;
    LISTA->tam=0;
}

lista *inserir(lista *LISTA, int dado){
    struct Cel *novo= malloc(sizeof(struct Cel));

    novo->dado= dado;

    if(novo == NULL){
        return 0;
    }
    if(LISTA->inicio == NULL){
        LISTA->inicio= novo;
        LISTA->fim= novo;
        LISTA->fim->prox= NULL;
    }
    else{
        novo->prox= LISTA->inicio;
        LISTA->inicio= novo;
    }
    LISTA->tam++;
       return LISTA;
}

/*lista *remover(lista *LISTA, int dado){
    struct Cel *aux;
    struct Cel *ant;

    aux=LISTA->inicio;
    ant=NULL;

    while(aux != NULL){
        if(aux->dado== dado){
            LISTA->tam--;

            if(aux== LISTA->inicio){
                LISTA->inicio= aux->prox;
                free(aux);
                aux= LISTA->inicio;
            }
            else if(aux== LISTA->fim){
                ant->prox= NULL;
                LISTA->fim= ant;
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

    return LISTA;  
}*/

int removerInicio(lista *LISTA){
    int res= LISTA->inicio->dado;
    cel *pointer= LISTA->inicio;
    LISTA->inicio= LISTA->inicio->prox;
    free(pointer);
    LISTA->tam--;

    return res;
}

void ler(lista *LISTA){
    int numero;
    scanf("%d", &numero);

    //enquanto -1 não for lido, continua adicionando
    while(numero != -1){
        inserir(LISTA, numero);
        scanf("%d", &numero);
    }
}

void soma(lista *LISTA1, lista *LISTA2, lista *resposta){
    int carry=0;
    int resp1, resp2;

    //enquanto alguma das listas estiver pelo menos 1 elemento
    while((LISTA1->tam>0) || (LISTA2->tam>0)){

        if(LISTA1->tam>0){
            //função remover retornar o valor removido
            resp1= removerInicio(LISTA1);
        }
        else{
            resp1= 0;
        }

        if(LISTA2->tam>0){
            resp2= removerInicio(LISTA2);
        }
        else{
            resp2=0;
        }

        //resto da divisão por 10
        int resp= (resp1+resp2+carry)%10;
        inserir(resposta, resp);
        
        //divisão inteira
        carry= (resp1+resp2+carry)/10;
    }

    //se sobrar algum valor
    if(carry> 0){
        inserir(resposta, carry);
    }
}

/*void imprimir(lista *LISTA){
    cel *aux= LISTA;

    //system("clear");
    while(aux != NULL){
        printf("%d", aux->dado);
        aux= aux->prox;
    }
}*/

void imprimir(lista *list){
     
    /*if(pointer == NULL){
        printf("LISTA VAZIA\n");
    }
    if(isEmpty(list)){
        printf("LISTA VAZIA\n");
        return;
    }*/

    cel *pointer= list->inicio;

    while(pointer != NULL){
        printf("%d", pointer->dado);
        pointer= pointer->prox;
    }
}

int main(){
    //lista
    lista lista1;
    lista lista2;
    lista resposta;

    inicializar(&lista1);
    inicializar(&lista2);
    inicializar(&resposta);

    ler(&lista1);
    ler(&lista2);

    soma(&lista1, &lista2, &resposta);

    imprimir(&resposta);
}