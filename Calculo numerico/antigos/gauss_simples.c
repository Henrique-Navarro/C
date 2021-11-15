#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, i, j, k, l;
    float matriz[10][10], v1[10], v2[10], m, a, multi, s;
    printf("Qual a ordem do sistema?\n");
    scanf("%d", &x);

    printf("Qual a matriz dos coeficientes?\n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("Qual o vetor dos termos independentes?\n");
    for (i = 0; i < x; i++)
    {
        scanf("%f", &v1[i]);
    }
    for (i = 0; i < x; i++)
    {
        m = matriz[i][i];
        l = i;
        for (k = i + 1; k < x; k++)
        {
            if (m == 0 || abs(matriz[k][i]) > abs(m))
            {
                m = matriz[k][i];
                l = k;
            }
        }
        if (l != i)
        {
            for (k = i; k < x; k++)
            {
                a = matriz[i][k];
                matriz[i][k] = matriz[l][k];
                matriz[l][k] = a;
            }
            a = v1[i];
            v1[i] = v1[l];
            v1[l] = a;
        }
        for (k = 0; k < x; k++)
        {
            for (j = 0; j < x; j++)
            {
                printf("%.2f ", matriz[k][j]);
            }
            printf("\n");
        }
        for (j = i + 1; j < x; j++)
        {
            multi = -((matriz[j][i]) / matriz[i][i]);
            matriz[j][i] = 0;
            for (k = i + 1; k < x; k++)
            {
                matriz[j][k] = matriz[j][k] + multimatriz[i][k];
            }
            v1[j] = v1[j] + multiv1[i];
        }
    }
    for (i = x - 1; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j <= x - 1; j++)
        {
            s += matriz[i][j] * v2[j];
        }
        v2[i] = (v1[i] - s) / matriz[i][i];
    }

    printf("Resultado:\n");
    for (i = 0; i < x; i++)
    {
        printf("%.2f\n", v2[i]);
    }

    return 0;
}