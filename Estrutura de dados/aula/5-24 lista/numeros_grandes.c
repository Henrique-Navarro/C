#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
}; 
typedef struct Node node;

int tam;

//certo
void inicializar(node *LISTA){
    LISTA->prox= NULL;
    tam=0;
}

//inicio
void insereInicio(node *LISTA){ 
    node *novo=aloca(); 
    node *oldHead = LISTA->prox;
 
    LISTA->prox = novo;
    novo->prox = oldHead;
 
    tam++;
}

node *aloca(){
    node *novo=(node *) malloc(sizeof(node));
    if(!novo){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else{
        printf("Novo elemento: "); scanf("%d", &novo->num);
        return novo;
    }
}

//
node *retiraFim(node *LISTA){
    if(LISTA->prox == NULL){
        printf("Lista ja vazia\n\n");
        return NULL;
    }
    else{
    node *ultimo = LISTA->prox,
        *penultimo = LISTA;
        
    while(ultimo->prox != NULL){
    penultimo = ultimo;
    ultimo = ultimo->prox;
    }
        
    penultimo->prox = NULL;
    tam--;
    return ultimo;  
    }
}

//certo
void ler(node *LISTA){
    int numero;
    scanf("%d", &numero);

    //enquanto -1 não for lido, continua adicionando
    while(numero != -1){
        inserir(LISTA, numero);
        scanf("%d", &numero);
    }
}

int soma(node *LISTA1, node *LISTA2){
    int carry=0;
    int resp1, resp2;
    node *resposta;

    //enquanto alguma das listas estiver pelo menos 1 elemento
    while(tam>0){

        if(LISTA1->tam>0){
            //função remover retornar o valor removido
            resp1= retiraFim(LISTA1);
        }
        else{
            resp1= 0;
        }

        if(LISTA2->tam>0){
            resp2= retiraFim(LISTA2);
        }
        else{
            resp2=0;
        }

        //resto da divisão por 10
        int resp= (resp1+resp2+carry)%10;
        resposta=inserir(resposta, resp);

        //divisão inteira
        carry= (resp1+resp2+carry)/10;
    }

    //se sobrar algum valor
    if(carry> 0){
        resposta=inserir(resposta, carry);
    }
}

void exibe(node *LISTA)
{
 system("clear");
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp;
 tmp = LISTA->prox;
 printf("Lista:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);
 
  
 printf("\n\n");
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

    soma(&lista1, &lista2);

    imprimir(&resposta);
}