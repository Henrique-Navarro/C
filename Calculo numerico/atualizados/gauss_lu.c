#include <stdio.h>
#include <stdlib.h>

void lerA(double **matrizA, int n, double **L)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrizA[i][j]);

            if (i == j)
            {
                L[i][j] = 1;
            }
            else
            {
                L[i][j] = 0;
            }
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

double somaY(double **L, double *vetorY, int i, int n, int constante)
{
    if (i == 0)
    {
        return 0;
    }

    else
    {
        double res = L[constante][i - 1] * vetorY[i - 1] + somaY(L, vetorY, i - 1, n, constante);
        return res;
    }
}

double somaX(double **matrizA, double *vetorX, int i, int n, int constante)
{
    if (i + 1 == n)
    {
        return 0;
    }

    else
    {
        double res = matrizA[constante][i + 1] * vetorX[i + 1] + somaX(matrizA, vetorX, i + 1, n, constante);
        return res;
    }
}

void triangularY(double **L, double *vetorB, double *vetorX, int n, double *vetorY)
{
    for (int i = 0; i < n; i++)
    {
        vetorY[i] = (vetorB[i] - somaY(L, vetorY, i, n, i)) / L[i][i];
    }
}

void triangularX(double **matrizA, double *vetorB, double *vetorX, int n, double *vetorY)
{
    for (int i = n - 1; i >= 0; i--)
    {
        vetorX[i] = (vetorY[i] - somaX(matrizA, vetorX, i, n, i)) / matrizA[i][i];
    }
}

int main()
{
    int n, i, j, k, op;
    scanf("%d", &n);

    double **matrizA = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        matrizA[i] = malloc(n * sizeof(double));
    }

    double **L = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        L[i] = malloc(n * sizeof(double));
    }

    double *vetorB = malloc(n * sizeof(double));
    double *vetorX = malloc(n * sizeof(double));
    double *vetorY = malloc(n * sizeof(double));

    lerA(matrizA, n, L);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            L[j][i] = matrizA[j][i] / matrizA[i][i];
            for (k = 0; k < n; k++)
            {
                matrizA[j][k] = matrizA[j][k] - L[j][i] * matrizA[i][k];
            }
        }
    }

    do
    {
        lerB(vetorB, n);

        triangularY(L, vetorB, vetorX, n, vetorY);
        triangularX(matrizA, vetorB, vetorX, n, vetorY);

        printf("Digite 1 para sair");
        scanf("%d", &op);
    } while (op != 1);

    printar(vetorX, n);
}