#include<stdio.h>
#include<stdlib.h>
int firstMissingPositive(int *arr, int n);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int num=firstMissingPositive(arr,size);
    printf("Missing Number : %d\n",num);
    free(arr);
    return 0;
}
int firstMissingPositive(int *arr, int n){
    for(int x=1;x<n+1;x++){
        int found=0;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                found=1;
            }
        }
        if(!found){
            return x;
        }
    }
    return n+1;
}