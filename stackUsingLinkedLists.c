// Stack Using Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    return false;
}

void push(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Stack Overflow");
        return;
    }

    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow");
        exit(0);
    }

    struct node *temp = top;
    int data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack Is Empty");
        exit(0);
    }
    return top->data;
}

void printStack()
{
    if (isEmpty())
    {
        printf("Stack Is Empty");
        exit(0);
    }

    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
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
    push(100);
    printStack();
    printf("\n");
    printf("Peek Element : %d", peek());
}