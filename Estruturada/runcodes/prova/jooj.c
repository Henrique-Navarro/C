#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cont{
    char nome[100];
    char endereco[200];
    int idade;
}Contato; 

void exibeContatos(FILE *fp, Contato cont);
void insertContato(Contato cont, FILE *fp);
int main(){
FILE *fp; 
int op,aux=1;
Contato cont;
fp=fopen("dados.dat","a");
if (fp == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return 1;
  }

printf("\n1-) Cadastrar novo contato ao final do arquivo\n");
printf("2-) Exibir todos os contatos\n");
printf("3-) Sair\n");

while (aux==1)
{
   scanf("%d",&op) ;

    switch(op)
{
case 1:

    printf("Digite o nome da pessoa: \n");
    fgets(cont.nome, sizeof(cont.nome), stdin);
    strtok(cont.endereco, " ");
    

    strtok(cont.endereco, "\n");
    printf("Digite o endereco: \n");
    fgets(cont.endereco, sizeof(cont.endereco), stdin);
    strtok(cont.endereco, "\n");

    printf("Digite a idade: \n");
    scanf("%d%*c", &cont.idade);

    fprintf(fp, "%s\n", cont.nome);
    fprintf(fp, "%s\n", cont.endereco);
    fprintf(fp, "%d\n", cont.idade);

    fwrite(&cont, sizeof(Contato), 1, fp);

    insertContato(cont, fp);
    
    break;

case 2: 

     exibeContatos(fp, cont);
    
  
  break;

  case 3: 
  aux=0;
  
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
    fprintf(fp,"%s\n",cont.nome);
    fprintf(fp,"%s\n",cont.endereco);
    fprintf(fp,"%d",cont.idade);
}
void exibeContatos(FILE *fp, Contato cont){
    fp=fopen("dados.dat","r");

    while(fp == NULL){ 
        fscanf(fp, "%s", cont.nome);
        printf("%s\n", cont.nome);

        fscanf(fp, "%s", cont.endereco);
        printf("%s\n", cont.endereco);

        fscanf(fp, "%d", cont.idade);
        printf("%d\n", cont.idade);
        fflush(stdin);    
    } 
}