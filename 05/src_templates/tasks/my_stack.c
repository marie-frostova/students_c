#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dequeue.h"
#include "tasks.h"

#define CAPACITY 10000

/*======== STACK USING QUEUES ========*/
//https://leetcode.com/problems/implement-stack-using-queues

typedef struct {
    //TODO
} MyStack;

MyStack* myStackCreate(void) {
    //TODO
}

void myStackPush(MyStack* obj, int x) {
    //TODO
}

int myStackTop(MyStack* obj) {
    //TODO
}

int myStackPop(MyStack* obj) {
    //TODO
}

bool myStackEmpty(MyStack* obj) {
    //TODO
}

void myStackFree(MyStack* obj) {
    //TODO
}

void test_my_stack(void) {
    printf("Testing MyStack:\n");

    MyStack* stack = myStackCreate();
    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("Top: %d\n", myStackTop(stack));
    printf("Pop: %d\n", myStackPop(stack));
    printf("Empty: %d\n", myStackEmpty(stack));
    myStackFree(stack);
    printf("=====================\n");
}