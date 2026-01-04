#include <stdio.h>
#include <stdlib.h>
int findLast(int *, int, int);
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
    printf("Enter the key you want : ");
    scanf("%d", &key);
    int index = findLast(arr, size, key);
    printf("Index is : %d\n", index);
    free(arr);
    arr = NULL;
    return 0;
}
int findLast(int *arr, int size, int key)
{
    static int i = 0, j = -1;
    if (i >= size)
    {
        return j;
    }
    if (arr[i] == key)
    {
        j = i;
    }

    i = i + 1;
    return findLast(arr, size, key);
}