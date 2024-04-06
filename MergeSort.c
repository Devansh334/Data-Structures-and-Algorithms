/*
Merge Sort Algorithm :

Avg case : o(nlogn)
Adaptive : Not adaptive
Stable : Order Maintained

*/

#include <stdio.h>

void Merge(int a[], int b[], int arr[], int m1, int m2)
{
    int i, j, k;

    for (i = 0, j = 0, k = 0; i < m1 && j < m2;)
    {

        if (a[i] < b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }

    while (i < m1)
    {
        arr[k++] = a[i++];
    }

    while (j < m2)
    {
        arr[k++] = b[j++];
    }
}

void Divide(int arr[], int n)
{
    if (n <= 1)
        return;

    int m1 = n / 2;
    int m2 = n - m1;

    int a[m1], b[m2];

    for (int i = 0; i < m1; i++)
    {
        a[i] = arr[i];
    }

    for (int j = 0; j < m2; j++)
    {
        b[j] = arr[m1 + j];
    }

    Divide(a, m1);
    Divide(b, m2);

    Merge(a, b, arr, m1, m2);
}

void main()
{
    int arr[] = {3, 5, -4, 1, 9, -9, 4, 7, 5, 6};
    int n = 10;

    Divide(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
