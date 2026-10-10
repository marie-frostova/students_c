#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*======== NULLABLE INT ========*/

int int_copy(const void* src, void** out) {
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

void int_destroy(void* elem) {
    free(elem);
}

void int_print(const void* elem) {
    if (elem)
        printf("%d ", *(const int*)elem);
    else
        printf("NULL ");
}

/*======== NULLABLE CHAR ========*/

int char_copy(const void* src, void** out) {
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

void char_destroy(void* elem) {
    free(elem);
}

void char_print(const void* elem) {
    if (elem)
        printf("%c ", *(const char*)elem);
    else
        printf("NULL ");
}

/*======== NULLABLE STRING ========*/

int string_copy(const void* src, void** out) {
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

void string_destroy(void* elem) {
    free(elem);
}

void string_print(const void* elem) {
    if (elem)
        printf("%s ", (const char*)elem);
    else
        printf("NULL ");
}