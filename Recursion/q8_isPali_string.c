#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPali(char *);
int main()
{
    int size;
    printf("Enter the size of string : ");
    scanf("%d", &size);
    char *str = malloc(sizeof(char) * size + 1);
    printf("Enter the string : ");
    scanf(" %[^\n]", str);
    int flag = isPali(str);
    if (flag)
    {
        printf("Yes,Palindrome\n");
    }
    else
    {
        printf("Not ,Palindrome\n");
    }
    free(str);
    str = NULL;
}

int isPali(char *str)
{
    static int left = 0, right = -1;
    if (right == -1)
    {
        right = strlen(str) - 1;
    }
    if (left > right)
    {
        return 1;
    }
    if (str[left] != str[right])
    {
        return 0;
    }
    left = left + 1;
    right = right - 1;
    return isPali(str);
}