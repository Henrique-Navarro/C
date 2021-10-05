#include <stdio.h>
#include <stdlib.h>

struct endereco{
    char nome[100];
    char rua[100];
    int numero;
}end1;

int main(){

    fgets(end1.nome, sizeof(end1.nome), stdin);
    strtok(end1.nome, "\n");
    fgets(end1.rua, sizeof(end1.rua), stdin);
    strtok(end1.rua, "\n");
    scanf("%d%*c", &end1.numero);

    struct endereco *endpoint;
    endpoint = &end1;

    printf("\n%s", endpoint->nome);
    printf("\n%s", endpoint->rua);
    printf("\n%d", endpoint->numero);
}