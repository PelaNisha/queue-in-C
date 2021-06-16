// array implementation for linear queue

#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int lqueue[SIZE];
int front = -1, rear = -1;

void insert(int);
void display();
bool isEmpty();
bool isFull();
int peek();
void del();

void insert(int item)
{
	if (isFull() == true)
		printf("STack is full\n");
	else if(isEmpty() == true)
	{
			front=0; rear=0;
			lqueue[rear]=item;
	}
	else{
			
			lqueue[++rear]=item;	
}}

void del()
{
	int item;
	if(isEmpty()==true)
		printf("Empty");
	else if(rear==front)
		{
				item = lqueue[front];
			rear == front ==-1;
		}
	else
		item = lqueue[front];
		front++;	
}

bool isEmpty()
{
	return rear==-1 && front==-1;
}
bool isFull()
{
	return rear== SIZE-1;
}
int peek()
{
	if(isEmpty()==true)
		printf("Empty, Nothing to peek\n");
	else
		printf("%d\n",lqueue[front]);
}
void display()
{
//	int temp = front;
	if(isEmpty()==true)
	{
		printf("Nothing to display\n");
	}
	else
		
		for(int i = front; i<=rear; i++)
		{
				printf("%d | \n",lqueue[i]);
	}
}

int main()
{
	int a, p =1, v;
//	printf("%d\n", rear);
//	printf("%d\n", lqueue[front]);
//	printf("%d\n", lqueue[front]);
	while(p!=0)
	{
	printf("Enter a option\n1.insert\n2.delete\n3.check empty\n4.check full\n5.display\n6.peek\n7.exit\n");
	scanf("%d", &a);
	switch(a)
	{
		case(1):
			printf("Enter the value: ");
			scanf("%d", &v);
			insert(v);
			break;
		case(2):
			del();
			break;
		case(3):
			if(isEmpty()==true)
				printf("Empty\n");
			else printf("Not Empty\n");	
			break;
		case(4):
			if(isFull()==true)
				printf("Full\n");
			else printf("Not full\n");
			break;
		case(5):
			display();
			break;
		case(6):
			peek();
			break;	
		case(7):
			p--;
			break;
		default:
			printf("Enter a valid input\n");
			break;						
		}
	}
}
