#include <stdio.h>
#include <stdlib.h>


typedef struct stack{
    int value;
    int flag;
    struct stack* prev;
} stack;

stack* create_stack(){
    stack* s = (stack*)malloc(sizeof(stack));
    s-> prev = NULL;
    int flag=1;
    return s;
}

void append(stack** s, int val){
    stack* aux = create_stack();
    aux -> value = val;
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

size_t size(stack* s){
    size_t counter = 1;
    while(!(s->flag)){
        counter++;
        s = s->prev;
    }
    return counter-1;
}

int main(){
    stack* s = create_stack();
    append(&s,1);
    append(&s,12);
    append(&s,3);
    pop(&s);
    pop(&s);
    int v = pop(&s);
    printf("%d",v);
    return 0;
}