#include <stdio.h>
#include <stdlib.h>


void merge_sort(int *v, int len){
    if(len > 2){
        merge_sort(v, len/2);
        merge_sort(v+len/2, len/2);
    } if(len == 2){
        if(v[0] > v[1]){
            int temp = v[0];
            v[0] = v[1];
            v[1] = temp;
        } 
    }
}

int* merge_arrays(int*v1, int*v2){

}

int main(){
    int v[6] = {0,1,2,3,4,5};
    merge_sort(v, 6);
    for(int i=0; i<6; i++) printf("%d ", v[i]);
    return 0;
}

