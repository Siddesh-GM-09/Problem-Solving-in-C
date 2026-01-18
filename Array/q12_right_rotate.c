#include<stdio.h>
#include<stdlib.h>
void rotateRig(int*,int,int);
int main(){
    int size,*arr,key;
    printf("Enter the size : ");
    scanf("%d",&size);
    arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the rotations : ");
    scanf("%d",&key);
    rotateRig(arr,size,key);
    printf("After  : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}

void rotateRig(int* arr,int size,int key){
    key=key%size;
    int *copy=malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        copy[i]=arr[i];
    }
    int s=0;
    for(int i=size-key;i<size;i++){
        arr[s++]=copy[i];
    }
    for(int i=0;i<=key;i++){
        arr[s++]=copy[i];
    }
    free(copy);
    copy=NULL;
}