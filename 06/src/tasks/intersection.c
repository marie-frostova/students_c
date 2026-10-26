#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

int getlen(struct ListNode* lst) {
    int count = 0;
    while (lst != NULL) {
        count++;
        lst = lst->next;
    }
    return count;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = getlen(headA), lenB = getlen(headB);
    if (lenA > lenB) {
        for (int i = 0; i < lenA-lenB; i++) {
            headA = headA->next;
        }
    }
    else {
        for (int i = 0; i < lenB-lenA; i++) {
            headB = headB->next;
        }
    }

    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
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

    struct ListNode* result = getIntersectionNode(&node1, &node5);
    assert(result == &node4);

    printf("%d", result->val);
}