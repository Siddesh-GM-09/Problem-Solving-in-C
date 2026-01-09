#include<stdio.h>
#define size 10
#define MAX 1000
int result[MAX][size];
int resultSize=0;
void swap(int *,int *);
void recPer(int,int*,int);
int main(){
    int arr[]={1,2,3};
    printf("Final Result : \n");
    int n=3;
    recPer(0,arr,n);
    for(int i=0;i<resultSize;i++){
        for(int j=0;j<n;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void recPer(int index,int* nums,int n){
    if(index==n){
        for(int i=0;i<n;i++){
            result[resultSize][i]=nums[i];
        }
        resultSize++;
        return;
    }
    for(int i=index;i<n;i++){
        swap(&nums[index],&nums[i]);
        recPer(index+1,nums,n);
        swap(&nums[index],&nums[i]);
    }
}