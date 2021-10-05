/*Faça um programa para calcular o valor das parcelas de um financiamento no regime de juros compostos
com capitalização mensal. O programa deverá ler o valor do financiamento e o número de parcelas, calcular
e exibir o valor da parcela. O programa termina quando o valor do financiamento for igual a zero. 
Abaixo apresentamos a tabela contendo os prazos de financiamentos e a taxa de juros anual:
PRAZO	TAXA A.A.
6	    7%
12	    10%
18	    12%
24	    15%
36	    18%
Fazer uma função denominada float financiamento() que deverá receber o valor do financiamento e o número de parcelas, 
calcular e retornar o valor da prestação. Utilizar a estrutura </>switch ... case apar selecionar a taxa de juros
representada em valor decimal. 
Como a capitalização é mensal, dividir a taxa por 12. A fórmula de cálcula da prestação é:
prestação= valor financiamento * (1+taxa)^p * taxa      p= num parcelas
                                 (1+taxa)^p -1*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float financiamento(int finan, int numparcelas);

int main(){
    int finan, numparcelas;

    scanf("%d %d", &finan, &numparcelas);
    printf("A parcela vale: %f", financiamento(finan, numparcelas));

}

float financiamento(int finan, int numparcelas){
    float parcela,taxa;
    switch(numparcelas){
        case 6:
            taxa=0.07/12;
        case 12:
            taxa=0.1/12;
        case 18:
            taxa=0.12/12;
        case 24:
            taxa=0.15/12;
        case 36:
            taxa=0.18/12;
    }
    parcela= finan* ( (pow((1+taxa),numparcelas)*taxa) / (pow((1+taxa),numparcelas)-1) );
    return parcela;
}