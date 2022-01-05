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

void area()
{
    double lado, base, altura, raio, area, g;
    int op;
    do
    {
        printf("\n\n\n[ 1  ] - Quadrado\n[ 2  ] - Retangulo\n[ 3  ] - Triangulo\n[ 4  ] - Circulo\n[ 5  ] - Losango\n[ 6  ] - Trapezio");
        printf("\n[ 7  ] - Cubo\n[ 8  ] - Piramide\n[ 9  ] - Cone\n[ 10 ] - Cilindro\n[ 11 ] - Prisma\n[ 12 ] - Esfera\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            break;

        //quadrado
        case 1:
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            area = lado * lado;
            printf("Area do quadrado: %.2lf", area);
            break;

        //retangulo
        case 2:
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            area = lado * base;
            printf("Area do retangulo: %.2lf", area);
            break;

        //triangulo
        case 3:
            printf("Digite o valor da altura: \n");
            scanf("%lf", &base);
            printf("Digite o valor da base: \n");
            scanf("%lf", &altura);
            area = (base * altura) / 2;
            printf("Area do triangulo: %.2lf", area);
            break;

        //circulo
        case 4:
            printf("Digite o valor do raio: \n");
            scanf("%lf", &raio);
            area = 3.1415926535 * (pow(raio, 2));
            printf("Area do circulo: %.2lf", area);
            break;

        //losango
        case 5:
            printf("Digite o valor da diagonal Maior: \n");
            scanf("%lf", &base);
            printf("Digite o valor da diagonal Menor: \n");
            scanf("%lf", &altura);
            area = (base * altura) / 2;
            printf("Area do losango: %.2lf", area);
            break;

        //trapezio
        case 6:
            printf("Digite o valor da Base Maior: \n");
            scanf("%lf", &base);
            printf("Digite o valor da base menor: \n");
            scanf("%lf", &lado);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            area = ((base + lado) * altura) / 2;
            printf("Area do trapezio: %.2lf", area);
            break;

        //cubo
        case 7:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            area = base * altura * lado;
            printf("Area do cubo: %.2lf", area);
            break;

        //piramide
        case 8:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            g = sqrt((pow((base / 2), 2)) + (pow(altura, 2)));
            //area base(quadrado) + area lado(triangulo)
            area = ((base * base) + ((base * g) / 2) * 4);
            printf("Area da piramide: %.2lf", area);
            break;

            //cone
            /*case 9:

            break;

        //cilindro
        case 10:

            break;

        //prisma
        case 11:

            break;

        //esfera
        case 12:

            break;
        }*/
        }
    } while (op != 0);
}

void expressao()
{
    double a, b, c, x, y, delta;
    printf("\nDigite os coeficientes:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    delta = (pow(b, 2) - (4 * a * c));
    x = ((-b + sqrt(delta)) / (2 * a));
    y = ((-b - sqrt(delta)) / (2 * a));
    printf("x1: %.2lf\nx2: %.2lf\n", x, y);
}

void fatorial()
{
    int numero;

    printf("\nQual numero vc quer o fatorial?\n");
    scanf("%d", &numero);

    for (int i = numero - 1; i >= 1; i--)
    {
        numero *= i;
    }
    printf("%d", numero);
}

void velocidade()
{
    double posicaoI, posicaoF, tempoI, tempoF, velocidadeMed;
    int op;
    do
    {
        printf("\nO que voce quer achar?\n[ 0 ] - sair\n[ 1 ] - velocidade media\n[ 2 ] - variacao distancia\n[ 3 ] - variacao tempo\n[ 4 ] - m/s -> km/h\n[ 5 ] - km/h -> m/s\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            break;

        //velocidade
        case 1:
            printf("\nQuanto e a posicao inicial e a posicao final? [m]\n");
            scanf("%lf %lf", &posicaoI, &posicaoF);

            printf("\nQuanto e o tempo inicial e o tempo final? [s]\n");
            scanf("%lf %lf", &tempoI, &tempoF);

            velocidadeMed = ((posicaoF - posicaoI) / (tempoF - tempoI));
            printf("\nA velocidade media e de: m/s", velocidadeMed);
            break;

        //distancia
        case 2:

        //tempo
        case 3:

        //m/s -> km/h
        case 4:
            printf("\nA velocidade media e de: %.2lf km/h\n", velocidadeMed * 3.6);
            break;

        //km/h -> m/s
        case 5:
            printf("\nA velocidade media e de: %.2lf m/s\n", velocidadeMed / 3.6);
            break;

        default:
            break;
        }
    } while (op != 0);
}

int main()
{
    int op;

    printf("\n[ 1 ] - juros simples\n[ 2 ] - juros compostos\n[ 3 ] - unidades de medida\n[ 4 ] - area\n[ 5 ] - volume\n[ 6 ] - expressao 2 grau\n[ 7 ] - fatorial\n");
    printf("[ 8 ] - velocidade\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        juros_simples();

    case 2:
        juros_compostos();

    case 4:
        area();

        //case 5:
        //  volume();

    case 6:
        expressao();

    case 7:
        fatorial();

    case 8:
        velocidade();

    default:
        break;
    }
}