#include <stdio.h>
#include <stdlib.h>
int sorted(int *, int);
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * size);
    printf("Enter the inputs : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int found = sorted(arr, size);
    if (found)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    free(arr);
    return 0;
}
int sorted(int *arr, int size)
{
    static int i = 0;
    if (i < size-1)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
        i = i + 1;
        sorted(arr, size);
    }
    return 1;
}