// Insertion and Deletion in Doubly Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    temp->prev = NULL;
    temp->next = start;
    if (start != NULL)
    {
        start->prev = temp;
    }
    else
    {
        end = temp;
    }
    start = temp;
}
void ShowAll()
{
    if (start == NULL)
    {
        printf("empty List");
        return;
    }

    struct node *temp = start;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
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
    temp->next = NULL;
    temp->prev = end;
    end->next = temp;
    end = temp;
}
int count()
{
    struct node *temp = start;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

void ShowAllRev()
{
    if (start == NULL)
    {
        printf("empty List");
        return;
    }

    struct node *temp = end;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->prev;
    }
}

void InsAtIndex(int p, int data)
{
    if (p <= 0)
    {
        InsAtB(data);
        return;
    }
    else if (p >= count())
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
    struct node *temp = start;
    for (int i = 0; i < p - 1; i++)
    {
        temp = temp->next;
    }
    temp->next->prev = ins;
    ins->next = temp->next;
    temp->next = ins;
    ins->prev = temp;
    ins->data = data;
}

void DelAtB()
{
    if (start == NULL)
    {
        printf("Empty List");
        return;
    }

    struct node *temp = start;

    if (start->next == NULL)
    {
        free(temp);
        start = end = NULL;
        return;
    }

    start = start->next;
    start->prev = NULL;
    free(temp);
}

void DelAtE()
{
    if (start == NULL || start->next == NULL)
    {
        DelAtB();
        return;
    }

    struct node *temp = end;
    end = end->prev;
    free(temp);
    end->next = NULL;
}

void DelAtIndex(int p)
{
    if (p <= 0)
    {
        DelAtB();
        return;
    }
    else if (p >= count() - 1)
    {
        DelAtE();
        return;
    }
    struct node *temp = start;
    struct node *temp2 = start;
    for (int i = 0; i < p; i++)
    {

        temp = temp->next;
    }
    temp2 = temp->prev;

    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
}

void main()
{
    InsAtE(10);
    InsAtE(20);
    InsAtE(30);
    InsAtE(40);
    InsAtE(50);
    InsAtB(0);
    InsAtIndex(2, 100);
    DelAtB();
    DelAtE();
    DelAtIndex(2);
    ShowAll();
    printf("\n\n");
    ShowAllRev();
}