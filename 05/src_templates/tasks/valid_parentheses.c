#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dequeue.h"
#include "tasks.h"

/*======== VALID PARENTHESES ========*/
//https://leetcode.com/problems/valid-parentheses

bool isValid(char* s) {
    //TODO
}

void test_parentheses(void) {
    printf("Testing Valid Parentheses:\n");

    char* s1 = "()";
    char* s2 = "()[]{}";
    char* s3 = "(]";
    char* s4 = "([)]";
    char* s5 = "{[]}";

    printf("Test 1: %s -> %s\n", s1, isValid(s1) ? "true" : "false");
    printf("Test 2: %s -> %s\n", s2, isValid(s2) ? "true" : "false");
    printf("Test 3: %s -> %s\n", s3, isValid(s3) ? "true" : "false");
    printf("Test 4: %s -> %s\n", s4, isValid(s4) ? "true" : "false");
    printf("Test 5: %s -> %s\n", s5, isValid(s5) ? "true" : "false");
    printf("=====================\n");
}