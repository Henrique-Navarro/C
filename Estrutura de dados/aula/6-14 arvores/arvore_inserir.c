void inserirNode(node **leaf, int key_value){
    if(*leaf == NULL){
        *leaf=(node *)malloc(sizeof(node));
        (* leaf)->esq= NULL;
        (* leaf)->dir= NULL;
        (* leaf)->key=  key_value;
    }
    else{
        if(key_value < (* leaf)->key){
            inserirNode(&(*leaf)->esq, key_value);
        }
        if(key_value >= (*leaf)->key){
            inserirNode(&(*leaf)->dir, key_value);
        }
    }
}