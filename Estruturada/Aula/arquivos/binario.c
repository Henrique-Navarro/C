#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct p{
    char nome[92];
    int altura;
    int idade;
}Pessoa;

int main(){
    FILE *fp;
    Pessoa pessoa;

    fp= open("pessoas.dat", "wb+");
    if(fp == NULL){
        printf("erro");
        return 1;
    }

    strcpy(pessoa.nome, "Joao");
    pessoa.altura= 172;
    pessoa.idade= 30;
    fwrite(&pessoa, sizeof(pessoa),1,fp);
    fflush(fp);
    
    strcpy(pessoa.nome, "Maria");
    pessoa.altura= 165;
    pessoa.idade= 25;
    fwrite(&pessoa, sizeof(pessoa),1,fp);
    fflush(fp);

    strcpy(pessoa.nome, "Julia");
    pessoa.altura= 167;
    pessoa.idade= 38;
    fwrite(&pessoa, sizeof(pessoa),1,fp);
    fflush(fp);

    rewind(fp);
    //ponteiro volta para o inicio do arquivo
    //vai sobre escrever os dados do joao

    strcpy(pessoa.nome, "Jose");
    pessoa.altura= 180;
    pessoa.idade= 22;
    fwrite(&pessoa, sizeof(pessoa),1,fp);
    fflush(fp);

    //vai para o final do programa
    //0 -> numero de bites do final pra trás
    fseek(fp,0, SEEK_END);
              //SEEK_SET coloca no começo
              //SEEK_CUR adiciona de onde está
              //SEEK_END coloca no final

    strcpy(pessoa.nome, "Douglas");
    pessoa.altura= 180;
    pessoa.idade= 40;
    fwrite(&pessoa, sizeof(pessoa),1,fp);
    fflush(fp);

    //a partir do final, o ponteiro vai andar -2*100 bites (200 bites pra trás)
    fseek(fp, (-2* sizeof(Pessoa)), SEEK_END);

    //vai sobre escrever a Julia
    strcpy(pessoa.nome, "Amanda");
    pessoa.altura= 170;
    pessoa.idade= 28;
    fwrite(&pessoa, sizeof(pessoa),1,fp);
    fflush(fp);

    //ponteiro voltando para o inicio
    rewind(fp);

    while(fread(&pessoa, sizeof(Pessoa), 1, fp)){
        printf("Nome: %s\n", pessoa.nome);
        printf("Altura: %d\n", pessoa.altura);
        printf("Idade: %d\n", pessoa.idade);
        printf("\n");
    }

    fclose(fp);
    return 0;
}