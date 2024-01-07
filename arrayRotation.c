// Rotation in Arrays---->

#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int k;
    printf("Enter number of Rotations : ");
    scanf("%d", &k);
    int n = 10;

    int val;
    while (k > 0)
    {
        val = arr[n - 1];
        for (int i = n - 1; i > 0; i--)
        {

            arr[i] = arr[i - 1];
        }

        arr[0] = val;
        display(arr, n);
        k--;
    }
}