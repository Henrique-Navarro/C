#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *p;
    char g;
    int contavogais=0;
    p= fopen("texto.txt","r");
    if (p == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return 1;
  }
  else{
  do
      {g= getc (p);
             if(g=='a' || g=='e' || g=='i' || g=='o' || g=='u'){
      contavogais++;
  }
  if(g=='A' || g=='E' || g=='I' || g=='O' || g=='U'){
      contavogais++;
  }

      }
       while (g!= EOF);
  
  }
  printf("A quantidades de vogais eh:%d",contavogais);
  fclose(p);
  return 0;
    
}