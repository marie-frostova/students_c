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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    printlist(list1);
    printlist(list2);
    struct ListNode *curr1 = list1;
    struct ListNode *curr2 = list2;
    struct ListNode dummyNode = {0, NULL};
    struct ListNode *res = &dummyNode;
    while (curr1 && curr2){
        if (curr1->val <= curr2->val){
            res->next = curr1;
            curr1 =curr1->next;
        }
        else{
            res->next = curr2;
            curr2 = curr2->next;
        }
        res = res->next;
    }
    if (curr1){
        res->next = curr1;
    }
    if (curr2){
        res->next = curr2;
    }
    printlist(dummyNode.next);
    return dummyNode.next;
}
static void test1(){
    printf("test first");
    struct ListNode* merged = mergeTwoLists(NULL, NULL);
}

static void test2(){
    printf("test second");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {3, NULL};
    node1.next = &node2;
    node2.next = NULL;
    struct ListNode* merged = mergeTwoLists(&node1, NULL);
}
static void test3(){
    printf("test third");
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {3, NULL};
    struct ListNode node3 = {2, NULL};
    struct ListNode node4 = {4, NULL};
    node1.next = &node2;
    node3.next = &node4;
    struct ListNode* merged = mergeTwoLists(&node1, &node3);
}
void test_merge() {
    test1();
    test2();
    test3();
}