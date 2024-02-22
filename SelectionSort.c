/*
Selection Sort Algorithm:

Avg case : o(n2)
Not Adaptive : Since no benifit in already sorted array
Not Stable : since Order not Maintained !
*/

#include <stdio.h>

void SelectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
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
    SelectionSort(arr, n);
    printf("After Sort : ");
    Display(arr, n);
}
