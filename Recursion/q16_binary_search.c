#include <stdio.h>
#include <stdlib.h>
int findIndex(int *, int, int, int);
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
    int key;
    printf("Enter the number you want to find : ");
    scanf("%d", &key);
    int flag = findIndex(arr, 0, size - 1, key);
    printf("The index is : %d\n", flag);
    free(arr);
    arr = NULL;
    return 0;
}
int findIndex(int *arr, int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (key > arr[mid])
    {
        return findIndex(arr, mid + 1, high, key);
    }
    else
    {
        return findIndex(arr, low, mid - 1, key);
    }
}