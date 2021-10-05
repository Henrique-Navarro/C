#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__ 
#include <sys/time.h>
#include <time.h>
#elif _WIN32
#include <sys/time.h>
#endif

#define TAM 3

struct pessoa {
	char nome[30];
	int idade;
};

void bubblesort(struct pessoa *vetor_pessoa, int n) ;

int main()
{
	unsigned int i, j = 0;
	
	struct pessoa *vetor = (struct pessoa *)malloc(TAM * sizeof(struct pessoa));

	if (vetor == NULL)
	{
		printf("Nao foi possivel alocar o vetor");
		return 0;
	}

    strcpy(vetor[0].nome,"Paulo");
    vetor[0].idade =  30;

    strcpy(vetor[1].nome,"Giselle");
    vetor[1].idade = 20;

    strcpy(vetor[2].nome,"Joaquim");
    vetor[2].idade = 8;

    for(i=0; i<3; i++){
        printf("Nome: %s e idade: %d\n", vetor[i].nome, vetor[i].idade);
    }
	
	bubblesort(vetor,TAM);
    printf("\nOrdenado\n");
	
    for(i=0; i<3; i++){
        printf("Nome: %s e idade: %d\n", vetor[i].nome, vetor[i].idade);
    }
	

    free(vetor);
}

void bubblesort(struct pessoa *vetor_pessoa, int n) {
    int k, j;
    struct pessoa aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (strcmp(vetor_pessoa[j].nome , vetor_pessoa[j + 1].nome) > 0 ) {
                aux          = vetor_pessoa[j];
                vetor_pessoa[j]     = vetor_pessoa[j + 1];
                vetor_pessoa[j + 1] = aux;
            }
        }
    }
}