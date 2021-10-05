#include <stdio.h>
#include <stdlib.h>

int contvogal(char palavra[]);

int main(){
    int a;
    char palavra[100];
    gets(palavra);

    a=contvogal(palavra);
    printf("%d", a);
}

int contvogal(char palavra[]){
    char vogal[]= "aeiouAEIOU";
    int cont=0, i,j;

    for(i=0; palavra[i] != '\0'; i++){
        for(j=0; vogal[j] != '\0'; j++){
            if(vogal[j] == palavra[i]){
                cont++;
                break;
            }
        }
    }
    return cont;
}