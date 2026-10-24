#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
    //TODO
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    //TODO
}

int lRUCacheGet(LRUCache* obj, int key) {
    //TODO
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    //TODO
}

void lRUCacheFree(LRUCache* obj) {
    //TODO
}

void test_cache() {
    printf("Testing LRU cache\n");

    LRUCache* cache = lRUCacheCreate(2);
    assert(cache);
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    assert(lRUCacheGet(cache, 1) == 1);
    lRUCachePut(cache, 3, 3);
    assert(lRUCacheGet(cache, 2) == -1);
    lRUCachePut(cache, 4, 4);
    assert(lRUCacheGet(cache, 1) == -1);
    assert(lRUCacheGet(cache, 3) == 3);
    assert(lRUCacheGet(cache, 4) == 4);
    lRUCacheFree(cache);
}