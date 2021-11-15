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