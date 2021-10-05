#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct raizes{
    double x1;
    double x2;
};

int main(){
    struct raizes r1={1.0, 2.0};
    struct raizes r2={1.0, 2.0};
    struct raizes *ptr1, *ptr2;
    ptr1= &r1;
    ptr2= &r2;

    if(ptr1 == ptr2){ 
        printf("sim");
    }
    else{ 
        printf("nao");
    }
    return 0;
}