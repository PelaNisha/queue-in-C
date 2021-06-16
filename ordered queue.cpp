// ordered priority queue


#include<stdio.h>


#define SIZE 4

int pqueue[SIZE];
int front = -1, rear = -1, i;

void insert(int);
void display();
bool isEmpty();
bool isFull();
int peek();
void del();

void insert(int item)
{
	i= rear;
	if (isFull())
	{
			printf("STack is full\n");
	}else if(isEmpty())
	{
			front=0; rear=0;
			pqueue[rear]=item;
	}
	else{
			
			while(i>=front&&item<pqueue[i])
			{
				pqueue[i+1]=pqueue[i];//right shift
				i--;
			}
			pqueue[i+1]= item;
			rear++;
}}

void del()
{
	int item;
	if(isEmpty())
	{
			printf("Empty");
	}	
	else if(rear==front)
	{
			item = pqueue[front];
			rear == front ==-1;
		}
	else
	{
			item = pqueue[front];
		front++;
	}
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
	if(isEmpty())
	{
			printf("Empty, Nothing to peek\n");
	}else
	{
			printf("%d\n",pqueue[front]);
	}
}

void display()
{
//	int temp = front;
	if(isEmpty())
	{
		printf("Nothing to display\n");
	}
	else
		
		for(int i = front; i<=rear; i++)
		{
				printf("%d | \n",pqueue[i]);
	}
}

int main()
{
	int a, v;
//	printf("%d\n", rear);
//	printf("%d\n", pqueue[front]);
//	printf("%d\n", pqueue[front]);
	while(a!=7)
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
