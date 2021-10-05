#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *p_text;
    int qntV=0;
    char b='z';

    p_text = fopen("texto.txt", "r");

    if (p_text == NULL){
        printf("Erro ao abrir o arquivo escolhido.");
        return 0;
    }
    
    do{
        b = getc(p_text);
        if(b=='a'||b=='A'||b=='e'||b=='E'||b=='i'||b=='I'||b=='o'||b=='O'||b=='u'||b=='U'){
            qntV++;
        }
    }while(b !=EOF);

    printf("A quantidade de vogais no arquivo de texto: %d",qntV);
    fclose(p_text);
    return 0;
}