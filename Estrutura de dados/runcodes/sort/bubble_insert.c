#include <stdio.h>
#include <stdlib.h>

void insert(int *itens, int tam){
    int i, j, eleito;
    int comp=0, op=0, aux=0;

    for(i=1; i<=tam-1; i++){
        eleito= itens[i];
        j= i-1;
        
        while((j>=0)&&(itens[j]>eleito)){
            itens[j+1]=itens[j];
            j--;
            op++;
            comp++;
            aux=1;
        }
        itens[j+1]=eleito;
        comp++;
        if(aux==1){
            op++;
        }
        aux=0;
    }
    printf("comp:%d op:%d\n", comp, op);
}
void bubble2(int *itens, int tam){
    int n=1,i,troca=1,aux;
    int comp=0, op=0;
    while(n<tam && troca == 1){
        troca=0;
        for(i=0; i<tam-1; i++){
            if(itens[i] > itens[i+1]){
                troca=1;
                aux= itens[i];
                itens[i]= itens[i+1];
                itens[i+1]= aux;
                op= op+3;
            }
            comp++;
        }
        n++;
    }
    printf("Bubblesort v2 = %d comparacoes, %d operacoes\n", comp, op);
}
void bubble1(int *itens, int tam){
    int i,j,aux, comp=0, op=0;
    for(i=0; i<tam-1; i++){
        for(j=0; j<tam-1; j++){
            if(itens[j]>itens[j+1]){
                aux= itens[j];
                itens[j]= itens[j+1];
                itens[j+1]= aux;
                op= op+3;
            }
            comp++;
        }
    }
    printf("Bubblesort v1 = %d comparacoes, %d operacoes\n", comp, op);
}

int main(){
    int i, tam, *vbubble1, *vbubble2, *vinsert;
    scanf("%d", &tam);
    vbubble1= (int *)malloc(sizeof(int) * tam);
    vbubble2= (int *)malloc(sizeof(int) * tam);
    vinsert = (int *)malloc(sizeof(int) * tam);
    for(i=0; i<tam; i++){
        scanf("%d", &vbubble1[i]);
        vbubble2[i]= vbubble1[i];
        vinsert[i] = vbubble1[i];
    }

    bubble1(vbubble1, tam);
    bubble2(vbubble2, tam);
    insert(vinsert, tam);
}
