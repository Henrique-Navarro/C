#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *p;
    char g,linha[100],vogal[]="AEIOUaeiou";
    int i,a,contavogais;
    p= fopen("texto.txt","r");
    if (p == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return 1;
  }
  g= gets (p);
  do
  {
             for(i=0; linha[i] != '\0'; i++){
        for(a=0; vogal[a] != '\0'; a++){
      if (vogal[a]==linha[i]){
      contavogais++;
      printf("A quantidades de vogais eh:%d",contavogais);
      break;
      }
      
        
      }
       
  }  
	  
  } while (g!= EOF);
  
 
  fclose(p);
  return 0;
    
}