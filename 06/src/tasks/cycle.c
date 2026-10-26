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

bool hasCycle(struct ListNode *head) {
    if (head == NULL){
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void test_several_full() {
    printf("test_several_full");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node1;
    assert(hasCycle(&node1) == true);
}

void test_several_not_full() {
    printf("test_several_not_full");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node2;
    assert(hasCycle(&node1) == true);
}

void test_one_node_cycle() {
    printf("test_one_node_cycle");
    struct ListNode node1 = {1, NULL};
    node1.next = &node1;
    assert(hasCycle(&node1) == true);
}

void test_one_node_no_cycle() {
    printf("test_one_node_no_cycle");
    struct ListNode node1 = {1, NULL};
    assert(hasCycle(&node1) == false);
}

void test_no_cycle() {
    printf("test_no_cycle");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    node1.next = &node2;
    node2.next = &node3;
    assert(hasCycle(&node1) == false);
}

void test_null() {
    printf("test_null");

    assert(hasCycle(NULL) == false);
}


void test_cycle() {
    printf("Testing cycle\n");
    test_no_cycle();
    test_null();
    test_one_node_cycle();
    test_several_full();
    test_several_not_full();
    test_one_node_no_cycle();
}