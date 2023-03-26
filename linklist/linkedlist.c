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

}

node* create_node(int key){
    
}

void append(list** l, int key){

}

int pop(list** l){

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