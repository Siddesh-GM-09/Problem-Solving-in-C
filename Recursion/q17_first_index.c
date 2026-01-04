#include <stdio.h>
#include <stdlib.h>
int findIndex(int *, int, int);
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
    printf("Enter the key you want to find : ");
    scanf("%d", &key);
    int index = findIndex(arr, size, key);
    printf("Index is : %d\n", index);
    free(arr);
    arr = NULL;
    return 0;
}
int findIndex(int *arr, int size, int key)
{
    static int i = 0;
    if (i > size)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    i = i + 1;
    return findIndex(arr, size, key);
}