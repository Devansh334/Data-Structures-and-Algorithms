//Insertion and Deletion in Circular Singly Linked Lists

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *end=NULL;

void ShowAll()
{
	
	if(start==NULL){
		printf("Empty List");
		return;
	}
	
	struct node *temp=start;
	
	do{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	while(temp!=start);
}


void InsAtB(int data)
{
	struct node *temp=(struct node*)malloc (sizeof(struct node));
	
	if(temp==NULL){
		printf("Heap Exhausted");
		return;
	}
	
	temp->data=data;
	
	if(start==NULL){
		start=end=temp->next=temp;
		return;
	}
	
	temp->next=start;
	start=end->next=temp;
	//start=temp;
	
}

void InsAtE(int data)
{
	if(start==NULL){
		InsAtB(data);
		return;
	}
	
	struct node *temp=(struct node*)malloc (sizeof(struct node));
	
	if(temp==NULL){
		printf("Heap Exhausted");
		return;
	}
	
	temp->data=data;
	end->next=temp;
	temp->next=start;
	end=temp;
}

void rev(struct node *temp)
{
	if(temp==end)return;
	rev(temp->next);
	printf("%d\n",temp->data);
}

void RevShow()
{
	printf("%d\n",end->data);
	struct node *temp=start;
	rev(temp);
}

void DelAtB()
{
	if(start==NULL){
		printf("Empty List");
		return;
	}
	if(start==end){
		struct node *temp=start;
		start=end=NULL;
		free(temp);
		return;
	}
	struct node *temp=start;
	start=start->next;
	end->next=temp->next;
	free(temp);
}

void DelAtE()
{
	if(start==end || start==NULL){
		DelAtB();
		return;
	}
	struct node *temp=start;
	struct node *temp2;
	
	while(temp!=end){
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=start;
	end=temp2;
	free(temp);
	
	
}

void main()
{
	InsAtE(10);
	InsAtE(20);
	InsAtE(30);
	InsAtE(40);
	InsAtE(50);
	InsAtB(0);
	DelAtB();
	DelAtE();
	ShowAll();
	printf("\n\n");
	RevShow();
	
}