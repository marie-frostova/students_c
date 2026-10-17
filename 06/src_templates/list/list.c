#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list_node {
    void* data;
    list_node* next;
    list_node* prev;
    list* owner;
};

struct list {
    list_node* dummy;
    size_t size;
    copy_fn copy;
    destroy_fn destroy;
};

static int list_node_data_copy(list* l, const void* src, void** out) {
    if (!l || !out) return 1;
    if (!l->copy) {
        *out = (void*)src;
        return 0;
    }
    return l->copy(src, out);
}

static void list_node_data_destroy(list* l, void* data) {
    if (!l || !data) return;
    if (l->destroy) l->destroy(data);
}

static list_node* list_node_create(list* l, const void* data, list_node* next, list_node* prev) {
    //TODO
}

static void list_node_destroy(list* l, list_node* node) {
    //TODO
}

list* list_create(copy_fn copy, destroy_fn destroy) {
    //TODO
}

void list_destroy(void* l) {
    //TODO
}

void* list_copy(const void* src) {
    //TODO
}

size_t list_size(const list* l) { return l ? l->size : 0; }

bool list_is_empty(const list* l) { return l ? l->size == 0 : true; }

const list_node* list_get_node_ref(const list* l, size_t index) {
    //TODO
}

const list_node* list_get_dummy_ref(const list* l) { return l ? l->dummy : NULL; }

const void* list_get_data_ref(const list_node* node) { return node ? node->data : NULL; }

int list_insert_next(list* l, list_node* node, const void* in) {
    //TODO
}

int list_insert_prev(list* l, list_node* node, const void* in) {
    //TODO
}

int list_remove(list* l, list_node* node) {
    //TODO
}

void list_print(const list* l, print_fn print) {
    //TODO
}