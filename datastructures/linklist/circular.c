#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
} node;

typedef struct circular_list{
    node* head;
    node* pseudotail;
    int size;
} clist;

node* __create_node(int key){
    node* aux = calloc(1, sizeof(node));
    aux -> value = key;
    return aux;
}

clist* create_circular_list(){
    clist* list = calloc(1, sizeof(clist));
}


int search(){

}

int search_from_index(){

}

int append(clist** list, int key){
    node* new = __create_node(key);
    (*list) -> size++;
    if((*list) -> size == 1){
        (*list) -> pseudotail = (*list) -> head = new;
        return 1;
    } if((*list) -> size == 2){
        (*list) -> pseudotail = new;
        new -> next = (*list) -> head;
        (*list) -> head -> next = new;
    }
    (*list) -> pseudotail ->next = new;
    new -> next = (*list) -> head;
    (*list) -> pseudotail = new;
    return 1;
}

int insert(){

}

int pop(){

}

int remove(){

}

void print_circular_list(clist* list){
    node* aux = list -> head;
    if(list->size == 1){
        // TODO
        return;
    }
    while(aux != list -> pseudotail){
        printf("%d ", aux -> value);
        aux = aux -> next;
    }
    aux = aux -> next;
    printf("%d\n", aux->value);
}

size_t len(clist* list){
    return list -> size;
}

void free_all(clist** list){
    // node* aux = list -> head;
    // if(list->size == 1){
    //     // TODO
    //     return;
    // }
    // while(aux != list -> pseudotail){
    //     printf("%d ", aux -> value);
    //     aux = aux -> next;
    // }
    // aux = aux -> next;
    // printf("%d\n", aux->value);
}