#include <stdio.h>
#include <stdlib.h>

double getDistancia(struct Point a, struct Point b);

TAM= 10;

struct coordenada {
    int a[][], b[][];
}coord;

int main(){
    int linhas,j,i;
    scanf("%d", &linhas);

    for(i=0; i<linhas; i++){
        for(j=0; i<2; j++){
            scanf("%d", &coord.a[i][j]);
        }
    }
    for(i=0; i<linhas; i++){
        for(j=0; j<2; j++){
            scanf("%d", &coord.b[i][j]);
        }
    }


    getDistancia(coord.a, coord.b);    
}

double getDistancia(struct Point a, struct Point b){
    printf("distancia")
}
