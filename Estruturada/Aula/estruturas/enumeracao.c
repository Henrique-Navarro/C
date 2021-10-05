#include <stdio.h>

enum opcao{soma=1, subtracao=2, divisao=3, multiplicacao=4
}op;

int main(){
    int n1,n2,res;
    scanf("%u", &op);
    scanf("%d", &n1);
    scanf("%d", &n2);

    switch(op){
        case soma:
        res= n1+n2;
        break;

        case subtracao:
        res= n1-n2;
        break;

        case divisao:
        if(n2 !=0)
            res= n1/n2;
            break;

        case multiplicacao:
            res= n1*n2;
            break;

        default:
            printf("erro");
    }
    printf("%d", res);
}