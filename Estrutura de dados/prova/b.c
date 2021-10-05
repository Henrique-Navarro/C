#include<stdio.h>
#include<stdlib.h>


void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; 

	mid = n/2; 

	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = A[i];
	for(i = mid;i<n;i++) R[i-mid] = A[i];

	MergeSort(L,mid); 
	MergeSort(R,n-mid); 
	Merge(A,L,mid,R,n-mid); 
    free(L);
    free(R);
}

int main () {
    int N,i,C,aux,j;
    scanf("%d",&N);
    int *Ids;
    Ids= malloc(sizeof(int)*N);
    for (i = 0; i < N;i++){
        scanf("%d",&Ids[i]);
    }

    scanf("%d",&C);
    int chaves[C];
    for (i = 0; i < C;i++){
        scanf("%d",&chaves[i]);
    }
    

	
	MergeSort(Ids, N);

    for (i = 0; i < C;i++){
        aux=binario(Ids,chaves[i],N);
        printf("%d\n",aux);
        
    }
    printf("%d ",Ids[1]);    
    printf("%d ",Ids[3]);
	 

    free(Ids);
	
}

int pesquisar(int *vetor, int chave , int vezes){
    int t, cont;
    cont=0;

    for(t=0; t<vezes; t++){
        if(vetor[t] == chave){
            cont++;
            while(vetor[t]==vetor[t+1]){
                cont++;
                t++;
            }
            return cont;
        }
    }
    return cont;
}

int binario(int *item, int key, int tam){
    int bot, top, mid;
    bot=0;
    top = tam - 1;
    int i,j;
    i=0;
    while(bot <= top){
        mid = (bot+top)/2;
        if(key<item[mid]){
            top = mid - 1;
        }else if(key > item[mid]){
            bot = mid + 1;
        }else{
            
            //return mid;
        }
        i=1;
        j=mid-1;
        while (item[mid]==item[j]){
            i++;
            j=j-1;
        }
        j=mid+1;
        while (item[mid]==item[j]){
            i++;
            j=j+1;
        }
        return i;
    }
    /*if(item[mid]==key){
        i=1;
        j=mid-1;
        while (item[mid]==item[j]){
            i++;
            j=j-1;
        }
        j=mid+1;
        while (item[mid]==item[j]){
            i++;
            j=j+1;
        }
        
    }*/
    
    //printf("%d",i);
    return 0;


}