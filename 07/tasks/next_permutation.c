#include <assert.h>
#include <stdio.h>

void nextPermutation(int* nums, int numsSize) {
    //TODO
}

void testNextPermutation() {
    int first[] = { 1, 2, 3 };
    int second[] = { 3, 2, 1 };
    int third[] = { 1, 1, 5 };
    nextPermutation(first, 3);
    nextPermutation(second, 3);
    nextPermutation(third, 3);
    assert(first[0] == 1 && first[1] == 3 && first[2] == 2);
    assert(second[0] == 1 && second[1] == 2 && second[2] == 3);
    assert(third[0] == 1 && third[1] == 5 && third[2] == 1);
    puts("Next Permutation: OK");
}