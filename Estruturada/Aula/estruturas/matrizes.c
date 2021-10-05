#include <stdio.h>
#include <string.h>

struct endereco{
    char nome[100];
    char rua[100];
    int numero;
}ends,end2;

int main(){
    struct endereco ends[3];
    int i;

    for(i=0;i<3;i++){
        fgets(ends[i].nome, sizeof(ends[i].nome), stdin);
        strtok(ends[i].nome, "\n");
        fgets(ends[i].rua, sizeof(ends[i].rua), stdin);
        strtok(ends[i].rua, "\n");
        scanf("%d%*c", &ends[i].numero);
    }

    for(i=0;i<3;i++){
        printf("\nRegistro #%d", i);
        printf("\n%s", ends[i].nome);
        printf("\n%s", ends[i].rua);
        printf("\n%d", ends[i].numero);
    }
}