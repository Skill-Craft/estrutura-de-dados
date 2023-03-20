#include <stdio.h>
#include <stdlib.h>

typedef struct node_tree{
    int val;
    struct node_tree *ln;
    struct node_tree *rn;
} node_tree;

// typedef struct node_list{
//     int val;
//     struct node_list *next;
//     struct node_list *prev;
// } node_list;

// typedef struct linked_list{
//     node_list* head;
//     node_list* tail;
//     size_t size;    
// } list;

// typedef struct bin_tree{
//     node_tree* head;
// } binary_tree;

int is_empty(node_tree* t){
    return t == NULL;
}

node_tree* create_tree(){
    return NULL;
}

node_tree* create_node_tree(int value){
    node_tree* t = (node_tree*)malloc(sizeof(node_tree));
    t -> ln = t -> rn = NULL;
    t -> val = value;
    return t;
}

void append_node_tree(node_tree** t, int value){
    if(is_empty(*t)) *t = create_node_tree(value);
    else if(value < (*t)->val) append_node_tree(&(*t)->ln,value);
    else append_node_tree(&((*t)->rn),value);
}

void print_tree(node_tree*t){
    printf("<");
    if(!is_empty(t)){
        printf("%d ",t-> val);
        print_tree(t->ln);
        print_tree(t->rn);
    }
    printf(">");
}

node_tree* search(node_tree*t, int val){
    if(val < t -> val) return search(t->ln,val);
    else if(val == t->val) return t;
    else return search(t->rn,val);
}

node_tree* find_greatest(node_tree* t){
    while(!is_empty(t->rn)) t = t->rn;
    return t;
}

int find_to_pop(node_tree* t){
    if(is_empty(t)) return 0;
    if(is_empty(t->rn)) return 1;
    int iter = 1;
    while(!is_empty(t ->rn->rn)){
        iter++;
        t = t->rn;
    } 
    return iter;
}

void pop(node_tree** t, int value){
    if(is_empty(*t)||(is_empty((*t)->ln) && value < (*t)->val)||(is_empty((*t)->rn) && value > (*t)->val)) return;
    if(value < (*t)->val){
        if(value == (*t)->ln->val){
            int iter = find_to_pop((*t)->ln->ln);
            if(iter == 0){
                free((*t)->ln);
                (*t)->ln = (*t)->ln ->rn;
            } else if(iter == 1){
                (*t)->ln -> val = (*t)->ln -> ln -> val;
                free((*t)->ln -> ln);
                (*t)->ln -> ln = NULL;
            } else{
                node_tree* aux = find_greatest((*t)->ln->ln);
                (*t)->ln -> val = aux -> val;
                free(aux);
            }
        } else pop(&(*t)->ln, value);
    } else if(value > (*t)->val){
        if(value == (*t)->rn->val){

        } else pop(&(*t)->rn, value);
    }
}



int main(){
    node_tree* t = create_tree();
    append_node_tree(&t,5);
    append_node_tree(&t,6);
    append_node_tree(&t,3);
    append_node_tree(&t,4);
    append_node_tree(&t,4);
    append_node_tree(&t,2);
    append_node_tree(&t,2);
    append_node_tree(&t,2);
    
    pop(&t, 2);
    print_tree(t);
    return 0;
}
