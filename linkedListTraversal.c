#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void showall(struct node *ptr)
{
    while (ptr->next != NULL)
    {
        printf("%d ,", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));

    head->data = 11;
    head->next = first;

    first->data = 12;
    first->next = second;

    second->data = 15;
    second->next = NULL;

    showall(head);

    free(head);
    free(first);
    free(second);

    return 0;
}
