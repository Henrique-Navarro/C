#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    int x;
    int y;
}Ponto;

typedef struct retangulo {
    Ponto superiorEsquerdo;
    Ponto inferiorDireito;
}Retangulo;

void area(Retangulo rec);
float **alocacao(int qtd, int c);

int main(){
    Retangulo ret;
    int qtd,i,j;
    float **todos;

    scanf("%d", &qtd);
    
    todos = alocacao(qtd, 4);

    for(i=0; i< qtd; i++){
        for(j=0; j<4; j++){
            scanf("%f", &todos[i][j]);
        }
    }

    for(i=0; i<qtd; i++){ 
        ret.superiorEsquerdo.x= todos[i][0];
        ret.superiorEsquerdo.y= todos[i][1];

        ret.inferiorDireito.x= todos[i][2];
        ret.inferiorDireito.y= todos[i][3];

        area(ret);
    }
    
}

void area(Retangulo rec){
    int lado1, lado2;
    float area;

    lado1= (rec.inferiorDireito.x) - (rec.superiorEsquerdo.x);
    lado2= rec.superiorEsquerdo.y - rec.inferiorDireito.y;

    area= lado1 * lado2;
    printf("%.0lf\n", area);

}

float **alocacao(int qtd, int c){
    int i;
    float **t;

    t= (float **)malloc(sizeof(float )* qtd);
    for(i=0; i<qtd; i++){
        t[i]= (float *)malloc(sizeof(float )* 4 );
    }

    return t;
}