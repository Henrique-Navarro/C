#include <stdio.h>
#include <stdlib.h>

 struct Cel {   
  int dado;   
  struct Cel *prox;   
};

struct Lista{
    struct Cel *inicio;
	struct Cel *fim;
} Lista;

void inicializar(struct Lista *lista);
int inserirInicio(struct Lista *lista, int dado);
int inserirFim(struct Lista *lista, int dado);
int mostrar(struct Lista lista);
int remover(struct Lista *lista, int dado);
int menu();

int main(){

    int op;
	int dado;
	struct Lista lista;

	inicializar(&lista);	

	do{
		op = menu();
		switch(op){
			case 1:  printf("Digite um numero: ");
						scanf("%d", &dado);
						if(inserirInicio(&lista, dado))
							printf("Insercao realizado com sucesso!");
						else
							printf("Falha na insercao!");
						break;
			case 2:  printf("Digite um numero: ");
						scanf("%d", &dado);
						if(inserirFim(&lista, dado))
							printf("Insercao realizado com sucesso!");
						else
							printf("Falha na insercao!");
						break;
			case 3:	mostrar(lista);
						break;
			case 4:  printf("Digite um numero: ");
						scanf("%d", &dado);
						printf("\n%d removidos!!!", remover(&lista,dado));
						break;
			case 5:	printf("\nTchau!!!");
						break;
			default: printf("\nOpcao Invalida!!!");
		}

	}while(op != 5);
	
	return 0;
}

int menu(){
	int op;
	printf("\n 1 - Inserir no Inicio");
	printf("\n 2 - Inserir no Fim");
	printf("\n 3 - Mostrar Lista");
	printf("\n 4 - Remover itens");
	printf("\n 5 - Sair\n");
	scanf("%d", &op);
	return op;
}

void inicializar (struct Lista *lista){   
  lista->inicio = NULL;   
  lista->fim = NULL;   
}   

int inserirInicio(struct Lista *lista, int dado){
	struct Cel  *novo = malloc(sizeof(struct Cel));
	
	if(novo == NULL)
		return 0;

	novo->dado = dado;	
	
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		lista->fim->prox = NULL;
	}else{
		novo->prox = lista->inicio;
		lista->inicio = novo;
	}

	return 1;
}

int inserirFim(struct Lista *lista, int dado){
	struct Cel  *novo = malloc(sizeof(struct Cel));
	novo->dado = dado;	
	
	if(novo == NULL)
		return 0;

	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
		lista->fim->prox = NULL;
	}else{
		lista->fim->prox = novo;
		lista->fim = novo;
		lista->fim->prox = NULL;
	}

	return 1;
}

int remover(struct Lista *lista, int dado){
	struct Cel *aux;
	struct Cel *ant;
	int qtdDel = 0;
	
	aux = lista->inicio;
	ant = NULL;

	while(aux != NULL){
		if(aux->dado == dado){
			qtdDel++;
			if(aux == lista->inicio){
				lista->inicio = aux->prox;
				free(aux);
				aux = lista->inicio;
			}else if(aux == lista->fim){
				ant->prox = NULL;
				lista->fim = ant;
				free(aux);
				aux = NULL;
			}else{
				ant->prox = aux->prox;
				free(aux);
				aux = ant->prox;
			}
		}else{
			ant = aux;
			aux = aux->prox;
		}
	}
	
	return qtdDel;
}

int mostrar(struct Lista lista){
	struct Cel *aux;	
	
	if(lista.inicio == NULL){
		return 0;	
	}else{
		aux = lista.inicio;
		while(aux != NULL){
			printf("%d ", aux->dado);
			aux = aux->prox;
		}
	}
	return 1;
}