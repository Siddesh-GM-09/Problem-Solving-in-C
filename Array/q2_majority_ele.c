/*
3. Majority Element
Problem: Find element appearing more than n/2 times.
Function Prototype: int majority(int arr[], int n);
Sample Input:
3 2 3
Expected Output:
3
Hint: Boyer–Moore voting algorithm.
*/
#include <stdio.h>
#include <stdlib.h>
int majority(int *, int);
int main()
{
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int *arr = malloc(sizeof(int) * size);
    printf("Enter the inputs : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int n1 = majority(arr, size);
    printf("Majority number is : %d\n", n1);
    return 0;
}
int majority(int *arr, int size)
{
    int cnt = 0, i;
    int el;
    for (i = 0; i < size; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (el == arr[i])
        {
            cnt++;
        }
    }
    if (cnt > size / 2)
    {
        return el;
    }
    return -1;
}