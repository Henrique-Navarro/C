#include <stdio.h>
#include <stdlib.h>

struct endereco{
    char nome[100];
    char rua[200];
    int numero;
};

int main(){
    int a;
    struct endereco end1;
    strcpy(end1.nome, "THIAGO");
    strcpy(end1.rua, "TESTE1");
    end1.numero= 1;

    a=valorInt(end1);
    printf("%d", a);
    return 0;
}

int valorInt(struct endereco end){
    end.numero= 15;
    return end.numero;
}