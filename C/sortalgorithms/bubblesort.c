// BUBBLE SORT

#include <stdio.h>
#include <stdlib.h>


void bubble_sort_static_alloc(int* v, int length){
    int swap = 1;
    while(swap){
        swap = 0;
        for(int i = 0; i < length-1; i++){
            if(v[i] > v[i+1]){
                swap = 1;
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}

void bubble_sort_linked_list(int* v, int length){
    
}


int main(){
    int v[]= {1,3,2,4,6,3,5};
    bubble_sort_static_alloc(v,7);
    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    return 0;
}