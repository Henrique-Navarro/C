#include <stdio.h>
#include <stdlib.h>

int sf(int n);
int fat(int n, int m);

int main(){

    int n;
    scanf("%d", &n);
    printf("%d", sf(n));
    return 0;
}

int sf (int n){

    if(n==0){
        return 1;
    }

    return fat(n, n);
}

int fat(int n, int a){

    if( a== 1){
        return 1;
    }
    if( n== 1){
        return fat( a-1, a-1);
    }
    
    return n* fat( n-1, a);
}