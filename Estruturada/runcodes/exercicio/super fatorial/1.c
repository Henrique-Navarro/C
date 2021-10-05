#include <stdio.h>
#include <stdlib.h>


int sf(int n);
int s(int n, int m);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", sf(n));
    return 0;
}

int sf (int n){
    if(n ==0){
        return 1;
    }
    return s(n, n);
}

int s (int n, int m) {
   if (m == 1){
        return 1;
   }
   if (n == 1){
        return s (m - 1, m - 1);
   }
   return n * s(n - 1, m);
}