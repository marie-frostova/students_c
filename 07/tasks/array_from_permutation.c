#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* buildArray(int* nums, int numsSize, int* returnSize) {
    //TODO
}

void testBuildArrayFromPermutation() {
    int nums[] = { 0, 2, 1, 5, 3, 4 };
    int size;
    int* result = buildArray(nums, 6, &size);
    int expected[] = { 0, 1, 2, 4, 5, 3 };
    assert(result != NULL && size == 6);
    for (int i = 0; i < size; ++i)
        assert(result[i] == expected[i]);
    puts("Build Array from Permutation: OK");
}