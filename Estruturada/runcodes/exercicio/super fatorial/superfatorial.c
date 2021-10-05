#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int n);
int sf(int n);

int main () {
    int n,a;
    scanf("%d", &n);
    
    a = sf(n);

    printf("%d", a);
}

int sf(int n){
    int res=1,b;
    
    b= f(n);
    res= (res) * (b);

    return sf(n-1);

    return res;
}

int f(int n){
    int fat;

    if (n == 0 ){
        return (1);
    }
    else{
        return (n)* (f(n-1));
    }
}