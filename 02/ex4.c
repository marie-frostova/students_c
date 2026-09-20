//Шалобанов
#include <stdio.h>
#include <assert.h>

int cnt_words(char* sentence) {
    int i = 0, in_word = 0, cnt = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] != ' ' && in_word == 0) {
            in_word = 1;
            cnt++;
        }
        if (sentence[i] == ' ') {
            in_word = 0;
        }
        i++;
    }
    return cnt;
}

int test() {
    char* word = "Hello world";
    int count = cnt_words(word);
    assert(count == 2);  
}

int main() {
    int cnt_max = 0;
    char* arr[] = {
        "Hello world.",
        "This is a test sentence.",
        "Another one." };
    //test();
    for (int i = 0; i < 3; i++) {
        int cnt1 = cnt_words(arr[i]);
        if (cnt1 > cnt_max) {
            cnt_max = cnt1;
        }
    }
    printf("%d", cnt_max);
    return 0;
}