// DOUBLE ENDED QUEUE IMPLEMENTATION USING LINKED LIST

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enQueueAtBeg(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Queue is Full");
        return;
    }
    temp->data = data;
    if (isEmpty())
    {
        front = rear = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = front;
        front = temp;
    }
}

void enQueueAtEnd(int data)
{
    if (isEmpty())
    {
        enQueueAtBeg(data);
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Queue is Full");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    rear->next = temp;
    rear = temp;
}

void deQueueAtBeg()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    struct node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void deQueueAtEnd()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    struct node *temp = front;
    struct node *temp2 = rear;
    while (temp->next != rear)
    {
        temp = temp->next;
    }
    rear = temp;
    if (rear == NULL)
    {
        front = NULL;
    }
    rear->next = NULL;
    free(temp2);
}

int FrontPeek()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        exit(0);
    }
    return front->data;
}

int RearPeek()
{
    if (isEmpty())
    {
        printf("Queue is Empty");
        exit(0);
    }
    return rear->data;
}

void printQueue()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enQueueAtBeg(5);
    enQueueAtEnd(15);
    enQueueAtEnd(20);
    enQueueAtBeg(25);

    printQueue();

    deQueueAtEnd();
    deQueueAtBeg();

    printQueue();

    printf("Element at first : %d\n", FrontPeek());
    printf("Element at last : %d\n", RearPeek());

    return 0;
}
