#include <stdio.h>
int toggleBit(unsigned int, int, int);
int main()
{
    unsigned int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    int st, lt;
    printf("Enter the start range : ");
    scanf("%d", &st);
    printf("Enter the end range : ");
    scanf("%d", &lt);
    int final = toggleBit(num, st, lt);
    printf("Final number is : %d\n", final);
    return 0;
}
int toggleBit(unsigned int num, int st, int lt)
{
    int mask = (1<<(lt - st + 1))-1;
    mask = mask << st;
    return mask ^ num;
}