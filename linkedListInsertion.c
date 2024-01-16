// Linked List Insertion

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

void InsAtE(int data)
{
    if (start == NULL)
    {
        InsAtB(data);
        return;
    }
    struct node *ins = (struct node *)malloc(sizeof(struct node));

    if (ins == NULL)
    {
        printf("Heap Exhausted");
        return;
    }

    struct node *temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ins->data = data;
    ins->next = temp->next;
    temp->next = ins;
}

int count()
{
    struct node *temp = start;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void InAtIndex(int data, int index)
{
    if (index <= 0)
    {
        InsAtB(data);
        return;
    }
    else if (index > count())
    {
        InsAtE(data);
        return;
    }

    struct node *ins = (struct node *)malloc(sizeof(struct node));

    if (ins == NULL)
    {
        printf("Heap Exhausted");
        return;
    }

    int i = 0;
    struct node *temp = start;

    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    ins->data = data;
    ins->next = temp->next;
    temp->next = ins;
}

void rev(struct node *temp)
{
    if (temp == NULL)
    {
        return;
    }
    rev(temp->next);
    printf("%d\n", temp->data);
}

void showAllRev()
{
    rev(start);
}

void showAll()
{
    if (start == NULL)
    {
        printf("Empty List");
        return;
    }

    struct node *temp = start;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main()
{
    InsAtE(10);
    InsAtE(20);
    InsAtE(30);
    InsAtE(40);
    InsAtE(50);
    InsAtB(0);
    InsAtB(-10);
    InAtIndex(-20, 0);

    showAll();
    printf("\n\n");
    showAllRev();
}