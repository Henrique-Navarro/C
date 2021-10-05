int binario(char **item, char *key, int tam){
    int low, high, mid;
    low=0;
    high=tam-1;

    while(low <= high){
        mid= (low+high)/2;
        if (strcmp(key, item[mid]) < 0){
            high= mid-1;
        }
        else if(strcmp(key, item[mid]) > 0){
            low=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}