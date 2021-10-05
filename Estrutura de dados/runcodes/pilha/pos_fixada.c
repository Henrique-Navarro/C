#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

struct stack{
    int numero;
    struct stack *prox;
};

typedef struct stack Pilha;

int imprimeTopo(Pilha pilha){

    Pilha *aux = pilha.prox;
    
	return aux->numero;
}

void imprimeTudo(Pilha pilha){
	
	Pilha *aux = pilha.prox;
	
	if(aux == NULL)
	{
		printf("\nPilha esta vazia !");
	   return;
	}
	
	printf("\nPilha\n");
	
	while(aux != NULL){
		printf("%d  "  , aux->numero);
		aux = aux->prox;
	}
	printf("\n");
}

int pop(Pilha *pilha){
    Pilha *aux= pilha->prox;
    int rem= aux->numero;

    pilha->prox = pilha->prox->prox;
    free(aux);

    return rem;
}

int push(Pilha *pilha, int numero){
    Pilha *novo= (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL){
        return 0;
    }

    novo->numero= numero;
    novo->prox= pilha->prox;
    pilha->prox= novo;

    return 1;
}

void inicializar(Pilha *pilha){
    pilha->numero= 0;
    pilha->prox= NULL;
}

int main(){
    int num, res, aux1, aux2;
    char token[30];
    //ler (onde, quantos, como)
    // (variavel, 30, teclado)
    fgets(token, 30, stdin);

    token[strcspn(token, "\n")] = '\0';

    //pilha
    Pilha p1;
    inicializar(&p1);

    //dividir a string com os espaços
    char *split= strtok(token, " ");
    while(split != NULL){

        //se for símbolo    0-não 1-sim

            if(strcmp(split, "*") == 0){
                aux1= pop(&p1);
                aux2= pop(&p1);
                res= aux2 * aux1;
                //printf("%d", res);
                push(&p1, res);
            }
            else if(strcmp(split, "/") == 0){
                aux1= pop(&p1);
                aux2= pop(&p1);
                res= aux2 / aux1;
                //printf("%d", res);
                push(&p1, res); 
            }
            else if(strcmp(split, "+") == 0){
                aux1= pop(&p1);
                aux2= pop(&p1);
                res= aux2 + aux1;
                //printf("%d", res);
                push(&p1, res);
            }
            else if(strcmp(split, "-") == 0){
                aux1= pop(&p1);
                aux2= pop(&p1);
                res= aux2 - aux1;
                //printf("%d", res);
                push(&p1, res);
                push(&p1, res);
            }

        //se for numero
            else{
                //converter string em int
                //num= strtol(split, NULL, 10);
                num= atoi(split);
                push(&p1, num);
                
                /*int printa;
                printa=imprimeTopo(p1);
                printf("%d ", printa);*/
            }

        //ler char
        split= strtok(NULL, " ");
    }
    int printa;
    printa=imprimeTopo(p1);
    printf("%d", printa);
}