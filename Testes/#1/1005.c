#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x,y,z,m;
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    x=x*2;
    y=y*3;
    z=z*5;
    m= (x+y+z)/10;
    printf("MEDIA = %.1f\n", m);
    return 0;
}