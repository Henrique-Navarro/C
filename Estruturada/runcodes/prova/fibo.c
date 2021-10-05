#include <stdio.h>
#include <stdlib.h>

int fibo(int n);

int main(){
    int n,res;
    scanf("%d", &n);
    res =fibo(n);
    printf("%d", res);
    return 0;
}

int fibo(int n){
    if(n == 0 || n< 0){
        return 0;
    }
    if (n ==1 || n== 2){
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}