#include <stdio.h>
#include<stdlib.h>
 
int contvog(int a, char b);
 
int main() {
    int a=0;
    FILE *p_text;
    char b;
 
    p_text= fopen("texto.txt", "r");
 
    if(p_text == NULL){
        printf("erro");
        return 1;
    }
    else{
        do {
            b=getc(p_text);
            a=contvog(a,b);
        }
 
        while(b != EOF);
    }
 
    printf("O arquivo de texto possui: %d vogais", a);
    fclose(p_text);
}
 
int contvog(int a, char b){
    if(b == 'a' ||b == 'e'||b == 'i'||b == 'o'||b == 'u'||b == 'A'||b == 'E'||b == 'I'||b == 'O'||b == 'U'){
        a++;
    }
    return a;
}
 
 

