#include <stdio.h>
#include <stdlib.h>

int main()
{
    //criar vetor
    int vetor[11];

    //atribuir valores
    for (int i = 0; i <= 10; i++)
    {
        vetor[i] = 10 + i;
    }

    //imprimir valores
    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", vetor[i]);
    }
}