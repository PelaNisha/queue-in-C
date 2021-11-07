// ascending priority queue
#include<stdio.h>
#define SIZE 5
int pq[SIZE];
int rear=-1;
int front=-1;

bool isEmpty()
{
	return(rear==-1&&front==-1);
}
bool isFull()
{
	return (rear==SIZE-1);
}
void arrange()
{
	int i, j;
	for(int i = front; i<rear-1; i++)
	{
		for(int j = front; j<rear-i-1; j++)
		{
			if(pq[j]>pq[j+1])
			{
				int a = pq[j];
				pq[j] = pq[j+1];
				pq[j+1] = a;
			}
		}
	}
//	for (int c = front; c <= rear; c++)
//	{
//		printf("%d\n", pq[c]);
//	}
}
void insert()
{
	int el;
	if(isFull())
	{
		printf("queue Full\n");
	}else
	if(isEmpty())
	{
		printf("enter the element\n");
		scanf("%d", &el);
		rear =0;
		 front =0;
		pq[rear]= el;
	}else
	{
		printf("enter the element if not empty\n");
		scanf("%d", &el);
//		rear = rear+1;
		pq[++rear]= el;
		arrange();
	}
}

void delet()
{
	int el;
	if(isEmpty())
	{
		printf("Nothig to delete\n");
	}else
	{
		el = pq[front];
		front++;
	}
}

void display()
{
	if(isEmpty())
	{
		printf("nothing to display\n");
	}else
	{
		for(int i = front; i<=rear; i++)
		{
			printf("%d\n", pq[i]);
		}
	}
}
//
int find_min()
{
	int el;
	int min = pq[front];
	for(int i = front+1; i<=rear; i++)
	{
		if(pq[i]<min)
		{
			min = pq[i];
		}
	}
	printf("%d\n", min);
//	return min;
}


int main()
{
	int a, i;
	do{
		printf("Enter the options:\n1.insert\n2.display\n3.findmin\n4.arrange\n5.delete\n");
		scanf("%d", &a);
		switch(a){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				find_min();
				break;	
			case 4:
				arrange();
				break;	
			case 5:
				delet();
				break;		
			default:
				printf("Invalid option\n");
				break;	
		}
	}while(i!=2);
	
}
