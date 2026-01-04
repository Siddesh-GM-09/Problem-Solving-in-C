#include <stdio.h>
#include <stdlib.h>
int subArr(int *, int, int);
void main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * size);
    printf("Enter the array elements : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Entered Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int target;
    printf("Enter the target sum : ");
    scanf("%d", &target);
    int maxLen = subArr(arr, size, target);
    printf("Max Length is : %d\n", maxLen);
    free(arr);
    arr = NULL;
}
int subArr(int *arr, int size, int target)
{
    int maxLen = 0, sum = 0, r = 0, l = 0;
    int start = 0, end = 0;
    while (r < size)
    {
        sum += arr[r];
        if (sum > target)
        {
            sum = sum - arr[l];
            l++;
        }
        if (r - l + 1 > maxLen)
        {
            maxLen = r - l + 1;
            start = l;
            end = r;
        }
        r = r + 1;
    }
    printf("Sub array is : ");
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    return maxLen;
}
