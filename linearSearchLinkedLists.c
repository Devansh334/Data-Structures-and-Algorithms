// Linear Search in Linked Lists ->

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void InsAtB(int data)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Heap Exhausted");
        return;
    }
    temp->data = data;
    temp->next = start;
    start = temp;
}

void LinearSearch(int data)
{
    int i = -1, flag = 0;
    if (start == NULL)
    {
        printf("Element %d not Found\n", data);
    }
    struct node *temp = start;

    while (temp != NULL)
    {
        i++;
        if (temp->data == data)
        {
            printf("Element %d found at index : %d\n", data, i);
            flag = 1;
        }
        temp = temp->next;
    }

    if (flag == 0)
    {
        printf("Element %d Not Found\n", data);
    }
}

void main()
{
    InsAtB(50);
    InsAtB(20);
    InsAtB(30);
    InsAtB(20);
    InsAtB(10);
    InsAtB(0);

    LinearSearch(20);
    LinearSearch(0);
    LinearSearch(100);
}