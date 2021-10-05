void bubblesort(int *item, int numELEMENTOS){
    int n,i,aux;

    for(n=1; n<= numELEMENTOS; n++){
        for(i=0; i<numELEMENTOS-1; i++){
            aux=item[i];
            item[i]=item[i+1];
            item[i+1]=aux;
        }
    }
}