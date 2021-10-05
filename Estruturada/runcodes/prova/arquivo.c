#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cont{
    char nome[100];
    char endereco[200];
    int idade;
}Contato; 

void exibeContato(Contato contato, FILE *fp);
void insertContato(Contato contato, FILE *fp);

int main(){
    Contato pessoa;
    pessoa.idade=0;
    int op;

    FILE *in = fopen("dados.dat", "a");
    FILE *out = fopen("dados.dat", "a");

    if(in == NULL|| out == NULL){
        printf("Erro ao abrir");
        return 1;
    }

    
        printf("1-) Cadastrar novo contato\n2-) Exibir todos os contatos\n3-) Sair\n"); 
        scanf("%d", &op);

            switch (op){
                case 1:
                    insertContato(pessoa, in);
                    break;

                case 2:
                    exibeContato(pessoa, in);
                    break;

                case 3:
                    break;

                default:
                    printf("Opcao invalida \n");
                    break;
            }
    }

void insertContato(Contato contato, FILE *fp){

    printf("Digite o nome a ser cadastrado: \n");
    gets(contato.nome);
    fprintf(fp, "%s\n", contato.nome);

    printf("Digite o endereco a ser cadastrado: \n");
    gets(contato.endereco);
    fprintf(fp, "%s\n", contato.endereco);

    printf("Digite a idade a ser cadastrada: \n");
    scanf("%d", &contato.idade);
    fprintf(fp, "%d\n", contato.idade);
}

void exibeContato(Contato contato, FILE *fp){
    printf("\n a \n a\n");

    fscanf(fp, "%s", contato.nome);
    printf("%s", contato.nome);

    fscanf(fp, "%s", contato.endereco);
    printf("%s", contato.endereco);

    fscanf(fp, "%d", contato.idade);
    printf("%d", contato.idade);
}