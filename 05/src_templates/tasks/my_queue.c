#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dequeue.h"
#include "tasks.h"

#define CAPACITY 100

/*======== QUEUE USING STACKS ========*/
//https://leetcode.com/problems/implement-queue-using-stacks

typedef struct {
    //TODO
} MyQueue;

MyQueue* myQueueCreate(void) {
    //TODO
}

void myQueuePush(MyQueue* obj, int x) {
    //TODO
}

int myQueuePop(MyQueue* obj) {
    //TODO
}

int myQueuePeek(MyQueue* obj) {
    //TODO
}

bool myQueueEmpty(MyQueue* obj) {
    //TODO
}

void myQueueFree(MyQueue* obj) {
    //TODO
}

void test_my_queue(void) {
    printf("Testing MyQueue:\n");

    MyQueue* queue = myQueueCreate();
    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    printf("Peek: %d\n", myQueuePeek(queue));
    printf("Pop: %d\n", myQueuePop(queue));
    printf("Empty: %d\n", myQueueEmpty(queue));
    myQueueFree(queue);
    printf("=====================\n");
}