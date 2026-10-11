#include <stdlib.h>
#include <stdio.h>
#include "dequeue.h"

/*======== HELPERS ========*/

static inline size_t ring_add(size_t start, size_t steps, size_t cap) {
    //TODO
}

static inline size_t ring_sub(size_t start, size_t steps, size_t cap) {
    //TODO
}

static int elem_copy(const dequeue* dq, const void* src, void** out) {
    if (!dq->copy) {
        *out = (void*)src;
        return 0;
    }
    return dq->copy(src, out);
}

static void elem_destroy(const dequeue* dq, void* elem) {
    if (dq->destroy && elem) dq->destroy(elem);
}

/*======== LIFECYCLE ========*/

dequeue* dequeue_create(size_t capacity, copy_fn copy, destroy_fn destroy) {
    //TODO
    //check capacity!!!
}

void dequeue_destroy(dequeue* dq) {
    //TODO
    //use elem_destroy to free each element before freeing the data array and the dequeue itself
}

dequeue* dequeue_copy(const dequeue* dq) {
    //TODO
    //use elem_copy to copy each element into the new dequeue from zero index
}

/*======== SIZE / STATE ========*/

size_t dequeue_size(const dequeue* dq) { 
    //TODO 
}

size_t dequeue_capacity(const dequeue* dq) { 
    //TODO 
}

bool dequeue_is_empty(const dequeue* dq) { 
    //TODO 
}

bool dequeue_is_full(const dequeue* dq) { 
    //TODO 
}

/*======== ACCESS: COPY ========*/

int dequeue_front_copy(const dequeue* dq, void** out) {
    //TODO
}

int dequeue_back_copy(const dequeue* dq, void** out) {
    //TODO
}

/*======== ACCESS: REF ========*/

int dequeue_front_ref(const dequeue* dq, const void** out) {
    //TODO
}

int dequeue_back_ref(const dequeue* dq, const void** out) {
    //TODO
}

/*======== PUSH ========*/

int dequeue_push_front(dequeue* dq, const void* in) {
    //TODO
}

int dequeue_push_back(dequeue* dq, const void* in) {
    //TODO
}

/*======== POP: COPY ========*/

int dequeue_pop_front_copy(dequeue* dq, void** out) {
    //TODO
}

int dequeue_pop_back_copy(dequeue* dq, void** out) {
    //TODO
}

/*======== POP: DESTROY ========*/

int dequeue_pop_front(dequeue* dq) {
    //TODO
}

int dequeue_pop_back(dequeue* dq) {
    //TODO
}

/*======== OTHER ========*/

void dequeue_clear(dequeue* dq) {
    //TODO
}

void dequeue_print(const dequeue* dq, print_fn print) {
    //TODO
}