#include <stdio.h>
#include <stdlib.h>
int findMin(int *, int);
int main()
{
    int size;
    printf("Enter ths size of array : ");
    scanf("%d", &size);
    int *arr = calloc(size, sizeof(int));
    printf("Enter the inputs : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = findMin(arr, size);
    printf("Min is %d\n", min);
    free(arr);
    arr = NULL;
}
int findMin(int *arr, int size)
{
    static int i = 0, min;
    if (i == 0)
    {
        min = arr[0];
        i = i + 1;
    }
    if (i >= size)
    {
        return min;
    }
    if (arr[i] < min)
    {
        min = arr[i];
    }
    i = i + 1;
    return findMin(arr, size);
}