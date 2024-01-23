// Stack Using Arrays

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5

int stack[CAPACITY];
int top = -1;

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if (top == CAPACITY - 1)
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

    stack[++top] = data;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(0);
    }
    return stack[top--];
}

int peek()
{
    if (isEmpty())
    {
        printf("Empty Stack");
        exit(0);
    }
    return stack[top];
}

void printStack()
{
    if (isEmpty())
    {
        printf("Empty Stack");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
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
    printStack();
    printf("\n");
    printf("Peek Element : %d", peek());
}