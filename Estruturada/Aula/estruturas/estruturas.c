#include <stdio.h>
#include <string.h>

struct endereco{
    char nome[100];
    char rua[100];
    int numero;
}end1,end2;

int main(){
    fgets(end1.nome, sizeof(end1.nome), stdin);
    strtok(end1.nome, "\n");
    fgets(end1.rua, sizeof(end1.rua), stdin);
    strtok(end1.rua, "\n");
    scanf("%d%*c", &end1.numero);

    printf("\n%s", end1.nome);
    printf("\n%s", end1.rua);
    printf("\n%d", end1.numero);

    end2=end1;
    printf("\nMostrando end2");
    printf("\n%s", end1.nome);
    printf("\n%s", end1.rua);
    printf("\n%d", end1.numero);
}