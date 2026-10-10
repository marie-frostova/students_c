#ifndef COMMON_H
#define COMMON_H

typedef int (*copy_fn)(const void* src, void** out);
typedef void (*destroy_fn)(void* elem);
typedef void (*print_fn)(const void* elem);

/*======== NULLABLE INT ========*/

int int_copy(const void* src, void** out);

void int_destroy(void* elem);

void int_print(const void* elem);

/*======== NULLABLE CHAR ========*/

int char_copy(const void* src, void** out);

void char_destroy(void* elem);

void char_print(const void* elem);

/*======== NULLABLE STRING ========*/

int string_copy(const void* src, void** out);

void string_destroy(void* elem);

void string_print(const void* elem);

#endif