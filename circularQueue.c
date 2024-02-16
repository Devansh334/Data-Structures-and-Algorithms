// Circular Quueues :

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CAPACITY 5

int queue[CAPACITY];
int f = -1;
int r = -1;

bool isEmpty()
{

    if (r == f)
        return true;
    return false;
}

bool isFull()
{
    if ((r + 1) % CAPACITY == f)
        return true;
    return false;
}

void Enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is Full");
        return;
    }

    if (f == -1)
    {
        f = (f + 1) % CAPACITY;
    }
    r = (r + 1) % CAPACITY;
    queue[r] = data;
}

void Dequeue()
{

    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    f = (f + 1) % CAPACITY;
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

    if (isEmpty())
    {
        printf("Queue is Empty");
        return;
    }
    int i = f;
    while (i != r)
    {
        printf("%d  ", queue[i]);

        i = (i + 1) % CAPACITY;
    }
    printf("%d  ", queue[i]);
    printf("\n");
}

void main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Dequeue();
    Dequeue();
    Enqueue(60);
    Enqueue(70);

    printQueue();
}