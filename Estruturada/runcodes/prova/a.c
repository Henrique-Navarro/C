#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    int x;
    int y;
}ponto;

typedef struct retangulo {
    ponto superiorEsquerdo;
    ponto inferiorDireito;
}retangulo;

double area(retangulo r);
float **alocaPonto(int n,int k);

int main(){
    retangulo r;
    int n,i,j,k=4; 
    float **retan;
    double result;


    scanf("%d",&n); 
    retan= alocaPonto(n,k);

    for(i=0; i<n; i++){
        for(j=0; i<k; j++){
        scanf("%f",&retan[i][j]);
   
        }
        }
        for(i=0; i < n; i++){
            r.superiorEsquerdo.x=retan[i][0];
            r.superiorEsquerdo.y= retan[i][1];
            r.inferiorDireito.x= retan[i][2];
            r.inferiorDireito.y= retan[i][3]; 
            result = area(r);
            printf("%.0lf\n", result);
        }

    return 0;
}
float **alocaPonto(int n, int k){
    int i;
    float **m;

    m=(float **) malloc(sizeof(float) * n);
    for(i=0; i<n; i++){
        m[i] = (float*) malloc(sizeof(float) * k);
    }

    return m;
}

double area(retangulo r){
double resultado;
  resultado=  (r.superiorEsquerdo.x - r.inferiorDireito.x) * (r.superiorEsquerdo.y - r.inferiorDireito.y);
  return resultado;
}