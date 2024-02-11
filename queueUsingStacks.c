#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5

int stack1[CAPACITY];
int stack2[CAPACITY];
int top1 = -1;
int top2 = -1;

bool isEmpty1()
{
    if (top1 == -1)
    {
        return true;
    }
    return false;
}

bool isEmpty2()
{
    if (top2 == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if (top1 == CAPACITY - 1)
    {
        return true;
    }
    return false;
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow");
        return;
    }

    stack1[++top1] = data;
}

int pop()
{
    if (isEmpty1())
    {
        printf("Stack Underflow");
        exit(0);
    }
    while (!isEmpty1())
    {
        stack2[++top2] = stack1[top1--];
    }
    int data = stack2[top2];
    top2--;
    while (!isEmpty2())
    {
        stack1[++top1] = stack2[top2--];
    }
    return data;
}

void printQueue()
{
    if (isEmpty1())
    {
        printf("Empty Stack");
        return;
    }

    for (int i = 0; i <= top1; i++)
    {
        printf("%d  ", stack1[i]);
    }

    printf("\n");
}

void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    pop();
    push(35);
    push(45);
    printQueue();
}