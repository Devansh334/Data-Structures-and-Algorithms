#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;

        return root;
    }

    struct node *current = root;
    struct node *parent = root;

    while (current != NULL)
    {
        parent = current;

        if (current->data > data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    current = (struct node *)malloc(sizeof(struct node));
    current->data = data;
    current->left = NULL;
    current->right = NULL;

    if (parent->data > data)
    {
        parent->left = current;
    }
    else
    {
        parent->right = current;
    }

    return root;
}

void main()
{
    root = insert(root, 10);
    insert(root, 73);
    insert(root, 14);
    insert(root, 36);
    insert(root, 94);
    insert(root, 55);
    insert(root, 78);
    insert(root, 10);
    printf("Values Inserted Successfully !!");
}
