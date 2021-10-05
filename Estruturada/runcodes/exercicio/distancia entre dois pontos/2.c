#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos {
    int l,c;
   
};
struct reta {
    float **retas;
};

float **alocaMatriz(int l, int c);
void recebeMatriz(float **retas,int l,int c);
void maiorReta(float **retas,int l);
float caldistancia( int x1, int x2, int y1, int y2);

int main(){
    struct pontos end1;
    struct reta end2;
    end1.c= 4;
    scanf("%d",&end1.l);
    end2.retas = alocaMatriz(end1.l,end1.c);
    recebeMatriz(end2.retas,end1.l,end1.c);
    maiorReta(end2.retas,end1.l );

return 0;
}
float **alocaMatriz(int l, int c){
    int i;
    float **m;

    m=(float *) malloc(sizeof(float) * l);

    for(i=0; i<l; i++){
        m[i] = (float*) malloc(sizeof(float) * c);
    }

    return m;
}

void recebeMatriz(float **retas,int l,int c){
    int i,j;

    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            scanf("%f", &retas[i][j]);
        }
    }
}

void maiorReta(float **retas,int l){
    int i,x1,x2,y1,y2,rn;
    double d, comparador = -1;
    for( i = 0; i<l; i++){
    x1 = retas[i][0];
    y1 = retas[i][1];
    x2 = retas[i][2];
    y2 = retas[i][3];
    d= caldistancia(x1,x2,y1,y2);
    if (d>comparador)
    {
        comparador = d;
        rn = i;
    }
    }
    printf("Reta numero %d, pontos [%.0lf,%.0lf] e [%.0lf,%.0lf], tamanho %.2f.",rn,retas[rn][0],retas[rn][1],retas[rn][2],retas[rn][3],comparador);
}

float caldistancia( int x1, int x2, int y1, int y2){
    float result;
    result = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
    return result;
}