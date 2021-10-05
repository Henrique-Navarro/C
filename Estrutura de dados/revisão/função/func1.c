/*Faça um programa que leia duas notas de um aluno numa turma de 10 alunos. 
Para cada aluno, calcular a média ponderadas das notas, sabendo que a nota1 tem peso = 4 e a nota2 tem peso = 6
Imprimir a média do aluno e o conceito final, conforme tabela abaixo:
INTERVALO	CONCEITO
0.0 a 4.9	D
5.0 a 6.9	C
7.0 a 8.9	B
9.0 a 10.0	A
Fazer 2 funções: A primeira função denominada float mediapond() irá receber as duas notas,
calcular e retornar a média ponderada. A segunda função denominada char conceito()
irá receber a média das notas e retornar o conceito conforme a tabela acima.
*/
#include <stdio.h>
#include <stdlib.h>

float media(int n1, int n2);
char imprimir(float med);

int main(){
    int n1,n2,i;
    float med;
    char conceito;
    for(i=0; i<10; i++){
        scanf("%d", &n1);
        scanf("%d", &n2);
        med=media(n1,n2);
        conceito=imprimir(med);
        printf("%d aluno tirou: %c\n",i, conceito);
    }
}

float media(int n1, int n2){
    int med;
    n1=n1*4;
    n2=n2*6;
    med=(n1+n2)/10;
    return med;
}

char imprimir(float med){
    if((med>=0)&&(med<5)){
        return 'D';
    }
    else if((med>=5)&&(med<7)){
        return 'C';
    }
    else if((med>=7)&&(med<9)){
        return 'B';
    }
    else if((med>=9)&&(med<10)){
        return 'A';
    }
}