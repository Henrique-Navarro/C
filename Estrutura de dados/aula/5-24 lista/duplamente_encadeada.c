int inserirInicio(Lista *lista, int dado){
    Cel *novo= malloc(sizeof(Cel));

    if(novo==NULL){
        return 0;
    }

    novo->dado= dado;

    if(lista->inicio== NULL){
        lista->inicio= novo;
        lista->fim= novo;
        novo->prox= NULL;
        novo->ant= NULL;
    }
    else{
        novo->prox= lista->inicio;
        lista->inicio->ant= novo;
        novo->prox= NULL;
        lista->inicio= novo;
    }

    lista->tam++;
    return 1;
}

int inserirFim(Lista *lista, int dado){
    Cel *novo= malloc(sizeof(Cel));

    if(novo==NULL){
        return 0;
    }

    novo->dado= dado;

    if(lista->inicio== NULL){
        lista->inicio= novo;
        lista->fim= novo;
        novo->prox= NULL;
        novo-> NULL;
    }
    else{
        lista->fim->prox= novo;
        novo->ant= lista->fim;
        novo->prox= NULL;
        lista->fim= novo;
    }

    lista->tam++;
    return 1;
}

int remover(Lista *lista, int dado){
    if(lista->inicio == NULL){
        return 0;
    }

    Cel *aux;
    int qtdDel=0;
    aux= lista->inicio;

    while(aux != NULL){
        if(aux->dado == dado){
            qtdDel++;
            if(aux== lista->inicio){
                lista->inicio= aux->prox;
                if(lista->inicio != NULL){
                    lista->inicio->ant= NULL;
                }
                free(aux);
                aux= lista->inicio;
            }
            else if(aux== lista->fim){
                lista->fim= lista->fim->ant;
                lista->fim->prox= NULL;
                free(aux);
                aux= NULL;
            }
            else{
                aux->ant->prox= aux->prox;
                aux->prox->ant= aux->ant;
                Cel *aux2;
                aux2= aux->prox;
                free(aux);
                aux= aux2;
            }
        }
        else{
            aux= aux->prox;
        }
    }

    lista->tam++;
    return qtdDel;
}