#include<stdio.h>
int multi(int,int);
int sum(int ,int);
int main(){
    int n1,n2;
    printf("Enter the number 1 : ");
    scanf("%d",&n1);
    printf("Enter the number 2 : ");
    scanf("%d",&n2);
    int result=multi(n1,n2);
    printf("Result : %d\n",result);
    return 0;
}
int multi(int a,int b){
    int result=0;
    while(b!=0){
        if(b&1){
            result=sum(result,a);
        }
        a<<=1;
        b>>=1;
    }
    return result;
}
int sum(int a,int b){
    while (b!=0)
    {
        int carry=(a&b)<<1;
        a=a^b;
        b=carry;
    }
    return a;
}