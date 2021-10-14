#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,h;
    float sal,p;
    scanf("%d",&n);
    scanf("%d",&h);
    scanf("%f",&p);
    sal= h*p;
    printf("NUMBER = %d\n",n);
    printf("SALARY = U$ %.2f\n", sal);
    return 0;
}