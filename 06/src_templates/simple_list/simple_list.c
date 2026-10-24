#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

typedef struct s_list_node {
    int data;
    struct s_list_node* next;
    struct s_list_node* prev;
    s_list* owner;
} s_list_node; 

struct s_list {
    s_list_node* dummy;
    size_t size;
};

static s_list_node* s_list_node_create(s_list* l, int data, s_list_node* next, s_list_node* prev) {
    s_list_node* res = malloc(sizeof(s_list_node));
    if(res==NULL){
        return NULL;
    }
    res->data = data;
    res->next = next;
    res->prev = prev;
    res->owner = l; 
    return res;
}

static void s_list_node_destroy(s_list_node* node) {
    free(node);
}

s_list* s_list_create() {
    s_list* res = malloc(sizeof(s_list));
    res->size = 0;
    res->dummy = s_list_node_create(res, 0, NULL, NULL);
    res->dummy->next = res->dummy->prev = res->dummy;
    return res;
}

void s_list_destroy(void* l) {
    s_list *list = l;
    s_list_node *fstnode = list->dummy;
    for (int i = 0; i <= list->size; i++) {
        s_list_node* next = fstnode->next;
        s_list_node_destroy(fstnode);
        fstnode = next;
    }
    free(list);
}

size_t s_list_size(const s_list* l) { return l ? l->size : 0; }

bool s_list_is_empty(const s_list* l) { return l ? l->size == 0 : true; }

const s_list_node* s_list_get_node_ref(const s_list* l, size_t index) {
    if (index >= l->size) {
        return NULL; 
    }
    s_list_node *cur_node = l->dummy->next;
    for (int i = 0; i < index; i++) {
        cur_node = cur_node->next;
    }
    return cur_node;
}

const s_list_node* s_list_get_dummy_ref(const s_list* l) { return l ? l->dummy : NULL; }

int s_list_get_data(const s_list_node* node, int* out) {
    if(!node){
        return 1;
    }
     *out = node->data;
     return 0;
}

int s_list_insert_next(s_list* l, s_list_node* node, const int in) {
    s_list_node* new_node = s_list_node_create(l, in, node -> next, node);
    if(!new_node){
        return 1;
    }
    node->next->prev = new_node; 
    node->next = new_node;
    l->size++;
    
    return 0;
    
}

int s_list_insert_prev(s_list* l, s_list_node* node, const int in) {
    s_list_node* new_node = s_list_node_create(l, in, node, node->prev);
    if(!new_node){
        return 1;
    }
    
    node->prev->next = new_node; 
    node->prev = new_node;
    l->size++;
    
    return 0;
}

int s_list_remove(s_list* l, s_list_node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    
    s_list_node_destroy(node);
    l->size--;
    return 0;
}

void s_list_print(const s_list* l) {
    for (s_list_node* cur = l->dummy->next; cur != l->dummy; cur = cur->next) {
        printf("%d \n", cur->data);
    }
}