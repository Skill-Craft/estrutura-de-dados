#include <stdio.h>
#include <stdlib.h>


typedef struct linked node;
struct linked {
    int value;
    node *next;
    int index;
};

typedef struct list{
    node *head;
    node *end;
    int size;
} list;


node* create_node(int val,int index){
    node * new_node = (node *)malloc(sizeof(node));
    new_node->value = val;
    new_node -> index = index;
    new_node->next = NULL;
    return new_node;
}

list* create_list(){
    list* lista = (list*)malloc(sizeof(list));
    lista->head = lista-> end = NULL;
    lista -> size = 0;
    return lista;
} 

void free_list(list* lista){
    node* aux = lista -> head;
    node* prox = aux;
    while(prox != NULL){
        aux = prox;
        prox = aux -> next;
        free(aux);
    }
    free(aux);
    lista -> head = lista -> end = NULL;
    free(lista);
}

list* append(list* lista, int val){
    lista->size++;
    node *new_node = create_node(val,lista->size-1);
    if(lista->head==NULL){
        lista->head = new_node;
    }
    else{
        node* atual = lista-> head;
        while(atual -> next !=NULL){
            atual = atual-> next;
        }
        atual -> next = new_node;
    }
    lista -> end = new_node;
    return lista;
}


list* reindex_elements(list* lista, int start, int end){
    if(start < 0 || end > lista-> size){
        return lista;
    }
    node* aux = lista-> head;
    int factor = 0;
    for(int i = 0;i<start;i++){
        aux = aux -> next;
    }
    for(int i = start;i<end;i++){
        aux -> index = i;
        aux = aux -> next;
    }
    return lista;
}

list* append_from_end(list* lista, int val){
    lista -> size++;
    node *new_node = create_node(val,lista->size-1);
    if(lista->head==NULL){
        lista->head = new_node;
    }
    else{
        node *last = lista -> end;
        last -> next = new_node;
    }
    lista -> end = new_node; 
    return lista;
}

list* append_middle(list* lista, int val, int index){
    if(index < 0 || index > lista -> size){
        printf("Valor de index invalido\n");
        return lista;
    }
    lista -> size++;
    node* new_node = create_node(val,index);
    node* aux = lista -> head;
    for(int i=0;i<index-1;i++){
        aux = aux->next;
    }
    node* prox = aux -> next;
    aux -> next = new_node;
    new_node -> next = prox;
    reindex_elements(lista,index,lista->size);
    return lista;
}

list* initialize_list(list* lista, int n){
    node *atual;
    for(int i = 0; i<n; i++){
        int valor = 0;
        printf("insira o valor %d valor da lista ", i+1);
        scanf("%d", &valor);
        printf("\n");
        lista = append_from_end(lista,valor);
        if(i == 0){
            atual = lista -> head;
        }
        else{
            atual = atual -> next;
        }
    }
    return lista;
}

void print_list(list* lista){
    node *aux = lista->head;
    while(aux!=NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    return;
}

list* pop(list* lista, int val){
    node *aux = lista->head;
    if(lista-> size == 0){
        return lista;
    }
    if(aux -> value ==val){
        lista -> size--;
        lista -> head = aux -> next;
        reindex_elements(lista,0,lista->size);
        return lista;
    }
    while(aux->next!=NULL){
        if(aux->next->value == val){
            lista -> size--;
            node *rem = aux->next;
            int i = aux -> index;
            aux -> next = rem -> next;
            reindex_elements(lista,i,lista->size);
            free(rem);
            return lista;
        }
        aux = aux->next;
    }
    return lista;
}

int index(list* lista, int val){
    node *aux = lista->head;
    while(!(aux == NULL || aux -> next == NULL) && aux->value != val){
        aux = aux->next;
    }
    if(aux == NULL || (aux->next == NULL && aux->value !=val)){
        return -1;
    }
    else{
        return aux->index;
    }
}


int main(){
    printf("insira o tamanho da lista: ");
    int n = 0;
    scanf("%d",&n);
    list* lista = create_list();
    lista = initialize_list(lista, n);
    // lista = append_middle(lista,1,3);
    print_list(lista);
    // print_list(lista);
    // lista = pop(lista, 4);
    // printf("\n");
    // print_list(lista);
    // printf("\n");
    // printf("%d", index(lista, 5));
    free_list(lista);
    printf("\na\n");
    // print_list(lista);
    return 0;
}