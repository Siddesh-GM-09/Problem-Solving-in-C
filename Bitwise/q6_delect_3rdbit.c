#include <stdio.h>
#include <stdlib.h>
void delectBit(int *, int);
int main()
{
    int size;
    printf("Enter the size os array : ");
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * size);
    printf("Enter the inputs : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    delectBit(arr, size);
    printf("Final : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
void delectBit(int *arr, int size)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        num = arr[i];
        num = (num & 3) | (num >> 1);
        arr[i] = num;
    }
}