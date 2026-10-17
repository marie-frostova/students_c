#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*copy_fn)(const void* src, void** out);
typedef void (*destroy_fn)(void* item);
typedef void (*print_fn)(const void* item);

static inline int int_copy(const void* src, void** out) {
    if (!out) return 1;
    if (!src) {
        *out = NULL;
        return 0;
    }

    int* p = (int*)malloc(sizeof(int));
    if (!p) return 1;
    *p = *(const int*)src;
    *out = p;
    return 0;
}

static inline void int_destroy(void* elem) {
    free(elem);
}

static inline void int_print(const void* elem) {
    if (elem)
        printf("%d ", *(const int*)elem);
    else
        printf("NULL ");
}

static inline int char_copy(const void* src, void** out) {
    if (!out) return 1;
    if (!src) {
        *out = NULL;
        return 0;
    }

    char* p = (char*)malloc(sizeof(char));
    if (!p) return 1;
    *p = *(const char*)src;
    *out = p;
    return 0;
}

static inline void char_destroy(void* elem) {
    free(elem);
}

static inline void char_print(const void* elem) {
    if (elem)
        printf("%c ", *(const char*)elem);
    else
        printf("NULL ");
}

static inline int string_copy(const void* src, void** out) {
    if (!out) return 1;
    if (!src) {
        *out = NULL;
        return 0;
    }

    const char* s = (const char*)src;
    char* p = strdup(s);
    if (!p) return 1;
    *out = p;
    return 0;
}

static inline void string_destroy(void* elem) {
    free(elem);
}

static inline void string_print(const void* elem) {
    if (elem)
        printf("%s ", (const char*)elem);
    else
        printf("NULL ");
}

#endif