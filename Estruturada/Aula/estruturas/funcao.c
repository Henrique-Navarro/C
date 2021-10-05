#include <stdio.h>
#include <string.h>

struct endereco{
    char nome[100];
    char rua[100];
    int numero;
}end1,end2;

void mostraCampoStringEstrutura(char *texto){
    printf("\n%s", texto);
}

void mostraCampoIntEstrutura(int num){
    printf("\n%d", num);
}

void mostraEstruturaInteira(struct endereco end){
    printf("\n%s", end.nome);
    printf("\n%s", end.rua);
    printf("\n%d", end.numero);
}

int main(){
    struct endereco end1;

    fgets(end1.nome, sizeof(end1.nome), stdin);
    strtok(end1.nome, "\n");
    fgets(end1.rua, sizeof(end1.rua), stdin);
    strtok(end1.rua, "\n");
    scanf("%d%*c", &end1.numero);

    mostraCampoStringEstrutura(end1.nome);
    mostraCampoIntEstrutura(end1.numero);
    mostraEstruturaInteira(end1);

}