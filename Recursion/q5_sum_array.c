#include <stdio.h>
#include <stdlib.h>
int sumArr(int *, int);
int main()
{
    int s1;
    printf("Enter the size of array : ");
    scanf("%d", &s1);
    int *arr = malloc(sizeof(int) * s1);
    printf("Enter the inputs : ");
    for (int i = 0; i < s1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = sumArr(arr, s1);
    printf("Sum is %d\n", sum);
    free(arr);
    return 0;
}
int sumArr(int *arr, int size)
{
    static int sum = 0, i = 0;
    if (i < size)
    {
        sum += arr[i];
        i = i + 1;
        sumArr(arr, size);
    }
    return sum;
}