#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lerA(double **matrizA, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrizA[i][j]);
        }
    }
}

void lerB(double *vetorB, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &vetorB[i]);
    }
}

void printar(double *vetorX, int n)
{
    printf("Resposta:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", vetorX[i]);
    }
}

void zerar(double **matrizA, double *vetorB, int n)
{
    int i, j, k;
    double pivo, aux;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                pivo = -matrizA[j][i] / matrizA[i][i];
                vetorB[j] = vetorB[j] + pivo * vetorB[i];
                for (k = 0; k < n; k++)
                {
                    matrizA[j][k] = matrizA[j][k] + pivo * matrizA[i][k];
                }
            }
        }
    }
}

void respostas(double **matrizA, double *vetorB, double *vetorX, int n)
{
    for (int i = 0; i < n; i++)
    {
        vetorX[i] = vetorB[i] / matrizA[i][i];
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double **matrizA = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        matrizA[i] = malloc(n * sizeof(double));
    }
    double *vetorB = malloc(n * sizeof(double));
    double *vetorX = malloc(n * sizeof(double));

    lerA(matrizA, n);
    lerB(vetorB, n);

    zerar(matrizA, vetorB, n);

    respostas(matrizA, vetorB, vetorX, n);

    printar(vetorX, n);
}