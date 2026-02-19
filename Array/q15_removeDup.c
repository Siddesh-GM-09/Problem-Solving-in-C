#include<stdio.h>
#include<stdlib.h>
void remDup(int*,int*);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Array is : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    remDup(arr,&size);
    printf("After Array is : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}
void remDup(int* arr,int* size){
    int index=0,i;
    for(i=0;i<*size-1;i++){
        if(arr[i]!=arr[i+1]){
            arr[index++]=arr[i];
        }
    }
    arr[index++]=arr[i];
    *size=index;
}