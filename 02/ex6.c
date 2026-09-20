//Бойко
#include <stdio.h>
int sum[3][3]= {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};
int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
int fill_sum(){
    for (int i = 0; i<3;i++){
        for (int j = 0; j<3; j++){
            sum[i][j]=arr[i][j];
            if (j > 0){
                sum[i][j]+= sum[i][j-1];
            }
            if (i>0){
                sum[i][j]+= sum[i-1][j];
            }
            if (i>0 && j>0){
                sum[i][j]-= sum[i-1][j-1];
            }
        }
    }
}
int main(){
    int x1=1,y1=1,x2=2,y2=2;
    int res = sum[x2][y2]-sum[x2][y2-y1] - sum[x2-x1][y2] + sum[x1][y1];
    printf("%d\n",res);
}