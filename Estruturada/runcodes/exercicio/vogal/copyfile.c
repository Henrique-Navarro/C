#include <stdio.h>

int main(int agrc, char *agrv[]){
    FILE *in, *out;
    char c;

    if(agrc == 3){
        in = fopen(agrv[1], "r");
        out = fopen(agrv[2], "w");
    }

    if(in == NULL || out == NULL){
        printf("erro!");
        return 1;
    }

    while(!feof(in)){
        c= getc(in);
        if(!feof(in)){
            putc(c,out);
        }
    }
    fclose(in);
    fclose(out);    
}