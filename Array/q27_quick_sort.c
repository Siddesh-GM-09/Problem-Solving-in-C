/*Sort array using quick sort.
Input: 5   5 4 3 2 1
Output: 1 2 3 4 5*/

#include<stdio.h>
#include<stdlib.h>
void quickSort(int*,int,int);
int part(int*,int,int);
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
    quickSort(arr,0,size-1);
    printf("\nAfter : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}

void quickSort(int* arr,int low,int high){
    if(low<high){
        int p=part(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}
int part(int* arr,int low,int high){
    int pivot=arr[low];
    int i=low-1;
    int j=high+1;
    while(1){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j){
            return j;
        }
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return 0;
}