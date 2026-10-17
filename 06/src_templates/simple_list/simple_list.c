#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

struct s_list_node {
    int data;
    s_list_node* next;
    s_list_node* prev;
    s_list* owner;
};

struct s_list {
    s_list_node* dummy;
    size_t size;
};

static s_list_node* s_list_node_create(s_list* l, int data, s_list_node* next, s_list_node* prev) {
    //TODO
}

static void s_list_node_destroy(s_list_node* node) {
    //TODO
}

s_list* s_list_create() {
    //TODO
}

void s_list_destroy(void* l) {
    //TODO
}

size_t s_list_size(const s_list* l) { return l ? l->size : 0; }

bool s_list_is_empty(const s_list* l) { return l ? l->size == 0 : true; }

const s_list_node* s_list_get_node_ref(const s_list* l, size_t index) {
    //TODO
}

const s_list_node* s_list_get_dummy_ref(const s_list* l) { return l ? l->dummy : NULL; }

int s_list_get_data(const s_list_node* node, int* out) {
    //TODO
}

int s_list_insert_next(s_list* l, s_list_node* node, const int in) {
    //TODO
}

int s_list_insert_prev(s_list* l, s_list_node* node, const int in) {
    //TODO
}

int s_list_remove(s_list* l, s_list_node* node) {
    //TODO
}

void s_list_print(const s_list* l) {
    //TODO
}