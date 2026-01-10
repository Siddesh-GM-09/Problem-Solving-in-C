#include<stdio.h>
int findUnique(int *arr, int size);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int num=findUnique(arr,size);
    printf("Unique Number is : %d\n",num);
    return 0;
}
int findUnique(int *arr, int size){
    int result=arr[0];
    for(int i=1;i<size;i++){
        result=result^arr[i];
    }
    return result;
}