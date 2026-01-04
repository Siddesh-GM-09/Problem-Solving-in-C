#include <stdio.h>
void fib(int);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    fib(num);
    printf("\n");
}
void fib(int num)
{
    static int a = 0, b = 1, c;
    if (num > 0)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
        fib(num - 1);
    }
}
// int fib(num)
// {
//     if (num == 0)
//     {
//         return 0;
//     }
//     if (num == 1)
//     {
//         return 1;
//     }
//     return fib(num - 1) + fib(num - 2);
// }