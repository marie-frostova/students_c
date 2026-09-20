//Ильиных
#include <stdio.h>

int count_details(int n,int k, int m){
    int kolk=n/k;
    int ostn=n%k;
    int kolm=(k/m)*kolk;
    int ostk=(k%m)*kolk;
    if (ostn+ostk>=k){
        kolm+=count_details(ostn+ostk, k, m);
    }
    return kolm;
}

int main(){
    int n,k,m;
    scanf("%d %d %d", &n,&k,&m);
    int detailscnt=count_details(n,k,m);
    printf("%d", detailscnt);
}