#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *revSt(char *);
int main()
{
    int size;
    printf("Enter the size of string : ");
    scanf("%d", &size);
    char *str = malloc(sizeof(char) * size + 1);
    printf("Enter the string : ");
    scanf(" %[^\n]", str);
    char *final = revSt(str);
    printf("Revcersed String is : %s\n", final);
    free(str);
    str = NULL;
}
char *revSt(char *str)
{
    static int left = 0, right = -1;
    if (right == -1)
    {
        right = strlen(str) - 1;
    }
    if (left >= right)
    {
        return str;
    }
    char ch = str[left];
    str[left] = str[right];
    str[right] = ch;
    left = left + 1;
    right = right - 1;
    return revSt(str);
}