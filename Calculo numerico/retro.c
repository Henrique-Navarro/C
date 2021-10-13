#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int **matrizA;
    //alocar matriz
    matrizA = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        matrizA[i] = malloc(3 * sizeof(int));
    }
    //ler matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &matrizA[i][j]);
        }
    }

    int *matrizB;
    //alocar
    matrizB = malloc(n * sizeof(int));
    //ler vetor
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &matrizB[i]);
    }

    int *x;
    x = malloc(n * sizeof(int));
    int soma;

    for (int i = n; i <= 1; i--)
    {
        soma = 0;
        for (int j = (i + 1); j <= n; j++)
        {
            soma = soma + matrizA[i][j] * x[j];
        }
        x[i] = (matrizB[i] - soma) / matrizA[i][i];
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
    for (int i = 1; i <= n; i++)
    {
        printf("%.3d\n", x[i]);
    }
}