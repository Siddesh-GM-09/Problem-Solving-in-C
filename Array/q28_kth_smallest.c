/*Find Kth smallest element using QuickSort idea.
Input: 7 4 6 3 9 1 k=2
Output: 3 */
#include<stdio.h>
#include<stdlib.h>
int KSmallest(int*,int,int,int);
int part(int*,int,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int k;
    printf("\nEnter the Kth value : ");
    scanf("%d",&k);
    int ans=KSmallest(arr,0,size-1,k);
    printf("Final Answer : %d\n",ans);
    free(arr);
    arr=NULL;
    return 0;
}
int KSmallest(int* arr,int low,int high,int k){
    int p=part(arr,low,high);
    if(p==k-1){
        return arr[p];
    }
    else if(p>k-1){
        return KSmallest(arr,low,p-1,k);
    }
    else{
        return KSmallest(arr,p+1,high,k);
    }
}
int part(int* arr,int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}