/*
Radix Sort Algorithm :

Avg case : o(nk) , n: no of elements in array , k: no of digits
Not Adaptive : Best Case O(nk) when already sorted array
Stable : Order Maintained
*/

#include <stdio.h>
#include <stdlib.h>
void show(int x[], int n, int div)
{
    int i;
    int a[10] = {0};
    int y[n];

    int min = x[0];

    for (i = 1; i < n; i++)
    {
        if (min > x[i])
        {
            min = x[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        x[i] = x[i] + abs(min);
    }
    for (i = 0; i < n; i++)
    {
        a[(x[i] / div) % 10]++;
    }
    for (i = 1; i < 10; i++)
    {
        a[i] += a[i - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        y[a[(x[i] / div) % 10] -= 1] = x[i];
    }

    for (i = 0; i < n; i++)
    {
        x[i] = y[i];
    }
    for (i = 0; i < n; i++)
    {
        x[i] = x[i] - abs(min);
    }
}

void display(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void RadixSort(int x[], int n)
{
    int max = x[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (max < abs(x[i]))
        {
            max = abs(x[i]);
        }
    }

    for (i = 1; i <= max; i *= 10)
    {
        show(x, n, i);
    }
}

void main()
{
    int x[] = {329, -457, -57, 1000, 839, 0, 355};
    display(x, 7);
    RadixSort(x, 7);
    display(x, 7);
}