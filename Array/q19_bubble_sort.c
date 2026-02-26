/* Sort array using Bubble Sort. 
Input: 5 3 1 4 2 
Output: 1 2 3 4 5*/
#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int*,int);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    bubbleSort(arr,size);
    printf("\nAfter : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}
void bubbleSort(int* arr,int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                arr[j]^=arr[j+1];
                arr[j+1]^=arr[j];
                arr[j]^=arr[j+1];
            }
        }
    }
}