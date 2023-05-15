#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node *left;
    struct node *right;
} node;

typedef struct tree{
    node *root;
} tree;


tree* create_tree(){
    return NULL;
}

int is_empty(tree** t){
    return (*t)->root == NULL;
}

node* __create_node(int value){
    node *new = calloc(sizeof(node),1);
    new->value = value;
    return new;
}

node* __search_engine(tree** t, int value){
    
}


node* find(tree** t, int value){
    node* searched = __search_engine(t, value);
    if(searched -> value == value) return searched;
    else return NULL;
}

node* __search_father_engine(tree** t, int value){

}

void insert_node(tree** t, int value){
    node *new = __create_node(value);
    if(*t == NULL){
        *t = new;
        return;
    }
    node *current = __search_engine(t,value);
    if(current -> value < value){
        current -> left = new;
    }
    else{
        current -> right = new;
    }
}

void delete_node(tree** t, int value){
    node* aux = find(t, value);
    if(!aux) return;

}

void simmetric(tree* t){}

void pre_order(tree* t){}

void post_order(tree* t){}