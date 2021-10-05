#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz(int linhas, int colunas);
void recebeMatriz(float **matriz, int linhas, int colunas);
float **somaMatriz(float **matriz, float **matriz1, float **matriz2, int linhas, int colunas);
void exibeMatriz(float **matriz, int linhas, int colunas);

int main(){

    int x,y,i;
    float **matriz1, **matriz2, **matriz;

    scanf("%d %d", &x, &y);

    matriz1= alocaMatriz(x,y);
    matriz2= alocaMatriz(x,y);
    matriz= alocaMatriz(x,y);

    recebeMatriz(matriz1,x,y);
    recebeMatriz(matriz2,x,y);

    matriz= somaMatriz(matriz, matriz1, matriz2, x, y);

    exibeMatriz(matriz, x,y);

    for(i=0;i<x;i++){
        free(matriz[i]);
    }
    free(matriz);
}

float **alocaMatriz(int linhas, int colunas){
    int i;
    float **m;

    m=(float **) malloc(sizeof(float*) * linhas);
    for(i=0; i<linhas; i++){
        m[i] = (float*) malloc(sizeof(float) * colunas);
    }

    return m;
}

void recebeMatriz(float **matriz,int linhas,int colunas){
    int i,j;

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
}

float **somaMatriz(float **matriz, float **matriz1, float **matriz2, int linhas, int colunas){
    int i,j;

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            matriz[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matriz;
}

void exibeMatriz(float **matriz, int linhas, int colunas){
    int i,j;

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}
