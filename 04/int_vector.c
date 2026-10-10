//Михаил
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
    int_vector* v = (int_vector *)malloc(sizeof(int_vector));

    if (!v) return NULL;

    int *data = malloc(INITIAL_CAPACITY*sizeof(int));

    if (!data) {
        free(v);
        return NULL;
    }
    
    v->data = data;
    v->capacity = INITIAL_CAPACITY; 
    v->size = 0;

    return v;
}

int int_vector_realloc(int_vector* v) {
    if (!v) return 1;
    if (v->capacity > SIZE_MAX / sizeof(int) / GROWTH_FACTOR) return 1;

    int* attempt = (int*)realloc(v->data, sizeof(int)*v->capacity*GROWTH_FACTOR);

    if (!attempt) return 1;

    v->data = attempt;
    v->capacity *= GROWTH_FACTOR;

    return 0;
}

void int_vector_destroy(int_vector* v) {
    if (!v) return;
    free(v->data);
    free(v);
}

size_t int_vector_size(const int_vector* v) {
    if (!v) return 0;
    return v->size;
}

size_t int_vector_capacity(const int_vector* v) {
    if (!v) return 0;
    return v->capacity;
}

int int_vector_is_empty(const int_vector* v) {
    if (!v) return 1;
    return v->size == 0;
}

int int_vector_push_back(int_vector* v, int elem) {
    if (!v) return 1;

    if (v->size == v->capacity) {
        if (int_vector_realloc(v)) return 1;
    }

    v->data[v->size++] = elem;

    return 0;
}

int int_vector_insert(int_vector* v, size_t index, int elem) {
    if (!v || index > v->size) return 1;

    memmove(v->data+index+1, v->data+index, sizeof(int)*(v->size-index));

    v->data[index] = elem;
    v->size++;

    return 0;
}

int int_vector_pop_back(int_vector* v, int* out) {
    if (!v || v->size==0 || !out) return 1;

    v->size--;
    *out = v->data[v->size];

    return 0;
}

int int_vector_remove(int_vector* v, size_t index, int* out) {
    if (!v || index >= v->size || !out) return 1;

    memmove(v->data+index, v->data+index+1, sizeof(int)*(v->size-index-1));

    *out = v->data[index];
    v->size--;

    return 0;
}

void int_vector_clear(int_vector* v) {
    if (!v) return;
    v->size = 0;
}

int int_vector_get(const int_vector* v, size_t index, int* out) {
    if (!v || index >= v->size || !out) return 1;

    *out = v->data[index];

    return 0;
}

const int* int_vector_get_ref(const int_vector* v, size_t index) {
    if (!v) return NULL;
    return v->data+index;
}

int int_vector_set(int_vector* v, size_t index, int in) {
    if (!v || index >= v->size) return 1;

    v->data[index] = in;

    return 0;
}

int_vector* int_vector_copy(const int_vector* v) {
    if (!v) return NULL;

    int_vector* vector_copy = int_vector_create();

    for (int i = 0; i < v->size; i++) {
        int_vector_push_back(vector_copy, v->data[i]);
    }

    return vector_copy;
}

void int_vector_print(const int_vector* v) {
    if (!v) return;
    printf("{data = [");

    for (int i = 0; i < v->size - 1; i++) {
        printf("%d, ", v->data[i]);
    }
    
    printf("%d], ", v->data[v->size-1]);

    printf("capacity = %zu, ", v->capacity);
    printf("size = %zu}\n", v->size);
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
    printf("Got item from index 2: %d\n", val);

    int_vector_set(v, 2, 1000);
    printf("Set item at index 2: %d\n", *int_vector_get_ref(v, 2));

    int_vector_clear(v);
    int_vector_destroy(v);
    
}

/*======== MAIN ========*/

int main() {
    test_int_vector();
    return 0;
}