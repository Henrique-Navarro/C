#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcaoFunc()
{
    int opcao;
    printf("1- o\n2- x\n");
    scanf("%d", &opcao);
    return opcao;
}
/*
modoFunc()
{
    int modo;
    printf("1- PVP\n2- BOT");
    scanf("%d", &modo);
}*/

void printar(char *vetor)
{
    printf("\n\n");
    printf(" %c | %c | %c \n", vetor[1], vetor[2], vetor[3]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n", vetor[4], vetor[5], vetor[6]);
    printf("___|___|___\n");
    printf(" %c | %c | %c \n", vetor[7], vetor[8], vetor[9]);
    printf("   |   |   \n");
}

verifica()
{
    x x x 1 2 3

        x
            x
                x 1 5 9

        x
            x
                x 1 4 7

    //verificar todas as colunas, depois as linhas
}

int main()
{
    char *vetor = malloc(sizeof(char) * 9);

    printf(" 1 | 2 | 3 \n");
    printf("___|___|___\n");
    printf(" 4 | 5 | 6 \n");
    printf("___|___|___\n");
    printf(" 7 | 8 | 9 \n");
    printf("   |   |   \n");

    //limpar
    for (int i = 1; i <= 9; i++)
    {
        vetor[i] = ' ';
    }

    printar(vetor);

    int opcao = opcaoFunc();
    int posic, acabou = 0;
    // o
    if (opcao == 1)
    {
        do
        {
            printf("Digite a posicao: \n");
            scanf("%d", &posic);
            vetor[posic] = 'o';
            printar(vetor);
        } while (acabou == 0);
    }
    // x
    else
    {
        do
        {
            printf("Digite a posicao: \n");
            scanf("%d", &posic);
            vetor[posic] = 'x';
            printar(vetor);
        } while (acabou == 0);
    }

    //modoFunc();
}