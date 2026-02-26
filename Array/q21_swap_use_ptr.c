/*Swap two numbers using pointers. 
Input: a=5 b=10 
Output: a=10 b=5 */

#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the numbers : ");
    scanf("%d %d",&a,&b);
    printf("A : %d B: %d\n",a,b);
    int* ptr1,*ptr2;
    ptr1=&a;
    ptr2=&b;
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1=*ptr2;
    printf("A : %d B: %d\n",a,b);
    return 0;
}