// Balanced Parentheses

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define CAPACITY 50

char stack[CAPACITY];
int top = -1;

bool isEmpty(){
	if(top==-1){
		return true;
	}
	return false;
}

bool isFull(){
	if(top==CAPACITY-1){
		return true;
	}
	return false;
}

void push(char data)
{
	if(isFull()){
		printf("Stack Overflow");
		return;
	}
	
	stack[++top]=data;
}

char pop()
{
	if(isEmpty()){
		printf("Stack Underflow");
		exit(0);
	}
	return stack[top--];
}

char peek()
{
	if(isEmpty()){
		printf("Empty Stack");
		exit(0);
	}
	return stack[top];
}

void printStack()
{
	if(isEmpty()){
		printf("Empty Stack");
		return;
	}
	
	for(int i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	}
}

bool IsValid(char str[])
{
	int i=0;
	while(str[i]!='\0'){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			push(str[i]);
		}
		else if(str[i]==')'||str[i]=='}'||str[i]==']'){
			
			if(isEmpty()){
				return false;
			}
			else if(str[i]==')'){
				if(peek()=='('){
					pop();
				}
				else{
					return false;
				}
			}
		else if(str[i]=='}'){
				if(peek()=='{'){
					pop();
				}
				else{
					return false;
				}
			}
			else if(str[i]==']'){
				if(peek()=='['){
					pop();
				}
				else{
					return false;
				}
			}
		}
		
		i++;
	}
	
	if(isEmpty()){
		return true;
	}
	return false;
}

void main()
{
	char input[CAPACITY];
	printf("Enter input String : ");
	gets(input);
	if(IsValid(input)){
		printf("Balanced Parentheses : ");
		puts(input);
	}
	else{
		printf("Unbalanced Parentheses : ");
		puts(input);
	}
}