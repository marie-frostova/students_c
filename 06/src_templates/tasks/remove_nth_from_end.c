#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    n--;
    
    int size = 0;
    for (struct ListNode* cur = head; cur != NULL; cur = cur->next){
        ++size; 
    }    
    if (size-n == 1){
        return head->next;
    }
    struct ListNode* cur = head;
    for (int i=0; i< size-n-2; ++i){
        cur = cur->next;
    }
    cur->next = cur->next->next;
    return head;
}

void test_remove_nth_from_end() {
    printf("Testing remove Nth node from end\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {2, NULL};
    struct ListNode node3 = {3, NULL};
    struct ListNode node4 = {4, NULL};
    struct ListNode node5 = {5, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct ListNode* result = removeNthFromEnd(&node1, 2);
    assert(result == &node1);
    assert(result->next == &node2);
    assert(result->next->next == &node3);
    assert(result->next->next->next == &node5);
    assert(result->next->next->next->next == NULL);

    result = removeNthFromEnd(result, 4);
    assert(result == &node2);
    assert(result->next == &node3);
    assert(result->next->next == &node5);

    result = removeNthFromEnd(result, 1);
    assert(result == &node2);
    assert(result->next == &node3);
    assert(result->next->next == NULL);

    struct ListNode single = {1, NULL};
    assert(removeNthFromEnd(&single, 1) == NULL);
}