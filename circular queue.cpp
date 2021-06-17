// array implementation od circular queue

#include<stdio.h>


#define SIZE 4

//global variable decclaration
int cqueue[SIZE];
int front = -1, rear = -1;

//declaring function
void enqueue(int);
void display();
bool isEmpty();
bool isFull();
int peek();
int dequeue();

//enqueue function
void enqueue(int item)
{
	if (isFull())
		printf("Queue is full\n");
	else if(isEmpty())
		{
			front =0 ; rear = 0;//if empty then initialize fron and rear to 0 and pass item to rear
			cqueue[rear]=item;
	}
	else{
	
		rear = (rear+1)%SIZE;  //increment rear and pass item to rear
		cqueue[rear]=item;	
	}
	
}

//dequeue function
int dequeue()
{
	int item;
	if(isEmpty())
		printf("Empty");
	else if(front==rear)// if there is only one element
		{
			item = cqueue[front];// pass front to item and intialize rear and front to -1
			rear =-1;
			front =-1;
		}
	else
	{
		item = cqueue[front];// else pass front to item and increment front
		front = (front+1)%SIZE;	
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
	return front== (rear+1)%SIZE;
}

//peak function
int peek()
{
	if(isEmpty())
	{
			printf("Empty, Nothing to peek\n");
	}else{
	
		printf("%d",cqueue[front]);// print the front element
	}	
}

//display function
void display()
{
	int temp = front;
	if(isEmpty())
	{
		printf("Nothing to display\n");
	}
	else
	{
		while(temp!=rear)
		{
			printf("%d | ",cqueue[temp]);// display the element till temp!= rear
			temp =(temp+1)%SIZE;
		}
	}
	printf("%d |\n",cqueue[temp]);// display last element
}

//main function
int main()
{
	int a,  v;
	while(a!=7)
	{
		printf("Enter an option\n1.insert\n2.delete\n3.check empty\n4.check full\n5.display\n6.peek\n7.exit\n");
		scanf("%d", &a);
		switch(a)
		{
			case(1):
				printf("Enter the value: ");
				scanf("%d", &v);
				enqueue(v);// call enqueue function
				break;
			case(2):
				dequeue();
				break;
			case(3):
				if(isEmpty())// call empty function 
				{
						printf("Empty\n");
				}else 
				{
					printf("Not Empty\n");	
				}break;
			case(4):
				if(isFull())// call full function 
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
