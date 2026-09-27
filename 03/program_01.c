//Алфимов
#include <stdio.h>
#include <assert.h>
#include <string.h>
void swap(char* a, char* b){
    char save = *a;
    *a = *b;
    *b = save;
}

void reverse(char* sss, int left, int right){
    while(left<right){
        swap(sss+left, sss+right);
        left+=1;
        right-=1;
    }
}

void test(){
    char s[] = "Hello";
    char c[] = "6signs";
    char s_expected[] = "olleH";
    char c_expected[] = "sngis6";

    reverse(s, 0, 4);
    reverse(c, 0, 5);
    printf("%s/n", c);

    for(int i = 0; i<5; i++){
        assert(s[i] == s_expected[i]);
    }

    for(int i = 0; i<6; i++){
        assert(c[i] == c_expected[i]);
    }

}


void word(char* s){
    int in_word = 0;
    int i = 0;
    int start, end;
    while(s[i]!='\0'){
        if(s[i]!=' ' && in_word==0){
            in_word=1;
            start = i;
        }
        if(s[i] == ' ' && in_word==1){
            end = i-1;
            in_word = 0;
            for(int j = start; j<=end; j++){
               printf("%c", s[j]);
            }
            printf("\n");
            reverse(s, start, end);
        }
        i++;
    }
    if(in_word==1){
        end = i-1;
        for(int j = start; j<=end; j++){
                printf("%c", s[j]);
            }
            printf("\n");
        reverse(s, start, end);

    }
}

int main(){
    //test();
    char str[] = "";
    int len = strlen(str);
    reverse(str, 0, len-1);
    word(str);
    printf("%s", str);
    return 0;
}
