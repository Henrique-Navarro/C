/*Escreva um programa que declare uma matriz 10x10 de inteiros. Você criar uma função void (procedimento)
para inicializar a matriz com zeros usando um ponteiro para a matriz. Faça outra função void para preencher
depois a matriz com os números de 99 a 0, também usando ponteiro para matriz como parâmetro. Por fim, o programa
deve imprimir a matriz.*/

#include <stdio.h>
#include <stdlib.h>

void inicializar(int *p);
void preencher(int *p);
void imprimir(int *p);

int main(){
    int matriz[10][10];
    inicializar(matriz);
    preencher(matriz);
    imprimir(matriz);
}

void inicializar(int *p){
    int i,j;
    for (i=0; i<10; i++){
        for(j=0; j<10; j++){
            *p=0;
            p++;
        }
    }
}

void preencher(int *p){
    int i;
    for(i=0; i<100; i++){
        *p= 99-i;
        p++;
    }
}

void imprimir(int *p){
    int i,j;
    for(i=0; i<10; i++){
        printf("\n");
        for(j=0; j<10; j++){
            printf("%d ", *p);
            p++;
        }
    }
}