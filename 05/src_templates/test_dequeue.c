#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"

void test_string_dequeue(void) {
    printf("Testing String Dequeue:\n");

    dequeue* dq = dequeue_create(4, string_copy, string_destroy);

    const char* strs[] = {"one", "two", "three", "four"};
    for (int i = 0; i < 4; i++) {
        if (dequeue_push_back(dq, strs[i]) != 0)
            printf("push %s failed\n", strs[i]);
    }
    printf("size=%zu cap=%zu full=%d\n", dequeue_size(dq), dequeue_capacity(dq), dequeue_is_full(dq));

    dequeue_print(dq, string_print);

    const char* v = "five";
    if (dequeue_push_back(dq, &v) != 0)
        printf("push_back on full -> rejected\n");

    dequeue_pop_front(dq);
    dequeue_push_back(dq, &v);
    dequeue_print(dq, string_print);

    char* p = NULL;
    if (dequeue_front_copy(dq, (void**)&p) == 0) {
        printf("front=%s\n", p);
        free(p);
    }

    dequeue_destroy(dq);
    printf("=====================\n");
}

void test_int_dequeue(void) {
    printf("Testing Int Dequeue:\n");

    dequeue* dq = dequeue_create(4, int_copy, int_destroy);

    for (int i = 1; i <= 4; i++) {
        if (dequeue_push_back(dq, &i) != 0)
            printf("push %d failed\n", i);
    }
    printf("size=%zu cap=%zu full=%d\n", dequeue_size(dq), dequeue_capacity(dq), dequeue_is_full(dq));

    dequeue_print(dq, int_print);

    int v = 99;
    if (dequeue_push_back(dq, &v) != 0)
        printf("push_back on full -> rejected\n");

    dequeue_pop_front(dq);
    dequeue_push_back(dq, &v);
    dequeue_print(dq, int_print);

    int* p = NULL;
    if (dequeue_front_copy(dq, (void**)&p) == 0) {
        printf("front=%d\n", *p);
        free(p);
    }

    dequeue_destroy(dq);
    printf("=====================\n");
}