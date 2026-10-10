#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <stdbool.h>
#include <stddef.h>
#include "common.h"

/*
Generic double-ended queue on a FIXED-SIZE circular buffer.

The capacity is set at creation and never changes.
push_* returns 1 when the dequeue is full.

Ownership model:
    - If copy is set, the dequeue stores COPIES of elements produced by copy, and calls destroy on each stored copy when removed / on destroy.
    - If copy is NULL, the dequeue stores the caller's pointers as-is (shallow mode, caller owns the elements).
    - If destroy is NULL, stored elements are never freed by the dequeue.

Error codes:
    - Functions returning int: 0 = success, 1 = failure.
    - On failure, the dequeue is left unchanged (strong guarantee).

NULL elements:
    - NULL is a valid element if copy handles it (see int_copy).
    - Use the *_copy / *_ref variants with a status code to distinguish "empty dequeue" from "element is NULL".
*/

typedef struct dequeue {
    void** data;
    size_t size;
    size_t capacity;
    size_t front_ind;
    size_t back_ind;
    copy_fn copy;
    destroy_fn destroy;
} dequeue;

/*======== LIFECYCLE ========*/

dequeue* dequeue_create(size_t capacity, copy_fn copy, destroy_fn destroy);

void dequeue_destroy(dequeue* dq);

dequeue* dequeue_copy(const dequeue* dq);

/*======== SIZE / STATE ========*/

size_t dequeue_size(const dequeue* dq);

size_t dequeue_capacity(const dequeue* dq);

bool dequeue_is_empty(const dequeue* dq);

bool dequeue_is_full(const dequeue* dq);

/*======== ACCESS: COPY ========*/

int dequeue_front_copy(const dequeue* dq, void** out);

int dequeue_back_copy(const dequeue* dq, void** out);

/*======== ACCESS: REF ========*/

int dequeue_front_ref(const dequeue* dq, const void** out);

int dequeue_back_ref(const dequeue* dq, const void** out);

/*======== PUSH ========*/

int dequeue_push_front(dequeue* dq, const void* in);

int dequeue_push_back(dequeue* dq, const void* in);

/*======== POP: COPY ========*/

int dequeue_pop_front_copy(dequeue* dq, void** out);

int dequeue_pop_back_copy(dequeue* dq, void** out);

/*======== POP: DESTROY ========*/

int dequeue_pop_front(dequeue* dq);

int dequeue_pop_back(dequeue* dq);

/*======== OTHER ========*/

void dequeue_clear(dequeue* dq);

void dequeue_print(const dequeue* dq, print_fn print);

#endif
