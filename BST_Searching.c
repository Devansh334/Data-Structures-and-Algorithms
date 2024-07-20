#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *insert(struct node *temp, int data)
{
    if (temp == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (data < temp->data)
    {
        temp->left = insert(temp->left, data);
    }
    else if (data >= temp->data)
    {
        temp->right = insert(temp->right, data);
    }
    return temp;
}

struct node *Search(struct node *temp, int key)
{
    if (temp == NULL)
    {
        return NULL;
    }
    else if (temp->data == key)
    {
        return temp;
    }
    else if (temp->data > key)
    {
        Search(temp->left, key);
    }
    else
    {
        Search(temp->right, key);
    }
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

    struct node *ptr = Search(root, 94);
    if (ptr == NULL)
    {
        printf("Element Not Found\n");
    }
    else
    {
        printf("Element found data : %d\n", ptr->data);
    }
}
