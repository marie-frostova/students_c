//Алексеева
#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0) {
        printf("X - любое число");
    }
    else {
        int x = (c * c - b) / a;

        if ((a * x + b) < 0 || c < 0) {
            printf("Нет решений");
        }
        else {
            printf("%d", x);
        }
    }
    return 0;
}