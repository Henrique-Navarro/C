/*Faça um programa para calcular a área e o perímetro de um hexágono. O programa deve implementar uma função
chamada calc_hexa que calcula a área e o perímetro de um hexágono regular de lado L. O program deve solicitar
ao usuário o lado do polígono, calcular e imprimir a área e o perímetro do polígono. O programa termina quando
for digitado um valor negativo qualquer para o lado. A função deve obedecer o seguinte protótipo:

void calc_hexa(float l, floar *area, float *perimetro);

Lembrando que a área e o perímetro de um hexágono regular são dados por:
area=3 x L^2 x raiz(3) / 2
perimetro= L x 6*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_hex(float lado, float *area, float *perimetro);
void imprime_hex(float lado, float *area, float *perimetro);

int main(){
    float l, *a, *p;
    scanf("%f", &l);
    if(l<0){
        return 0;
    }
    calc_hex(l, &a, &p);
    imprime_hex(l, &a, &p);
}

void calc_hex(float lado, float *area, float *perimetro){
    *area= (3* (pow(lado,2)) * (sqrt(3)) )/2;
    *perimetro= 6* lado;
}

void imprime_hex(float lado, float *area, float *perimetro){
    printf("Um hexagono regular com lado= %.2f\npossui area= %.2f\nperimetro= %.2f", lado, *area, *perimetro);
}