/*
Heap Sort Algorithm :

Avg case : o(nlogn)
Not Adaptive : Not Adaptive
Stable : Not Stable
*/

#include <stdio.h>

void show(int arr[], int n, int i)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int min = i;
    if (r < n)
    {
        if (arr[l] < arr[r])
        {
            min = l;
        }
        else
        {
            min = r;
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

void heapify(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        show(arr, n, i);
    }
}

void DelInHeap(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {

        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr, i); // or show(arr,i,0);
    }
}

void main()
{
    int arr[] = {8, 3, 4, 7, 2, 5, -4, 0, -6, 1};
    int n = 10;

    heapify(arr, n);
    DelInHeap(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
