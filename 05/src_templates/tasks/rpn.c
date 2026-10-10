#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequeue.h"
#include "tasks.h"

/*======== REVERSE POLISH NOTATION ========*/
//https://leetcode.com/problems/evaluate-reverse-polish-notation

int evalRPN(char** tokens, int tokensSize) {
    //TODO
}

void test_rpn(void) {
    printf("Testing Reverse Polish Notation:\n");

    char* tokens1[] = {"2", "1", "+", "3", "*"};
    int result1 = evalRPN(tokens1, 5);
    printf("Test RPN 1: %d\n", result1);

    char* tokens2[] = {"4", "13", "5", "/", "+"};
    int result2 = evalRPN(tokens2, 5);
    printf("Test RPN 2: %d\n", result2);

    char* tokens3[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int result3 = evalRPN(tokens3, 13);
    printf("Test RPN 3: %d\n", result3);

    printf("=====================\n");
}