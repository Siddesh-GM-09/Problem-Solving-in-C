#include<stdio.h>
int isPowerOfTwo(int n);
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int flag=isPowerOfTwo(num);
    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
int isPowerOfTwo(int n){
    return (n>0)&&((n&(n-1))==0);
}