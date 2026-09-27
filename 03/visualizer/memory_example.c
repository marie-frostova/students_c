#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 3

int global_variable;
int global_array[ARRAY_SIZE];

void fun1(int* y) {
    *y = *y + 1;
}

int fun2(int x) {
    fun1(&x);
    return x * x;
}

void fun3(int* arr, int size) {
    static int cnt;
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] + cnt;
    }
    cnt++;
}

void fun4(int** ptr) {
  *ptr = (int*)malloc(ARRAY_SIZE * sizeof(int));
}

int main() {
    int local_variable = 1;
    fun2(local_variable);

    int local_array[ARRAY_SIZE] = { 1 };

    int* malloc_array;
    fun4(&malloc_array);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        malloc_array[i] = i + 1;
    }

    fun3(malloc_array, ARRAY_SIZE);
    fun3(local_array, ARRAY_SIZE);
    fun3(global_array, ARRAY_SIZE);

    free(malloc_array);

    char* str = "Hello, world!";
    printf("%s\n", str);

    return 0;
}