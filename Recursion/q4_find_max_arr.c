#include <stdio.h>
#include <stdlib.h>
int find(int *, int);
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
    int max = find(arr, size);
    printf("Max is %d\n", max);
    free(arr);
}
int find(int *arr, int size)
{
    static int max, i = 0;
    if (i == 0)
    {
        max = arr[0];
    }
    if (i < size)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        i = i + 1;
        find(arr, size);
    }
    return max;
}