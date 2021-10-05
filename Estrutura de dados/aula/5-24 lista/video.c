#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode{
    int id;
} DataNode;

typedef struct node{
    DataNode data;
    struct node *next;
} Node;

typedef struct list{
    int size;
    Node *head;
} List;


List *createList();
void push(List *list, DataNode data);
void printList(List *list);
void pop(List *list);
bool isEmpty(List *list);
Node *atPos(List *list, int index);
int indexOf(List *list, Node *node);
void erase(List *list,int index);
void insert(List *list, DataNode data, int index);


List *createList(){
    List *list=(List *)malloc(sizeof(List));

    list->size=0;
    list->head= NULL;

    return list;
}

void push(List *list, DataNode data){
    Node *node= (Node*)malloc(sizeof(Node));

    node->data= data;
    node->next= list->head;
    list->head= node;
    list->size++;
}

void printList(List *list){
     
    /*if(pointer == NULL){
        printf("LISTA VAZIA\n");
    }*/
    if(isEmpty(list)){
        printf("LISTA VAZIA\n");
        return;
    }

    Node *pointer= list->head;

    while(pointer != NULL){
        printf("%d ", pointer->data.id);
        pointer= pointer->next;
    }
}

bool isEmpty(List *list){
    //se o tamanho da lista for zero, a função retorna verdadeiro
    return (list->size==0);
}

void pop(List *list){
    if(!isEmpty(list)){
        Node *pointer= list->head;

        list->head= pointer->next;
        free(pointer);
        list->size--;
    }
}

Node *atPos(List *list, int index){
    if(index >= 0 && index < list->size){
        Node *node= list->head;
        for(int i=0; i<index;i++){
            node= node->next;
        }
        return node;
    }
    return NULL;
}

int indexOf(List *list, Node *node){
    if(node != NULL){
        Node *pointer= list->head;
        int index=0;
        while(pointer != node && pointer!= NULL){
            pointer= pointer->next;
            index++;
        }
        if(pointer != NULL){
            return index;
        }
        return index;
    }
    return -1;
}

void erase(List *list,int index){
    if(index==0){
        pop(list);
    }
    else{
        Node *current= atPos(list, index);
        if(current != NULL){
            Node *previous= atPos(list, index-1);
            previous->next= current->next;

            free(current);
            list->size--;
        }
    }
}

void insert(List *list, DataNode data, int index){
    if(index==0){
        push(list, data);   
    }
    else{
        Node *current= atPos(list, index);
        if(current != NULL){
            Node *previous= atPos(list, index-1);

            Node *newNode= (Node*)malloc(sizeof(Node));
            newNode->data= data;

            previous->next= newNode;
            newNode->next= current;
            list->size++;
        }
    }
}

int main(){
    //criar
    List *lista= createList();
    //printf("%d", lista->size);

    //inserir
    DataNode data;
    data.id=5;
    push(lista, data);
    
    data.id=9;
    push(lista, data);
    //printf("%d %d", lista->head->data.id, lista->head->next->data.id);
    

   //printar
   printList(lista);

   //remover
   pop(lista);

    //retorna o no que está o indice
    if(atPos(lista, 1) != NULL){
        printf("esse:%d", atPos(lista, -1)->data.id);
    }

    //retorna o indice que está o no
    printf("%d", indexOf(lista, lista->head));

    //excluir indice em determinada posição
    erase(lista, 1);

    //adicionar indice em determinada posição
    data.id=11;
    insert(lista, data, 2);
    //adicionar 11 na posição 2
}

//https://www.youtube.com/watch?v=-yRqFjYSvAA&list=PL1EkVGo1AQ0HgYpSwWwt_7JnavxRmCwt0&index=9
//https://www.cprogressivo.net/2013/10/Como-fazer-uma-lista-em-C.html#:~:text=Vamos%20agora%20mostrar%20como%20criar,posição%20%27n%2B1%27. 