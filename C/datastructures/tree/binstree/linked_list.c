#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
    struct list_node* next;
    struct list_node* prev;
    int val;
} node;

typedef struct list{
    size_t size;
    node* head;
    node* tail;
} list;



node_tree* find_second_greatest(node_tree* t){
    if(is_empty(t) || is_empty(t->rn)) return t;
    while(!is_empty(t->rn->rn)){
        t = t->rn;
    }
    return t;
}




node_tree* find_smallest(node_tree* t){
    while(!is_empty(t->ln)) t = t->ln;
    return t;
}

void clear(node_tree* t){
    if(!is_empty(t)){
        node_tree* aux1 = t -> ln;
        node_tree* aux2 = t -> rn;
        t ->ln = t -> rn = NULL;
        free(t);
        clear(aux1);
        clear(aux2);
    }
}
// if((*t) -> val == value){
    //     if(is_empty((*t)->ln)){
            
    //         return;
    //     } else if (is_empty((*t)->ln->rn)){
    //         node_tree* aux = (*t)->ln;
    //         (*t) -> val = aux ->val;
    //         (*t) -> ln = NULL;
    //         free(aux);
    //         return;
    //     }        
    //     node_tree* aux = find_second_greatest((*t)->ln);
    //     (*t) -> val = aux-> rn -> val;
    //     node_tree* aux2 = aux-> rn;
    //     aux -> rn = NULL;
    //     free(aux2);
    // } else if(value < (*t) -> val) pop(&(*t)->ln, value);
    // else pop(&(*t)->rn, value);