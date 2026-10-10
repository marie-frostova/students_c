#include <stdio.h>
#include <stdlib.h>
#include "dequeue.h"
#include "tasks.h"

/*======== RECENT COUNTER ========*/
//https://leetcode.com/problems/number-of-recent-calls

typedef struct {
    //TODO
} RecentCounter;

RecentCounter* recentCounterCreate(void) {
    //TODO
}

int recentCounterPing(RecentCounter* obj, int t) {
    //TODO
}

void recentCounterFree(RecentCounter* obj) {
    //TODO
}

void test_recent_counter(void) {
    printf("Testing Recent Counter:\n");

    RecentCounter* rc = recentCounterCreate();
    if (!rc) return;

    printf("Ping 1: %d\n", recentCounterPing(rc, 1));
    printf("Ping 100: %d\n", recentCounterPing(rc, 100));
    printf("Ping 3000: %d\n", recentCounterPing(rc, 3000));
    printf("Ping 3001: %d\n", recentCounterPing(rc, 3001));
    printf("Ping 3002: %d\n", recentCounterPing(rc, 3002));

    recentCounterFree(rc);
    printf("=====================\n");
}