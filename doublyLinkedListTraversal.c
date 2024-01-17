//Doubly Linked Lists

#include<stdio.h>
#include<stdlib.h>		

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

void ShowAll(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

void ShowAllRev(struct node *third)
{
	struct node *temp =third;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->prev;
	}
}
void main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *second=(struct node *)malloc(sizeof(struct node));
	struct node *third=(struct node *)malloc(sizeof(struct node));
	
	head->data=1;
	head->next=first;
	head->prev=NULL;
	
	first->data=2;
	first->next=second;
	first->prev=head;
	
	second->data=3;
	second->next=third;
	second->prev=first;
	
	third->data=4;
	third->next=NULL;
	third->prev=second;
	
	ShowAll(head);
	printf("\n\n");
	ShowAllRev(third);
}