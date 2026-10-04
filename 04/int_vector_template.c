#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/*======== INT VECTOR ========*/

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} int_vector;

typedef struct {
    int_vector* vector;
    size_t index;
} int_vector_iter;

int_vector* int_vector_create(void) {
    //TODO
}

int int_vector_realloc(int_vector* v) {
    //TODO
}

void int_vector_destroy(int_vector* v) {
    //TODO
}

size_t int_vector_size(const int_vector* v) {
    //TODO
}

size_t int_vector_capacity(const int_vector* v) {
    //TODO
}

int int_vector_is_empty(const int_vector* v) {
    //TODO
}

int int_vector_push_back(int_vector* v, int elem) {
    //TODO
}

int int_vector_insert(int_vector* v, size_t index, int elem) {
    //TODO
}

int int_vector_pop_back(int_vector* v, int* out) {
    //TODO
}

int int_vector_remove(int_vector* v, size_t index, int* out) {
    //TODO
}

void int_vector_clear(int_vector* v) {
    //TODO
}

int int_vector_get(const int_vector* v, size_t index, int* out) {
    //TODO
}

const int* int_vector_get_ref(const int_vector* v, size_t index) {
    //TODO
}

int int_vector_set(int_vector* v, size_t index, int in) {
    //TODO
}

int_vector* int_vector_copy(const int_vector* v) {
    //TODO
}

void int_vector_print(const int_vector* v) {
    //TODO
}

/*======== ITERATORS ========*/

int_vector_iter int_vector_begin(int_vector* v) {
    //TODO
}

int_vector_iter int_vector_end(int_vector* v) {
    //TODO
}

int_vector_iter int_vector_next(int_vector_iter it) {
    //TODO
}

int int_vector_iter_is_equal(int_vector_iter a, int_vector_iter b) {
    //TODO
}

int int_vector_iter_is_end(int_vector_iter it) {
    //TODO
}

int* int_vector_iter_get(int_vector_iter it) {
    //TODO
}

/*======== TEST ========*/

void test_int_vector(void) {
    int_vector* v = int_vector_create();
    if (!v) return;

    for (int i = 0; i < 20; i++)
        int_vector_push_back(v, i);

    int_vector_print(v);

    printf("Vector size: %zu\n", int_vector_size(v));
    printf("Vector capacity: %zu\n", int_vector_capacity(v));
    printf("Vector is empty: %d\n", int_vector_is_empty(v));

    for (int i = 0; i < 10; i++) {
        int val;
        if (int_vector_pop_back(v, &val) == 0) {
            printf("Popped value: %d\n", val);
        }
    }

    int_vector_print(v);

    int_vector_insert(v, 0, 1000);
    int_vector_insert(v, int_vector_size(v) >> 1, 2000);
    int_vector_insert(v, int_vector_size(v), 3000);

    int_vector_print(v);

    int val;
    int_vector_remove(v, 0, &val);
    int_vector_remove(v, int_vector_size(v) >> 1, &val);
    int_vector_remove(v, int_vector_size(v) - 1, &val);

    int_vector_print(v);

    int_vector_get(v, 2, &val);
    printf("Vector item at index 2: %d\n", val);

    int_vector_set(v, 2, 1000);
    printf("Vector item at index 2: %d\n", *int_vector_get_ref(v, 2));

    int_vector_iter iter = int_vector_begin(v);
    while (!int_vector_iter_is_end(iter)) {
        int* vall = int_vector_iter_get(iter);
        printf("Val: %d\n", *vall);
        iter = int_vector_next(iter);
    }

    int_vector_clear(v);
    int_vector_destroy(v);
}

/*======== MAIN ========*/

int main() {
    test_int_vector();
    return 0;
}