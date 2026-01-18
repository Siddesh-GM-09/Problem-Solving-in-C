#include<stdio.h>
#include<stdlib.h>
void moveZero(int*,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    moveZero(arr,size);
    printf("\nAfter : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
void moveZero(int* arr,int size){
    int index=0;
    for(int i=0;i<size;i++){
        if(arr[i]!=0){
            arr[index++]=arr[i];
        }
    }
    while(index<size){
        arr[index++]=0;
    }
}