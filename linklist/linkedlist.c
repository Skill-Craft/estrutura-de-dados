#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node* next;
} node;

typedef struct list{
    size_t size;
    node* head;
    node* tail;
} list;


list* create_list(){
    list* l = (list*)malloc(sizeof(list));
    l->size = 0;
    l->head = l->tail = NULL;
}

node* __create_node(int key){
    node* new = (node*)malloc(sizeof(node));
    new -> val = key;
    new -> next = NULL;
    return new;
}

void append(list** l, int key){
    (*l)->size++;
    node* new = __create_node(key);
    if((*l)->size == 0){
        (*l)->head = (*l)->tail = new;
        return;
    }
    (*l)->tail ->next = new;
    (*l)->tail = new;
}

int pop(list** l){
    node* aux = (*l)->head;
    if((*l)->size == 0) return;
    else if((*l)->size == 1){
        
    }
    while(aux -> next ->next !=NULL){
        aux = aux->next;
    }
}

int remove(list** l, int key){

}

size_t search(list* l, int key){

}

size_t len(list* l){
return l->size;
}

int main(){

    return 0;
}