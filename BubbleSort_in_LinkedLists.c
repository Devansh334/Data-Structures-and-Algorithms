//Bubble Sort on Linked Lists -->

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *next;
};

struct node *start =NULL;

void InsAtB(int data)
{
	
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("Heap Exhausted");
        return;
    }
    temp->data = data;
    temp->next = start;
    start = temp;
}

void InsAtE(int data)
{
	if (start == NULL)
    {
        InsAtB(data);
        return;
    }
    struct node *ins = (struct node *)malloc(sizeof(struct node));

    if (ins == NULL)
    {
        printf("Heap Exhausted");
        return;
    }

    struct node *temp = start;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ins->data = data;
    ins->next = temp->next;
    temp->next = ins;
}
void showAll()
{
    if (start == NULL)
    {
        printf("Empty List");
        return;
    }

    struct node *temp = start;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
	printf("\n");
}

void BubbleSort() {
    if (start == NULL || start->next == NULL) {
        return;
    }

    struct node *ptr;
    int flag;

    do {
        flag = 0;
        ptr = start;

        while (ptr->next != NULL) {
            if ((ptr->data) > (ptr->next->data)) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                flag = 1;
            }
            ptr = ptr->next;
        }
 
    } while (flag);
}

void main()
{
	
	InsAtE(100);
    InsAtE(5);
	InsAtE(-9);
    InsAtE(-1);
    InsAtE(40);
    InsAtB(0);
    InsAtB(30);
	printf("List Before Sort : ");
	showAll();
	BubbleSort();
	printf("List After Sort : ");
	showAll();
	
}