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
        (*l)->size--;
        int value = (*l)->head->val;
        free((*l)->head);
        return value;
    }
    (*l)->size--;
    while(aux -> next ->next !=NULL){
        aux = aux->next;
    }
    int value = aux -> next; 
    free(aux -> next);
    aux -> next = NULL;
    (*l)->tail = aux;
    return value;
}

size_t remove(list** l, int key){
    size_t counter = 0;
    node* aux = (*l)->head;
    if((*l)->size == 0) return;
    else if((*l)->size == 1){
        if((*l)->head->val != key) return;
        (*l)->size--;
        return counter;
    } else if((*l)->size == 2){

    }
    while(aux -> next ->next !=NULL){
        counter++;
        if(aux->next->val == key) break;
        aux = aux->next;
    }
    if(aux->next == (*l)->tail && (*l)->tail->val != key) return;
    (*l)->size--;
    free(aux -> next);
    aux -> next = NULL;
    return counter;
}

size_t search(list* l, int key){
    size_t counter = 0;
    node* aux = l->head;
    while(aux != NULL){
        counter++;
        if(aux->val == key) break;
        aux = aux->next;
    }
    if(aux == NULL) return;
    return counter;
}

size_t len(list* l){
return l->size;
}

void free_all(list** l){

}

int main(){

    return 0;
}