#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 10

float **allocateMatriz(int ordem);
float *allocateIndex(int ordem);
void receiveMat(float **matriz, int ordem);
void arrumaMatriz(float **matriz, int ordem, float *b, float *newB, int q, float *err);
void calcErro(float **matriz, float *err, float *newB, float *b, int ordem);

int main(){
    int i, ordem, q = 0;
    float **matriz, *b, *newB;
    float *err;

    printf("ordem da matriz\n");
    scanf("%d", &ordem);
    matriz = allocateMatriz(ordem);
    newB = allocateIndex(ordem);
    b = allocateIndex(ordem);
    err = allocateIndex(TAM);

    printf("matriz\n");
    receiveMat(matriz, ordem);
    printf("termos idependentes\n");
    for(i=0;i<ordem;i++)
        scanf("%f",&b[i]);

    printf("chute inicial\n");
    for(i=0;i<ordem;i++)
        scanf("%f", &newB[i]);

    arrumaMatriz(matriz, ordem, b, newB, q, err);

    for(i=0; i<ordem; i++)
        free(matriz[i]);
    free(matriz);
    free(newB);
    free(err);
    free(b);
}

float *allocateIndex(int ordem){
    float *x;

    x = malloc(ordem*sizeof(float));
    return x;
}

float **allocateMatriz(int ordem){
    int i;
    float **matriz;

    matriz = malloc(ordem * sizeof(float*));
    for(i=0; i< ordem; i++)
        matriz[i] = malloc(ordem * sizeof(float));

    return matriz;
}

void receiveMat(float **matriz, int ordem){
    int i, j;

    for(i=0; i < ordem; i++){
        for(j=0; j<ordem; j++)
            scanf("%f", &matriz[i][j]);
    }
}

void arrumaMatriz(float **matriz, int ordem, float *b, float *newB, int q, float *err){
    int i, j;
    float aux;
    
    calcErro(matriz, err, newB, b, ordem);

    if(q<TAM){
        for(i=0;i<ordem;i++){
            aux = 0;
            for(j=0;j<ordem;j++)
                if(i != j){
                    aux += (matriz[i][j] * newB[j]);
                    newB[i] = (b[i] - aux)/matriz[i][i];
                }          
            printf("newB %d = %.4f\n", i, newB[i]);
        }
        arrumaMatriz(matriz, ordem, b, newB, q+1, err);
    }


}

void calcErro(float **matriz, float *err, float *newB, float *b, int ordem){

    float cont = 0, aux = 0;
    int i, j;

    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++)
            aux += matriz[i][j] * newB[j];
        err[i] = aux;
        aux = 0;
    }
    for(i=0;i<ordem;i++)
        cont += pow((b[i] - err[i]), 2);
    cont = sqrt(cont);
    printf("erro = %.6f\n", cont);
    printf("\n\n");
}