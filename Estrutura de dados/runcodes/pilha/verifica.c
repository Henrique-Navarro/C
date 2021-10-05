#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    char simbolo;
    struct stack *prox;
};

typedef struct stack Pilha;

void inicializar(Pilha *pilha){
    pilha->simbolo= '0';
    pilha-> prox= NULL;
}

int vazia(Pilha *pilha){
	return pilha->prox == NULL ? 1 : 0;
}

int push(Pilha *pilha, char simbolo){
    Pilha *novo= (Pilha *)malloc(sizeof(Pilha));
    if (novo == NULL){
        return 0;
    }

    novo->simbolo= simbolo;
    novo->prox= pilha->prox;
    pilha->prox= novo;

    return 1;
}

char pop(Pilha *pilha){
    Pilha *aux= pilha->prox;
    char rem= aux->simbolo;

    pilha->prox= pilha->prox->prox;
    free(aux);
    return rem;
}


int main(){
    char *simb_abrir= "{[(";
    char *simb_fechar= ")]}";
    char expressao[50], verifica;
    int aux=0, i,j;

    //ler
    fgets(expressao, 50, stdin);

    Pilha p1;
    inicializar(&p1);

    for( i=0; expressao[i]!= '\0'; i++){
        for( j=0; j<3; j++){
            aux=0;
            if(expressao[i] == simb_abrir[j]){
                push(&p1, expressao[i]);
            }

            else if(expressao[i] == simb_fechar[j]){
                verifica=pop(&p1);
                if(expressao[i] == ']'){
                    if(verifica== '['){
                        //printf("1VALIDO\n");
                        aux=1;
                    }
                }
                else if(expressao[i] == ')'){
                    if(verifica== '('){
                        //printf("2VALIDO\n");
                        aux=1;
                    }
                }
                else if(expressao[i] == '}'){
                    if(verifica== '{'){
                        //printf("3VALIDO\n");
                        aux=1;
                    }
                }
                if(aux==0){ 
                    push(&p1, verifica);
                    //printf("INVALIDO\n");
                    j=4;
                    expressao[i+1]= '\0';
                }

                
            }
        }
        if(j==4){
            break;
        }
    }
    if(vazia(&p1) == 1){
		printf("Valido\n");
	}
    else{
        printf("Invalido\n");
    }
}