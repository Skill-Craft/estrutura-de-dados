// SELECTION SORT

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *v, int length){
    for(int i = 0; i < length-1; i++){
        int min = i;
        for(int j = i+1; j < length; j++){
            if(v[j] < v[min]) min = j;
        }
        int aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }

}


int main(){
    int v[]= {1,3,2,4,6,3,5};
    selection_sort(v,7);
    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    return 0;
}