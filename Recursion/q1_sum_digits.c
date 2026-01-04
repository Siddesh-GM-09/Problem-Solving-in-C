#include <stdio.h>
int sumDig(int);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int sum = sumDig(num);
    printf("Sum is : %d\n", sum);
}

int sumDig(int num){
    if(num==0){
        return 0;
    }
    return (num%10)+sumDig(num/10);
}
// int sumDig(int num)
// {
//     static int sum = 0;
//     if (num)
//     {
//         sum += num % 10;
//         sumDig(num / 10);
//     }
//     return sum;
// }