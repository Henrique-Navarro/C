#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct raizes{
    double x1;
    double x2;
};

int main(){
    struct raizes *ptr, r1= {3.0, 2.0};
    ptr = &r1;
    ptr->x1= 20.0;
    printf("%.2lf %.2lf", r1.x1, r1.x2);
    return 0;
}