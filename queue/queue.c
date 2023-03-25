#include <stdio.h>
#include <stdlib.h>

typedef struct node_queue{
    int val;
    struct node_queue* next;
} node_queue;

typedef struct queue{
    int size;
    node_queue* first;
    node_queue* last;
} queue;

queue* create_queue(){
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = 0;
    q->first = q->last = 0;
    return q;
}

node_queue* create_node(){
    node_queue* node = (node_queue*)malloc(sizeof(node_queue));
    
}