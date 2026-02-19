#include<stdio.h>
#include<stdlib.h>
int* funTar(int*,int,int,int*);
int main(){
    int si;
    printf("Enter the size : ");
    scanf("%d",&si);
    int* arr=malloc(sizeof(int)*si);
    printf("Enter the array inputs : \n");
    for(int i=0;i<si;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enered Array : ");
    for(int i=0;i<si;i++){
        printf("%d ",arr[i]);
    }
    int target,rS;
    printf("\nEntere the target : ");
    scanf("%d",&target);
    int *res=funTar(arr,si,target,&rS);
    for(int i=0;i<rS;i++){
        printf("%d ",res[i]);
    }
    free(arr);
    free(res);
    res=arr=0;
    return 0;
}
int* funTar(int* arr,int size,int target,int* rS){
    int *res=malloc(sizeof(int)*2);
    for(int i=1;i<size;i++){
        for(int j=i;j<size;j++){
            if(arr[j]+arr[j-i]==target){
                res[0]=j-i;
                res[1]=i;
                *rS=2;
                return res;
            }
        }
    }
    *res=0;
    return NULL;
}