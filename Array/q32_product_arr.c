/*Return an array where each element is the product of all other elements.
Sample Input:5
1 2 3 4 5
Sample Output: 120 60 40 30 24*/

#include<stdio.h>
#include<stdlib.h>
int* proArr(int*,int);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int* res=proArr(arr,size);
    printf("\nResult : ");
    for(int i=0;i<size;i++){
        printf("%d ",res[i]);
    }
    free(res);
    free(arr);
    res=NULL;
    arr=NULL;
    return 0;
}
int* proArr(int* arr,int size){
    int left=1,right=1;
    int *res=malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        res[i]=left;
        left*=arr[i];
    }
    for(int i=size-1;i>=0;i--){
        res[i]*=right;
        right*=arr[i];
    }
    return res;
}