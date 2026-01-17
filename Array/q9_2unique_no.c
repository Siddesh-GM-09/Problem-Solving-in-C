/*Problem Statement
You are given an integer array where:
    Exactly two numbers appear only once
    All other numbers appear exactly twice
*/
#include<stdio.h>
#include<stdlib.h>
void findTwoUnique(int *arr, int size, int *x, int *y);
int main(){
    int size,x=0,y=0;
    printf("Enter the size : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    findTwoUnique(arr,size,&x,&y);
    printf("Numbers are : %d & %d\n",x,y);
    free(arr);
}
void findTwoUnique(int *arr, int size, int *x, int *y){
    int result=0;
    for(int i=0;i<size;i++){
        result^=arr[i];
    }
    result=result&(-result);
    for(int i=0;i<size;i++){
        if(result&(arr[i])){
            *x^=arr[i];
        }
        else{
            *y^=arr[i];
        }
    }
}
