#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPali(char *);
void main()
{
    int s1;
    printf("Enter the size of string : ");
    scanf("%d", &s1);
    char *str = malloc(sizeof(char) * s1);
    printf("Enter the input string : ");
    scanf(" %[^\n]", str);
    printf("Entered String is : ");
    printf("%s\n", str);
    int found = isPali(str);
    if (found)
    {
        printf("Yes,Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }
    free(str);
    str = NULL;
}

int isPali(char *str)
{
    int len = strlen(str);
    int k = 0;
    char *copy = malloc(sizeof(char) * len + 1);
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch ^ 32;
            }
            copy[k++] = ch;
        }
    }
    copy[k] = '\0';
    int i, j;
    i = 0;
    j = k - 1;
    while (i < j)
    {
        if (copy[i] != copy[j])
        {
            free(copy);
            copy = NULL;
            return 0;
        }
        i++;
        j--;
    }
    free(copy);
    copy = NULL;
    return 1;
}
