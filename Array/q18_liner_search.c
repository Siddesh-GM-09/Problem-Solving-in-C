/* Linear search element in array. 
Input: 10 20 30 40 50 
Search:30
Output: Found*/

#include<stdio.h>
#include<stdlib.h>
int LinearSearch(int*,int,int);
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int* arr=calloc(size,sizeof(int));
    printf("Enter the inputs : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int num;
    printf("Enter the number you want to search : ");
    scanf("%d",&num);
    int flag=LinearSearch(arr,size,num);
    if(flag){
        printf("Found\n");
    }
    else{
        printf("Not Found\n");
    }
    return 0;
}
int LinearSearch(int* arr,int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return 1;
        }
    }
    return 0;
}