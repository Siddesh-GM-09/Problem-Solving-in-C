/* Fibonacci using Recursion
Input: 6
Output: 8*/
#include<stdio.h>
int Fibonaci(int);
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Entered Number: %d\n",num);
    int data=Fibonaci(num);
    printf("Number : %d\n",data);
    return 0;
}

int Fibonaci(int num){
    if(num==0){
        return 0;
    }
    if(num==1){
        return 1;
    }
    return Fibonaci(num-1)+Fibonaci(num-2);
}
