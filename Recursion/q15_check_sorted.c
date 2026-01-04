#include <stdio.h>
#include <stdlib.h>
int findSort(int *, int);
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
    int flag = findSort(arr, size);
    if (flag)
    {
        printf("Yes,Sorted\n");
    }
    else
    {
        printf("Not Sorted\n");
    }
    free(arr);
    arr = NULL;
    return 0;
}
int findSort(int *arr, int size)
{
    static int i = 0;
    if (i >= size - 1)
    {
        return 1;
    }
    if (arr[i] > arr[i + 1])
    {
        return 0;
    }
    i = i + 1;
    return findSort(arr, size);
}