#include <stdio.h>
#include <stdlib.h>
char nonRep(const char *);
int main()
{
    int size;
    printf("Enter the size of string : ");
    scanf("%d", &size);
    char *str = malloc(sizeof(char) * size + 1);
    printf("Enter the string : ");
    scanf(" %[^\n]", str);
    printf("Entered string is %s\n", str);
    char ch = nonRep(str);
    printf("Char is %c\n", ch);
    free(str);
    str = NULL;
    return 0;
}

char nonRep(const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        int cnt = 0;
        char ch = str[i];
        for (int j = i + 1; str[j]; j++)
        {
            if (str[i] == str[j])
            {
                cnt++;
            }
        }
        if (cnt == 0)
        {
            return ch;
        }
    }
    return 0;
}