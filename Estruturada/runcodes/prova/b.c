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
    int op=1,j;

    FILE *in = fopen("dados.dat", "a");
    FILE *out = fopen("dados.dat", "a");

    if(in == NULL|| out == NULL){
        printf("Erro ao abrir");
        return 1;
    }

    while (op==1)
    {
        printf("\n1-) Cadastrar novo contato\n2-) Exibir todos os contatos\n3-) Sair\n"); 
        scanf("%d",&j) ;

        switch(j)
        {
            printf("%d", j);
                case 1:
                    printf("Digite o nome a ser cadastrado: \n");
                    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

                    printf("Digite o endereco a ser cadastrado: \n");
                    fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);

                    printf("Digite a idade a ser cadastrada: \n");
                    scanf("%d%*c", &pessoa.idade);

                    insertContato(pessoa, in);

                case 2:
                    exibeContato(pessoa, in);
                    break;

                case 3:
                    return 1;

                default:
                    printf("Opcao invalida \n");
                    break;
        }
    }
}

void insertContato(Contato contato, FILE *fp){

    fprintf(fp, "%s\n", contato.nome);
    fprintf(fp, "%s\n", contato.endereco);
    fprintf(fp, "%c\n", contato.idade);
}

void exibeContato(Contato contato, FILE *fp){

    fscanf(fp, "%s", contato.nome);
    printf("%s", contato.nome);

    fscanf(fp, "%s", contato.endereco);
    printf("%s", contato.endereco);

    fscanf(fp, "%d", contato.idade);
    printf("%d", contato.idade);
}