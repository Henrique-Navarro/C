#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char string[15];
    int id;
}chaves;

int binario(chaves *arr, char *key, int tam){
    int low, high, mid;

    low=0;
    high = tam - 1;

    while(low <= high){
        
        mid = (low+high)/2;
        
        if(strcmp(key,arr[mid].string) < 0) {               
            high = mid - 1;

        }else if(strcmp(key , arr[mid].string) > 0) {        
            low = mid + 1;

        }else{
            return mid;
        }
    }

    return -1;
}

void swap(char *a, char *b) 
{ 
    char t[15];
    strcpy(t,a);
    strcpy(a,b); 
    strcpy(b,t); 
} 

int partition (chaves *arr, int low, int high) 
{ 
    char pivot[15];
    strcpy(pivot,arr[high].string);

    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    {   if (strcmp(arr[j].string, pivot)  == -1 || strcmp(arr[j].string, pivot)  == 0){ 
            i++;     
            swap(arr[i].string, arr[j].string); 
        } 
    } 
    swap(arr[i + 1].string, arr[high].string); 
    return (i + 1); 
} 
  
void quickSort(chaves *arr, int low, int high) { 
    if (low < high) { 
        
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 


int main(){

    char key1[15];
    char key2[15];
    int i, j, n, n1, posicao;
    int p = 0;

    scanf("%d", &n);

    chaves *arr = (chaves*) malloc(n*sizeof(chaves));

    for (i = 0; i < n; i++){
        scanf("%s", key1);

        strcpy(arr[i].string, key1); 
        arr[i].id = p;
        p++;
    }

    int m= sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,m-1);
    for(i=0; i<n; i++){
        printf("%s ", arr[i].string);
    }
    scanf("%d", &n1);

    for (j = 0; j < n1; j++){
        scanf("%s", key2);
        posicao = binario(arr, key2, n);
        arr[-1].id = -1;
        printf("%d\n", arr[posicao].id);  
    }
    
    free(arr);
    
    return 0;
}



