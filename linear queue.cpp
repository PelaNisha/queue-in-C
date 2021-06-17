 // array implementation for linear queue

#include<stdio.h>

#define SIZE 4

//initializing global variables
int lqueue[SIZE];
int front = -1, rear = -1;

//declaring functions
void insert(int);
void display();
bool isEmpty();
bool isFull();
int peek();
int del();

//insert function
void insert(int item)
{
	if (isFull())//check full condition
	{
			printf("Queue is full\n");
	}else if(isEmpty())
	{
			front=0; rear=0;// initialize rear and front to 0
			lqueue[rear]=item;//pass item to the rear position
	}
	else{
			
			lqueue[++rear]=item;	// else increment rear and pass item to rear
}}

//delete function
int del()
{
	int item;
	if(isEmpty())//check empty
	{
			printf("Empty\n");
	}else if(rear==front)
		{
			item = lqueue[front];//pass the front to item and make queue empty
			rear =-1; 
			front=-1;
		}
	else
	{
		item = lqueue[front];		//pass the element at the front to item
		front++;					//and increment front

	}
	printf("Deleted item: %d\n",item);
		
}

//empty function
bool isEmpty()
{
	return (rear==-1 && front==-1);//return true if rear=front=-1
}

//full function
bool isFull()
{
	return rear== SIZE-1;//return true if rear = size-1 
}

//peek function
int peek()
{
	if(isEmpty())//check empty
		printf("Empty, Nothing to peek\n");
	else
	{
			printf("%d\n",lqueue[front]);//print the first element
	}
}

//diaplay function
void display()
{
	if(isEmpty())//check empty
	{
		printf("Nothing to display!\n");
	}
	else
	{
			
		for(int i = front; i<=rear; i++)
		{
				printf("%d | \n",lqueue[i]);//print every element from front to rear
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
				insert(v);						//call insert function
				break;
			case(2):
				del();
				break;
			case(3):
				if(isEmpty())					//call empty function
				{
						printf("Empty\n");
				}else{
				 printf("Not Empty\n");	
				}
				break;
			case(4):
				if(isFull())					//call full function
				{
						printf("Full\n");
				}else 
				{
					printf("Not full\n");
				}break;
			case(5):
				display();						//call display function
				break;
			case(6):
				peek();							//call peek function
				break;	
			case(7):
				break;
			default:
				printf("Enter a valid input\n");//default output
				break;						
		}
	}
}
