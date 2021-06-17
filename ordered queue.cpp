// min ordered priority queue

#include<stdio.h>

#define SIZE 4

//global variable decclaration
int pqueue[SIZE];
int front = -1, rear = -1, i;

//funtion declaration
void insert(int);
void display();
bool isEmpty();
bool isFull();
int peek();
int del();

//insert function
void insert(int item)
{
	i= rear;
	if (isFull())
	{
			printf("Queue is full\n");
	}else if(isEmpty())
	{
			front=0; rear=0;
			pqueue[rear]=item;//pass item to rear and make rear=front=0
	}
	else{
			
			while(i>=front&&item<pqueue[i])
			{
				pqueue[i+1]=pqueue[i];//right shift
				i--;
			}
			pqueue[i+1]= item;//pass item to i+1 and increment rear
			rear++;
	}
}

//delete function
int del()
{
	int item;
	if(isEmpty())
	{
			printf("Empty");
	}	
	else if(rear==front)
	{
			item = pqueue[front];// pass front to item and make rear=front=-1
			rear =-1;
			front =-1;
		}
	else
	{
		item = pqueue[front];//pass front to item and increment front
		front++;
	}
	printf("Deleted item: %d\n",item);
}

//empty function
bool isEmpty()
{
	return rear==-1 && front==-1;
}

//full function
bool isFull()
{
	return rear== SIZE-1;
}

//peek function
int peek()
{
	if(isEmpty())
	{
			printf("Empty, Nothing to peek\n");
	}else
	{
			printf("%d\n",pqueue[front]);// print the front
	}
}

//display function
void display()
{
	if(isEmpty())
	{
		printf("Nothing to display\n");
	}
	else
	{
		for(int i = front; i<=rear; i++)
		{
				printf("%d | \n",pqueue[i]);// print every element frrom front to rear
		}
	}
}

//main function
int main()
{
	int a, v;

	while(a!=7)
	{
		printf("Enter an option\n1.insert\n2.delete\n3.check empty\n4.check full\n5.display\n6.peek\n7.exit\n");
		scanf("%d", &a);
		switch(a)
		{
			case(1):
				printf("Enter the value: ");
				scanf("%d", &v);
				insert(v);//call insert function
				break;
			case(2):
				del();//call delete function
				break;
			case(3):
				if(isEmpty())//call empty function
				{
						printf("Empty\n");
				}else
				{
				  printf("Not Empty\n");	
				}break;
			case(4):
				if(isFull())//call full function
				{
						printf("Full\n");
				}else 
				{
						printf("Not full\n");
				}break;
			case(5):
				display();// call display function
				break;
			case(6):
				peek();//call peek function
				break;	
			case(7):
				break;
			default:
				printf("Enter a valid input\n");
				break;						
		}
	}
}
