#include<stdio.h>
unsigned int reverseBits(unsigned int n);
int main(){
    unsigned int num;
    printf("Enter the number : ");
    scanf("%u",&num);
    unsigned int final=reverseBits(num);
    printf("Final Number : %u\n",final);
    return 0;
}
unsigned int reverseBits(unsigned int n){
    for(int i=0,j=31;i<j;i++,j--){
        unsigned int a=n>>i&1;
        unsigned int b=n>>j&1;
        if(a!=b){
            n=n^(1<<i);
            n=n^(1<<j);
        }
    }
    return n;
}