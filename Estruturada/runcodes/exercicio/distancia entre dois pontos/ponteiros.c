#include <stdio.h>
#include <stdlib.h>

struct endereco{
    char nome[100];
    char rua[200];
    int numero;
};

void valorInt(struct endereco *end){
    end->numero=15;
}

int main(){ 
    struct endereco end1;
    strcpy(end1.nome, "THIAGO");
    strcpy(end1.rua, "TESTE1");
    end1.numero=1;

    valorInt(&end1);

    printf("%d", end1.numero);
    return 0;
}