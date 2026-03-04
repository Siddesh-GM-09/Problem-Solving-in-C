/*Move all zeros to end while maintaining order.
Sample Input: 5
0 1 0 3 12
Sample Output:
1 3 12 0 0*/
#include<stdio.h>
#include<stdlib.h>
void moveZero(int*,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
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
    free(arr);
    arr=NULL;
    return 1;
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