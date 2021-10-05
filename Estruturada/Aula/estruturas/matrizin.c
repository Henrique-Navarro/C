#include <stdio.h>
#include <stdlib.h>

struct matriz{
    int tamL;
    int tamC;
    int itens[1000][1000];
};

int main(){
    struct matriz m;
    int i,j;

    scanf("%d", &m.tamL);
    scanf("%d", &m.tamC);

    for(i=0; i<m.tamL; i++){
        for(j=0; j<m.tamC; j++){
            scanf("%d", &m.itens[i][j]);
        }
    }
    for(i=0; i<m.tamL; i++){
        for(j=0; j<m.tamC; j++){
            printf("%d ", m.itens[i][j]);
        }
    }

    return 0;
}
