#include <stdio.h>

enum opcao{soma=1, subtracao=2, divisao=3, multiplicacao=4};

int main(){
    enum opcao op;
    op= soma;
    printf("%s", op);
    return 0;
}