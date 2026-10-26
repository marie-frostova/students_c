#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

static void printlist(struct ListNode* head)
{
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL){
        return NULL;
    }
    printlist(head);
    struct ListNode* prev = head;
    struct ListNode* cur = prev->next;
    head->next = NULL;
    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    printlist(prev);
    return prev;
    
}

static void test1() {
    printf("Test 1\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct ListNode* result = reverseList(&node1);

    assert(result == &node5);
    assert(result->next == &node4);
    assert(result->next->next == &node3);
    assert(result->next->next->next == &node2);
    assert(result->next->next->next->next == &node1);
    assert(result->next->next->next->next->next == NULL);
}

static void test2(){
    printf("Test 2");
    struct ListNode node1 = {1, NULL};
    struct ListNode* result = reverseList(&node1);
}

static void test3(){
    printf("Test 3");
    struct ListNode* result = reverseList(NULL);
}

void test_reverse() {
    test1();
    test2();
    test3();
   
}