#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>
#include "common.h"

typedef struct list_node list_node;

typedef struct list list;

list* list_create(copy_fn copy, destroy_fn destroy);

void list_destroy(void* l);

void* list_copy(const void* src);

size_t list_size(const list* l);

bool list_is_empty(const list* l);

const list_node* list_get_node_ref(const list* l, size_t index);

const list_node* list_get_dummy_ref(const list* l);

const void* list_get_data_ref(const list_node* node);

int list_insert_next(list* l, list_node* node, const void* in);

int list_insert_prev(list* l, list_node* node, const void* in);

int list_remove(list* l, list_node* node);

void list_print(const list* l, print_fn print);

#endif