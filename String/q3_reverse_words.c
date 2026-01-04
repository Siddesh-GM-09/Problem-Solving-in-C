#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void revStr(char *);
void revWord(char *, char *);
int main()
{
    int size;
    printf("Enter the size of string : ");
    scanf("%d", &size);
    char *str = malloc(sizeof(char) * size + 1);
    printf("Enter the string : ");
    scanf(" %[^\n]", str);
    printf("Entered String is : %s\n", str);
    revStr(str);
    printf("After the string : %s\n", str);
    free(str);
    str=NULL;
    return 0;
}
void revStr(char *str)
{
    char *start = str;
    char *end = str;
    int len = strlen(str);
    revWord(str, str + len - 1);
    while (*end)
    {
        if (*end == ' ')
        {
            revWord(start, end - 1);
            start = end + 1;
        }
        end++;
    }
    revWord(start, end - 1);
}

void revWord(char *s, char *l)
{
    while (s < l)
    {
        char t = *s;
        *s = *l;
        *l = t;
        s++;
        l--;
    }
}