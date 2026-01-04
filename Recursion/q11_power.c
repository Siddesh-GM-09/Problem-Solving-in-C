#include <stdio.h>
int powerNo(int, int);
int main()
{
    int x, n;
    printf("Enter the number : ");
    scanf("%d", &x);
    printf("Enter the power : ");
    scanf("%d", &n);
    int num = powerNo(x, n);
    printf("Result : %d\n", num);
    return 0;
}
int powerNo(int x, int y)
{
    static int num = 1;
    if (y > 0)
    {
        num = num * x;
        powerNo(x, y - 1);
    }
    return num;
}
