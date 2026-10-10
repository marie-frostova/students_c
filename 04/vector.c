//Вячеслав
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/*======== VECTOR ========*/

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 2

//copy with value semantics
typedef void* (*vector_copy_fn)(const void* src);
typedef void  (*vector_destroy_fn)(void* elem);
typedef void  (*vector_print_fn)(const void* elem);

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
    vector_copy_fn copy;
    vector_destroy_fn destroy;
} vector;

typedef struct {
    vector* vector;
    size_t index;
} vector_iter;

vector* vector_create(vector_copy_fn copy, vector_destroy_fn destroy) {
    vector* v = (vector *)malloc(sizeof(vector));

    if (!v) return NULL;

    void** data = malloc(INITIAL_CAPACITY*sizeof(void*));

    if (!data) {
        free(v);
        return NULL;
    }
    
    v->data = data;
    v->capacity = INITIAL_CAPACITY; 
    v->size = 0;
    v->copy = copy;
    v->destroy = destroy;
    return v;
}

int vector_realloc(vector* v) {
    if (!v) return 1;
    if (v->capacity > SIZE_MAX / sizeof(void*) / GROWTH_FACTOR) return 1;

    void* attempt = (void*)realloc(v->data, sizeof(void*)*v->capacity*GROWTH_FACTOR);

    if (!attempt) return 1;

    v->data = attempt;
    v->capacity *= GROWTH_FACTOR;

    return 0;
}

void vector_destroy(vector* v) {
    if (!v || !v->data) return;
    for (int i = 0; i < v->size; i++) {
        v->destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}

//to use in vector of vectors
void vector_destroy_void(void* v) {
    vector_destroy((vector*)v);
}

//public destructor to use after pop/remove/get
void vector_destroy_elem(const vector* v, void* elem) {
    if (!v || !elem) {
        return;
    }
    v->destroy(elem);
}

size_t vector_size(const vector* v) {
    if (!v) {
        return 0;
    }
    return v->size;
}

size_t vector_capacity(const vector* v) {
    if (!v) {
        return 0;
    }
    return v->capacity;
}

int vector_is_empty(const vector* v) {
    if (!v) {
        return 1;
    }
    return v->size == 0;
}

int vector_push_back(vector* v, const void* elem) {
    if (!v) return 1;
    if (!elem) {
        return 1;
    }
    if (v->size == v->capacity) {
        if (vector_realloc(v)) return 1;
    }
    void* check = v->copy(elem);
    if (!check) {
        return 1;
    }
    v->data[v->size++] = check;
    return 0;
}

int vector_insert(vector* v, size_t index, const void* elem) {
    if (!v || index > v->size) return 1;
    if (!elem) {
        return 1;
    }
    memmove(v->data+index+1, v->data+index, sizeof(void*)*(v->size-index));
    void* check = v->copy(elem);
    if (!check) {
        return 1;
    }
    v->data[index] = check;
    v->size++;
    return 0;
}

//caller should use vector_destroy_elem(v, out)
int vector_pop_back(vector* v, void** out) {
    if (!v || v->size==0 || !out) return 1;
    if (!out) return 1;
    v->size--;
    void* check = v->copy(v->data[v->size]);
    if (!check) {
        return 1;
    }
    *out = check;
    v->destroy(v->data[v->size]);
    return 0;
}

int vector_pop_back_destroy(vector* v) {
    if (!v || v->size == 0) return 1;
    v->size--;
    return 0;
}

//caller should use vector_destroy_elem(v, out)
int vector_remove(vector* v, size_t index, void** out) {
    if (!v || index >= v->size || !out) return 1;
    memmove(v->data+index, v->data+index+1, sizeof(void*)*(v->size-index-1));
    *out = v->copy(v->data[index]);
    v->destroy(v->data[index]);
    v->size--;
    return 0;    
}

int vector_remove_destroy(vector* v, size_t index) {
    if (!v || index >= v->size) return 1;
    memmove(v->data+index, v->data+index+1, sizeof(void*)*(v->size-index-1));
    v->destroy(v->data[index]);
    v->size--;
    return 0; 
}

void vector_clear(vector* v) {
    if (!v) return;
    for (int i = 0; i < v->size; i++) {
        v->destroy(v->data[i]);
    }
    v->size = 0;
}

//caller should use vector_destroy_elem(v, out)
int vector_get_copy(const vector* v, size_t index, void** out) {
    if (!v || !out) return 1;
    if (index >= v->size) return 1;
    void* check = v->copy(v->data[index]);
    if (!check) {
        return 1;
    }
    *out = check;
    return 0;
}

//readonly access without copying
const void* vector_get_ref(const vector* v, size_t index) {
    if (!v) return NULL;
    if (index >= v->size) return NULL;
    return v->data[index];
}

int vector_set(vector* v, size_t index, const void* in) {
    if (!v || index >= v->size) return 1;
    void* js = v->copy(v->data[index]);
    if (!js) return 1;
    v->destroy(v->data[index]);
    v->data[index] = js;
}

void* vector_copy(const void* v) {
    if (!v) {
        return NULL;
    }
    vector* fst;
    vector* js = (vector*)v;
    fst = vector_create(js->copy, js->destroy);
    if (!fst) {
        return NULL;
    }
    for (int i = 0; i < js->size; i++) {
        vector_push_back(fst, js->data[i]);
    }
}

void vector_print(const vector* v, vector_print_fn print_elem) {
    if (!v) return;
    for (int i = 0; i < v->size; i++) {
        print_elem(v->data[i]);
    }
    return;
}

/*======== ITERATORS ========*/

vector_iter vector_begin(vector* v) {
    vector_iter iter;
    iter.vector = v;
    iter.index = 0;
    return iter;
}

vector_iter vector_end(vector* v) {
    vector_iter iter;
    iter.vector = v;
    iter.index = v->size;
    return iter;
}

vector_iter vector_next(vector_iter it) {
    it.index++;
    return it;
}

int vector_iter_is_equal(vector_iter a, vector_iter b) {
    return a.index == b.index && a.vector == b.vector;
}

int vector_iter_is_end(vector_iter it) {
    return it.index == it.vector->size;
}

void* vector_iter_get(vector_iter it) {
    return it.vector->data[it.index];
}

/*======== INT VECTOR ========*/

void* int_copy(const void* src) {
    if (!src) return NULL;
    int* new_int = (int*)malloc(sizeof(int));
    if (!new_int) return NULL;
    *new_int = *(const int*)src;
    return new_int;
}

void int_destroy(void* elem) {
    free(elem);
}

void int_print(const void* elem) {
    if (elem) printf("%d", *(const int*)elem);
}

void test_int_vector(void) {
    vector* v = vector_create(int_copy, int_destroy);
    if (!v) return;

    for (int i = 0; i < 20; i++)
        vector_push_back(v, &i);

    vector_print(v, int_print);

    printf("Vector size: %zu\n", vector_size(v));
    printf("Vector capacity: %zu\n", vector_capacity(v));
    printf("Vector is empty: %d\n", vector_is_empty(v));

    for (int i = 0; i < 10; i++) {
        int* val = NULL;
        if (vector_pop_back(v, (void**)&val) == 0) {
            printf("Popped value: %d\n", *val);
            vector_destroy_elem(v, val);
        }
    }

    vector_print(v, int_print);

    int val1 = 1000, val2 = 2000, val3 = 3000;
    vector_insert(v, 0, &val1);
    vector_insert(v, vector_size(v) >> 1, &val2);
    vector_insert(v, vector_size(v), &val3);

    vector_print(v, int_print);

    int* val = NULL;
    vector_remove(v, 0, (void**)&val);
    vector_destroy_elem(v, val);
    vector_remove(v, vector_size(v) >> 1, (void**)&val);
    vector_destroy_elem(v, val);
    vector_remove(v, vector_size(v) - 1, (void**)&val);
    vector_destroy_elem(v, val);

    vector_print(v, int_print);

    vector_get_copy(v, 2, (void**)&val);
    printf("Vector item at index 2: %d\n", *val);
    vector_destroy_elem(v, val);

    vector_set(v, 2, &val1);
    printf("Vector item at index 2: %d\n", *(const int*)vector_get_ref(v, 2));

    vector_iter iter = vector_begin(v);
    while (!vector_iter_is_end(iter)) {
        int* vall = (int*)vector_iter_get(iter);
        printf("Val: %d\n", *vall);
        iter = vector_next(iter);
    }

    vector_clear(v);
    vector_destroy(v);
}

/*======== STRING VECTOR ========*/

typedef char* str;

char* str_dup(const char* src) {
    if (!src) return NULL;
    size_t len = strlen(src) + 1;
    char* dst = (char*)malloc(len);
    if (!dst) return NULL;
    memcpy(dst, src, len);
    return dst;
}

void* str_copy(const void* src) {
    return str_dup((const char*)src);
}

void str_destroy(void* elem) {
    free(elem);
}

void str_print(const void* elem) {
    if (elem) printf("%s", (const char*)elem);
}

void test_string_vector(void) {
    vector* v = vector_create(str_copy, str_destroy);
    if (!v) return;

    const char* arr_strs[] = {
        "hello", "world", "!", "I", "love", "c", "programming", "language"
    };
    for (size_t i = 0; i < sizeof(arr_strs) / sizeof(arr_strs[0]); i++) {
        vector_push_back(v, arr_strs[i]);
    }

    vector_print(v, str_print);

    str val1 = str_dup("1");
    str val2 = str_dup("123");
    str val3 = str_dup("#");
    vector_insert(v, 0, val1);
    vector_insert(v, vector_size(v) >> 1, val2);
    vector_insert(v, vector_size(v), val3);
    free(val1);
    free(val2);
    free(val3);

    vector_print(v, str_print);

    str s = NULL;
    if (vector_pop_back(v, (void**)&s) == 0) {
        printf("Val: %s\n", s);
        vector_destroy_elem(v, s);
    }

    vector_print(v, str_print);

    vector_remove(v, 0, (void**)&s);
    printf("Val: %s\n", s);
    vector_destroy_elem(v, s);

    vector_remove(v, vector_size(v) >> 1, (void**)&s);
    printf("Val: %s\n", s);
    vector_destroy_elem(v, s);

    vector_remove(v, vector_size(v) - 1, (void**)&s);
    printf("Val: %s\n", s);
    vector_destroy_elem(v, s);

    vector_print(v, str_print);

    str ss = NULL;
    vector_get_copy(v, 2, (void**)&ss);
    printf("Vector item at index 2: %s\n", ss);
    vector_destroy_elem(v, ss);

    str new_val = str_dup("new_value");
    vector_set(v, 2, new_val);
    free(new_val);
    printf("Vector item at index 2: %s\n", (const char*)vector_get_ref(v, 2));

    vector_clear(v);
    vector_destroy(v);
}

/*======== VECTOR VECTOR ========*/

void test_vector_vector(void) {
    vector* v = vector_create(vector_copy, vector_destroy_void);
    if (!v) return;

    vector* inner1 = vector_create(int_copy, int_destroy);
    int a = 1, b = 2, c = 3;
    vector_push_back(inner1, &a);
    vector_push_back(inner1, &b);
    vector_push_back(inner1, &c);

    vector* inner2 = vector_create(int_copy, int_destroy);
    int d = 4, e = 5, f = 6;
    vector_push_back(inner2, &d);
    vector_push_back(inner2, &e);
    vector_push_back(inner2, &f);

    vector_push_back(v, inner1);
    vector_push_back(v, inner2);
    vector_destroy(inner1);
    vector_destroy(inner2);

    vector_iter iter = vector_begin(v);
    while (!vector_iter_is_end(iter)) {
        vector* inner = (vector*)vector_iter_get(iter);
        vector_print(inner, int_print);
        iter = vector_next(iter);
    }

    vector* moved = NULL;
    if (vector_remove(v, 0, (void**)&moved) == 0) {
        printf("Removed inner vector: ");
        vector_print(moved, int_print);
        vector_destroy(moved);
    }

    vector_clear(v);
    vector_destroy(v);
}

/*======== MAIN ========*/

int main() {
    test_int_vector();
    test_string_vector();
    test_vector_vector();
    return 0;
}