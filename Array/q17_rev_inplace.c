/* Reverse an array in-place. 
Input: 1 2 3 4 5 
Output: 5 4 3 2 1*/
#include<stdio.h>
#include<stdlib.h>
void revInPlace(int*,int);
int main(){
    int size;
    printf("Erter the size of array : ");
    scanf("%d",&size);
    int *arr=calloc(size,sizeof(int));
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    revInPlace(arr,size);
    printf("After : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}
void revInPlace(int* arr,int size){
    for(int i=0,j=size-1;i<j;i++,j--){
        arr[i]=arr[i]^arr[j];
        arr[j]=arr[i]^arr[j];
        arr[i]=arr[i]^arr[j];
    }
}