//Ильиных
#include <stdio.h>
#include <string.h>

int main(){
    char* strs[] = { "",
                     "",
                     "" };
    int i = 0;
    int size = 3;
    char* etalon = strs[0]; 
    int check = 1;
    for (i; i<strlen(etalon); ++i){
        for (int j=1; j < size; ++j){
            if (strs[j][i] != etalon[i]){
                check = 0;
                break;
            }

        } 
        if (check == 0){
            break;
        }  
    }
    for (int k=0; k<i; ++k){
        printf("%c", etalon[k]);
    }
    printf("\n");                    
}