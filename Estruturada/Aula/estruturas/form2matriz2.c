#include <stdio.h>
#include <stdlib.h>

struct endereco{
    char rua[100];
    char cep[9];
    int numero;
};

struct pessoa{
    char nome[100];
    int idade;
    struct endereco end;
};

void mostraEstrutura(struct pessoa *p);

int main(){
    struct pessoa *p;
    fgets(p->nome, sizeof(p->nome), stdin);
    strtok(p->nome, "\n");

    scanf("%d%*c", &p->idade);

    fgets(p->end.rua, sizeof(p->end.rua), stdin);
    strtok(p->end.rua, "\n");

    fgets(p->end.cep, sizeof(p->end.cep), stdin);
    strtok(p->end.cep, "\n");

    scanf("%d%*c", &p->end.numero);

    mostraEstrutura(p);

    return 0;
}

void mostraEstrutura(struct pessoa *p){
        printf("\nNome: %s", p->nome);
        printf("\nIdade: %d", p->idade);
        printf("\nRua: %s", p->end.rua);
        printf("\nNum: %d", p->end.numero);
        printf("\nCEP: %s", p->end.cep);
}