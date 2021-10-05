int seq_search(int *iten, int key, int count){
    int t;
    for (t=0; t<count; t++){
        if(key == iten[t]){
            return t;
        }
    }
    return -1;  
}