#include <stdio.h>
#include <stdlib.h>

typedef struct node_priority_queue{
    int val;
    struct node_priority_queue *next;
} node_priority_queue;

typedef struct priority_queue{
    size_t size;
    node_priority_queue *head;
    node_priority_queue *last;
} priority_queue;

priority_queue *create_priority_queue(){
    priority_queue *new = (priority_queue *)malloc(sizeof(priority_queue));
    new->last = new->head = NULL;
    new->size = 0;
    return new;
}

node_priority_queue *__create_node_priority_queue(){
    node_priority_queue *new = (node_priority_queue *)malloc(sizeof(node_priority_queue));
    new->next = NULL;
    new->val = 0;
    return new;
}

void append(priority_queue **q, int value, int (*compare)(node_priority_queue*, node_priority_queue*)){
    node_priority_queue *new = __create_node_priority_queue();
    new->val = value;
    if ((*q)->head == NULL){
        (*q)->head = (*q)->last = new;
    }
    else{
        node_priority_queue *aux = (*q)->head, *aux2 = (*q)->head;
        while(aux -> next != NULL){
            if((*compare)(new, aux)) break;
            aux2 = aux;
            aux = aux->next;
        }
        if(!(*compare)(new,(*q)->last)){
            (*q)->last->next = new;
            (*q)->last = new;
            return;
        } 
        aux2->next = new;
        new -> next = aux;

    }
    (*q)->size++;
}

int pop(priority_queue **q){
    if ((*q)->size == 1)
        (*q)->last = NULL;
    node_priority_queue *aux = (*q)->head;
    (*q)->head = aux->next;
    (*q)->size--;
    aux->next = NULL;
    int ret = aux->val;
    free(aux);
    return ret;
}

size_t search(priority_queue *q, int key){
    size_t counter = 1;
    if (q->head == NULL)
        return 0;
    else if (q->head->next == NULL){
        if (q->head->val == key)
            return counter;
        else
            return 0;
    }
    node_priority_queue *aux = q->head;
    while (aux->next != NULL){
        if (aux->val == key)
            return counter;
        counter++;
        aux = aux->next;
    }
    return 0;
}

size_t size(priority_queue *q){
    return q->size;
}

void print_priority_queue(priority_queue *q){
    node_priority_queue *aux = q->head;
    while (aux != NULL){
        printf("%d ", aux->val);
        aux = aux->next;
    }
}

void print_first(priority_queue *q){
    printf("%d\n", q->head->val);
}

void free_all(priority_queue **q){
    while ((*q)->head != (*q)->last && (*q)->last != NULL){
        node_priority_queue *aux = (*q)->head->next;
        free((*q)->head);
        (*q)->head = aux;
    }
    if ((*q)->head != NULL)
        free((*q)->head);
    free(*q);
}

int compare(node_priority_queue *q1, node_priority_queue *q2){
    return q1->val < q2->val;
}

// int main(){
//     priority_queue *q = create_priority_queue();
//     int (*fun)(node_priority_queue *, node_priority_queue *) = &compare;
//     append(&q, 10, fun);
//     append(&q, 30, fun);
//     append(&q, 20, fun);
//     // print_first(q);
//     // size_t v = search(q,20);
//     // printf("%d ",v);
//     print_priority_queue(q);
// }