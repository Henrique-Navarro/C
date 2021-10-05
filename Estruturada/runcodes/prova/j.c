#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cont{
    char nome[100];
    char endereco[200];
    int idade;
}Contato; 

void exibeContatos(FILE *fp);
void insertContato(Contato cont, FILE *fp);

int main(){
FILE *fp; 
int j,op=1;
Contato cont;

fp=fopen("dados.dat","rb+");
if (fp == NULL)
  {
    fp = fopen("dados.dat", "wb+");
    if(fp==NULL){
     printf("Problemas na abertura do arquivo\n");
     return 1;}
  }


while (op==1)
{
    printf("\n1-) Cadastrar novo contato ao final do arquivo\n");
    printf("2-) Exibir todos os contatos\n");
    printf("3-) Sair\n");

    scanf("%d",&j) ;
    fflush(stdin);

switch(j)
{
case 1:

    insertContato(cont, fp);
    
    j=0;
    
    break;

case 2: 

     exibeContatos(fp);
     j=0;
    
  break;

  case 3: 
  op=0;
  
printf("Voce encerrou o programa, obrigado");
return 1;

  
default: 
printf("Ops, voce digitou uma opcao invalida, tente novamente");
    break;
}
}
 fclose(fp);
return 0;

}
void insertContato(Contato cont, FILE *fp){
    printf("Digite o nome da pessoa: \n");
    fgets(cont.nome, sizeof(cont.nome), stdin);

    printf("Digite o endereco: \n");
    fgets(cont.endereco, sizeof(cont.endereco), stdin);
  
    printf("Digite a idade: \n");
    scanf("%d%*c\n", &cont.idade);

    fseek(fp, 0 , SEEK_END);
    fwrite(&cont, sizeof(Contato), 1, fp);
}

void exibeContatos(FILE *fp){
 Contato cont;
    fseek(fp,0,SEEK_SET);

do
{
    printf("%s", cont.nome);
    printf("%s", cont.endereco);
    printf("%d\n", cont.idade);
} while ((fread(&cont, sizeof(cont),1, fp)));
    
}