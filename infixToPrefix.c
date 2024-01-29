// Infix to Prefix

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

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else
        return 0;
}

void main()
{
    char input[CAPACITY];
    char output[CAPACITY];

    printf("Enter the Expression : ");
    scanf("%s", input);
    strrev(input);

    int j = 0;
    while (input[j] != '\0')
    {
        if (input[j] == '(')
        {
            input[j] = ')';
        }
        else if (input[j] == ')')
        {
            input[j] = '(';
        }
        j++;
    }

    int i = 0, k = 0;

    while (input[i] != '\0')
    {
        if (input[i] == '(')
        {
            push(input[i]);
        }
        else
        {

            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                output[k++] = input[i];
            }

            else if (input[i] == ')')
            {
                while (peek() != '(')
                {
                    output[k++] = pop();
                }
                pop();
            }

            else
            {

                while (priority(input[i]) <= priority(peek()))
                {
                    output[k++] = pop();
                }
                push(input[i]);
            }
        }

        i++;
    }

    output[k++] = '\0';
    strrev(output);
    printf(" Prefix Expression : %s", output);
}