#include <stdio.h>
#include <stdlib.h>

int main(){
    int op,x,tx;
    int tempo;
    float capital, taxa;
    printf("[1] simples\n[2] composto\n");
    scanf("%d", op);

    switch(op){
        case 1:
            printf("Oq vc quer descobrir?\n[1] Juros\n[2] Capital\n[3] Taxa\n[4] Tempo\n");
            scanf("%d", &x);
            switch(x){
                case 1:
                    printf("Primeiro informe o capital: ");
                    scanf("%f", &capital);
                    printf("Agora informe a taxa: ");
                    scanf("%f", &taxa);
                    printf("A taxa está em:\n[1] anos\n[2] meses\n");
                    scanf("%d", &tx);
                    if ()
                    printf("Por fim informe o tempo: ");
                    scanf("%d", &tempo);
                case 2:
                case 3:
                case 4:
            }
        case 2:

    }
}