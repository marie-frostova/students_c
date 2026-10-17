#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "leetcode_list.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    //TODO
}

void test_merge() {
    printf("Testing merge of two lists\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {3, NULL};
    struct ListNode node3 = {2, NULL};
    node1.next = &node2;
    node3.next = NULL;
    struct ListNode* merged = mergeTwoLists(&node1, &node3);
    while (merged != NULL) {
        printf("%d ", merged->val);
        merged = merged->next;
    }
    printf("\n");
}