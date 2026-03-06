/*Find the maximum element in an array.
Sample Input: 5   7 2 9 4 1
Sample Output: Max = 9 */

#include<stdio.h>
#include<stdlib.h>

int maxEle(int*,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the input : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int lar=maxEle(arr,size);
    printf("\nMaximum Element is : %d\n",lar);
    free(arr);
    arr=NULL;
    return 0;
}
int maxEle(int* arr,int size){
    int lar=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>lar){
            lar=arr[i];
        }
    }
    return lar;
}