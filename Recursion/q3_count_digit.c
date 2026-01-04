#include <stdio.h>
int count(int);
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int cnt = count(num);
    printf("Count is %d\n", cnt);
    return 0;
}
int count(int num)
{
    static int cnt = 0;
    if (num != 0)
    {
        cnt++;
        count(num / 10);
    }
    return cnt;
}