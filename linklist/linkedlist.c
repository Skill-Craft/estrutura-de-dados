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
    if((*l)->size == 1){
        (*l)->head = (*l)->tail = new;
        return;
    }
    (*l)->tail ->next = new;
    (*l)->tail = new;
}

int pop(list** l){
    node* aux = (*l)->head;
    if((*l)->size == 0) return -1;

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
    int value = aux -> val; 
    free(aux -> next);
    aux -> next = NULL;
    (*l)->tail = aux;
    return value;
}

int insert(list **l, int key, size_t pos){
    if(pos == (*l)->size){
        append(l,key);
        return 1; 
    } else if(pos > (*l)->size || pos < 0){
        return 0;
    } else if(pos == 0){
        node* aux = __create_node(key);
        aux -> next = (*l)->head;
        (*l)->head = aux;
        return 1;
    }
    node* aux = (*l)->head;
    for(int i = 0; i < pos-1; i++) aux = aux -> next;
    (*l) -> size++;
    node* aux2 = __create_node(key);
    aux2 -> next = aux -> next;
    aux -> next = aux2;
    return 1;
}

size_t remove_from_list(list** l, int key){
    size_t counter = 0;
    node* aux = (*l)->head;
    if((*l)->size == 0) return (*l)->size+1;
    else if((*l)->size == 1){
        if((*l)->head->val != key) return (*l)->size;
        (*l)->size--;
        return counter;
    } 
    // else if((*l)->size == 2){

    // }
    while(aux -> next ->next !=NULL){
        counter++;
        if(aux->next->val == key) break;
        aux = aux->next;
    }
    if(aux->next == (*l)->tail && (*l)->tail->val != key) return (*l)->size;
    (*l)->size--;
    node* aux2 = aux -> next;
    aux -> next = aux -> next ->next;
    free(aux2);
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
    if(aux == NULL) return l->size+1;
    return counter-1;
}

void print_list(list* l){
    node* aux = l->head;
    while(aux){
        printf("%d ",aux->val);
        aux = aux->next;
    }
}

size_t len(list* l){
return l->size;
}

void free_all(list** l){
    node* aux = (*l) -> head;
    while((*l) -> head){
        (*l)->head = (*l)->head -> next;
        free(aux);
        aux = (*l)->head;
    }
    free(*l);
}

int main(){
    list* l = create_list();
    append(&l,10);
    append(&l,20);
    append(&l,30);
    append(&l,40);
    append(&l,50);
    // remove_from_list(&l, 50);
    // pop(&l);
    // printf("\n");
    insert(&l,25,2);
    print_list(l);
    // print_list(l);
    // printf("%d\n",remove_from_list(&l,30));
    // print_list(l);
    // printf("\n");
    // size_t le = len(l);
    // size_t a = search(l,30);
    // printf("%d %d",le, a);
    return 0;
}