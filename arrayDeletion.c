// Deletion in Array as Abstract Data Type

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 100

int size = 6;

void deleteAtIndex();
void display();
void deleteAtBeg();
void deleteAtEnd();

void main()
{
    int arr[CAPACITY] = {1, 5, 0, 3, 5, 4};
    int ch;
    int in, y;

M:
    printf("Press 1 to Delete at Begning\n");
    printf("Press 2 to Delete at End\n");
    printf("Press 3 to Delete at given index\n");
    printf("Press 4 to display the array\n");

    printf("Enter choice here  :  ");

    scanf("%d", &ch);

    switch (ch)
    {
    case 1:

        deleteAtBeg(arr);
        break;

    case 2:

        deleteAtEnd(arr);
        break;

    case 3:

        printf("Enter valid index  :  \n");
        scanf("%d", &in);
        deleteAtIndex(arr, in);
        break;

    case 4:
        display(arr);
        break;

    default:
        printf("SYNTAX ERROR\n");
        return;
    }
    printf("\nPress 1 to Redelete Data    :   ");
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

void deleteAtIndex(int arr[], int index)
{

    if (size == 0)
    {
        printf("Empty Array");
        return;
    }
    if (index == 0)
    {
        deleteAtBeg(arr);
        return;
    }
    else if (index == size - 1)
    {
        deleteAtEnd(arr);
        return;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size = size - 1;
    printf("ELEMENT DELETED\n");
}

void display(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void deleteAtBeg(int arr[])
{
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size = size - 1;
    printf("ELEMENT DELETED\n");
}
void deleteAtEnd(int arr[])
{
    size = size - 1;
    printf("ELEMENT DELETED\n");
}
