//Тян
#include <stdio.h>

int check(int* arr, int arr_length) {
    int cntless = 0;
    for (int i = 1; arr_length > i; i++) {
        if (arr[i] < arr[i - 1]) {
            cntless++;
        }
    }
    if (arr[0] < arr[arr_length - 1]) {
        cntless++
    } 
    if (cntless > 1) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int nums[] = {2, 1, 3, 4, 5};
    int answer = check(nums, 5);
    if (answer == 0) {
        printf("False\n");
    } else {
        printf("True\n");
    }
    return 0;
}