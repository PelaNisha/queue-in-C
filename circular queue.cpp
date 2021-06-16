// array implementation od circular queue

#include<stdio.h>


#define SIZE 4

int cqueue[SIZE];
int front = -1, rear = -1;

void insert(int);
void display();
bool isEmpty();
bool isFull();
int peek();
void del();

void enqueue(int item)
{
	if (isFull())
		printf("Stack is full");
	else if(isEmpty())
		{
			front =0 ; rear = 0;
			cqueue[rear]=item;
	}
	else{
	
		rear = (rear+1)%SIZE;  
		cqueue[rear]=item;	
	}
	
}

void dequeue()
{
	int item;
	if(isEmpty())
		printf("Empty");
	else if(front==rear)
		{
			item = cqueue[front];
			rear ==front ==-1;
		}
	else
	{
			item = cqueue[front];
		front = (front+1)%SIZE;	
	}
	printf("%d", item);	
}

bool isEmpty()
{
	return rear==-1 && front==-1;
}
bool isFull()
{
	return front== (rear+1)%SIZE;
}
int peek()
{
	if(isEmpty())
	{
			printf("Empty, Nothing to peek");
	}else{
	
		printf("%d",cqueue[front]);
	}	
}
void display()
{
	int temp = front;
	if(isEmpty())
	{
		printf("Nothing to display");
	}
	else
	{
		while(temp!=rear)
		{
			printf("%d | ",cqueue[temp]);
			temp =(temp+1)%SIZE;
		}
	}
	printf("%d |\n",cqueue[temp]);
}

int main()
{
	int a,  v;
//	printf("%d\n", rear);
//	printf("%d\n", lqueue[front]);
//	printf("%d\n", lqueue[front]);
	while(a!=7)
	{
	printf("Enter a option\n1.insert\n2.delete\n3.check empty\n4.check full\n5.display\n6.peek\n7.exit\n");
	scanf("%d", &a);
	switch(a)
	{
		case(1):
			printf("Enter the value: ");
			scanf("%d", &v);
			enqueue(v);
			break;
		case(2):
			dequeue();
			break;
		case(3):
			if(isEmpty())
				printf("Empty\n");
			else printf("Not Empty\n");	
			break;
		case(4):
			if(isFull())
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
			break;
		default:
			printf("Enter a valid input\n");
			break;						
		}
	}
}
