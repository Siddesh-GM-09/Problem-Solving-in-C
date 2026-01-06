#include<stdio.h>
void binaryNo(int);
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Entered Number : %d\n",num);
    binaryNo(num);
}
void binaryNo(int num){
    int result=0,pos=1;
    while(num){
        result=result+(num%2)*pos;
        pos=pos*10;
        num/=2;
    }
    printf("Binary is : %d\n",result);
}