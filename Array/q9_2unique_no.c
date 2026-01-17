/*Problem Statement
You are given an integer array where:
    Exactly two numbers appear only once
    All other numbers appear exactly twice
*/
#include<stdio.h>
#include<stdlib.h>
void findTwoUnique(int *arr, int size, int *x, int *y);
int main(){
    int size,x,y;
    printf("Enter the size : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    findTwoUnique(arr,size,&x,&y);

}
void findTwoUnique(int *arr, int size, int *x, int *y){
    
}
