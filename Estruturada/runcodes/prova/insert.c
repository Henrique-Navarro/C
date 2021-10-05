#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cont{
    char nome[100];
    char endereco[200];
    int idade;
}Contato;

int main(){
    Contato pessoa;
    FILE *fp;
    fp = fopen("dados.dat", "a");

    printf("Digite o nome a ser cadastrado: \n");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

    printf("Digite o endereco a ser cadastrado: \n");
    fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);

    printf("Digite a idade a ser cadastrada: \n");
    scanf("%d%*c", &pessoa.idade);

    fprintf(fp, "%s", pessoa.nome);
    fprintf(fp, "%s", pessoa.endereco);
    fprintf(fp, "%d\n", pessoa.idade);

    fclose(fp);
}