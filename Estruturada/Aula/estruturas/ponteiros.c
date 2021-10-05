#include <stdio.h>
#include <string.h>

struct endereco{
    char nome[100];
    char rua[100];
    int numero;
}end1,end2;

int main(){
    struct endereco *end;
    end= malloc(sizeof(struct endereco));

    fgets(end->nome, sizeof(end->nome),stdin);
    fgets(end-> rua, sizeof(end->rua), stdin);
    scanf("%d%*c", &end->numero);

    printf("\n%s", end->nome);
    printf("\n%s", end->rua);
    printf("\n%d", end->numero);
}