#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    char simbolo;
    struct stack *prox;
};

typedef struct stack Pilha;

void inicializar(Pilha *pilha){
    pilha->prox= NULL;
}

int vazia(Pilha *pilha){
    return pilha->prox== NULL ? 1 : 0;
}

int main(){
    int x,y, **matriz;
    scanf("%d %d", &x, &y);

    //matriz
    matriz=(int **)malloc(sizeof(int) * x);
    for(int i=0; i<x; i++){
        matriz[i]=(int *)malloc(sizeof(int) * y);
    }

    //pilha
    Pilha p1;
    inicializar(&p1);

    char token[30];
    while(! vazia(&p1)){
        fgets(token, 30, stdin);
        token[strcspn(token, "\n")] = '\0';
        char *split= strtok(token, " ");
    }
}