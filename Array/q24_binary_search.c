/*Binary search implementation.
Input: 5  , 1 2 3 4 5  target=3
Output:Index 2*/
#include<stdio.h>
#include<stdlib.h>
int binarySearch(int*,int,int);
int main(){
    int size,target;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data is : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the target : ");
    scanf("%d",&target);
    int index=binarySearch(arr,size,target);
    if(index!=-1){
        printf("Found at : %d\n",target);
    }
    else{
        printf("Target Not found\n");
    }
    free(arr);
    arr=NULL;
    return 0;
}
int binarySearch(int* arr,int size,int target){
    int low=0,high=size-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(target<arr[mid]){
            high=mid-1;
        }
        else if(target>arr[mid]){
            low=mid+1;
        }
    }
    return -1;
}