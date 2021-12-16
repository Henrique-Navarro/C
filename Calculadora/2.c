#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double logBase(double logaritmando, double base)
{
    return (log(logaritmando) / log(base));
}

//criar variável de controle para não pedir os resultados toda vez
void juros_simples()
{
    double juros, capital, taxa, tempo, montante;
    int op;

    do
    {
        printf("\nO que voce quer achar?\n0-sair\n1-juros\n2-capital\n3-taxa\n4-tempo\n5-montante\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            break;

        //juros
        case 1:
            printf("Digite a capital:\n");
            scanf("%lf", &capital);

            printf("Digite a taxa:\n");
            scanf("%lf", &taxa);

            printf("Digite o tempo:\n");
            scanf("%lf", &tempo);

            juros = capital * (taxa / 100) * tempo;
            printf("\n\nJuros com valor de:\n%.2lf\n", juros);
            break;

        //capital
        case 2:
            printf("Digite o juros:\n");
            scanf("%lf", &juros);

            printf("Digite a taxa:\n");
            scanf("%lf", &taxa);

            printf("Digite o tempo:\n");
            scanf("%lf", &tempo);

            capital = juros / ((taxa / 100) * tempo);
            printf("\n\nCapital com valor de:\n%.2lf\n", capital);
            break;

        //taxa
        case 3:
            printf("Digite o juros:\n");
            scanf("%lf", &juros);

            printf("Digite a capital:\n");
            scanf("%lf", &capital);

            printf("Digite o tempo:\n");
            scanf("%lf", &tempo);

            taxa = juros / (capital * tempo);
            printf("\n\nTaxa com valor de:\n%.2lf\n", taxa);
            break;

        //tempo
        case 4:
            printf("Digite o juros:\n");
            scanf("%lf", &juros);

            printf("Digite a capital:\n");
            scanf("%lf", &capital);

            printf("Digite a taxa:\n");
            scanf("%lf", &taxa);

            tempo = juros / (capital * taxa / 100);
            printf("\n\nTempo com valor de:\n%.2lf\n", tempo);
            break;

        //montante
        case 5:
            montante = (capital * taxa / 100 * tempo) + capital;

            printf("\n\nMontante com valor de:\n%.2lf\n", montante);

        default:
            break;
        }
    } while (op != 0);
}

void juros_compostos()
{
    double montante, capital, taxa, tempo, juros;
    int op;
    do
    {
        printf("\nO que voce quer achar?\n0-sair\n1-montante\n2-capital\n3-taxa\n4-tempo\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            break;

        //montante
        case 1:
            printf("Digite a capital:\n");
            scanf("%lf", &capital);

            printf("Digite a taxa: \n");
            scanf("%lf", &taxa);

            printf("Digite o tempo: \n");
            scanf("%lf", &tempo);

            montante = capital * (pow(1 + taxa / 100, tempo));
            printf("\n\nMontante com valor de:\n%.2lf\n", montante);
            break;

        //capital
        case 2:
            printf("Digite o montante:\n");
            scanf("%lf", &montante);

            printf("Digite a taxa: \n");
            scanf("%lf", &taxa);

            printf("Digite o tempo: \n");
            scanf("%lf", &tempo);

            capital = montante / (pow(1 + taxa / 100, tempo));
            printf("\n\nCapital com valor de:\n%.2lf\n", capital);
            break;

        //taxa
        case 3:
            printf("Digite o montante:\n");
            scanf("%lf", &montante);

            printf("Digite a capital: \n");
            scanf("%lf", &capital);

            printf("Digite o tempo: \n");
            scanf("%lf", &tempo);

            taxa = (pow(montante / capital, 1 / tempo)) - 1;
            printf("\n\nTaxa com valor de:\n%.2lf\n", taxa);
            break;

        //tempo
        case 4:
            printf("Digite o montante:\n");
            scanf("%lf", &montante);

            printf("Digite a capital: \n");
            scanf("%lf", &capital);

            printf("Digite o taxa: \n");
            scanf("%lf", &taxa);

            //log - base
            tempo = logBase(montante / capital, 1 + taxa / 100);
            printf("\n\nTempo com valor de:\n%.2lf\n", tempo);
            break;

        default:
            break;
        }
    } while (op != 0);
}

int main()
{
    int op;

    printf("\n1-juros simples\n2-juros compostos\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        juros_simples();

    case 2:
        juros_compostos();

    default:
        break;
    }
}