#include <stdio.h>
#include <stdlib.h>


typedef struct stack{
    int value;
    int flag;
    size_t size;
    struct stack* prev;
} stack;

stack* create_stack(){
    stack* s = (stack*)malloc(sizeof(stack));
    s-> prev = NULL;
    s-> flag=1;
    s-> size = 0;
    return s;
}

void append(stack** s, int val){
    stack* aux = create_stack();
    aux -> value = val;
    aux -> size = (*s)->size+1;
    aux -> flag = 0;
    aux -> prev = *s;
    *s = aux;
}

int top(stack* s){
    return s->value;
}

int pop(stack** s){
    if((*s) -> flag) return -1;
    stack* aux = *s;
    int val = aux->value;
    *s = (*s)-> prev;
    free(aux);
    return val;
}

int find(stack* s, int key){
    size_t size = s->size;
    while(!(s->flag)){
        if(s->value == key) return size - s->size + 1;
        s = s->prev;
    }
}

size_t size(stack* s){
    return s->size;
}

int main(){
    stack* s = create_stack();
    append(&s,1);
    append(&s,12);
    append(&s,3);
    append(&s,35);
    append(&s,346);
    append(&s,31);
    int v = find(s,35);
    // pop(&s);
    // pop(&s);
    // size_t sz = size(s);
    // int v = pop(&s);
    printf("%d",v);
    return 0;
}