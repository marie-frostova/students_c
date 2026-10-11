#include <stdlib.h>
#include <stdio.h>
#include "dequeue.h"

/*======== HELPERS ========*/

static inline size_t ring_add(size_t start, size_t steps, size_t cap) {
    return (start + steps) % cap;
}

static inline size_t ring_sub(size_t start, size_t steps, size_t cap) {
    return (start + cap - steps) % cap;
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
    if (!capacity) return NULL;
    dequeue* d = (dequeue*)malloc(sizeof(dequeue));
    if(!d)
    {
        return NULL;
    }
    d->data = (void*)calloc(capacity, sizeof(void*));
    if(!d->data) {
        free(d);
        return NULL;
    }
    d->capacity = capacity;
    d->size = 0;
    d->back_ind = 0;
    d->front_ind = 0;
    d->copy = copy;
    d->destroy = destroy;
    return d;
}

void dequeue_destroy(dequeue* dq) {
    if (!dq) return;
    if (dq->data)
    {
        size_t index = dq->front_ind;
        for (size_t i = 0; i < dq->size; i++)
        {
            elem_destroy(dq, dq->data[index]);
            index = ring_add(index, 1, dq->capacity);
        }
        free(dq->data);
    }
    free(dq);
}

dequeue* dequeue_copy(const dequeue* dq) {
    if (dq == NULL){
        return NULL;
    }
    dequeue* new_dequeue = dequeue_create(dq->capacity, dq-> copy, dq-> destroy);
    if (new_dequeue == NULL){
        return NULL;
    }
    size_t read_old = dq->front_ind;
    for (size_t i=0; i< dq->size; i++){
        void* tmp = NULL;
        int copy_res= elem_copy(dq, dq->data[read_old], &tmp);
        if (copy_res == 0){
            dequeue_destroy(new_dequeue);
            return NULL;
        }
        new_dequeue->data[i]=tmp;
        read_old = ring_add(read_old, 1, dq->capacity);
    }
    return new_dequeue;
} 
/*======== SIZE / STATE ========*/

size_t dequeue_size(const dequeue* dq) { 
    //TODO
    if (!dq){
        return 0;
    }
    return (dq->size);
}

size_t dequeue_capacity(const dequeue* dq) { 
    //TODO
    if (!dq){
        return 0;
    }
    return (dq->capacity);
}

bool dequeue_is_empty(const dequeue* dq) { 
    //TODO
    if (!dq){
        return true;
    }
    return (dq->size) ? true : false;
}

bool dequeue_is_full(const dequeue* dq) { 
    //TODO
    if (!dq){
        return false;
    }
    return (dq->size == dq->capacity) ? true : false;
}

/*======== ACCESS: COPY ========*/

int dequeue_front_copy(const dequeue* dq, void** out) {
    //TODO
    if (!dq || !dq->data){
        return 1;
    }
    void* tmp = NULL;
    elem_copy(dq, dq->data[dq->front_ind], &tmp);
    int copy_res = elem_copy(dq, dq->data[dq->front_ind], &tmp);
    if (copy_res){
        return 1; 
    }
    *out = tmp;
    return 0;
}

int dequeue_back_copy(const dequeue* dq, void** out) {
    //TODO
    if (!dq || !dq->data){
        return 1;
    }
    void* tmp = NULL;
    size_t last_index = ring_sub(dq->back_ind, 1, dq->capacity);
    int copy_res = elem_copy(dq, dq->data[last_index], &tmp);
    if (copy_res){
        return 1; 
    }
    *out = tmp;
    return 0;
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
    if (!dq || !dq->data){
        return 1;
    }
    if (dq->size == dq->capacity){
        return 1;
    }
    void* tmp = NULL;
    int res_copy = elem_copy(dq, in, &tmp);
    if (res_copy){
        return 1;
    }
    dq->front_ind = ring_sub(dq->front_ind, 1, dq->capacity);
    dq->data[dq->front_ind] = tmp;
    dq->size++;
    return 0;
}

int dequeue_push_back(dequeue* dq, const void* in) {
    if (!dq || !dq->data){
        return 1;
    }
    if (dq->size == dq->capacity){
        return 1;
    }
    void* tmp = NULL;
    int res_copy = elem_copy(dq, in, &tmp);
    if (res_copy){
        return 1;
    }
    dq->data[dq->back_ind] = tmp;
    dq->back_ind = ring_add(dq->back_ind, 1, dq->capacity);
    dq->size++;
    return 0;
}

/*======== POP: COPY ========*/

int dequeue_pop_front_copy(dequeue* dq, void** out) {
    if (!dq || !dq->size){
        return 1;
    }
    void* tmp = NULL;
    int copy_res = elem_copy(dq,dq->data[dq->front_ind],&tmp);
    if (copy_res){
        return 1;
    }
    *out = tmp;
    elem_destroy(dq,dq->data[dq->front_ind]);
    dq->size--;
    dq->front_ind = ring_add(dq->front_ind,1,dq->capacity);
    return 0;
}

int dequeue_pop_back_copy(dequeue* dq, void** out) {
    if (!dq || !dq->size){
        return 1;
    }
    void* back_old = dq->back_ind;
    dq->back_ind = ring_sub(dq->back_ind,1,dq->capacity);
    void* tmp = NULL;
    int copy_res = elem_copy(dq,dq->data[dq->back_ind],&tmp);
    if (copy_res){
        dq->back_ind = back_old;
        return 1;
    }
    *out =tmp;
    elem_destroy(dq,dq->data[dq->back_ind]);
    dq->size--;
    return 0;
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
    if (dq != NULL) {
        size_t cur_ind = dq->front_ind;
        printf("[");
        do {
            print(dq->data[cur_ind]);
            cur_ind = ring_add(cur_ind, 1, dq->capacity);
        } while (cur_ind != dq->back_ind);
        printf("]");
    }
    return;
}