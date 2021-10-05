binary_search(int *item, int key, int count){
    int low,high,mid;
    low=0;
    high=count-1;

    while(low <= high){
        mid= (low+high)/2;
        if(key<item[mid]){
            high= mid-1;
        }
        else if(key>item[mid]){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}