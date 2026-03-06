/*Count number of 1 bits in binary representation.
Sample Input: 5
Sample Output:Set Bits = 2*/

#include<stdio.h>
int setBit(int);
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Total Number of set bits are : %d\n",setBit(num));
    return 0;
}
int setBit(int num){
    int cnt=0;
    while(num){
        if(num&1){
            cnt++;
        }
        num>>=1;
    }
    return cnt;
}