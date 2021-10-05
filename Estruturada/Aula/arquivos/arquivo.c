#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto{
    float x;
    float y;
}ponto;

typedef struct reta{
    ponto a;
    ponto b;
}reta;

float calcreta(reta r);

int main(){
    reta r;
    float tamreta;
    FILE *in,*out;
 
    in= fopen("pontos.txt", "r+");
    out= fopen("retas_tam.txt", "w+");

    if(in == NULL || out == NULL){
        printf("erro");
        return 1;
    }

    while(fscanf(in, "%f %f %f %f", &r.a.x, &r.a.y, &r.b.x, &r.b.y) != EOF){
        tamreta= calcreta(r);
        fprintf(out," Pontos:[%.2f, %2.f] [%.2f, %.2f] -> Tamanho: %.2f \n", r.a.x, r.a.y, r.b.x, r.b.y, tamreta);
    }

    fclose(in);
    fclose(out);
    return 0;
}

float calcreta(reta r){
    float d;
    d= sqrt(pow((r.b.x - r.a.x),2) + pow((r.b.y - r.b.x),2));
    return d;
}