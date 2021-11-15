#include <stdio.h>
#include <stdlib.h>

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

double soma(double **matrizA, double *vetorX, int i, int n, int constante)
{
    if (i + 1 == n)
    {
        return 0;
    }

    else
    {
        double res = matrizA[constante][i + 1] * vetorX[i + 1] + soma(matrizA, vetorX, i + 1, n, constante);
        return res;
    }
}

void triangular(double **matrizA, double *vetorB, double *vetorX, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        vetorX[i] = (vetorB[i] - soma(matrizA, vetorX, i, n, i)) / matrizA[i][i];
    }
}

void printar(double *vetorX, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", vetorX[i]);
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

    triangular(matrizA, vetorB, vetorX, n);

    printar(vetorX, n);
}