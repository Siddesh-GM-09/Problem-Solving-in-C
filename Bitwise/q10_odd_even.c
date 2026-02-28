/*Odd or Even using Bitwise*/
#include<stdio.h>
int isOE(int);
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int flag=isOE(num);
    if(flag){
        printf("Odd Number \n");
    }
    else{
        printf("Even Number\n");
    }
    return 0;
}
int isOE(int num){
    return num&1;
}