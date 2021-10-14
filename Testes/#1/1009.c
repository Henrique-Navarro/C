#include <stdio.h>
 
int main() {
    char nome;
    float sal,venda,total,por;
    scanf("%s", &nome);
    scanf("%f", &sal);
    scanf("%f", &venda);
    por=(venda*15)/100;
    total= (sal+ por);
    printf("TOTAL = R$ %.2f\n", total);
    return 0;
}