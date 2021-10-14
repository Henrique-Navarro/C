#include <stdio.h>
#include <stdlib.h>

void lerA(int **matrizA, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrizA[i][j]);
        }
    }
}
void imprimirA(int **matrizA, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", matrizA[i][j]);
        }
        printf("\n");
    }
}

void lerB(int *matrizB, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &matrizB[i]);
    }
}
void imprimirB(int *matrizB, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d \n", matrizB[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int **matrizA;
    matrizA = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        matrizA[i] = malloc(3 * sizeof(int));
    }
    lerA(matrizA, n);

    int *matrizB;
    matrizB = malloc(n * sizeof(int));
    lerB(matrizB, n);

    printf("\nA matriz ficou assim: \n");
    imprimirA(matrizA, n);
    imprimirB(matrizB, n);

    int *x;
    x = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }

    int soma;

    for (int i = n - 1; i <= 0; i--)
    {
        soma = 0;
        for (int j = n - 1; j == i; j--)
        {
            soma = (matrizA[i][j] * x[i + 1]) + soma;
        }
        x[i] = matrizB[i] / (matrizA[i][i] - soma);
    }

    //2z= 3
    //matrizA[n-1][n-1]= matrizB[n-1];
    /*int z= matrizB[n-1] / matrizA[n-1][n-1];
    int y= (-(matrizA[n-2][n-1] * z) + matrizB[n-2]) / matrizB[n-2];
    int x= ((-(matrizA[n-3][n-1] * z) + (matrizA[n-3][n-2] * y)) + matrizB[n-3]) / matrizB[n-3];*/

    /*
       [0]  [1]  [2]  
[0]    1x + 1y + 1z = 2
[1]    0x - 2y - 2z = -5
[2]    0x + 0y + 1z = -1/2
    */

    //printf("%d %d %d", x,y,z);
    for (int i = 0; i < n; i++)
    {
        printf("valor: %d\n", x[i]);
    }
}