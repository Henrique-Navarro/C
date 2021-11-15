#include <stdio.h>
#include <stdlib.h>

int main()
{
    int O, i, j, k, p, l, i1, j1, linha, coluna, maior = 0; //O=ordem do sistema; i=contador; j=contador k=contador
    float **A, *B, *X, ope, soma, aux;

    printf("Entre com a ordem do sistema: ");
    scanf("%d", &O);

    A = (float **)malloc(sizeof(float *) * O); //malloc da matriz dos coeficientes
    for (i = 0; i < O; i++)
    {
        A[i] = (float *)malloc(sizeof(float) * O);
    }
    printf("Entre com a matriz dos coeficientes:\n");
    for (i = 0; i < O; i++)
    { //preenche a matriz dos coeficientes
        for (j = 0; j < O; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }
    B = (float *)malloc(sizeof(float) * O);
    X = (float *)malloc(sizeof(float) * O);
    printf("Entre com o vetor dos termos independentes:\n");
    for (i = 0; i < O; i++)
    {
        scanf("%f", &B[i]);
    }
    printriz(A, O); //printa a matriz dos coeficientes

    for (i = 0; i < O - 1; i++)
    {
        if (0 == 0)
        { //Gauss Parcial
            p = i + 1;
            for (l = i + 1; l < O; l++)
            {
                if (abs(A[l][i]) > abs(A[p][i]))
                    p = l;
            }
            aux = B[i];
            B[i] = B[p];
            B[p] = aux;
            for (l = 0; l < O; l++)
            {
                aux = A[i][l];
                A[i][l] = A[p][l];
                A[p][l] = aux;
            }
        }
        printf("\n");
        printriz(A, O);
        for (j = i + 1; j < O; j++)
        { //Gauss Simples
            ope = -A[j][i] / A[i][i];
            B[j] = B[j] + (B[i] * ope);
            for (k = 0; k < O; k++)
            {
                A[j][k] = A[j][k] + (A[i][k] * ope);
            }
        }
        printf("\n");
        printriz(A, O);
    }

    for (i = O - 1; i >= 0; i--)
    { //Resolve sitemas triangulares
        soma = 0;
        for (j = i; j < O; j++)
        {
            soma += A[i][j] * X[j];
            X[i] = (B[i] - soma) / A[i][i];
        }
    }

    printf("Resultado:");
    for (i = 0; i < O; i++)
    {
        printf("\n%f", X[i]);
    }
}

printriz(float **A, int O)
{ //printa a matriz dos coeficientes
    int i, j;
    for (i = 0; i < O; i++)
    {
        for (j = 0; j < O; j++)
        {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}
void pontador(int h, int n, float **A, float *B, int i, int j)
{
    int a, b;
    float aux;
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < n; b++)
        {
            aux = B[h];
            B[h] = B[i];
            B[i] = aux;
            for (b = 0; b < n; b++)
            {
                aux = A[h][h];
                A[h][h] = A[i][b];
                A[i][b] = aux;
            }
            for (b = 0; b < n; b++)
            {
                aux = A[h][h];
                A[h][h] = A[b][j];
                A[b][j] = aux;
            }
        }
    }
}