/* Check whether number is prime and print in range. 
Input: 1 -> 100  Output: Prime Numbers */
#include<stdio.h>
#include<stdlib.h>
void printPrime(int,int);
int main(){
    int r1,r2;
    printf("Enter the ranges : ");
    scanf("%d %d",&r1,&r2);
    printPrime(r1,r2);
    return 0;
}
void printPrime(int r1,int r2){
    for(int i=r1;i<r2;i++){
        char flag=0;
        for(int j=2;j*j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(!flag){
            printf("%d ",i);
        }
    }
    printf("\n");
}