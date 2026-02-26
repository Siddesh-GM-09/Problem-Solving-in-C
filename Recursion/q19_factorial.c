/* Find factorial using recursion. 
Input: 5 
Output: 120*/
#include<stdio.h>
int factNum(int);
int main(){
    int num,res;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Entered Number : %d\n",num);
    res=factNum(num);
    printf("Factorial is : %d\n",res);
    return 0;
}
int factNum(int num){
    if(num==0){
        return 1;
    }
    return num*factNum(num-1);
}