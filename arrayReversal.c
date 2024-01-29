// Array Reversal

#include <stdio.h>

void Rev(int arr[], int n)
{
    int j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j--] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    Rev(arr1, 5);

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Rev(arr2, 10);
}