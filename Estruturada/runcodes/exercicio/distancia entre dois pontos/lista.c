#include <stdio.h>
#include <stdlib.h>

struct student{
    int isNum;
    char name;
    float gpa;
};

int main(){
    struct student joao;
    printf("\n%f", joao.gpa);
    joao.gpa = 6.5;
    printf("\n%f", joao.gpa);
    printf("\n%d", sizeof(joao));
    printf("\n%d", sizeof(joao.isNum));
    printf("\n%d", sizeof(joao.name));
    printf("\n%d", sizeof(joao.gpa));
}