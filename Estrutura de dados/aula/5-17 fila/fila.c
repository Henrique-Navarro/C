#include<stdio.h>
#include<stdlib.h>

struct cel {
    int info;
    struct cel * prox;
};
        
struct fila {
    struct cel *inicio;
    struct cel *fim;
};

void inicia ( struct fila * f ){
    f->inicio = NULL;
    f->fim = NULL;
}

void insere ( struct fila * f , int valor ){
	struct cel *novo;
	if ((novo = (struct cel*) malloc(sizeof( struct cel)))==NULL)
		printf ("Impossivel alocar a memoria\n");
	else {
		novo->info = valor;
		novo->prox = NULL;

		if (f->inicio == NULL) {
			f->inicio = novo;
			f->fim = novo;
		}
		else {
			(f->fim)-> prox = novo;
			f->fim = novo;
		}
	}							
}

int retira ( struct fila * f ) {
   
    struct cel *aux = f->inicio;
    int rem = aux->info;
    f->inicio = (f->inicio)->prox;
    free(aux);
    return rem; 
}

void apresentaFila( struct fila *f)
{
     struct cel *aux;
     aux = f->inicio;
 
     while(aux != NULL)
     {
         printf ("Elemento = %3d\n",(aux->info));
       	aux = aux->prox;
       
	 }
    
}
int main(){
    struct fila f;
    inicia(&f);
    insere(&f,10);
    insere(&f,7);
    insere(&f,8);
    insere(&f,1);
    
    getchar();
    apresentaFila(&f);
    printf("retira = %d\n",retira(&f));
    getchar();
    printf("retira = %d\n",retira(&f));
    getchar();
    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    printf("retira = %d\n",retira(&f));
    apresentaFila(&f);
    getchar();
}