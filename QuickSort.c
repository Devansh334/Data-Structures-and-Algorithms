/*
Quick Sort Algorithm :

Worst Case : o(n2) => WHEN WE HAVE ALREADY SORTED ARRAY !!
Avg case and Best Case : o(nlogn) 
Not Adaptive : Worst Case when already sorted
Not Stable : Order not Maintained
*/

#include <stdio.h>

int partition(int x[], int i, int n)
{
    int p = i;
    int pi = x[n];
    int t;

    while (i < n)
    {
        if (x[i] < pi)
        {
            t = x[i];
            x[i] = x[p];
            x[p] = t;
            p++;
        }
        i++;
    }
    x[n] = x[p];
    x[p] = pi;

    return p;
}

void quickSort(int x[], int si, int n)
{

    if (si >= n)
        return;
    int p = partition(x, si, n);
    quickSort(x, si, p - 1);
    quickSort(x, p + 1, n);
}
void main()
{
    int x[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int n = 9;
    quickSort(x, 0, n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
}
