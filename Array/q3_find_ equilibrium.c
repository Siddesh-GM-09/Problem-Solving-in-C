#include<stdio.h>
#include<stdlib.h>
int Find(int*,int);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int index=Find(arr,size);
    printf("Index is : %d\n",index);
    return 0;
}
int Find(int* arr,int size){
    int maxsum=0;
    for(int i=0;i<size;i++){
        maxsum+=arr[i];
    }
    int lsum=0;
    for(int i=0;i<size;i++){
        if(lsum==maxsum-lsum-arr[i]){
            return i;
        }
        lsum+=arr[i];
    }                               
    return -1;
}