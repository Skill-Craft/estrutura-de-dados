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

}

node* create_node(int value){
    
}

void append_right(deque** dq){

}

void append_left(deque** dq){

}

int pop_right(deque** dq){

}

int pop_left(deque** dq){

}

int remove(deque** dq, int key){

}

size_t search(deque* dq, int key){

}

size_t len(deque* dq){
    return dq->size;
}

int main(){

    return 0;
}