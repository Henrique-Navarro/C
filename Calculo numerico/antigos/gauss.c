#include <stdio.h>
#include <stdlib.h>

void lerA(double **matrizA, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lf", &matrizA[i][j]);
        }
    }
}
void imprimirA(double **matrizA, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf(" %lf ", matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
double **alocaA(int n)
{
    double **matrizA;
    matrizA = malloc(n * sizeof(double));
    for (int i = 1; i <= n; i++)
    {
        matrizA[i] = malloc(n * sizeof(double));
    }
    lerA(matrizA, n);
    printf("\nA matrizA ficou assim: \n");
    imprimirA(matrizA, n);

    return matrizA;
}

void lerB(double *matrizB, int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &matrizB[i]);
    }
}
void imprimirB(double *matrizB, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf(" %lf \n", matrizB[i]);
    }
    printf("\n");
}
double *alocaB(int n)
{
    double *matrizB;
    matrizB = malloc(n * sizeof(double));
    lerB(matrizB, n);
    printf("\nA matrizB ficou assim: \n");
    imprimirB(matrizB, n);

    return matrizB;
}

void printarAumentada(double **matrizAumentada, int n)
{
    printf("Matriz aumentada\n");
    for (int j, i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf(" %f ", matrizAumentada[i][j]);
        }
        printf("\n");
    }
}
double **alocaAumentada(int n, double **matrizA, double *matrizB)
{
    double **matrizAumentada;
    matrizAumentada = malloc(n * sizeof(double));
    for (int i = 1; i <= n + 1; i++)
    {
        matrizAumentada[i] = malloc(n * sizeof(double));
    }

    int j, i;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            matrizAumentada[i][j] = matrizA[i][j];
        }
        matrizAumentada[i][j] = matrizB[i];
    }

    printarAumentada(matrizAumentada, n);

    return matrizAumentada;
}

void resolverTriangular(double **matrizA, double *matrizB, int n)
{
    double *x;
    x = malloc(n * sizeof(double));
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    double soma;
    for (int i = n; i >= 1; i--)
    {
        soma = 0;
        for (int j = (i + 1); j <= n; j++)
        {
            soma = soma + matrizA[i][j] * x[j];
        }
        x[i] = (matrizB[i] - soma) / matrizA[i][i];
    }
    printf("\nA matrizX ficou assim: \n");
    for (int i = 1; i <= n; i++)
    {
        printf("%.3lf\n", x[i]);
    }
}

void resolverGauss(double **matrizAumentada, int n)
{
    //pivo
    double pivo, multiplicador;

    //multiplicador
    for (int coluna = 1; coluna <= n + 1; coluna++)
    {
        pivo = matrizAumentada[coluna][coluna];
        printf("pivo: %f ", pivo);

        for (int linha = coluna + 1; linha <= n; linha++)
        {
            multiplicador = (matrizAumentada[linha][coluna]) / pivo;
            printf("multiplicador: %f ", multiplicador);
            //multiplicar
            int i = linha;
            for (int j = 1; j <= n + 1; j++)
            {
                matrizAumentada[i][j] = matrizAumentada[i][j] - (multiplicador * pivo);
            }
            printarAumentada(matrizAumentada, n);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double **matrizA = alocaA(n);
    double *matrizB = alocaB(n);
    double **matrizAumentada = alocaAumentada(n, matrizA, matrizB);

    resolverGauss(matrizAumentada, n);
    printarAumentada(matrizAumentada, n);
    resolverTriangular(matrizA, matrizB, n);
}