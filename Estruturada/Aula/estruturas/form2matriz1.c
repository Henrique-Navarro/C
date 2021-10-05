#include <stdio.h>
#include <stdlib.h>

struct matriz{
    int tamL;
    int tamC;
    int itens[1000][1000];
}*m;

int main(){
    m->itens[2][2]=10;
    printf("%d", m->itens[2][2]);
}