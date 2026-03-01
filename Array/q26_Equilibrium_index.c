/*Find index where left sum equals right sum.
Sample Input: 5
1 3 5 2 2
Sample Output: Index = 2 */

#include<stdio.h>
#include<stdlib.h>

int Equilibrium(int*,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Inputs : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int index=Equilibrium(arr,size);
    if(index!=-1){
        printf("Equilibrium index is : %d\n",index);
    }
    else{
        printf("No Equilibrium index\n");
    }
    free(arr);
    arr=NULL;
    return 0;
}

int Equilibrium(int* arr,int size){
    int lsum=0,rsum=0,tsum=0;
    for(int i=0;i<size;i++){
        tsum+=arr[i];
    }
    for(int i=0;i<size;i++){
        rsum=tsum-lsum-arr[i];
        if(rsum==lsum){
            return i;
        }
        lsum+=arr[i];
    }
    return -1;
}