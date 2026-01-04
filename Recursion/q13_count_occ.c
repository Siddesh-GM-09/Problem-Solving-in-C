#include <stdio.h>
#include <stdlib.h>
int findOcc(int *, int, int);
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
    printf("Enter the key to search : ");
    scanf("%d", &key);
    int cnt = findOcc(arr, size, key);
    printf("Result : %d\n", cnt);
    free(arr);
    arr = NULL;
    return 0;
}
int findOcc(int *arr, int size, int key)
{
    static int cnt = 0, i = 0;
    if (i >= size)
    {
        return cnt;
    }
    if (arr[i] == key)
    {
        cnt++;
    }
    i = i + 1;
    return findOcc(arr, size, key);
}