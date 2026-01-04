#include <stdio.h>
int rec(int);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int revno = rec(num);
    if (revno == num)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No");
    }
    return 0;
}
int rec(int num)
{
    static int rev = 0;
    if (num)
    {
        rev = rev * 10 + (num % 10);
        rec(num / 10);
    }
    return rev;
}