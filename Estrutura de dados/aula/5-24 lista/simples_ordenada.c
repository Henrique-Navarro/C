int inserir(Lista *lista, int dado){
    Cel *novo= malloc(sizeof(Cel));
    Cel *ant;
    Cel *aux;

    if(novo==NULL){
        return 0;
    }

    novo->dado= dado;

    if(lista->inicio== NULL){
        lista->inicio= novo;
        lista->fim= novo;
        novo->prox= NULL;
    }
    else{
        ant= NULL;
        aux= lista->inicio;
        while(aux != NULL && novo->dado > aux->dado){
            ant= aux;
            aux= aux->prox;
        }
        if(ant== NULL){
            novo->prox= lista->inicio;
            lista->inicio= novo;
        }
        else if(aux== NULL){
            lista->fim->prox= novo;
            lista->fim= novo;
            lista->fim->prox= NULL;
        }
        else{
            ant->prox= novo;
            novo->prox= aux;
        }
    }
    lista->tam++;

    return 1;
}

int remover(struct Lista *lista, int dado){
    struct Cel *aux;
    struct Cel *ant;
    int qtdDel=0;

    aux=lista->inicio;
    ant=NULL;

    while(aux != NULL){
        if(aux->dado== dado){
            qtdDel++;
            lista->tam--;

            if(aux== lista->inicio){
                lista->inicio= aux->prox;
                free(aux);
                aux= lista->inicio;
            }
            else if(aux== lista->fim){
                ant->prox= NULL;
                lista->fim= ant;
                free(aux);
                aux= NULL;
            }
            else{
                ant->prox= aux->prox;
                free(aux);
                aux= ant->prox;
            }
        }
        else{
            ant= aux;
            aux= aux->prox;
        }
    }

    return qtdDel;  
}