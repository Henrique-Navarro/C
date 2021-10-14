#include <stdio.h>

void jogada(char caracter)
{

    printf("Digite a posição desejada\n\n");

    printf(" _0_|_1_|_2_\n");

    printf(" _3_|_4_|_5_ \n");

    printf("  6 | 7 | 8 \n\n");

    scanf("%d", &posic);
}

void iniciar(int op)
{

    int posic, acabou = 0;

    char caracter;

    while (acabou != 1)
    {

        if (op == 1)
        {

            caracter = 'X';

            jogada(caracter);
        }

        else if (op == 2)
        {

            caracter = 'O';

            jogada(caracter);
        }
    }
}

int main()

{

    int op, menu;

    printf(" \n");

    printf(" ___|___|___\n");

    printf(" ___|___|___ \n");

    printf("    |   | \n");

    printf(" \n\n\n\n\n");

    printf(" ___|___|___\n");

    printf(" ___|___|___ \n");

    printf("    |   | \n");

    printf("1- Iniciar\n2- Sair\n");

    scanf("%d", &menu);

    switch (menu)
    {

    case 1:

        printf("X[1] ||| O[2]");

        scanf("%d", &op);

        iniciar(op);

    case 2:

        break;

    default:

        printf("Digite uma opção válida");
    }
}