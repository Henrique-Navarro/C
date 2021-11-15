#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float **aloca(int n);
void imprime(float **A, float *b, int n);
void pivotamentoParcial(float **A, float *b, int n);
int encontraMaior(float **A, int i, int j, int n);

int main()
{
    int n, i, j, h, *posResposta, aux;
    float *x, **A, *b, soma;

    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    A = aloca(n);

    printf("\nDigite os valores da matriz: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %.2f ", A[i][j]);
        }
        printf("\n");
    }

    x = malloc(n * sizeof(float));
    b = malloc(n * sizeof(float));

    printf("\nDigite os termos independentes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf(" %.2f ", b[i]);
    }

    posResposta = malloc(n * sizeof(int));

    for (h = 0; h < n; h++)
    {
        posResposta[h] = h;
    }

    printf("\npivo");
    pivotamentoParcial(A, b, n);
    printf("\npivosaiu");
    imprime(A, b, n);

    printf("\n");
    for (i = n - 1; i >= 0; i--)
    {
        soma = 0;
        for (j = n - 1; j >= 0; j--)
        {
            soma += A[i][j] * x[j];
        }
        x[i] = (b[i] - soma) / A[i][i];
    }

    printf("\nResposta: ");
    for (i = 0; i < n; i++)
    {
        aux = posResposta[i];
        printf("%.2f ", x[aux]);
    }
    printf("\n");

    free(posResposta);
    free(A);
    free(b);
    free(x);
}

float **aloca(int n)
{

    int i;
    float **matriz;

    matriz = malloc(n * sizeof(float));
    if (matriz == NULL)
    {
        printf("\nErro!!!");
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        matriz[i] = malloc(n * sizeof(float));
        if (matriz[i] == NULL)
        {
            printf("\nErro!!!");
            exit(0);
        }
    }

    return matriz;
}

void imprime(float **A, float *b, int n)
{

    int i, j;

    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %.2f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf(" %.2f ", b[i]);
    }
}

void pivotamentoParcial(float **A, float *b, int n)
{

    int i = 0, j, k, posMaior, l;
    float m, b1, aux[n];

    for (k = 0; k < n; k++)
    {   
        printf("\nmaior");
        posMaior = encontraMaior(A, k, k, n);
        printf("\nmaior");
        if (posMaior != k)
        {
            for (l = k; l < n; l++)
            {
                aux[l] = A[k][l];
                A[k][l] = A[posMaior][l];
                A[posMaior][l] = aux[l];
            }

            b1 = b[k];
            b[k] = b[posMaior];
            b[posMaior] = b1;
        }

        for (i = k + 1; i < n; i++)
        {
            m = -1 * (A[i][k] / A[k][k]);
            for (j = k; j < n; j++)
            {
                A[i][j] = A[i][j] + (m * A[k][j]);
            }
            b[i] = b[i] + (m * b[k]);
        }
    }
}

int encontraMaior(float **A, int x, int y, int n)
{
    int posMaior;
    for (int i = x; i < n; i++)
    {
        for (int j = y, posMaior = j, aux = j; j < n; j++)
        {
            if (abs(A[j][aux]) > abs(A[posMaior][aux]))
            {
                posMaior = j;
            }
        }
    }

    return posMaior;
}