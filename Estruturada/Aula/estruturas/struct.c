#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void mostraestrutura(struct pessoa p);

int main(){
    struct pessoa p;

    fgets(p.nome, sizeof(p.nome), stdin);
    strtok(p.nome, "\n");

    scanf("%d%*c", &p.idade);

    fgets(p.end.rua,sizeof(p.end.rua),stdin);
    strtok(p.end.rua, "\n");

    fgets(p.end.cep, sizeof(p.end.cep), stdin);
    strtok(p.end.cep, "\n");

    scanf("%d%*c", &p.end.numero);

    mostraestrutura(p);
}

void mostraestrutura(struct pessoa p){
    printf("Nome: %s", p.nome);
    printf("\nIdade: %d", p.idade);
    printf("\nRua: %s", p.end.rua);
    printf("\nCep: %s", p.end.cep);
    printf("\nNumero: %d", p.end.numero);
}