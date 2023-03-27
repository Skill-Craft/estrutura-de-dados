#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} node;

typedef struct deque{
    size_t size;
    node* head;
    node* tail;
} deque;


deque* create_deque(){
    deque* dq = (deque*)malloc(sizeof(deque));
    dq->size = 0;
    dq->head = dq->tail = NULL;
}

node* __create_node(int value){
    node* new = (node*)malloc(sizeof(node));
    new -> val = value;
    new -> next = new->prev = NULL;
    return new;
}

void append_right(deque** dq, int key){
    (*dq)->size++;
    node* new = __create_node(key);
    if((*dq)->size == 0){
        (*dq)->head = (*dq)->tail = new;
        return;
    }
    (*dq)->tail ->next = new;
    // ! MISSING: new -> prev
    (*dq)->tail = new;  
}

void append_left(deque** dq){

}

int pop_right(deque** dq){

}

int pop_left(deque** dq){

}

int remove(deque** dq, int key){
    size_t counter = 0;
    node* aux = (*dq)->head;
    if((*dq)->size == 0) return;
    else if((*dq)->size == 1){
        if((*dq)->head->val != key) return;
        return counter;
    } else if((*dq)->size == 2){

    }
    while(aux -> next ->next !=NULL){
        counter++;
        if(aux->next->val == key) break;
        aux = aux->next;
    }
    if(aux->next == (*dq)->tail && (*dq)->tail->val != key) return;
    free(aux -> next);
    aux -> next = NULL;
    return counter;
}

size_t search(deque* dq, int key){
    size_t counter = 0;
    node* aux = dq->head;
    while(aux != NULL){
        counter++;
        if(aux->val == key) break;
        aux = aux->next;
    }
    if(aux == NULL) return;
    return counter;
}


size_t len(deque* dq){
    return dq->size;
}

void free_all(deque **dq){

}

int main(){

    return 0;
}