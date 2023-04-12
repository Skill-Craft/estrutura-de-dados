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

int __reverse_apend(clist** list, int key){
    node* new = __create_node(key);
    new -> next = (*list) -> head;
    (*list) -> pseudotail -> next = new;
    (*list) -> head = new;
    return 1;
}

int insert(clist** list, int key, size_t pos){
    node* new = __create_node(key);
    if((*list) -> size < 2 || pos % (*list) -> size == 0) return append(list, key);
    if(pos == 0) return __reverse_apend(list,key);
    node* aux = (*list)->head;
    for(size_t i = 0; i < pos-1; i++) aux = aux -> next;
    node* aux2 = aux -> next;
    aux -> next = new;
    new -> next = aux2;
    return 1;
}

int pop(clist** list){

}

int __pop_first(clist** list){

}

int remove_from_list(clist** list, size_t pos){

}

void print_circular_list(clist* list){
    node* aux = list -> head;
    if(list->size == 1){
        printf("%d\n", aux -> value);
        return;
    }
    while(aux != list -> pseudotail){
        printf("%d ", aux -> value);
        aux = aux -> next;
    }
    printf("%d\n", aux->value);
    aux = aux -> next;
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

int main(){
    clist* l = create_circular_list();
    append(&l, 1);
    append(&l, 2);
    append(&l, 3);
    printf("%d\n", l->size);
    // printf("%d", l->pseudotail->value);
    insert(&l,4,2);
    print_circular_list(l);
    return 0;
}