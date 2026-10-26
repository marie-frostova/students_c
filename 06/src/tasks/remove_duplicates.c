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
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL){
        return NULL;
    }
    printlist(head);
    struct ListNode* current = head;
    struct ListNode* step = head;
    while(step->next){
        if (current->val != step->val){
            current->next = step;
            current = step;
        }
        step = step->next;
    }
    current->next = NULL;
    printlist(head);
    return head;
}


void test_remove_duplicates() {
    printf("Testing remove duplicates\n");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {1, NULL};
    struct ListNode node3 = {2, NULL};
    struct ListNode node4 = {3, NULL};
    struct ListNode node5 = {3, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct ListNode* result = deleteDuplicates(&node1);
    struct ListNode* expected = &node1;
    assert(result == expected);
    assert(result->next == &node3);
    assert(result->next->next == &node4);
    assert(result->next->next->next == NULL);

    assert(deleteDuplicates(NULL) == NULL);

    struct ListNode single = {1, NULL};
    assert(deleteDuplicates(&single) == &single);
    assert(single.next == NULL);

    struct ListNode duplicate3 = {1, NULL};
    struct ListNode duplicate2 = {1, &duplicate3};
    struct ListNode duplicate1 = {1, &duplicate2};
    assert(deleteDuplicates(&duplicate1) == &duplicate1);
    assert(duplicate1.next == NULL);
}