/*Generate all subsets of a set.
Input:
1 2 3
Output:
{} {1} {2} {3} {1,2} {1,3} {2,3} {1,2,3} */

#include<stdio.h>
#include<stdlib.h>
int** genSubset(int*,int,int*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the elements : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int subSetCnt;
    int** subSet=genSubset(arr,size,&subSetCnt);
    int i,j;
    printf("The Subsets are : ");
    for(i=0;i<subSetCnt;i++){
        printf("{");
        for(j=0;subSet[i][j]!=-1;j++){
            printf("%d",subSet[i][j]);
            if(subSet[i][j+1]!=-1){
                printf(",");
            }
        }
        printf("} ");
    }
    return 0;
}
int** genSubset(int* arr,int size,int* returnSize){
    int total=1<<size;
    *returnSize=total;
    int** result=(int**)malloc(sizeof(int*)*total);
    for(int i=0;i<total;i++){
        result[i]=malloc(sizeof(int)*size);
    }
    for(int i=0;i<total;i++){
        int k=0;
        for(int j=0;j<size;j++){
            if(i&(1<<j)){
                result[i][k++]=arr[j];
            }
        }
        result[i][k]=-1;
    }
    return result;
}