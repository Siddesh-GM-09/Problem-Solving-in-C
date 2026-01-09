/*Write a C program to:
Rotate an integer array to the right by K positions
Without using any extra array
Input:
Array: 1 2 3 4 5 6 7   K = 3
Output: 5 6 7 1 2 3 4
*/

#include<stdio.h>
#include<stdlib.h>
void reverseArr(int *arr,int start,int end);
void rotateRight(int *arr, int size,int n);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    if(arr==NULL){
        printf("Momory Not Allocated \n");
        return 0;
    }
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int n;
    printf("Enter the number of rations : ");
    scanf("%d",&n);
    rotateRight(arr,size,n);
    printf("After the roations : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}
void rotateRight(int *arr, int size,int n){
    if(size<=1){
        return;
    }
    reverseArr(arr,0,size-1);
    reverseArr(arr,0,n-1);
    reverseArr(arr,n,size-1);
}
void reverseArr(int *arr,int start,int end){
    while(start<end){
        int t=arr[start];
        arr[start]=arr[end];
        arr[end]=t;
        start++;
        end--;
    }
}