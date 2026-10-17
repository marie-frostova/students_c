#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "tests.h"

void test_list() {
    printf("Testing list\n");

    list* l = list_create(int_copy, int_destroy);
    assert(l);

    for (int i = 5; i < 10; ++i) {
        list_insert_next(l, (list_node*)list_get_dummy_ref(l), &i);
    }
    list_print(l, int_print);

    assert(list_size(l) == 5);

    for (int i = 4; i >= 0; --i) {
        list_insert_prev(l, (list_node*)list_get_dummy_ref(l), &i);
    }
    list_print(l, int_print);
    assert(list_size(l) == 10);

    for (int i = 0; i < 10; ++i) {
        const list_node* node = (const list_node*)list_get_node_ref(l, i);
        assert(node);
        const int* node_data = (const int*)list_get_data_ref(node); 
        assert(*node_data == 9 - i);
    }

    for (int i = 0; i < 5; ++i) {
        list_remove(l, (list_node*)list_get_node_ref(l, 0));
    }
    list_print(l, int_print);
    assert(list_size(l) == 5);

    list_destroy(l);
}