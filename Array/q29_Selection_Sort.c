/*Sort numbers.
Sample Input: 4 2 1 3
Sample Output: 1 2 3 4 */
#include<stdio.h>
#include<stdlib.h>
void SelSort(int*,int);
int main(){
    int size;
    printf("Enter the size: ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    SelSort(arr,size);
    printf("After : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}

void SelSort(int* arr,int size){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}