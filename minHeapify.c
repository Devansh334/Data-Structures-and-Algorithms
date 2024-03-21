// MIN-HEAPIFY ALGORITHM

#include <stdio.h>

void show(int arr[], int n, int i)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int min = i;
    if (r < n)
    {
        if (arr[l] > arr[r])
        {
            min = r;
        }
        else
        {
            min = l;
        }
    }
    else if (l < n)
    {
        min = l;
    }

    if (arr[min] < arr[i])
    {
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

        show(arr, n, min);
    }
}

void Heapify(int arr[], int n)
{
    int r = n / 2 - 1;

    for (int i = r; i >= 0; i--)
    {
        show(arr, n, i);
    }
}

void main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    Heapify(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}