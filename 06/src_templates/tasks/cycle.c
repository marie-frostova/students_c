#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

bool hasCycle(struct ListNode *head) {
    //TODO
}

void test_cycle() {
    printf("Testing cycle\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node1;
    assert(hasCycle(&node1) == true);
}