#include<stdio.h>
#include<stdlib.h>

int maxPoint(int*,int,int);
int main(){
    int size,k;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    printf("Enter the inputs points : \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Points is : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the number of cards : ");
    scanf("%d",&k);
    int res=maxPoint(arr,size,k);
    printf("The maxpoints are %d\n",res);
    free(arr);
    arr=NULL;
    return 0;
}
int maxPoint(int* arr,int size,int k){
    int l=0,r=size-1;
    int lsum=0,rsum=0,maxSum=0;
    for(int l=0;l<k;l++){
        lsum+=arr[l];
    }
    maxSum=lsum;
    for(int i=k-1;i>=0;i--){
        lsum-=arr[i];
        rsum+=arr[r--];
        if(rsum+lsum>maxSum){
            maxSum=rsum+lsum;
        }
    }
    return maxSum;
}