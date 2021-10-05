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
    FILE *out;
    out= fopen("dados.dat", "r");


    while(!feof(out)){
        fgets(pessoa.nome, 100, out);
        printf("%s", pessoa.nome);

        fgets(pessoa.endereco, 100, out);
        printf("%s", pessoa.endereco);

        pessoa.idade= fgetc(out);
        printf("%c", pessoa.idade);
        
        memset(&pessoa.nome, 0, sizeof(pessoa.nome));
        memset(&pessoa.endereco, 0, sizeof(pessoa.endereco));
    }
    fclose(out);
}