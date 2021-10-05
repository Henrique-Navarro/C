#include <stdio.h>
#include <stdlib.h>
int mdc(int x, int y);
int main(){
    int x,y,resultado;
    scanf("%d", &x);
    scanf("%d", &y);
    
    resultado=mdc(x,y);
    printf("%d", resultado);
}

int mdc(int x, int y){
    int resto;
    while(resto != 0){
        resto= x%y;
        x=y;
        y= resto;
    }
    return x;
}