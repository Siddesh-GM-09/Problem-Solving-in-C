#include<stdio.h>
#include<stdlib.h>
void sortIns(int*,int);
int main(){
    int size;
    printf("Enter the size of array :");
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
    sortIns(arr,size);
    printf("\nAfter : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
void sortIns(int* arr,int size){
    int i,j,index;
    for(i=1;i<size;i++){
        index=arr[i];
        for(j=i;j>0&&arr[j-1]>index;j--){
            arr[j]=arr[j-1];
        }
        arr[j]=index;
    }
}