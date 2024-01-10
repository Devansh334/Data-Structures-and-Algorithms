// Linear Search Algorithm  o(n) ---->

#include <stdio.h>
int main()
{
    int arr[] = {5, 7, 3, 2, 0, 1, 5, 7};
    int n = 8;
    int x, ch = 1;
    printf("Enter value to be searched : ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("Element found at Index : %d\n", i);
            ch = 0;
        }
    }
    if (ch)
    {
        printf("Element Not Found");
    }
    return 0;
}