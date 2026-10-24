#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

struct ListNode* middleNode(struct ListNode* head) {
    int size = 0;
    struct ListNode* current = head;
    while (current){
        size++;
        current = current->next;
    }
    
    for (int i = 0; i < size / 2; i++){
        head = head->next;
    }
    return head;
}

void test_middle() {
    printf("Testing middle node\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct ListNode* middle = middleNode(&node1);
    assert(middle == &node3);
}