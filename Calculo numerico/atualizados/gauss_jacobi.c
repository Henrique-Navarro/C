#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10

double *vetor(int ordem)
{
    double *vetorX;

    vetorX = malloc(ordem * sizeof(double));
    return vetorX;
}

double **matriz(int ordem)
{
    int i;
    double **matrizA;

    matrizA = malloc(ordem * sizeof(double *));
    for (i = 0; i < ordem; i++)
        matrizA[i] = malloc(ordem * sizeof(double));

    return matrizA;
}

void ler(double **matrizA, int ordem)
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            scanf("%lf", &matrizA[i][j]);
        }
    }
}

void calcularErro(double **matrizA, double *erro, double *novoVB, double *vetorB, int ordem)
{
    int i, j;
    double cont = 0, aux = 0;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            aux += matrizA[i][j] * novoVB[j];
        }
        erro[i] = aux;
        aux = 0;
    }
    for (i = 0; i < ordem; i++)
    {
        cont += pow((vetorB[i] - erro[i]), 2);
    }

    cont = sqrt(cont);
    printf("\nErro: %lf\n", cont);
}

void organizarMatriz(double **matrizA, int ordem, double *chute, double *vetorB, double *novoVB, int q, double *erro)
{
    int i, j;
    double aux;

    calcularErro(matrizA, erro, novoVB, vetorB, ordem);

    if (q < TAM)
    {
        for (i = 0; i < ordem; i++)
        {
            aux = 0;
            for (j = 0; j < ordem; j++)
            {
                if (i != j)
                {
                    aux += (matrizA[i][j] * chute[j]);
                    novoVB[i] = (vetorB[i] - aux) / matrizA[i][i];
                }
            }
            printf("novoB %d: %lf\n", i, novoVB[i]);
        }

        for (i = 0; i < ordem; i++)
        {
            chute[i] = novoVB[i];
        }

        organizarMatriz(matrizA, ordem, chute, vetorB, novoVB, q + 1, erro);
    }
}

int main()
{
    int i, ordem, q = 0;
    double **matrizA, *vetorB, *chute, *novoVB, *erro;

    scanf("%d", &ordem);

    matrizA = matriz(ordem);
    vetorB = vetor(ordem);
    novoVB = vetor(ordem);
    chute = vetor(TAM);
    erro = vetor(TAM);

    ler(matrizA, ordem);
    for (i = 0; i < ordem; i++)
    {
        scanf("%lf", &vetorB[i]);
    }

    //chute aleatório
    for (i = 0; i < ordem; i++)
    {
        scanf("%lf", &chute[i]);
    }

    organizarMatriz(matrizA, ordem, chute, vetorB, novoVB, q, erro);
}