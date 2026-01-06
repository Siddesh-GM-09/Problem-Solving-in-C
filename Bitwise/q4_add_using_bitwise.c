#include<stdio.h>
int add(int,int);
int main(){
    int n1,n2;
    printf("Enter the number 1 : ");
    scanf("%d",&n1);
    printf("Enter the number 2 : ");
    scanf("%d",&n2);
    int sum=add(n1,n2);
    printf("Sum is : %d\n",sum);
    return 0;
}
int add(int a,int b){
    while(b!=0){
        int carry=(a&b)<<1;
        a=a^b;
        b=carry;
    }
    return a;
}