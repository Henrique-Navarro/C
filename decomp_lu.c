#include <stdio.h>
#include <stdlib.h>

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

void trocar(double **matrizA, int ordem, double **aux)
{
    int i, j, k;
    double pivo;

    for (k = 0; k < ordem - 1; k++)
    {
        for (i = k + 1; i < ordem; i++)
        {
            pivo = -matrizA[i][k] / matrizA[k][k];
            for (j = 0; j < ordem; j++)
            {
                matrizA[i][j + k] += (pivo * matrizA[k][j + k]);
            }
            aux[i][k] = pivo * -1;
        }
    }

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            if (i == j)
                aux[i][j] = 1;
        }
    }
}

double somaX(int i, int ordem, double **matrizA, double *vetorX)
{
    int j;
    double soma = 0;

    for (j = i + 1; j < ordem; j++)
        soma += matrizA[i][j] * vetorX[j];

    return soma;
}

double somaY(int i, int ordem, double **matrizA, double *vetorX)
{
    int j;
    double soma = 0;

    for (j = i - 1; j >= 0; j--)
        soma += matrizA[i][j] * vetorX[j];

    return soma;
}

void resultY(double **var, double *vetorY, int i, int ordem, double *vetorB)
{
    if (i < ordem)
    {
        vetorY[i] = ((vetorB[i] - somaY(i, ordem, var, vetorY)) / var[i][i]);
        printf("vetorY[%d] = %.4lf\n", i, vetorY[i]);
        resultY(var, vetorY, i + 1, ordem, vetorB);
    }
}

void resultado(double **matrizA, double *vetorX, int i, int ordem, double *vetorB)
{

    if (i >= 0)
    {
        vetorX[i] = ((vetorB[i] - somaX(i, ordem, matrizA, vetorX)) / matrizA[i][i]);
        resultado(matrizA, vetorX, i - 1, ordem, vetorB);
        printf("vetorX[%d] = %.4lf\n", i, vetorX[i]);
    }
}

void decompor(double **matrizA, double *vetorB, double *vetorX, double *vetorY, double **m, int n, int ordem)
{
    int i, j, k;
    do
    {
        for (i = 0; i < ordem; i++)
        {
            scanf("%lf", &vetorB[i]);
        }

        printf("\nL:\n");
        for (i = 0; i < ordem; i++)
        {
            for (j = 0; j < ordem; j++)
                printf("%lf ", m[i][j]);
            printf("\n");
        }
        printf("\n");

        printf("\nU:\n");
        for (i = 0; i < ordem; i++)
        {
            for (j = 0; j < ordem; j++)
                printf("%.2lf ", matrizA[i][j]);
            printf("\n");
        }
        printf("\n");

        resultY(m, vetorY, 0, ordem, vetorB);
        printf("\n");
        resultado(matrizA, vetorX, ordem - 1, ordem, vetorY);
        printf("\n");

        for (i = 0; i < ordem; i++)
            printf("vetorB = %lf\n", vetorB[i]);

        printf("\n1 para sair\n");
        scanf("%d", &n);
    } while (n != 1);
}

int main()
{
    int i, j, n = 0, ordem;
    double *vetorX, *vetorY, **m, **matrizA, *vetorB;

    scanf("%d", &ordem);

    matrizA = matriz(ordem);
    m = matriz(ordem);

    vetorX = vetor(ordem);
    vetorB = vetor(ordem);
    vetorY = vetor(ordem);

    ler(matrizA, ordem);

    //preencher
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
            m[i][j] = 0;
    }

    trocar(matrizA, ordem, m);

    decompor(matrizA, vetorB, vetorX, vetorY, m, n, ordem);
}