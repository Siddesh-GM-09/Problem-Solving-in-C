#include<stdio.h>
#include<stdlib.h>
void twoUni(int*,int,int*,int*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int n1=0,n2=0;
    twoUni(arr,size,&n1,&n2);
    printf("Unique numbers are : %d %d\n",n1,n2);
    free(arr);
    arr=NULL;
    return 0;
}
void twoUni(int* arr,int size,int* n1,int* n2){
    int res=0;
    for(int i=0;i<size;i++){
        res^=arr[i];
    }
    res=res&(-res);
    for(int i=0;i<size;i++){
        if(res&arr[i]){
            *n1^=arr[i];
        }
        else{
            *n2^=arr[i];
        }
    }
}