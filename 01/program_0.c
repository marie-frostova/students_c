//Калюжный
#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int minm = INT_MAX, indminm = -1, maxm = INT_MIN, indmaxm =-1;
    for (int i = 0 ; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > maxm) {
            indmaxm = i;
            maxm = x;
        }
        if (x < minm) {
            indminm = i;
            minm = x;
        }
    }
    indminm++;
    indmaxm++;
    printf("%d %d %d %d", minm, indminm, maxm, indmaxm);
	return 0;
}