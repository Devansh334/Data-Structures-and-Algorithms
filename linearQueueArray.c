// LINEAR QUEUE IMPLEMENTATION USING ARRAY

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CAPACITY 5

int f = -1;
int r = -1;
int queue[CAPACITY];

bool isEmpty()
{
    if (f == -1 || f > r)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if (r == CAPACITY - 1)
    {
        return true;
    }
    return false;
}

void enQueue(int data)
{

    if (isFull())
    {
        printf("Queue is Full");
        return;
    }
    if (f == -1)
    {
        f++;
    }

    queue[++r] = data;
}

void deQueue()
{

    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    f++;
}

int peek()
{

    if (isEmpty())
    {
        printf("Queue is Empty");
        exit(0);
    }
    return queue[f];
}

void printQueue()
{

    for (int i = f; i <= r; i++)
    {
        printf("%d  ", queue[i]);
    }
    printf("\n");
}

void main()
{
    enQueue(5);
    enQueue(15);
    enQueue(20);
    enQueue(25);

    printQueue();

    deQueue();
    deQueue();

    printQueue();

    printf("Element at first : %d\n", peek());
}