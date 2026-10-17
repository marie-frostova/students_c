#ifndef SLIST_H
#define SLIST_H

#include <stdbool.h>
#include <stddef.h>
#include "common.h"

typedef struct s_list_node s_list_node;

typedef struct s_list s_list;

s_list* s_list_create();

void s_list_destroy(void* l);

size_t s_list_size(const s_list* l);

bool s_list_is_empty(const s_list* l);

const s_list_node* s_list_get_node_ref(const s_list* l, size_t index);

const s_list_node* s_list_get_dummy_ref(const s_list* l);

int s_list_get_data(const s_list_node* node, int* out);

int s_list_insert_next(s_list* l, s_list_node* node, const int in);

int s_list_insert_prev(s_list* l, s_list_node* node, const int in);

int s_list_remove(s_list* l, s_list_node* node);

void s_list_print(const s_list* l);

#endif