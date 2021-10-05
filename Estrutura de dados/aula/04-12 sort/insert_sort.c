//i serve para percorrer o vetor
//j serve para marcar a divisão dos que já estão ordenados
for (i=1; i<=count-1; i++){
    // 5  3  2  4
    //[0][1][2][3]
    eleito= item[i];
    //eleito=3

    j = i-1;
    //j=0
    //    j=0     item[0]=5>3
    while(j>=0 && item[j]>eleito){
        //item[1]=item[0]
        //troca 3 pelo 5
        item[j+1]=item[j];

        //j=-1 (fora do vetor)
        j--;
    }

    //item[0]=3
    item[j+1]=eleito;

    //fez a troca do 3 pelo 5, e do 5 pelo 3
}

for(i=1; i<=tam-1; i++){
    eleito= itens[i];
    j= i-1;
    
    while((j>=0)&&(itens[j]>eleito)){
        itens[j+1]=itens[j];
        j--;
    }
    itens[j+1]=eleito;
}