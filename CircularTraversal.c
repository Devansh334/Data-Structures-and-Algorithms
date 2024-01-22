// Circular Traversal

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *end = NULL;

void InsAtB(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Heap Exhausted");
        return;
    }

    temp->data = data;

    if (start == NULL)
    {
        start = end = temp->next = temp;
        return;
    }

    temp->next = start;
    start = end->next = temp;
    // start=temp;
}

void InsAtE(int data)
{
    if (start == NULL)
    {
        InsAtB(data);
        return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Heap Exhausted");
        return;
    }

    temp->data = data;
    end->next = temp;
    temp->next = start;
    end = temp;
}

void CircularTraversal(int x)
{
    if (start == NULL)
    {
        printf("empty list");
        return;
    }

    struct node *temp = start;

    while (temp->data != x)
    {
        temp = temp->next;
        if (start == temp)
        {
            printf("No Data Found");
            return;
        }
    }
    struct node *temp2 = temp;

    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != temp2);
}
void main()
{
    InsAtE(10);
    InsAtE(20);
    InsAtE(30);
    InsAtE(40);
    InsAtE(50);
    InsAtB(0);

    CircularTraversal(30);
}