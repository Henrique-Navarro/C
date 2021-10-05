int inserir(Lista *lista, int dado){
    Cel *novo= malloc(sizeof(Cel));

    if(novo== NULL){
        return 0;
    }

    novo->dado= dado;

    if(lista->inicio== NULL){
        novo->prox= NULL;
        novo->ant= NULL;
        lista->inicio= novo;
        lista->fim= novo;
    }
    else{
        Cel *aux;
        aux= lista->inicio;
        while(aux != NULL && novo->dado > aux->dado){
            aux= aux->prox;
        }
        if(aux == lista > inicio){
            novo->prox= lista->inicio;
            novo->ant= NULL;
            lista->inicio->ant= novo;
            lista->inicio= novo;
        }
        else if(aux== NULL){
            lista->fim->prox= novo;
            novo->ant= lista->fim;
            lista->fim= novo;
            lista->fim->prox= NULL;
        }
        else{
            novo->prox= aux;
            aux->ant->prox= novo;
            novo->ant= aux->ant;
            aux->ant= novo;
        }
    }
    lista->tam++;
    return 1;
}