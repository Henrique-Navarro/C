#include<stdio.h>
#include<math.h>
float financiamento(float valor, int parcelas)
{
   float tx, prestacao;

   switch(parcelas)
   {
   case 6:
    tx = 0.07/12;
    break;
   case 12:
    tx = 0.1/12;
    break;
   case 18:
    tx = 0.12/12;
    break;
   case 24:
    tx = 0.15/12;
    break;
   case 36:
    tx = 0.18/12;
    break;
   default:
    tx = 0.0;
    break;
   }

 prestacao = valor * (pow((1+tx), parcelas)*tx)/(pow((1+tx),parcelas)-1);
 return prestacao;
}

int main(){
  int parc;
  float financia, presta;

  printf("\n\nDigite o valor a ser financiado:");
  scanf("%f",&financia);
  while(financia != 0){
    printf("\n\nDigite o numero de parcelas:");
    scanf("%d",&parc);
    presta = financiamento(financia, parc);
    printf("O valor da sua prestação e: %f", presta);
    printf("\n\nDigite o valor a ser financiado:");
    scanf("%f",&financia);

  }
}