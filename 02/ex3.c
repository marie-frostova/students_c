//Гельман
#include <stdio.h>

int main() {
    int arr[] = {0,0,1,1,2,2,2,3,4};
    int cnt = 1;
    int cur = arr[0];
    for (int i = 1; i < 9; i++) {
        if (arr[i]!=cur) {
            arr[cnt]=arr[i];
            cnt++;
            cur = arr[i];
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++){
        printf("%d ", arr[i]);
    }
}