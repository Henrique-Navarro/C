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
    printf("Resposta:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%lf\n", vetorX[i]);
    }
}

void gauss(double **matrizA, double *vetorB, int n)
{
    int i, j, k, auxlinha;
    double pivo, aux;
    for (i = 0; i < n - 1; i++)
    {
        auxlinha = i;
        //maior numero
        for (j = i + 1; j < n; j++)
        {
            if (fabs(matrizA[auxlinha][i]) < fabs(matrizA[j][i]))
            {
                auxlinha = j;
            }
        }

        //troca linha matriz
        for (j = 0; j < n; j++)
        {
            aux = matrizA[i][j];
            matrizA[i][j] = matrizA[auxlinha][j];
            matrizA[auxlinha][j] = aux;
        }

        //troca linha vetor
        aux = vetorB[i];
        vetorB[i] = vetorB[auxlinha];
        vetorB[auxlinha] = aux;

        for (j = i + 1; j < n; j++)
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

    gauss(matrizA, vetorB, n);

    triangular(matrizA, vetorB, vetorX, n);

    printar(vetorX, n);
}