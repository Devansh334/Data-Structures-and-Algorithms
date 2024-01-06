// Insertion in Array as Abstract Data Type

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100
int size = 6;
void insertAtIndex();
void display();
void insertAtBeg();
void insertAtEnd();

void main()
{
    int arr[CAPACITY] = {1, 5, 0, 3, 5, 4};
    int ch, x;
    int in, y;

M:
    printf("Press 1 to insert at Begning\n");
    printf("Press 2 to insert at End\n");
    printf("Press 3 to insert at given index\n");
    printf("Press 4 to display the array\n");

    printf("Enter choice here  :  ");

    scanf("%d", &ch);

    switch (ch)
    {
    case 1:

        printf("Enter the element to be inserted   :  ");
        scanf("%d", &x);
        insertAtBeg(arr, x);
        break;

    case 2:

        printf("Enter the element to be inserted   :  ");
        scanf("%d", &x);
        insertAtEnd(arr, x);
        break;

    case 3:

        printf("Enter the element to be inserted   :  ");
        scanf("%d", &x);
        printf("Enter valid index  :  \n");
        scanf("%d", &in);
        insertAtIndex(arr, in, x);
        break;

    case 4:
        display(arr);
        break;

    default:
        printf("SYNTAX ERROR\n");
        break;
    }
    printf("\nPress 1 to ReInsert Data    :   ");
    scanf("%d", &y);
    if (y == 1)
    {
        goto M;
    }
    else
    {
        exit(0);
    }
}

void insertAtIndex(int arr[], int index, int x)
{

    if (size >= CAPACITY)
    {
        printf("Array Capacity is FULL !!!!!");
        return;
    }
    if (index == 0)
    {
        insertAtBeg(arr, x);
        return;
    }
    else if (index == size - 1)
    {
        insertAtEnd(arr, x);
        return;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = x;
    size = size + 1;
    printf("ELEMENT INSERTED\n");
}

void display(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertAtBeg(int arr[], int x)
{
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = x;
    size = size + 1;
    printf("ELEMENT INSERTED\n");
}
void insertAtEnd(int arr[], int x)
{

    arr[size++] = x;
    printf("ELEMENT INSERTED\n");
}