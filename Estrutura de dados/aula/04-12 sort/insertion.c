#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *item, int count);
void print(int *item, int count, int index);

int main() {

    int v[5] = {5,8,2,1,9};
    print(v,5,0);
    insertionSort(v,5);
    printf("\nSort\n");
    print(v,5,0);



}

/**
 * Algoritmo InsertionSort O(n2)
 */
void insertionSort(int *item, int count){

    int i, j, eleito;

    for(i=1; i<=count-1; i++){
        eleito = item[i];
        j = i - 1;

        while(j>=0 && item[j] > eleito){
            item[j+1] = item[j];
            j = j - 1;
        }

        item[j+1] = eleito;
    }

}

/*
* Versão recursiva de um método para imprimir o vetor
*/
void print(int *item, int count, int index){

    if(count  <=  index)
        return;

    printf("%d ", item[index]);

    print(item,count,++index);        

}