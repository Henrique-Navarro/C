#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void printar(double valor)
{
    printf("%.2lf\n", valor);
}

double logBase(double logaritmando, double base)
{
    return (log(logaritmando) / log(base));
}

//criar variável de controle para não pedir os resultados toda vez
double juros_simples()
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
            printf("\n\nJuros com valor de: ");
            printar(juros);
            return juros;
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
            printf("\n\nCapital com valor de: ");
            printar(capital);
            return capital;
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
            printf("\n\nTaxa com valor de: ");
            printar(taxa);
            return taxa;
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
            printf("\n\nTempo com valor de: ");
            printar(tempo);
            return tempo;
            break;

        //montante
        case 5:
            montante = (capital * taxa / 100 * tempo) + capital;

            printf("\n\nMontante com valor de: ");
            printar(montante);
            return montante;

        default:
            break;
        }
    } while (op != 0);
}

double juros_compostos()
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
            printf("\n\nMontante com valor de: ");
            printar(montante);
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
            printf("\n\nCapital com valor de: ");
            printar(capital);
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
            printf("\n\nTaxa com valor de: ");
            printar(taxa);
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
            printf("\n\nTempo com valor de: ");
            printar(tempo);
            break;

        default:
            break;
        }
    } while (op != 0);
}

double area()
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

        //! figuras planas
        //quadrado
        case 1:
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            area = lado * lado;
            printf("Area do quadrado: ");
            printar(area);
            return area;
            break;

        //retangulo
        case 2:
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            area = lado * base;
            printf("Area do retangulo: ");
            printar(area);
            return area;
            break;

        //triangulo
        case 3:
            printf("Digite o valor da altura: \n");
            scanf("%lf", &base);
            printf("Digite o valor da base: \n");
            scanf("%lf", &altura);
            area = (base * altura) / 2;
            printf("Area do triangulo: ");
            printar(area);
            return area;
            break;

        //circulo
        case 4:
            printf("Digite o valor do raio: \n");
            scanf("%lf", &raio);
            area = 3.1415926535 * (pow(raio, 2));
            printf("Area do circulo: ");
            printar(area);
            return area;
            break;

        //losango
        case 5:
            printf("Digite o valor da diagonal Maior: \n");
            scanf("%lf", &base);
            printf("Digite o valor da diagonal Menor: \n");
            scanf("%lf", &altura);
            area = (base * altura) / 2;
            printf("Area do losango: ");
            printar(area);
            return area;
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
            printf("Area do trapezio: ");
            printar(area);
            return area;
            break;

        //! figuras espaciais
        //cubo
        case 7:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            area = base * altura * lado;
            printf("Area do cubo: ");
            printar(area);
            return area;
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
            printf("Area da piramide: ");
            printar(area);
            return area;
            break;

        //cone
        case 9:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            g = sqrt((pow((base / 2), 2)) + (pow(altura, 2)));
            area = ((3.141592 * (base / 2) * ((base / 2) + g)));
            printar(area);
            return area;
            break;

        //cilindro
        case 10:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            //area lateral + area base
            area = ((2 * 3.141592 * altura * (base / 2)) + (2 * 3.141592 * pow(base / 2, 2)));
            printar(area);
            return area;
            break;

        //TODO prisma
        case 11:
            return area;
            break;

        //esfera
        case 12:
            printf("Digite o valor do raio: \n");
            scanf("%lf", &raio);
            area = 4 * 3.1415 * pow(raio, 2);
            printar(area);
            return area;
            break;
        }

    } while (op != 0);
}

//! testar
double volume()
{
    double lado, base, altura, raio, volume, g;
    int op;
    do
    {
        printf("\n[ 1 ] - Cubo\n[ 2 ] - Piramide\n[ 3 ] - Cone\n[ 4 ] - Cilindro\n[ 5 ] - Prisma\n[ 6 ] - Esfera\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            return 0;
            break;

        //cubo
        case 1:
            printf("Digite o valor do lado: \n");
            scanf("%lf", &lado);
            volume = pow(lado, 3);
            printf("Volume do cubo: ");
            printar(volume);
            return volume;
            break;

        //TODO piramide
        case 2:

            return volume;
            break;

        //cone
        case 3:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            volume = (3.141592 * pow((base / 2), 2) * altura) / 3;
            printf("Volume do cone: ");
            printar(volume);
            return volume;
            break;

        //cilindro
        case 4:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            printf("Digite o valor da altura: \n");
            scanf("%lf", &altura);
            volume = (3.141592 * pow((base / 2), 2) * altura);
            printf("Volume do cilindro: ");
            printar(volume);
            return volume;
            break;

        //TODO prisma
        case 5:

            return volume;
            break;

        //esfera
        case 6:
            printf("Digite o valor da base: \n");
            scanf("%lf", &base);
            volume = (4 / 3) * 3.141592 * pow((base / 2), 3);
            printf("Volume da esfera: ");
            printar(volume);
            return volume;
            break;

        default:
            break;
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

    //TODO X vertice Y vertice
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
            printf("\nA velocidade media e de: ");
            printar(velocidadeMed);
            break;

        //TODO distancia
        case 2:

        //TODO tempo
        case 3:

        //m/s -> km/h
        case 4:
            printf("\nA velocidade media e de: ");
            printar(velocidadeMed * 3.6);
            break;

        //km/h -> m/s
        case 5:
            printf("\nA velocidade media e de: ");
            printar(velocidadeMed / 3.6);
            break;

        default:
            break;
        }
    } while (op != 0);
}

//TODO
int conversao()
{
    double a;
    int op;
    do
    {
        printf("O que vc deseja converter?\n");
        printf("[ 0 ] - sair\n[ 1 ] - Temperatura\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            a = temperatura();

        case 2:
            a = tempo();

        case 3:
            a = massa();

        case 4:
            a = comprimento();

        case 5:
            a = pressao();

        case 6:
            a = moeda();
        }
    } while (op != 0);
}

double temperatura()
{
    double temperatura;
    int op;
    do
    {
        printf("[ 0 ] - Sair\n[ 1 ] - Kelvin -> Fahrenheit\n[ 2 ] - Kelvin -> Celsius\n[ 3 ] - Celsius -> Kelvin\n[ 4 ] - Celsius -> Fahrenheit\n[ 5 ] - Fahrenheit -> Kelvin\n[ 6 ] - Fahrenheit -> Celsius\n");
        scanf("%d", &op);
        printf("Digite a temperatura:\n");
        scanf("%lf", &temperatura);

        switch (op)
        {
        case 0:
            break;

        //Kelvin -> Fahrenheit
        case 1:
            temperatura = (((temperatura - 273) / 5) * 9) + 32;
            printf("Temperatura convertida: ");
            printar(temperatura);
            return temperatura;

        //Kelvin -> Celsius
        case 2:
            temperatura = (temperatura - 273);
            printf("Temperatura convertida: ");
            printar(temperatura);
            return temperatura;

        //Celsius -> Kelvin
        case 3:
            temperatura = temperatura + 273;
            printf("Temperatura convertida: ");
            printar(temperatura);
            return temperatura;

        //Celsius -> Fahrenheit
        case 4:
            temperatura = ((temperatura / 5) * 9) + 32;
            printf("Temperatura convertida: ");
            printar(temperatura);
            return temperatura;

        //Fahrenheit -> Kelvin
        case 5:
            temperatura = (((temperatura - 32) / 9) * 5) + 273;
            printf("Temperatura convertida: ");
            printar(temperatura);
            return temperatura;

        //Fahrenheit -> Celsius
        case 6:
            temperatura = ((temperatura - 32) / 9) * 5;
            printf("Temperatura convertida: ");
            printar(temperatura);
            return temperatura;

        default:
            break;
        }
    } while (op != 0);
}

double tempo()
{
    double tempo;
    int op, op2;

    do
    {
        printf("O que vc deseja converter?\n");
        printf("[ 1 ] - anos ->\n[ 2 ] - meses ->\n[ 3 ] - semanas -> \n[ 4 ] - dias ->\n[ 5 ] - horas\n[ 6 ] - minutos\n[ 7 ] - segundos\n[ 8 ] - milisegundos\n[ 9 ] - microsegundos\n[ 10 ] - nanosegundos\n");
        scanf("%d", &op);

        printf("Digite o tempo:\n");
        scanf("%lf", &tempo);

        printf("[ 1 ] -> anos\n[ 2 ] -> meses\n[ 3 ] -> semanas\n[ 4 ] - dias\n[ 5 ] - horas\n[ 6 ] - minutos\n[ 7 ] - segundos\n[ 8 ] - milisegundos\n[ 9 ] - microsegundos\n[ 10 ] - nanosegundos\n");
        scanf("%d", &op2);

        //criar função p n ficar tão grande
        switch (op)
        {
        case 0:
            break;

        //anos
        case 1:
            switch (op2)
            {
            //anos
            case 1:

            //meses
            case 2:

            //semanas
            case 3:

            //dias
            case 4:

            //horas
            case 5:

            //minutos
            case 6:

            //segundos
            case 7:

            //milisegundos
            case 8:

            //microsegundos
            case 9:

            //microsegundos
            case 10:

            default:
                break;
            }
        }

    //meses
    case 2:

    //semanas
    case 3:

    //dias
    case 4:

    //horas
    case 5:

    //minutos
    case 6:

    //segundos
    case 7:

    //milisegundos
    case 8:

    //microsegundos
    case 9:

    //microsegundos
    case 10:

    default:
        break;
    }

    while (op != 0);
}

double pressao()
{
    //não seiu oq fazer
}

int main()
{
    int op;
    double a;

    printf("\n[ 1 ] - juros simples\n[ 2 ] - juros compostos\n[ 3 ] - unidades de medida\n[ 4 ] - area\n[ 5 ] - volume\n[ 6 ] - expressao 2 grau\n[ 7 ] - fatorial\n");
    printf("[ 8 ] - velocidade\n[ 9 ] - conversoes");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        a = juros_simples();

    case 2:
        a = juros_compostos();

    case 4:
        a = area();

    case 5:
        a = volume();

    case 6:
        expressao();

    case 7:
        fatorial();

    case 8:
        velocidade();

    case 9:
        conversao();
        //http://conversordemedidas.info

    default:
        break;
    }
}