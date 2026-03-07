/*Search element in rotated sorted array.
Input: 7
4 5 6 7 0 1 2  Target 0
Output: Index 4 */

#include<stdio.h>
#include<stdlib.h>

int searchTar(int*,int,int);
int main(){
    int size,target;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the data : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the target : ");
    scanf("%d",&target);
    int index=searchTar(arr,size,target);
    if(target!=-1){
        printf("Found at %d index\n",index);
    }
    else{
        printf("Target Not Found\n");
    }
    free(arr);
    arr=NULL;
    return 0;
}
int searchTar(int* arr,int size,int target){
    int low=0,high=size-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>=arr[low]){
            if(target<arr[mid] && target>=arr[low]){
                    high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(target>arr[mid] && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}