#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //TODO
}

void test_intersection() {
    printf("Testing intersection\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node5.next = &node4;

    assert(getIntersectionNode(&node1, &node5) == &node4);
}