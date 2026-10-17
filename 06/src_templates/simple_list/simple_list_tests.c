#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "simple_list.h"
#include "tests.h"

void test_s_list() {
    printf("Testing simple list\n");

    s_list* l = s_list_create();
    assert(l);

    for (int i = 5; i < 10; ++i) {
        s_list_insert_next(l, (s_list_node*)s_list_get_dummy_ref(l), i);
    }
    s_list_print(l);

    assert(s_list_size(l) == 5);

    for (int i = 4; i >= 0; --i) {
        s_list_insert_prev(l, (s_list_node*)s_list_get_dummy_ref(l), i);
    }
    s_list_print(l);
    assert(s_list_size(l) == 10);

    for (int i = 0; i < 10; ++i) {
        const s_list_node* node = (const s_list_node*)s_list_get_node_ref(l, i);
        assert(node);
        int node_data = 0;
        s_list_get_data(node, &node_data);
        assert(node_data == 9 - i);
    }

    for (int i = 0; i < 5; ++i) {
        s_list_remove(l, (s_list_node*)s_list_get_node_ref(l, 0));
    }
    s_list_print(l);
    assert(s_list_size(l) == 5);

    s_list_destroy(l);
}