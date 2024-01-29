// String Reversal Using Stacks

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define CAPACITY 50

char stack[CAPACITY];
int top = -1;

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void push(char data)
{
    stack[++top] = data;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

void main()
{
    char input[CAPACITY];
    char output[CAPACITY];

    printf("Enter Input String : ");
    gets(input);

    int i = 0;
    while (input[i] != '\0')
    {
        push(input[i++]);
    }

    int k = 0;
    while (!isEmpty())
    {
        output[k++] = pop();
    }

    output[k++] = '\0';

    printf("Reversed String  : ");
    puts(output);
}