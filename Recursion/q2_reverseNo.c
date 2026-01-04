#include <stdio.h>
int revNo(int);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int rev = revNo(num);
    printf("Reverse number : %d\n", rev);
    return 0;
}
int revNo(int num)
{
    static int r = 0;
    if (num != 0)
    {
        r = r * 10 + (num % 10);
        revNo(num / 10);
    }
    return r;
}