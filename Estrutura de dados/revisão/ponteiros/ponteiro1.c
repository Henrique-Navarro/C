/*Faça um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max. 100 caracteres)
e armazeá-la num vetor. Imprimir a frase lida trocando as vogais, isto é, trocar 'a' pelo 'u', 'e' pelo 'o',
'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'.
a-u  e-o  i-u  o-a  u-e
Usar uma função void (procedimento) para realizar a troca e uma
função para realizar a impressão da frase trocada. A função deve ter como parâmetro um ponteiro char referente
ao vetor. Dica: Use a função gets() da biblioteca string.h para realizar a leitura da frase. use o switch para
realizar as trocas. Só considere as letras minúsculas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char *frase);
void imprime(char *frase);

int main(){
    char frase[100];
    gets(frase);
    
    troca(frase);
    imprime(frase);
}

void troca(char *frase){
    int i;
    for(i=0; i<(strlen(frase)); i++){
        switch(*frase){
            case 'a':
                *frase= 'u';
                break;
            case 'e':
                *frase= 'o';
                break;
            case 'i':
                *frase= 'u';
                break;
            case 'o':
                *frase= 'a';
                break;
            case 'u':
                *frase= 'e';
                break;
        }
        frase++;
    }
}

void imprime(char *frase){
    int i;
    char *cont;
    cont = frase;
    for(i=0; i<strlen(frase); i++){
        printf("%c", *cont);
        cont++;
    }
}