// Insertion in Array at Given Index

#include <stdio.h>
#define CAPACITY 100
void insertion();
void display();

void main()
{
    int arr[CAPACITY] = {1, 5, 0, 3, 5, 4};
    int size = 6;
    int index, x;
    printf("Before Insertion : ");
    display(arr, size);
    printf("\nCurrent size of array = %d , Please enter a valid index for insertion: ", size);
    scanf("%d", &index);
    printf("Enter element to be inserted : ");
    scanf("%d", &x);
    insertion(arr, size, index, x);
    size++;
    printf("After Insertion : ");
    display(arr, size);
}

void insertion(int arr[], int size, int index, int x)
{

    if (size >= CAPACITY)
    {
        printf("Array Capacity is FULL !!!!!");
        return;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = x;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
