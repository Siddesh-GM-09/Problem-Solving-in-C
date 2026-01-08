#include<stdio.h>
#include<stdlib.h>
int isPrime(int );
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    int *ptr[size];
    printf("Enter the inputs : \n");
    int i=0,k=0;
    while (i<size)
    {
        scanf("%d",&arr[i]);
        if(isPrime(arr[i])){
            ptr[k++]=&arr[i];
            i++;
        }
    }
    printf("Final array : ");
    for(int i=0;i<size;i++){
        printf("%d ",*ptr[i]);
    }
    printf("\n");
}
int isPrime(int n){
    int i;
    for(i=2;i<=n;i++){
        if(n%i==0){
            break;
        }
    }
    if(i==n){
        return 1;
    }
    return 0;
}