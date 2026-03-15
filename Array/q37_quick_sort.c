#include<stdio.h>
#include<stdlib.h>
void QuickSort(int*,int,int);
int part(int*,int,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=(int*)malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    QuickSort(arr,0,size-1);
    printf("After  Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}

void QuickSort(int* arr,int low,int high){
    if(low<high){
        int p=part(arr,low,high);
        QuickSort(arr,low,p-1);
        QuickSort(arr,p+1,high);
    }
}
int part(int* arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}