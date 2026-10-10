#include "tasks.h"

typedef int *(operator)(int a, int b);

int calculate(int a, int b, operator op) {
    int* result = op(a, b);
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

void demo_fun_ptr() {
    int a = 5;
    int b = 3;
    printf("a + b = %d\n", calculate(a, b, add));
    printf("a - b = %d\n", calculate(a, b, sub));
}

int main(void) {
    demo_fun_ptr();
    //test_int_dequeue();
    //test_string_dequeue();
    //test_min_stack();
    //test_recent_counter();
    //test_rpn();
    //test_parentheses();
    //test_my_stack();
    //test_my_queue();
    return 0;
}