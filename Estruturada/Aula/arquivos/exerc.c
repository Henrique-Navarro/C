#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i=0;
    char nome[100][100];
    FILE *in,*out;


    in= fopen("nomes.txt", "r");
    out= fopen("invertido.txt", "w");

    if(in == NULL || out == NULL){
        printf("erro");
        return 1;
    }
    
    while(fgets(nome[i], sizeof(nome), in) != NULL){ 
        i++;
    }
    for(i--; i>=0; i--){
        printf("%s", nome[i]);
        fprintf(out,"%s", nome[i]);
    }



    fclose(in);
    fclose(out);
    return 0;
}