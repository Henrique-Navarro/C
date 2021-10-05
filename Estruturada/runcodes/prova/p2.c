#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cont{
    char nome[100];
    char endereco[200];
    int idade;
}Contato;

void exibeContatos(FILE *fp);
void insertContato(Contato contato, FILE *fp);

int main(){
    int op,aux=1;
    Contato pessoa;
    FILE *in;

    in = fopen("dados.dat", "rb+");

    if(in == NULL){
        in = fopen("dados.dat", "wb+");
        if(in == NULL){
            printf("Erro");
            return 1;
        }
    }

    if(in == NULL){
        printf("Erro");
        return 1;
    }

    while(aux == 1){ 
        printf("\n1-) Cadastrar novo contato\n2-) Exibir todos os contatos\n3-) Sair\n");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
            case 1:
                insertContato(pessoa, in);
                op=0;
                break;

            case 2:
                exibeContatos(in);
                op=0;
                break;

            case 3:
                aux=0;
                return 1;

            default:
                printf("Opcao invalida, tente novamante:\n");
                break;
        }
    }
    fclose(in);

    return 0;
}

void insertContato(Contato contato, FILE *fp){
    printf("Digite o nome a ser cadastrado: \n");
    fgets(contato.nome, sizeof(contato.nome), stdin);
    
    printf("Digite o endereco a ser cadastrado: \n");
    fgets(contato.endereco, sizeof(contato.endereco), stdin);

    printf("Digite a idade a ser cadastrada: \n");
    scanf("%d%*c", &contato.idade); 

    fseek(fp, 0 , SEEK_END);
    fwrite(&contato,sizeof(contato),1,fp);

}

void exibeContatos(FILE *fp){
    Contato contato;
    fseek(fp,0,SEEK_SET);

    while((fread(&contato, sizeof(contato),1, fp))){
        printf("%s", contato.nome);
        printf("%s", contato.endereco);
        printf("%d\n", contato.idade);
    }
    
}