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

