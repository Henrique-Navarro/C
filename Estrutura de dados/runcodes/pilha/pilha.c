int pop(Pilha *pilha){
    Pilha *aux= pilha->prox;
    int rem= aux->numero;

    pilha->prox = pilha->prox->prox;
    free(aux);

    return rem;
}

int push(Pilha *pilha, int numero){
    Pilha *novo= (Pilha *)malloc(sizeof(Pilha));
    if(novo == NULL){
        return 0;
    }

    novo->numero= numero;
    novo->prox= pilha->prox;
    pilha->prox= novo;

    return 1;
}

void inicializar(Pilha *pilha){
    pilha->numero= 0;
    pilha->prox= NULL;
}