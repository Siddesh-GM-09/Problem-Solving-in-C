/*Implement binary search.
Sample Input:  1 2 3 4 5 search 4
Sample Output: Found */

#include<stdio.h>
#include<stdlib.h>
int binarySearch(int*,int,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the input : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int target;
    printf("\nEnter the target : ");
    scanf("%d",&target);
    int flag=binarySearch(arr,size,target);
    if(flag!=-1){
        printf("Target Found\n");
    }
    else{
        printf("Target Not Found\n");
    }
    free(arr);
    arr=NULL;
    return 0;
}
int binarySearch(int* arr,int size,int target){
    int low=0,high=size-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}