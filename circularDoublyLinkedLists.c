//Circular Doubly Linked Lists 

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
	
};

struct node *start=NULL;
struct node *end=NULL;

void InsAtB(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	
	if(temp==NULL){
		printf("Heap Exhausted");
		return;
	}
	
	temp->data=data;
	if(start==NULL){
		start=end=temp->prev=temp->next=temp;
		return;
	}
	temp->prev=end;
	end->next=temp;
	temp->next=start;
	start->prev=temp;
	start=temp;
	
}

void ShowAll()
{
	struct node *temp= start;
	do{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	while(temp!=start);
}

void ShowAllRev()
{
	struct node *temp= end;
	do{
		printf("%d\n",temp->data);
		temp=temp->prev;
	}
	while(temp!=end);
}

void InsAtE(int data){
	
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
	temp->next=start;
	start->prev=temp;
	end->next=temp;
	temp->prev=end;
	end=temp;
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
	end->next=start;
	start->prev=end;
	free(temp);
}

void DelAtE()
{
	if(start==NULL || start==end){
		DelAtB();
		return;
	}
	
	struct node *temp=end;
	end = end ->prev;
	end->next=start;
	start->prev=end;
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
	ShowAllRev();
}