/*
Bubble Sort Algorithm :

Avg case : o(n2)
Can be made Adaptive using Flag (already sorted) : o(n)
Stable : Order Maintained

*/

#include <stdio.h>


void BubbleSort(int arr[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
                flag = 1;
            }
        }
        if (!flag)
            return;
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
    BubbleSort(arr, n);
    printf("After Sort : ");
    Display(arr, n);
}
