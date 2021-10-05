#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct coordenada{
    int x;
    int y;
};

double getDistancia(struct coordenada a, struct coordenada b);

int main(){
    int i,vezes;
    scanf("%d", &vezes);
    double r;

    struct coordenada a;
    struct coordenada b;

    for(i=0; i<4; i++){ 
        for(i=0; i<vezes; i++){ 
            scanf("%d", &a.x);
            scanf("%d", &a.y);

            scanf("%d", &b.x);
            scanf("%d", &b.y);

            r= getDistancia(a, b);
            printf("%.2lf\n", r);
        }
    }
}

double getDistancia(struct coordenada a,struct coordenada b){
    double d;
    d=sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2));
    return d;
}
