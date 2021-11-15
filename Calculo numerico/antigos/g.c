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

void imprimir(double **matrizA, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%f", matrizA[i][j]);
        }
    }
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

void resolverGauss(double **a, double *b, int or)
{
    int i, j, m, k;
    for (i = 0; i < (or -1); i++)
    {
        for (j = i + 1; j <= or ; j++)
        {
            m = -((a[j][i]) / a[i][i]);
            a[j][i] = 0;
            for (k = i + 1; k <= or ; k++)
                a[j][k] = a[j][k] + m * a[i][k];
            b[j] = b[j] + m * b[i];
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double **matrizA = alocaA(n);
    double *matrizB = alocaB(n);

    resolverGauss(matrizA, matrizB, n);
    imprimir(matrizA, n);
    resolverTriangular(matrizA, matrizB, n);
    imprimir(matrizA, n);
}