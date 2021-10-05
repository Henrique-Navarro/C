#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
    int linha, coluna;
}pt;
struct reta{
    double **retas;
}ret;

double **alocacao(int linha, int coluna);

int main(){
    int i,j, retanum;
    double distancia,potencia,aux=-1;
    int xa,ya;
    int xb, yb;
    pt.coluna=4;
    
    scanf("%d", &pt.linha);

    ret.retas= alocacao(pt.linha, pt.coluna);

    for(i=0; i<pt.linha; i++){
        for(j=0; j<pt.coluna; j++){
            scanf("%lf",&ret.retas[i][j]);
        }
    }

    for(i=0;i< pt.linha; i++){
        xa=ret.retas[i][pt.coluna-4];
        ya=ret.retas[i][pt.coluna-3];
        xb=ret.retas[i][pt.coluna-2];
        yb=ret.retas[i][pt.coluna-1];

        potencia= pow(xb-xa,2) + pow(yb-ya,2);
        distancia= sqrt(potencia);

        if(distancia > aux){
            aux= distancia;
            retanum= i;
        }
    }

    printf("Reta numero %d, pontos [%.0lf,%.0lf] e [%.0lf,%.0lf], tamanho %.2lf.", retanum, ret.retas[retanum][0], ret.retas[retanum][1], ret.retas[retanum][2], ret.retas[retanum][3], aux);
}

double **alocacao(int linha, int coluna){
    double **aloc;
    int i;

    aloc = (double**)malloc(sizeof(double*) * pt.linha);

    for(i=0; i<linha; i++){
        aloc[i]= (double*)malloc(sizeof(double)* pt.coluna);
    }

    return aloc;
}
