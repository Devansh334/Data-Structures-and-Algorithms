// Ordered Linear Search Algorithm ---> o(n)

#include <stdio.h>
void main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int target;
    printf("Enter value to be searched : ");
    scanf("%d", &target);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            printf("Element found at index : %d\n", i);
            return;
        }

        else if (arr[i] > target )
        {
            printf("Element not found\n");
            return;
        }
    }

    printf("Element not found\n");
}
