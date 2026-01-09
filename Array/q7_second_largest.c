/*
Write a C program to:
Dynamically allocate memory for an integer array,
Read N elements from the user,
Find and print the second largest element in the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void findSec(int *, int);
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * size);
    if (arr == NULL)
    {
        printf("Memory Not Allocated \n");
        return 0;
    }
    printf("Enter the inputs : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    findSec(arr, size);
    free(arr);
    arr = NULL;
    return 0;
}
void findSec(int *arr, int size)
{
    if (size < 2)
    {
        printf("Not Possible!!\n");
        return;
    }
    int l = INT_MIN, sl = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > l)
        {
            sl = l;
            l = arr[i];
        }
        else if (arr[i] < l && arr[i] > sl)
        {
            sl = arr[i];
        }
    }
    if (sl == INT_MIN)
    {
        printf("Elements Don't Exist\n");
    }
    else
    {
        printf("second largest is : %d\n", sl);
    }
}