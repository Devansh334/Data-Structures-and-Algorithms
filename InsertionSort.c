/*
Insertion Sort Algorithm :

Avg case : o(n2)
Adaptive : Best Case O(n) when already sorted array
Stable : Order Maintained

*/

#include <stdio.h>

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
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
    int arr[10] = {7, -2, 0, 1, 4, 9, 11, 3, 5, 10};

    int n = 10;
    printf("Before Sort : ");
    Display(arr, n);
    InsertionSort(arr, n);
    printf("After Sort : ");
    Display(arr, n);
}
