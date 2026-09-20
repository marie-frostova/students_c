//Розаев
#include <stdio.h>
#include <assert.h>
#define MAX_VAL 2000
#define OFFSET 1000

int set1[MAX_VAL] = {0};
int set2[MAX_VAL] = {0};

void test(){

}

void build_set(int* arr, int arr_size, int* set){
    for (int i =0;i < arr_size;i++){
        set[arr[i] + OFFSET]++;
    }
}

void print_diff(int* set1, int* set2){
    for (int i =0; i<MAX_VAL; i++){
        if (set1[i] && !set2[i]){
            printf("%d ", i-OFFSET);
        }
    }
    printf("\n");
}

int main(){
    int nums1[3] = {-999,2,3};
    int nums2[3] = {2,4,6};
    build_set(nums1,3,set1);
    build_set(nums2,3,set2);
    print_diff(set1,set2);
    print_diff(set2,set1);
}