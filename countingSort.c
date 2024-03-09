/*
Count Sort Algorithm :

Avg case : o(n)
Not Adaptive : Best Case O(n) when already sorted array
Stable : Order Maintained
*/

#include <stdio.h>
#include <stdlib.h>

void CountSort(int arr[], int n)
{

    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] + abs(min);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }
    int x = arr[max] + 1;
    int count[x];
    int sol[n];

    for (int i = 0; i < x; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i < x; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        sol[count[arr[i]] -= 1] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = sol[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - abs(min);
    }
}

void Display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[] = {-51, 0, -100, 54, 32, 110, 70, 70};
    int n = 8;
    printf("Before Sort : ");
    Display(arr, n);
    CountSort(arr, n);
    printf("After Sort : ");
    Display(arr, n);
}