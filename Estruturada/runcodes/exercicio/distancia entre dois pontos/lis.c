#include <stdio.h>
#include <stdlib.h>

struct endereco{
    char nome[100];
    char rua[200];
    int numero;
};

int main(){
    struct endereco ends[3];
    strcpy(ends[0].nome, "THIAGO");
    strcpy(ends[0].rua, "TESTE1");
    ends[0].numero= 123;

    strcpy(ends[1].nome, "JOAO");
    strcpy(ends[1].rua, "TESTE2");
    ends[1].numero=321;

    ends[1] = ends[0];
    printf("%d", ends[1].numero);
    return 0;
}