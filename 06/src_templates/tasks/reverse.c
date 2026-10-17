#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

struct ListNode* reverseList(struct ListNode* head) {
    //TODO
}

void test_reverse() {
    printf("Testing reverse list\n");
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