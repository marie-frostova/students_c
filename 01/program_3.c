//Лапцевич
#include <stdio.h>

int main() {
    int d;
    scanf("%d", &d);

    int x, y;
    scanf("%d %d", &x, &y);

    if (x > 0 && y > 0 && y <= d - x) { 
        printf("0\n");
        return 0;
    }

    long long dA, dB, dC;   
    dA = x * x + y * y;
    dB = x * x + (y - d) * (y - d);
    dC = (x - d) * (x - d) + y * y;     

    // printf("%lld %lld %lld", dA, dB, dC);

    if (dA <= dB && dA <= dC) {
        printf("1\n");
    } else if (dB <= dA && dB <= dC) {
        printf("2\n");
    } else {
        printf("3\n");
    }

    return 0;
}