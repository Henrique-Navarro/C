#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__ 
#include <sys/time.h>
#include <time.h>
#elif _WIN32
#include <sys/time.h>
#endif

#define TAM 1000
#define OPCAO 1   // 0 = vetor ordenado e 1 = aleatório

struct pessoa {
	char nome[30];
	int idade;
};

void bubblesort(int vetor[], int n) ;

int main()
{
	unsigned int i, j = 0;
	struct timeval start, stop;
	double secs = 0;
	srand(time(NULL)); //chama apenas 1 vez*/

	int *vetor = (int *)malloc(TAM * sizeof(int));

	if (vetor == NULL)
	{
		printf("Nao foi possivel alocar o vetor");
		return 0;
	}

	for (i = 0; i < TAM; i++)
	{
		if (OPCAO) //faz se OPCAO 1
		{
			*(vetor + i) = rand() % TAM; // retorna um valor entre 0 e TAM  | *(vetor + 1) = vetor[i]
		}
		else
		{
			*(vetor + i) = i;
		}
	}

    printf("Imprime as 10 ultimas posicoes: ");
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor + j));
	}

    printf("\nCarrega funcao...");
    gettimeofday(&start, NULL);

	bubblesort(vetor,TAM);
    
	
	gettimeofday(&stop, NULL);
    printf("\nFinaliza funcao...");
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
	printf("\nTempo decorrido %f em segundo(s)\n", secs);

	printf("\nImprime as 10 ultimas posicoes: ");
	for (j = TAM - 10; j < TAM ; j++)
	{
		printf("%d ", *(vetor + j));
	}

    free(vetor);
}

void bubblesort (int vetor[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}