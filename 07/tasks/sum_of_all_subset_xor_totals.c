#include <assert.h>
#include <stdio.h>

int subsetXORSum(int* nums, int numsSize) {
    //TODO
}

void testSubsetXORSum() {
    int first[] = { 1, 3 };
    int second[] = { 5, 1, 6 };
    int third[] = { 3, 4, 5, 6, 7, 8 };
    assert(subsetXORSum(first, 2) == 6);
    assert(subsetXORSum(second, 3) == 28);
    assert(subsetXORSum(third, 6) == 480);
    puts("Sum of All Subset XOR Totals: OK");
}