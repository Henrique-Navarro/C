#include <stdio.h>
#include <stdlib.h>

union numero{
    int x;
    float y;
}valor;

struct str_numero{
    int x;
    float y;
};

int main(){
    valor.x=100;
    valor.y=3.5;

    printf("\n%d", valor.x);
    printf("\n%f", valor.y);
    printf("\n\n");

    valor.x=100;
    printf("\n%d", valor.x);
    valor.y=3.5;
    printf("\n%f", valor.y);
    printf("\n\n");

    printf("\n%lu", sizeof(int));
    printf("\n%lu", sizeof(float));
    printf("\n%lu", sizeof(union numero));
    printf("\n%lu", sizeof(struct str_numero));
}