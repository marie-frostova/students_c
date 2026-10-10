#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"

#define MIN_STACK_CAPACITY 40000

/*======== MIN STACK ========*/
//https://leetcode.com/problems/min-stack

typedef struct {
    //TODO
} MinStack;

MinStack* minStackCreate() {
    //TODO
}

void minStackPush(MinStack* obj, int val) {
    //TODO
}

void minStackPop(MinStack* obj) {
    //TODO
}

int minStackTop(MinStack* obj) {
    //TODO
}

int minStackGetMin(MinStack* obj) {
    //TODO
}

void minStackFree(MinStack* obj) {
    //TODO
}

void test_min_stack(void) {
    printf("Testing MinStack\n");

    MinStack* stack = minStackCreate();

    minStackPush(stack, 3);
    minStackPush(stack, 5);
    minStackPush(stack, 2);
    minStackPush(stack, 1);

    printf("Top: %d\n", minStackTop(stack));
    printf("Min: %d\n", minStackGetMin(stack));

    minStackPop(stack);
    printf("Top after pop: %d\n", minStackTop(stack));
    printf("Min after pop: %d\n", minStackGetMin(stack));

    minStackPop(stack);
    printf("Top after second pop: %d\n", minStackTop(stack));
    printf("Min after second pop: %d\n", minStackGetMin(stack));
    
    minStackFree(stack);
    printf("=====================\n");
}