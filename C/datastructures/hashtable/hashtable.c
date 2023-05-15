#include <stdio.h>
#include <stdlib.h>


typedef struct ht{
    char* key;
    int value;
    size_t hashed_key;
} hash_table;


size_t hash(char* s){
    char c = s[0];
    int* v = (int*)malloc(sizeof(strlen(s))); // hashing will append ASCII values of each character as if it is a string
    while(c != '\0'){

    } 
}



